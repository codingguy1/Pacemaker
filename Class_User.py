import sys
from PyQt6.QtCore import *
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *

# Subclass QMainWindow to customize application's main window
class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        # Set the window title
        self.setWindowTitle("Peacemaker Control System")

        # Set the dimensions of the main window
        self.setFixedSize(QSize(800, 600))

        # Load images and set size
        mac_img = QPixmap("mac.png").scaled(600, 200, Qt.AspectRatioMode.KeepAspectRatio, Qt.TransformationMode.SmoothTransformation)
        fireball_img = QPixmap("fireball.png").scaled(100, 100, Qt.AspectRatioMode.KeepAspectRatio, Qt.TransformationMode.SmoothTransformation)

        # Create QLabel for welcome msg
        msg = QLabel('Hello, Welcom to Peacemaker Control System')
        msg.setFont(QFont('Arial', 14)) 

        # Create QLabel widgets to display the images
        mac_label = QLabel()
        mac_label.setPixmap(mac_img if not mac_img.isNull() else QPixmap()) 

        fireball_label = QLabel()
        fireball_label.setPixmap(fireball_img if not fireball_img.isNull() else QPixmap()) 

        # Create user registration, login, and delete existing user input line
        username_input = QLineEdit() 
        username_input.setFixedSize(400, 40)
        username_input.setPlaceholderText("Enter your username")

        password_input = QLineEdit()
        password_input.setFixedSize(400, 40)
        password_input.setPlaceholderText("Enter your password")

        # Create buttons for registration, login, and deleting users
        register_button = QPushButton("Register")
        register_button.setFixedSize(100,40)
        login_button = QPushButton("Log In")
        login_button.setFixedSize(100,40)
        delete_button = QPushButton("Delete User")
        delete_button.setFixedSize(100,40)

        # Create a layout and add the widgets
        main_layout = QVBoxLayout() # Vertical layout

        # Create a top and horizontal layout to hold image
        img_layout = QHBoxLayout() 
        img_layout.addWidget(mac_label, alignment=Qt.AlignmentFlag.AlignLeft)
        img_layout.addWidget(fireball_label, alignment=Qt.AlignmentFlag.AlignRight)

        # Create a horizontal layout for the buttons
        button_layout = QHBoxLayout()
        button_layout.addWidget(register_button, alignment=Qt.AlignmentFlag.AlignRight | Qt.AlignmentFlag.AlignTop)
        button_layout.addWidget(login_button, alignment=Qt.AlignmentFlag.AlignVCenter | Qt.AlignmentFlag.AlignTop)
        button_layout.addWidget(delete_button, alignment=Qt.AlignmentFlag.AlignLeft | Qt.AlignmentFlag.AlignTop)


        # Arrange layout vertical order and combine them together
        main_layout.addLayout(img_layout)
        main_layout.addWidget(msg, alignment=Qt.AlignmentFlag.AlignHCenter | Qt.AlignmentFlag.AlignBottom)
        main_layout.addWidget(username_input, alignment=Qt.AlignmentFlag.AlignHCenter | Qt.AlignmentFlag.AlignBottom)
        main_layout.addWidget(password_input, alignment=Qt.AlignmentFlag.AlignHCenter | Qt.AlignmentFlag.AlignTop)
        main_layout.addLayout(button_layout)

        # Set the layout for the central widget
        central_widget = QWidget()
        central_widget.setLayout(main_layout)
        self.setCentralWidget(central_widget)

        


# Create an instance of QApplication
app = QApplication(sys.argv)
window = MainWindow()
window.show()  # Show the main window

# Start the application's event loop
app.exec()