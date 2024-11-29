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
    def __init__(self, port=None):
        super().__init__()
        self.port = port  # Connected serial port 
        self.aData = np.array([])  # Data for atrium signals
        self.vData = np.array([])  # Data for ventricle signals
        self.tData = np.array([])  # Time data
        self.cont = True  # Continue plotting 
        self.vS = True  # Visibility of ventricle signals
        self.aS = True  # Visibility of atrium signals
        self.start_time = time.time()

        # Set up the window
        self.setWindowTitle('Egram')
        self.setGeometry(100, 100, 800, 600)

        # Set up the central widget and layout
        self.central_widget = QWidget(self)
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        # Set up the plot
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

        # Add plot layout
        self.canvas = FigureCanvas(self.fig)
        self.layout.addWidget(self.canvas)

        # Button for start atrium graph 
        self.a_button = QPushButton('Atrium', self)
        self.a_button.clicked.connect(self.toggle_atrium_plot)
        self.layout.addWidget(self.a_button)
        # Button for start ventricle graph 
        self.v_button = QPushButton('Ventricle', self)
        self.v_button.clicked.connect(self.toggle_ventricle_plot)
        self.layout.addWidget(self.v_button)
        # Button for start and stop data transmitting
        self.start_stop_button = QPushButton('Start/Stop', self)
        self.start_stop_button.clicked.connect(self.toggle_plot)
        self.layout.addWidget(self.start_stop_button)

        # Start plotting
        self.plot()

    def plot(self):
        if self.cont:
            try:
                if self.port:
                    # Recived data from pacemaker
                    with serial.Serial(port=self.port, baudrate=115200, timeout=1) as ser:
                        ser.write(struct.pack('<2B', 0x16, 0x22))  # Request data
                        serial_data = ser.read(71)
                        if len(serial_data) != 71:
                            raise serial.SerialException("Incomplete data received.")
                    
                    # Process received data
                    a_signal = -6.6 * (struct.unpack('<f', serial_data[4:8])[0] - 0.5)
                    v_signal = -6.6 * (struct.unpack('<f', serial_data[8:12])[0] - 0.5)
                else:
                    # Generate random data if no pacemaker is connected
                    a_signal = np.random.uniform(-5, 5)
                    v_signal = np.random.uniform(-5, 5)

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

            except (serial.SerialException, struct.error) as e:
                QMessageBox.warning(self, "Error", f"Error: {str(e)}. Switching to random data.")
                self.port = None  # Fallback to random data

        QTimer.singleShot(50, self.plot)  # Refresh every 50ms

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

# Only for test the egram functionalities
if __name__ == '__main__':
    app = QApplication(sys.argv)
    egram = EgramPlot(port="COM6")  # Example port for testing
    egram.show()
    sys.exit(app.exec())
