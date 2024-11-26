import serial
import serial.tools.list_ports
from PyQt6.QtCore import *
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *

# Application window for pacemaker
class ApplicationWindow(QMainWindow):
    def __init__(self, username):
        super().__init__()

        # Set up window title and size
        self.setWindowTitle("Pacing Mode Selection")
        self.setFixedSize(QSize(1000, 850))  

        # Store the connected port
        self.connected_port = None  

        # Parameter fields and ranges
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

        # Create the main layout for pacing mode selection
        main_layout = QVBoxLayout()

        # Header layout for username display and exit button
        header_layout = QHBoxLayout()

        # Username display
        self.username_label = QLabel(f"Logged in as: {username}")
        self.username_label.setFont(QFont('Arial', 14))
        header_layout.addWidget(self.username_label, alignment=Qt.AlignmentFlag.AlignLeft)

        # Exit Button 
        self.exit_button = QPushButton("Exit")
        self.exit_button.setFixedSize(120, 30)
        self.exit_button.clicked.connect(self.exit_program)
        header_layout.addStretch()  # stretch exit button to the right
        header_layout.addWidget(self.exit_button)

        # header layout for login user display and exit button
        main_layout.addLayout(header_layout)

        # Spacer for better display
        main_layout.addSpacing(30)

        # Pacing Mode Selection Dropdown
        pacing_mode_layout = QHBoxLayout()
        pacing_mode_label = QLabel("Select Pacing Mode:")
        pacing_mode_label.setFont(QFont('Arial', 16))  

        self.pacing_mode_combo = QComboBox()
        self.pacing_mode_combo.setFont(QFont('Arial', 14)) # Combo box for drop down menu
        self.pacing_mode_combo.setFixedSize(250, 40) 
        self.pacing_mode_combo.addItems(["None", "AOO", "VOO", "AAI", "VVI"])
        self.pacing_mode_combo.currentIndexChanged.connect(self.update_parameters)

        pacing_mode_layout.addStretch()
        pacing_mode_layout.addWidget(pacing_mode_label)
        pacing_mode_layout.addWidget(self.pacing_mode_combo)
        pacing_mode_layout.addStretch()

        # Add pacing mode layout to the main layout
        main_layout.addLayout(pacing_mode_layout)

        # Spacer for better diplay
        main_layout.addSpacing(50)

        # Parameter Fields Layout
        param_layout = QVBoxLayout()
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

        # Add fields with labels and units
        self.field_containers = {}
        self.field_labels = {}
        for field_name, field_widget in self.fields.items():
            field_layout = QHBoxLayout()

            label = QLabel(f"{field_name}:")
            label.setFont(QFont('Arial', 12))
            self.field_labels[field_name] = label

            unit_label = QLabel(units.get(field_name, ""))
            unit_label.setFont(QFont('Arial', 10))

            field_layout.addStretch()
            field_layout.addWidget(label)
            field_layout.addWidget(field_widget)
            field_layout.addWidget(unit_label)
            field_layout.addStretch()

            container = QWidget()
            container.setLayout(field_layout)
            self.field_containers[field_name] = container

            param_layout.addWidget(container)

        main_layout.addLayout(param_layout)

        # Spacer for better display
        main_layout.addSpacing(50)

        # Layout for Apply Button and Electrogram Button 
        button_layout = QHBoxLayout()

        # Apply Button for Parameter Validation / Save parameter
        self.apply_button = QPushButton("Apply")
        self.apply_button.setFixedSize(200, 60)
        self.apply_button.clicked.connect(self.validate_parameters)
        button_layout.addStretch()
        button_layout.addWidget(self.apply_button, alignment=Qt.AlignmentFlag.AlignCenter)

        # Electrogram Button to dispaly plot
        self.egram_button = QPushButton("Open Electrogram Display")
        self.egram_button.setFixedSize(200, 60)
        self.egram_button.clicked.connect(self.open_egram_window)
        button_layout.addWidget(self.egram_button, alignment=Qt.AlignmentFlag.AlignCenter)
        button_layout.addStretch()

        # Add button layout to main layout
        main_layout.addLayout(button_layout)

        # Spacer for better display
        main_layout.addSpacing(30)

        # Connection Status at Bottom Right Corner
        connection_layout = QHBoxLayout()
        self.status_msg = QLabel("Device not connected")
        self.status_msg.setFont(QFont('Arial', 12))
        self.status_msg.setStyleSheet("color: red;")
        self.refresh_button = QPushButton("Refresh")
        self.refresh_button.setFixedSize(120, 50)
        self.refresh_button.clicked.connect(self.check_connection_status)

        connection_layout.addStretch()
        connection_layout.addWidget(self.status_msg, alignment=Qt.AlignmentFlag.AlignRight)
        connection_layout.addWidget(self.refresh_button, alignment=Qt.AlignmentFlag.AlignRight)

        main_layout.addLayout(connection_layout)

        # Set the layout in a central widget
        central_widget = QWidget()
        central_widget.setLayout(main_layout)
        self.setCentralWidget(central_widget)

    # Method to validate parameters
    def validate_parameters(self):
        for field_name, (min_value, max_value) in self.parameter_ranges.items():
            field_text = self.fields[field_name].text()
            if field_text:  # Only check if there is an input
                try:
                    value = float(field_text)
                    if not (min_value <= value <= max_value):
                        QMessageBox.warning(self, "Input Error", f"{field_name} is out of range ({min_value}-{max_value}).")
                        return
                except ValueError:
                    QMessageBox.warning(self, "Input Error", f"Invalid input for {field_name}. Please enter a numeric value.")
                    return

        QMessageBox.information(self, "Success", "All parameters are within the valid range.")

    # Method to update parameters for the selected pacing mode
    def update_parameters(self):
        mode = self.pacing_mode_combo.currentText()
        self.current_pacing_mode = mode

        # Define visibility for each pacing mode
        visibility_dict = {
            "Lower Rate Limit": mode in ["AOO", "VOO", "AAI", "VVI"],
            "Upper Rate Limit": mode in ["AOO", "VOO", "AAI", "VVI"],
            "Atrial Amplitude": mode in ["AOO", "AAI"],
            "Atrial Pulse Width": mode in ["AOO", "AAI"],
            "Ventricular Amplitude": mode in ["VOO", "VVI"],
            "Ventricular Pulse Width": mode in ["VOO", "VVI"],
            "VRP": mode in ["AAI", "VVI"],
            "ARP": mode == "AAI"
        }
        self.set_field_visibility(visibility_dict)

    # Method to set visibility of parameter fields
    def set_field_visibility(self, visibility_dict):
        for field_name, is_visible in visibility_dict.items():
            container = self.field_containers.get(field_name)
            label = self.field_labels.get(field_name)
            if container:
                container.setVisible(is_visible)
            if label:
                label.setVisible(is_visible)

    # Method to create and open electrogram display window
    def open_egram_window(self):
        egram_window = QWidget()
        egram_window.setWindowTitle("Electrogram Display")
        egram_window.setFixedSize(QSize(500, 400))

        layout = QVBoxLayout()
        egram_label = QLabel("Current Pacing Mode: None")
        egram_label.setFont(QFont('Arial', 12))
        layout.addWidget(egram_label, alignment=Qt.AlignmentFlag.AlignTop | Qt.AlignmentFlag.AlignLeft)

        egram_graph = QLabel("Insert Electrogram Here")
        egram_graph.setFont(QFont('Arial', 12))
        layout.addWidget(egram_graph, alignment=Qt.AlignmentFlag.AlignCenter)

        egram_window.setLayout(layout)
        egram_window.show()

    # Method to check connection status
    def check_connection_status(self):
        common_ports = ["COM6", "COM5", "COM4", "COM3"]
        for port in common_ports:
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

    # Method to exit the application
    def exit_program(self):
        QApplication.quit()
