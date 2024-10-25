import sys
import serial
import serial.tools.list_ports
from PyQt6.QtCore import *
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *

class ApplicationWindow(QMainWindow):
    def __init__(self, username):
        super().__init__()

        # Set the window title and dimensions
        self.setWindowTitle("Application Window")
        self.setFixedSize(QSize(800, 600))

        # Create a label to display the logged-in user's name
        self.username_label = QLabel(f"Logged in as: {username}", self)
        self.username_label.setFont(QFont('Arial', 14))
        self.username_label.setGeometry(10, 550, 300, 30)  # Set position and size of label

        # Section: Central Stacked Widget (Click toolbar will lead current window to a different section)
        # ---------------------------------
        # Create a central stacked widget to hold different views 
        self.central_stack = QStackedWidget()
        self.setCentralWidget(self.central_stack)

        # Create individual widgets for each functionality
        self.parameters_widget = self.create_parameters_widget()
        self.pacing_modes_widget = self.create_pacing_modes_widget()
        self.egram_widget = self.create_egram_widget()
        self.connection_widget = self.create_connection()

        # Add each widget to the central stacked widget
        self.central_stack.addWidget(self.parameters_widget)
        self.central_stack.addWidget(self.pacing_modes_widget)
        self.central_stack.addWidget(self.egram_widget)
        self.central_stack.addWidget(self.connection_widget)

        # Section: Toolbar (Remember to define a new toolbar when need a new Widget (which means window))
        # ---------------------------------
        # Create Toolbar
        toolbar = QToolBar("Main Toolbar")
        self.addToolBar(toolbar)

        # Add actions to the toolbar
        parameters_action = QAction("Parameters", self)
        parameters_action.triggered.connect(lambda: self.central_stack.setCurrentWidget(self.parameters_widget))
        toolbar.addAction(parameters_action)

        pacing_modes_action = QAction("Pacing Modes", self)
        pacing_modes_action.triggered.connect(lambda: self.central_stack.setCurrentWidget(self.pacing_modes_widget))
        toolbar.addAction(pacing_modes_action)

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
        layout = QFormLayout()

        # Add input fields for parameters
        layout.addRow("Lower Rate Limit:", QLineEdit())
        layout.addRow("Upper Rate Limit:", QLineEdit())
        layout.addRow("Atrial Amplitude:", QLineEdit())
        layout.addRow("Atrial Pulse Width:", QLineEdit())
        layout.addRow("Ventricular Amplitude:", QLineEdit())
        layout.addRow("Ventricular Pulse Width:", QLineEdit())
        layout.addRow("VRP:", QLineEdit())
        layout.addRow("ARP:", QLineEdit())

        widget.setLayout(layout)
        return widget

    # Section: Pacing Modes Widget
    # ---------------------------------
    def create_pacing_modes_widget(self):
        # Create a widget for selecting pacing modes
        widget = QWidget()
        layout = QVBoxLayout()

        # Add a combo box for selecting pacing modes
        pacing_mode_combo = QComboBox()
        pacing_mode_combo.addItems(["AOO", "VOO", "AAI", "VVI"])
        layout.addWidget(pacing_mode_combo)

        # Set layout to the widget
        widget.setLayout(layout)
        return widget

    # Section: Electrogram Widget
    # ---------------------------------
    def create_egram_widget(self):
        # Create a widget for real-time electrogram data (Placeholder)
        widget = QWidget()
        layout = QVBoxLayout()

        # Add a label as a placeholder for electrogram data visualization
        egram_label = QLabel("Real-Time Electrogram Data Placeholder")
        egram_label.setFont(QFont('Arial', 12))
        layout.addWidget(egram_label, alignment=Qt.AlignmentFlag.AlignCenter)

        # Set layout to the widget
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
        self.disconnect_button.clicked.connect(self.disconnect_device)

        widget.setLayout(layout)
        return widget

    def check_connection_status(self):
        # Check available serial ports
        ports = serial.tools.list_ports.comports()
        for port in ports:
            # Pacemaker ID 
            if "H00140" in port.description:
                self.status_msg.setText(f"Connected device: {port.device}")
                self.status_msg.setStyleSheet("color: green;")
                return

        # If no device is found
        self.status_msg.setText("Device not connected")
        self.status_msg.setStyleSheet("color: red;")

    def disconnect_device(self):
        # Set the logic here when actually connecting with the device
        # A condition to detect that the telemetry is on
        self.status_msg.setText("Telemetry is stopped")
        self.status_msg.setStyleSheet("color: red;")


    # Section: Program exit
    # ---------------------------------
    def exit(self):
        self.hide()
