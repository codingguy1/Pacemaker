import sys
from PyQt6.QtCore import *
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *

class ApplicationWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        # Set the window title and dimensions
        self.setWindowTitle("Main Application Window")
        self.setFixedSize(QSize(800, 600))

        # Section: Central Stacked Widget (Click toolbar will lead current window to a different section)
        # ---------------------------------
        # Create a central stacked widget to hold different views 
        self.central_stack = QStackedWidget()
        self.setCentralWidget(self.central_stack)

        # Create individual widgets for each functionality
        self.parameters_widget = self.create_parameters_widget()
        self.pacing_modes_widget = self.create_pacing_modes_widget()
        self.egram_widget = self.create_egram_widget()

        # Add each widget to the central stacked widget
        self.central_stack.addWidget(self.parameters_widget)
        self.central_stack.addWidget(self.pacing_modes_widget)
        self.central_stack.addWidget(self.egram_widget)

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

    # Section: Parameters Widget
    # ---------------------------------
    def create_parameters_widget(self):
        # Create a widget for setting programmable parameters
        widget = QWidget()
        layout = QFormLayout()

        # Add input fields for parameters
        lower_rate_limit = QLineEdit()
        upper_rate_limit = QLineEdit()
        atrial_amplitude = QLineEdit()
        atrial_pulse_width = QLineEdit()
        ventricular_amplitude = QLineEdit()
        ventricular_pulse_width = QLineEdit()
        vrp = QLineEdit()
        arp = QLineEdit()

        # Add fields to the form layout
        layout.addRow("Lower Rate Limit:", lower_rate_limit)
        layout.addRow("Upper Rate Limit:", upper_rate_limit)
        layout.addRow("Atrial Amplitude:", atrial_amplitude)
        layout.addRow("Atrial Pulse Width:", atrial_pulse_width)
        layout.addRow("Ventricular Amplitude:", ventricular_amplitude)
        layout.addRow("Ventricular Pulse Width:", ventricular_pulse_width)
        layout.addRow("VRP:", vrp)
        layout.addRow("ARP:", arp)

        # Set layout to the widget
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

# Only for test purpose, later we will use the main_window to start the DCM by log in the systerm
# ---------------------------------
def main():
    app = QApplication(sys.argv)
    window = ApplicationWindow()
    window.show()
    sys.exit(app.exec())

if __name__ == "__main__":
    main()