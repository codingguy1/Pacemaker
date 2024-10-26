import serial
import serial.tools.list_ports
from PyQt6.QtCore import *
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *

# Sub Class to customize pacemaker's application window
class ApplicationWindow(QMainWindow):
    def __init__(self, username):
        super().__init__()

        # Section: Initialization
        # ---------------------------------
        # Parameter fields
        self.fields = {
            "Lower Rate Limit": QLineEdit(),
            "Upper Rate Limit": QLineEdit(),
            "Atrial Amplitude": QLineEdit(),
            "Atrial Pulse Width": QLineEdit(),
            "Ventricular Amplitude": QLineEdit(),
            "Ventricular Pulse Width": QLineEdit(),
            "VRP": QLineEdit(),
            "ARP": QLineEdit()
        }
        self.current_pacing_mode = None  # Set initial pacing mode as none

        # Parameter Ranges
        self.parameter_ranges = {
            "Lower Rate Limit": (30, 175),
            "Upper Rate Limit": (50, 175),
            "Atrial Amplitude": (0, 7),
            "Atrial Pulse Width": (0.05, 1.9),
            "Ventricular Amplitude": (0, 7),
            "Ventricular Pulse Width": (0.05, 1.9),
            "VRP": (150, 500),
            "ARP": (150, 500)
        }

        # Window title and dimensions
        self.setWindowTitle("Application Window")
        self.setFixedSize(QSize(800, 600))

        # Display the logged-in user's name
        self.username_label = QLabel(f"Logged in as: {username}", self)
        self.username_label.setFont(QFont('Arial', 14))
        self.username_label.setGeometry(10, 550, 300, 30)  # Set position and size of label

        # Section: Central Stacked Widget
        # ---------------------------------
        # Create a central stacked widget to hold different views
        self.central_stack = QStackedWidget()
        self.setCentralWidget(self.central_stack)

        # Create individual widgets for each functionality
        self.parameters_widget = self.create_parameters_widget()
        self.egram_widget = self.create_egram_widget()
        self.connection_widget = self.create_connection()

        # Add each widget to the central stacked widget
        self.central_stack.addWidget(self.parameters_widget)
        self.central_stack.addWidget(self.egram_widget)
        self.central_stack.addWidget(self.connection_widget)

        # Section: Toolbar
        # ---------------------------------
        # Create Toolbar
        toolbar = QToolBar("Main Toolbar")
        self.addToolBar(toolbar)

        # Add actions to the toolbar
        parameters_action = QAction("Parameters", self)
        parameters_action.triggered.connect(lambda: self.central_stack.setCurrentWidget(self.parameters_widget))
        toolbar.addAction(parameters_action)

        egram_action = QAction("Electrogram", self)
        egram_action.triggered.connect(lambda: self.central_stack.setCurrentWidget(self.egram_widget))
        toolbar.addAction(egram_action)

        connection_action = QAction("Device Connection", self)
        connection_action.triggered.connect(lambda: self.central_stack.setCurrentWidget(self.connection_widget))
        toolbar.addAction(connection_action)

        # Add Exit button to the toolbar
        exit_action = QAction("Exit", self)
        exit_action.triggered.connect(self.exit)
        toolbar.addAction(exit_action)

    # Section: Parameters Widget
    # ---------------------------------
    def create_parameters_widget(self):
        # Create a widget for setting programmable parameters
        widget = QWidget()
        layout = QVBoxLayout()

        # Create a layout for the pacing mode selection at the top
        pacing_mode_layout = QHBoxLayout()
        pacing_mode_label = QLabel("Select Pacing Mode:")
        pacing_mode_label.setFont(QFont('Arial', 12))

        # Dropdown menu for pacing modes
        self.pacing_mode_combo = QComboBox()
        self.pacing_mode_combo.addItems(["None", "AOO", "VOO", "AAI", "VVI"])  # Added 'None' as the first option
        self.pacing_mode_combo.currentIndexChanged.connect(self.update_parameters)

        # Add label and drop down menu to the layout
        pacing_mode_layout.addWidget(pacing_mode_label)
        pacing_mode_layout.addWidget(self.pacing_mode_combo)

        # Create a form layout for parameter fields
        self.param_form_layout = QFormLayout()
        layout.addLayout(pacing_mode_layout)
        layout.addLayout(self.param_form_layout)

        # Units for each parameter
        units = {
            "Lower Rate Limit": "ppm",
            "Upper Rate Limit": "ppm",
            "Atrial Amplitude": "V",
            "Atrial Pulse Width": "ms",
            "Ventricular Amplitude": "V",
            "Ventricular Pulse Width": "ms",
            "VRP": "ms",
            "ARP": "ms"
        }

        # Create dictionaries to hold field containers and labels
        self.field_containers = {}
        self.field_labels = {}

        # Add fields to the form layout with units
        for field_name, field_widget in self.fields.items():
            # Create a horizontal layout to hold the field and the unit label
            field_layout = QHBoxLayout()
            field_layout.addWidget(field_widget)

            # Add unit label if defined for the field
            unit_label = QLabel(units.get(field_name, ""))
            unit_label.setFont(QFont('Arial', 10))
            field_layout.addWidget(unit_label)

            # Create a container widget for the field and unit
            container = QWidget()
            container.setLayout(field_layout)

            # Store the container and label 
            self.field_containers[field_name] = container
            label = QLabel(f"{field_name}:")
            self.field_labels[field_name] = label

            # Add the label and container to the form layout
            self.param_form_layout.addRow(label, container)

        # Add Apply Button to validate input
        self.apply_button = QPushButton("Apply")
        self.apply_button.clicked.connect(self.validate_parameters)
        layout.addWidget(self.apply_button, alignment=Qt.AlignmentFlag.AlignCenter)

        widget.setLayout(layout)
        return widget

    # Function to valiadate whether the input value is out of range
    def validate_parameters(self):
        for field_name, (min, max) in self.parameter_ranges.items():
            field_text = self.fields[field_name].text()
            if field_text:  # Only check if there is an input
                try:
                    value = float(field_text)
                    if not (min <= value <= max):
                        QMessageBox.warning(self, "Input Error", f"{field_name} is out of range ({min}-{max}).")
                        return  # Exit on the first error
                except ValueError:
                    QMessageBox.warning(self, "Input Error", f"Invalid input for {field_name}. Please enter a numeric value.")
                    return

        QMessageBox.information(self, "Success", "All parameters are within the valid range.")


    def update_parameters(self):
        # Define the relevant parameters to show for each mode
        mode = self.pacing_mode_combo.currentText()
        self.current_pacing_mode = mode

        self.update_egram_label()  # Update the Egram label with the current pacing mode

        # Define specified parameters for each pacing mode
        if mode == "AOO":
            self.set_field_visibility({
                "Lower Rate Limit": True,
                "Upper Rate Limit": True,
                "Atrial Amplitude": True,
                "Atrial Pulse Width": True,
                "Ventricular Amplitude": False,
                "Ventricular Pulse Width": False,
                "VRP": False,
                "ARP": False
            })
            self.set_nominal_value("60", "120", "3.5", "0.4", "", "", "", "")

        elif mode == "AAI":
            self.set_field_visibility({
                "Lower Rate Limit": True,
                "Upper Rate Limit": True,
                "Atrial Amplitude": True,
                "Atrial Pulse Width": True,
                "Ventricular Amplitude": False,
                "Ventricular Pulse Width": False,
                "VRP": True,
                "ARP": True
            })
            self.set_nominal_value("60", "120", "3.5", "0.4", "", "", "320", "250")

        elif mode == "VOO":
            self.set_field_visibility({
                "Lower Rate Limit": True,
                "Upper Rate Limit": True,
                "Atrial Amplitude": False,
                "Atrial Pulse Width": False,
                "Ventricular Amplitude": True,
                "Ventricular Pulse Width": True,
                "VRP": False,
                "ARP": False
            })
            self.set_nominal_value("60", "120", "", "", "3.5", "0.4", "", "")

        elif mode == "VVI":
            self.set_field_visibility({
                "Lower Rate Limit": True,
                "Upper Rate Limit": True,
                "Atrial Amplitude": False,
                "Atrial Pulse Width": False,
                "Ventricular Amplitude": True,
                "Ventricular Pulse Width": True,
                "VRP": True,
                "ARP": False
            })
            self.set_nominal_value("60", "120", "", "", "3.5", "0.4", "320", "")

        else:
            self.clear_parameters()

    def set_field_visibility(self, visibility_dict):
        # Set visibility for each parameter field container and label 
        for field_name, is_visible in visibility_dict.items():
            container = self.field_containers.get(field_name)
            label = self.field_labels.get(field_name)
            if container:
                container.setVisible(is_visible)
            if label:
                label.setVisible(is_visible)

    def set_nominal_value(self, lower_rate_limit, upper_rate_limit, atrial_amplitude, atrial_pulse_width, ventricular_amplitude, ventricular_pulse_width, vrp, arp):
        # Set parameter values in the QLineEdit widgets only for visible fields
        if self.fields["Lower Rate Limit"].isVisible():
            self.fields["Lower Rate Limit"].setText(lower_rate_limit)
        if self.fields["Upper Rate Limit"].isVisible():
            self.fields["Upper Rate Limit"].setText(upper_rate_limit)
        if self.fields["Atrial Amplitude"].isVisible():
            self.fields["Atrial Amplitude"].setText(atrial_amplitude)
        if self.fields["Atrial Pulse Width"].isVisible():
            self.fields["Atrial Pulse Width"].setText(atrial_pulse_width)
        if self.fields["Ventricular Amplitude"].isVisible():
            self.fields["Ventricular Amplitude"].setText(ventricular_amplitude)
        if self.fields["Ventricular Pulse Width"].isVisible():
            self.fields["Ventricular Pulse Width"].setText(ventricular_pulse_width)
        if self.fields["VRP"].isVisible():
            self.fields["VRP"].setText(vrp)
        if self.fields["ARP"].isVisible():
            self.fields["ARP"].setText(arp)

    def clear_parameters(self):
        # Clears all fields in the form layout
        for field_widget in self.fields.values():
            field_widget.clear()

    def update_egram_label(self):
        # Update electrogram widget label with the current pacing mode
        if hasattr(self, 'egram_label'):
            self.egram_label.setText(f"Current Pacing Mode: {self.current_pacing_mode}")

    # Section: Electrogram Widget
    # ---------------------------------
    def create_egram_widget(self):
        # Create a widget for real-time electrogram data (Placeholder)
        widget = QWidget()
        layout = QVBoxLayout()

        # Add a label to display the current pacing mode
        self.egram_label = QLabel("Current Pacing Mode: None")
        self.egram_label.setFont(QFont('Arial', 12))
        layout.addWidget(self.egram_label, alignment=Qt.AlignmentFlag.AlignTop | Qt.AlignmentFlag.AlignLeft)

        # Add the egram graph in the future
        self.egram_graph = QLabel("Insert Electrogram Here")
        self.egram_graph.setFont(QFont('Arial', 12))
        layout.addWidget(self.egram_graph, alignment=Qt.AlignmentFlag.AlignCenter)

        widget.setLayout(layout)
        return widget

    # Section: Device Connect Status Widget
    # ---------------------------------
    def create_connection(self):
        widget = QWidget()
        layout = QVBoxLayout()

        # Create buttons
        self.connect_button = QPushButton("Connection Status")
        self.disconnect_button = QPushButton("Disconnect Telemetry")

        # Set button sizes
        self.connect_button.setFixedSize(300, 60)
        self.disconnect_button.setFixedSize(300, 60)

        # Create a single status message label
        self.status_msg = QLabel("Device not connected")
        self.status_msg.setFont(QFont('Arial', 12))
        self.status_msg.setStyleSheet("color: red;")
        layout.addWidget(self.status_msg, alignment=Qt.AlignmentFlag.AlignCenter)

        # Button layout
        layout.addWidget(self.connect_button, alignment=Qt.AlignmentFlag.AlignCenter | Qt.AlignmentFlag.AlignBottom)
        layout.addWidget(self.disconnect_button, alignment=Qt.AlignmentFlag.AlignCenter | Qt.AlignmentFlag.AlignTop)
    
        # Connect the buttons to the appropriate slots
        self.connect_button.clicked.connect(self.check_connection_status)
        self.disconnect_button.clicked.connect(self.stop_telemetry)

        widget.setLayout(layout)
        return widget

    def check_connection_status(self):
        # Check available serial ports
        ports = serial.tools.list_ports.comports()
        for port in ports:
            # Pacemaker ID (Not tested)
            if "H00140" in port.description:
                self.status_msg.setText(f"Connected device: {port.device}")
                self.status_msg.setStyleSheet("color: green;")
                return

        # If no device is found
        self.status_msg.setText(f"Connected device: None")
        self.status_msg.setText("Device not connected")
        self.status_msg.setStyleSheet("color: red;")

    def stop_telemetry(self):
        # Set the logic here when actually connecting with the device
        # A condition to detect that the telemetry is on
        self.status_msg.setText("Telemetry is stopped")
        self.status_msg.setStyleSheet("color: red;")

    # Section: Program exit
    # ---------------------------------
    def exit(self):
        self.hide()
