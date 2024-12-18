import serial
import serial.tools.list_ports
from PyQt6.QtCore import *
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
import pickle
from ParameterManager import ParameterManager  
import struct
import time
from egram_plot import EgramPlot  

# Application window for pacemaker
class ApplicationWindow(QMainWindow):
    def __init__(self, username):
        super().__init__()

        # Create an instance of ParameterManager
        self.parameter_manager = ParameterManager()

        # Initialize for user file to store all parameters
        self.username = username
        self.users_file = 'users.dat'
        self.load_user_parameters()

        # Create an instance of ParameterManager for the current user
        self.parameter_manager = self.user_parameters.get(username, ParameterManager())

        # Set up window title and size
        self.setWindowTitle("Pacing Mode Selection")
        self.setFixedSize(QSize(1000, 700))

        # Store the connected port
        self.connected_port = None  

        # Parameter fields
        self.fields = {
            "Lower Rate Limit": QLineEdit(),
            "Upper Rate Limit": QLineEdit(),
            "Atrial Amplitude": QLineEdit(),
            "Atrial Pulse Width": QLineEdit(),
            "Ventricular Amplitude": QLineEdit(),
            "Ventricular Pulse Width": QLineEdit(),
            "VRP": QLineEdit(),
            "ARP": QLineEdit(),
            "Maximum Sensor Rate": QLineEdit(),
            "Fixed AV Delay": QLineEdit(),
            "Ventricular Sensitivity": QLineEdit(),
            "PVARP": QLineEdit(),
            "Hysteresis": QLineEdit(),
            "Rate Smoothing": QComboBox(),
            "Activity Threshold": QComboBox(),
            "Reaction Time": QLineEdit(),
            "Response Factor": QLineEdit(),
            "Recovery Time": QLineEdit(),
        }

        # Set initial values in the fields using the ParameterManager
        for field_name, field_widget in self.fields.items():
            if isinstance(field_widget, QComboBox):
                if field_name == "Rate Smoothing":
                    field_widget.addItems(["0", "3", "6", "9", "12", "15", "18", "21", "25"])
                elif field_name == "Activity Threshold":
                    field_widget.addItems([
                        "1.13", "1.25", "1.4", "1.6", "2", "2.4", "3"
                    ])
                current_value = str(getattr(self.parameter_manager, f"get{field_name.replace(' ', '')}")())
                index = field_widget.findText(current_value, Qt.MatchFlag.MatchContains)
                field_widget.setCurrentIndex(index if index != -1 else 0)
            else:
                field_widget.setText(str(getattr(self.parameter_manager, f"get{field_name.replace(' ', '')}")()))

        # Create the main layout for pacing mode selection
        main_layout = QVBoxLayout()

        # Header layout for username display and exit button
        header_layout = QHBoxLayout()

        # Username display
        self.username_label = QLabel(f"Logged in as: {username}")
        self.username_label.setFont(QFont('Arial', 12))
        header_layout.addWidget(self.username_label, alignment=Qt.AlignmentFlag.AlignLeft)

        # Exit Button 
        self.exit_button = QPushButton("Exit")
        self.exit_button.setFixedSize(100, 30)
        self.exit_button.clicked.connect(self.exit_program)
        header_layout.addStretch()  # stretch exit button to the right
        header_layout.addWidget(self.exit_button)

        # Add header layout to the main layout
        main_layout.addLayout(header_layout)

        # Spacer for better display
        main_layout.addSpacing(20)

        # Pacing Mode Selection Dropdown
        pacing_mode_layout = QHBoxLayout()
        pacing_mode_label = QLabel("Select Pacing Mode:")
        pacing_mode_label.setFont(QFont('Arial', 12))

        self.pacing_mode_combo = QComboBox()
        self.pacing_mode_combo.setFont(QFont('Arial', 12))  # Combo box for drop down menu
        self.pacing_mode_combo.setFixedSize(200, 30)
        # All pacing modes
        self.pacing_mode_combo.addItems(["None", "AOO", "VOO", "AAI", "VVI", "AOOR", "AAIR", "VOOR", "VVIR", "DDD", "DDDR"])
        self.pacing_mode_combo.currentIndexChanged.connect(self.update_parameters)

        pacing_mode_layout.addStretch()
        pacing_mode_layout.addWidget(pacing_mode_label)
        pacing_mode_layout.addWidget(self.pacing_mode_combo)
        pacing_mode_layout.addStretch()

        # Add pacing mode layout to the main layout
        main_layout.addLayout(pacing_mode_layout)

        # Spacer for better display
        main_layout.addSpacing(20)

        # Parameter Fields
        self.field_containers = {}  

        # Create a main horizontal layout for two columns
        param_main_layout = QHBoxLayout()
        left_param_layout = QVBoxLayout()
        right_param_layout = QVBoxLayout()

        # Add fields for parameter display
        for i, (field_name, field_widget) in enumerate(self.fields.items()):
            label = QLabel(f"{field_name}:")
            label.setFont(QFont('Arial', 10))
            field_widget.setFixedSize(150, 25)

            self.field_containers[field_name] = (label, field_widget)

            field_layout = QHBoxLayout()
            field_layout.addWidget(label, alignment=Qt.AlignmentFlag.AlignRight)
            field_layout.addWidget(field_widget, alignment=Qt.AlignmentFlag.AlignLeft)

            if i < 9:
                left_param_layout.addLayout(field_layout)
            else:
                right_param_layout.addLayout(field_layout)

        # Add to the main horizontal layout
        param_main_layout.addStretch()
        param_main_layout.addLayout(left_param_layout)
        param_main_layout.addSpacing(50) 
        param_main_layout.addLayout(right_param_layout)
        param_main_layout.addStretch()

        # Add the parameter layout to the main layout
        main_layout.addLayout(param_main_layout)

        # Spacer for better display
        main_layout.addSpacing(20)

        # Layout for Apply Button
        button_layout = QHBoxLayout()

        # Apply Button for Parameter 
        self.apply_button = QPushButton("Apply")
        self.apply_button.setFixedSize(150, 50)
        self.apply_button.clicked.connect(self.apply_parameters)
        button_layout.addStretch()
        button_layout.addWidget(self.apply_button, alignment=Qt.AlignmentFlag.AlignCenter)

        # Add button layout to main layout
        main_layout.addLayout(button_layout)

        # Spacer for better display
        main_layout.addSpacing(20)
        
        # Egram Button 
        self.egram_button = QPushButton("Egram")
        self.egram_button.setFixedSize(150, 50)
        self.egram_button.clicked.connect(self.start_egram)
        button_layout.addWidget(self.egram_button, alignment=Qt.AlignmentFlag.AlignCenter)

        # Connection Status Check Button
        connection_layout = QHBoxLayout()
        self.status_msg = QLabel("Device not connected")
        self.status_msg.setFont(QFont('Arial', 12))
        self.status_msg.setStyleSheet("color: red;")
        self.refresh_button = QPushButton("Refresh")
        self.refresh_button.setFixedSize(100, 40)
        self.refresh_button.clicked.connect(self.check_connection_status)

        connection_layout.addStretch()
        connection_layout.addWidget(self.status_msg, alignment=Qt.AlignmentFlag.AlignRight)
        connection_layout.addWidget(self.refresh_button, alignment=Qt.AlignmentFlag.AlignRight)

        main_layout.addLayout(connection_layout)

        # Set the layout in a central widget
        central_widget = QWidget()
        central_widget.setLayout(main_layout)
        self.setCentralWidget(central_widget)

    def load_user_parameters(self):
        try:
            with open(self.users_file, 'rb') as file:
                self.user_parameters = pickle.load(file)
                print("Loaded user parameters:")
                for user, params in self.user_parameters.items():
                    print(f"User: {user}, Parameters: {params.__dict__}")
        except FileNotFoundError:
            self.user_parameters = {}
            print("User data file not found. Creating new data structure.")

    def save_user_parameters(self):
        self.user_parameters[self.username] = self.parameter_manager
        with open(self.users_file, 'wb') as file:
            pickle.dump(self.user_parameters, file)
        print("Saved user parameters:")
        for user, params in self.user_parameters.items():
            print(f"User: {user}, Parameters: {params.__dict__}")

    # Method to get relevant parameters for the selected pacing mode
    def get_relevant_parameters_for_mode(self, mode):
        relevant_params_dict = {
            "AOO": ["Lower Rate Limit", "Upper Rate Limit", "Atrial Amplitude", "Atrial Pulse Width"],
            "AAI": ["Lower Rate Limit", "Upper Rate Limit", "Atrial Amplitude", "Atrial Pulse Width", "Atrial Sensitivity", "ARP", "PVARP", "Hysteresis", "Rate Smoothing"],
            "VOO": ["Lower Rate Limit", "Upper Rate Limit", "Ventricular Amplitude", "Ventricular Pulse Width"],
            "VVI": ["Lower Rate Limit", "Upper Rate Limit", "Ventricular Amplitude", "Ventricular Pulse Width", "Ventricular Sensitivity", "VRP", "Hysteresis", "Rate Smoothing"],
            "AOOR": ["Lower Rate Limit", "Upper Rate Limit", "Maximum Sensor Rate", "Atrial Amplitude", "Atrial Pulse Width", "Activity Threshold", "Reaction Time", "Response Factor", "Recovery Time"],
            "AAIR": ["Lower Rate Limit", "Upper Rate Limit", "Maximum Sensor Rate", "Atrial Amplitude", "Atrial Pulse Width", "Atrial Sensitivity", "ARP", "PVARP", "Hysteresis", "Rate Smoothing", "Activity Threshold", "Reaction Time", "Response Factor", "Recovery Time"],
            "VOOR": ["Lower Rate Limit", "Upper Rate Limit", "Maximum Sensor Rate", "Ventricular Amplitude", "Ventricular Pulse Width", "Activity Threshold", "Reaction Time", "Response Factor", "Recovery Time"],
            "VVIR": ["Lower Rate Limit", "Upper Rate Limit", "Maximum Sensor Rate", "Ventricular Amplitude", "Ventricular Pulse Width", "Ventricular Sensitivity", "VRP", "Hysteresis", "Rate Smoothing"],
        }
        return relevant_params_dict.get(mode, [])

    # Method to map the pacing mode 
    def get_mode_value(self, mode):
        mode_mapping = {
            "AOO": 1,
            "VOO": 2,
            "AAI": 3,
            "VVI": 4,
            "AOOR": 5,
            "VOOR": 6,
            "AAIR": 7,
            "VVIR": 8
        }
        return mode_mapping.get(mode, 0)  # Default to 0 if "None" or unrecognized
   
    # Method to apply parameters to ParameterManager
    def apply_parameters(self):
        mode = self.pacing_mode_combo.currentText()
        relevant_params = self.get_relevant_parameters_for_mode(mode)

        errors = 0
        error_text = ""

        # Apply only relevant parameters depending on the pacing modes
        for field_name, field_widget in self.fields.items():
            if field_name in relevant_params:
                if isinstance(field_widget, QComboBox):
                    value = field_widget.currentText().split()[0]
                else:
                    value = field_widget.text()

                if value:
                    try:
                        set_method = getattr(self.parameter_manager, f"set{field_name.replace(' ', '')}")
                        if field_name in ["Lower Rate Limit", "Upper Rate Limit", "Maximum Sensor Rate", "Fixed AV Delay", "ARP", "VRP", "PVARP", "Reaction Time", "Response Factor", "Recovery Time"]:
                            set_method(float(value))
                        elif field_name in ["Atrial Amplitude", "Ventricular Amplitude", "Atrial Sensitivity", "Ventricular Sensitivity", "Activity Threshold"]:
                            set_method(float(value))
                        elif field_name == "Rate Smoothing":
                            set_method(int(value))
                        elif field_name == "Hysteresis":
                            set_method(int(float(value)))
                    except TypeError:
                        errors += 1
                        error_text += f"{field_name}: Please use numeric value input!."
                    except IndexError:
                        errors += 1
                        if field_name == "Lower Rate Limit":
                            error_text += f"{field_name}: Must be between 30 and 175 bpm."
                        elif field_name == "Upper Rate Limit":
                            error_text += f"{field_name}: Must be between 50 and 175 bpm and greater than Lower Rate Limit."
                        elif field_name == "Maximum Sensor Rate":
                            error_text += f"{field_name}: Must be between 50 and 175 bpm and greater than Lower Rate Limit."
                        elif field_name == "Atrial Amplitude" or field_name == "Ventricular Amplitude":
                            error_text += f"{field_name}: Must be between 0.1 and 5.0 V."
                        elif field_name == "Atrial Pulse Width" or field_name == "Ventricular Pulse Width":
                            error_text += f"{field_name}: Must be between 1 and 30 ms."
                        elif field_name == "Atrial Sensitivity" or field_name == "Ventricular Sensitivity":
                            error_text += f"{field_name}: Must be between 0.0 and 5.0 V."
                        elif field_name == "ARP" or field_name == "VRP" or field_name == "PVARP":
                            error_text += f"{field_name}: Must be between 150 and 500 ms."
                        elif field_name == "Hysteresis":
                            error_text += f"{field_name}: Must be between 0 and 175."
                        elif field_name == "Reaction Time":
                            error_text += f"{field_name}: Must be between 10 and 50 seconds."
                        elif field_name == "Response Factor":
                            error_text += f"{field_name}: Must be between 1 and 16."
                        elif field_name == "Recovery Time":
                            error_text += f"{field_name}: Must be between 1 and 16 minutes."
                        else:
                            error_text += f"{field_name}: Value out of range, please enter a valid value."

        if errors > 0:
            QMessageBox.warning(self, "Input Error", f"There are {errors} error(s):{error_text}")
        else:
            self.save_user_parameters()
            QMessageBox.information(self, "Success", "Parameters successfully updated!")
            # Send inputted data to the pacemaker device
            self.send_and_validate_parameters()

    # Method to update parameters for the selected pacing mode
    def update_parameters(self):
        mode = self.pacing_mode_combo.currentText()
        self.current_pacing_mode = mode

        # Define visibility for each pacing mode
        visibility_dict = {field: field in self.get_relevant_parameters_for_mode(mode) for field in self.fields}
        self.set_field_visibility(visibility_dict)

    # Method to set visibility of parameter fields
    def set_field_visibility(self, visibility_dict):
        for field_name, is_visible in visibility_dict.items():
            label, field_widget = self.field_containers.get(field_name, (None, None))
            if label and field_widget:
                label.setVisible(is_visible)
                field_widget.setVisible(is_visible)

    # Method to check connection status
    def check_connection_status(self):

        ports = serial.tools.list_ports.comports()
        available_ports = [port.device for port in ports]

        # Common ports for macOS and Windows
        common_ports = ["COM9", "COM8", "COM7", "COM6", "COM5", "COM4", "COM3"]  # Windows
        mac_ports = ["/dev/tty.usbserial", "/dev/tty.usbmodem", "/dev/cu.usbserial", "/dev/cu.usbmodem"]  # macOS
        
        # Add macOS ports to the list of ports to check
        all_ports_to_check = available_ports + common_ports + mac_ports

        for port in all_ports_to_check:
            try:
                ser = serial.Serial(port=port, baudrate=115200, timeout=1)
                ser.close()
                self.connected_port = port
                self.status_msg.setText(f"Connected device: {port}")
                self.status_msg.setStyleSheet("color: green;")
                return
            except (serial.SerialException, FileNotFoundError):
                continue

        self.connected_port = None
        self.status_msg.setText("Device not connected")
        self.status_msg.setStyleSheet("color: red;")

    # Method to send parameters via serial communication and validate the response
    def send_and_validate_parameters(self):
        ser = None
        try:
            if not self.connected_port:
                QMessageBox.warning(self, "Error", "Device not connected.")
                return

            # Open the serial port
            ser = serial.Serial(port=self.connected_port, baudrate=115200, timeout=1)

            # Define the header and structure format for sending data
            data_format = '<3B13fH6f'  

            mode = self.get_mode_value(self.pacing_mode_combo.currentText())
            lrl = self.parameter_manager.getLowerRateLimit()
            url = self.parameter_manager.getUpperRateLimit()
            msr = self.parameter_manager.getMaximumSensorRate()
            aa = self.parameter_manager.getAtrialAmplitude()
            va = self.parameter_manager.getVentricularAmplitude()
            apw = self.parameter_manager.getAtrialPulseWidth()
            vpw = self.parameter_manager.getVentricularPulseWidth()
            asens = self.parameter_manager.getAtrialSensitivity()
            vsens = self.parameter_manager.getVentricularSensitivity()
            arp = self.parameter_manager.getARP()
            vrp = self.parameter_manager.getVRP()
            pvarp = self.parameter_manager.getPVARP()
            act_thresh = self.parameter_manager.getActivityThreshold()
            react_time = self.parameter_manager.getReactionTime()
            response_factor = self.parameter_manager.getResponseFactor()
            recovery_time = self.parameter_manager.getRecoveryTime()

            # Pack the data
            data_packet = struct.pack(data_format, 0x16, 0x55, mode, lrl, url, msr, aa, va, apw, vpw, asens, vsens, arp, vrp, pvarp, act_thresh, react_time, response_factor, recovery_time)
            print(f"Packet Length: {len(data_packet)}")
            ser.write(data_packet)

            # Wait for a response and read it
            time.sleep(0.5)
            response_data = ser.read(71)  ############# DATA LENGTH IS HERE
            ser.close()

            # Debug data type
            if len(response_data) != 71:
                QMessageBox.warning(self, "Error", "Invalid data length received from pacemaker.")
                return
            
            # Unpack the response values 
            modeV = struct.unpack('B', response_data[0:3])
            lrlV = struct.unpack('f', response_data[4:7])
            urlV = struct.unpack('f', response_data[8:11])
            msrV = struct.unpack('f', response_data[12:15])
            aaV = struct.unpack('f', response_data[16:19])
            vaV = struct.unpack('f', response_data[20:23])
            apwV = struct.unpack('f', response_data[24:27])
            vpwV = struct.unpack('f', response_data[28:31])
            asensV = struct.unpack('f', response_data[32:35])
            vsensV = struct.unpack('f', response_data[36:39])
            arpV = struct.unpack('H', response_data[40:43])
            vrpV = struct.unpack('H', response_data[44:47])
            pvarpV = struct.unpack('H', response_data[48:49])
            act_threshV = struct.unpack('f', response_data[50:53])
            react_timeV = struct.unpack('f', response_data[54:57])
            response_factorV = struct.unpack('f', response_data[58:61])
            recovery_timeV = struct.unpack('f', response_data[62:65])

            # Debugging recived data
            print(f"Data received:")
            print(f"Mode: {modeV}, Lower Rate Limit: {lrlV}, Upper Rate Limit: {urlV}, Maximum Sensor Rate: {msrV}")
            print(f"Atrial Amplitude: {aaV}, Ventricular Amplitude: {vaV}, Atrial Pulse Width: {apwV}, Ventricular Pulse Width: {vpwV}")
            print(f"Atrial Sensitivity: {asensV}, Ventricular Sensitivity: {vsensV}, ARP: {arpV}, VRP: {vrpV}, PVARP: {pvarpV}")
            print(f"Activity Threshold: {act_threshV}, Reaction Time: {react_timeV}, Response Factor: {response_factorV}, Recovery Time: {recovery_timeV}")

            # Validate the response data
            if (modeV == mode and lrlV == lrl and urlV == url and msrV == msr and abs(aaV - aa) < 0.01 and
                    abs(vaV - va) < 0.01 and apwV == apw and vpwV == vpw and asensV == asens and vsensV == vsens and
                    arpV == arp and vrpV == vrp and pvarpV == pvarp and abs(act_threshV - act_thresh) < 0.01 and
                    react_timeV == react_time and response_factorV == response_factor and recovery_timeV == recovery_time):
                QMessageBox.information(self, "Success", "Parameters set and stored successfully.")
            else:
                QMessageBox.warning(self, "Error", "Some or all parameters did not store properly.")

        except struct.error as e:
            QMessageBox.warning(self, "Error", f"Data Packing/Unpacking Error: {str(e)}")
        except serial.SerialException as e:
            QMessageBox.warning(self, "Error", f"Serial Communication Error: {str(e)}")
        finally:
            if ser and ser.is_open:
                ser.close()

    # Method to start the Egram plot
    def start_egram(self):
        if self.connected_port:
            # Pass the connected port to the EgramPlot instance 
            self.egram_plot = EgramPlot(port=self.connected_port) 
            self.egram_plot.show()  
        else:
            QMessageBox.warning(self, "Error", "Device not connected. Please connect to start Egram.")

    # Method to exit the application
    def exit_program(self):
        QApplication.quit()

