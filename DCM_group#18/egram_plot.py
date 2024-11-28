import sys
import numpy as np
import serial
import struct
import time
from PyQt6.QtCore import QTimer
from PyQt6.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QPushButton, QWidget, QMessageBox
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure

class EgramPlot(QMainWindow):
    def __init__(self, port):
        super().__init__()
        self.port = port
        self.aData = np.array([])
        self.vData = np.array([])
        self.tData = np.array([])
        self.cont = True
        self.vS = True
        self.aS = True
        self.start_time = time.time()

        # Set up window
        self.setWindowTitle('Egram')
        self.setGeometry(100, 100, 800, 600)

        # Set up central widget and layout
        self.central_widget = QWidget(self)
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        # Set up figure and canvas
        self.fig = Figure(figsize=(7, 7), dpi=100)
        self.plotA = self.fig.add_subplot(211)
        self.plotV = self.fig.add_subplot(212)
        self.fig.subplots_adjust(hspace=0.8)
        self.plotA.set_title('Atrium Signals', fontsize=12)
        self.plotV.set_title('Ventricle Signals', fontsize=12)
        self.plotA.set_xlabel("Time (sec)", fontsize=10)
        self.plotA.set_ylabel("Voltage (V)", fontsize=10)
        self.plotV.set_xlabel("Time (sec)", fontsize=10)
        self.plotV.set_ylabel("Voltage (V)", fontsize=10)
        self.plotA.set_ylim(-6, 6)
        self.plotA.set_xlim(0, 16)
        self.linesA = self.plotA.plot([], [])[0]
        self.plotV.set_ylim(-6, 6)
        self.plotV.set_xlim(0, 16)
        self.linesV = self.plotV.plot([], [])[0]

        # Add canvas to layout
        self.canvas = FigureCanvas(self.fig)
        self.layout.addWidget(self.canvas)

        # Add control buttons
        self.a_button = QPushButton('Atrium', self)
        self.a_button.clicked.connect(self.toggle_atrium_plot)
        self.layout.addWidget(self.a_button)

        self.v_button = QPushButton('Ventricle', self)
        self.v_button.clicked.connect(self.toggle_ventricle_plot)
        self.layout.addWidget(self.v_button)

        self.start_stop_button = QPushButton('Start/Stop', self)
        self.start_stop_button.clicked.connect(self.toggle_plot)
        self.layout.addWidget(self.start_stop_button)

        # Start plotting
        self.plot()

    def plot(self):
        if self.cont:
            try:
                with serial.Serial(port=self.port, baudrate=115200, timeout=1) as ser:
                    # Request data from the pacemaker
                    ser.write(struct.pack('<2B', 0x16, 0x22))
                    serial_data = ser.read(66)
                    if len(serial_data) != 66:
                        raise serial.SerialException("Incomplete data received.")
            except (serial.SerialException, FileNotFoundError):
                QMessageBox.warning(self, "Error", "Pacemaker not connected")
                self.close()
                return

            # Process received data
            try:
                # Unpack the response values based on the expected format from the ApplicationWindow class
                modeV = struct.unpack('B', serial_data[0:1])[0]
                a_signal = -6.6 * (struct.unpack('<f', serial_data[4:7])[0] - 0.5)
                v_signal = -6.6 * (struct.unpack('<f', serial_data[8:11])[0] - 0.5)
            except struct.error:
                QMessageBox.warning(self, "Error", "Error unpacking data")
                return

            # Update data arrays
            if len(self.aData) < 300:
                self.aData = np.append(self.aData, a_signal)
                self.vData = np.append(self.vData, v_signal)
                self.tData = np.append(self.tData, time.time() - self.start_time)
            else:
                self.aData[:-1] = self.aData[1:]
                self.vData[:-1] = self.vData[1:]
                self.tData[:-1] = self.tData[1:]
                self.aData[-1] = a_signal
                self.vData[-1] = v_signal
                self.tData[-1] = time.time() - self.start_time
                self.plotA.set_xlim(self.tData[0], self.tData[-1])
                self.plotV.set_xlim(self.tData[0], self.tData[-1])

            # Update plot lines
            self.linesA.set_data(self.tData, self.aData)
            self.linesV.set_data(self.tData, self.vData)
            self.canvas.draw()

        QTimer.singleShot(5, self.plot)

    def toggle_atrium_plot(self):
        self.aS = not self.aS
        self.plotA.set_visible(self.aS)
        self.canvas.draw()

    def toggle_ventricle_plot(self):
        self.vS = not self.vS
        self.plotV.set_visible(self.vS)
        self.canvas.draw()

    def toggle_plot(self):
        self.cont = not self.cont
        if self.cont:
            self.start_time = time.time() - self.tData[-1] if len(self.tData) > 0 else time.time()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    egram = EgramPlot(port="COM6")  # Example port
    egram.show()
    sys.exit(app.exec())
