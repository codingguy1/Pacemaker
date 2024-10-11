from PyQt6.QtCore import *
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *

class ApplicationWindow(QWidget):
    def __init__(self):
        super().__init__()

        # Set the window title and dimensions
        self.setWindowTitle("Main Application Window")
        self.setFixedSize(QSize(800, 600))

        # Create a layout and a welcome label
        layout = QVBoxLayout()
        welcome_label = QLabel("Welcome to the main application!")
        welcome_label.setFont(QFont('Arial', 16))
        layout.addWidget(welcome_label, alignment=Qt.AlignmentFlag.AlignCenter)

        # Set the layout
        self.setLayout(layout)
