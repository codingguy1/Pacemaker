import serial
import struct
from ParameterManager import ParameterManager

# Initialize ParameterManager and set parameters to test values
parameter_manager = ParameterManager()
parameter_manager.setLowerRateLimit(60)
parameter_manager.setUpperRateLimit(120)
parameter_manager.setMaximumSensorRate(120)
parameter_manager.setAtrialAmplitude(3.5)
parameter_manager.setVentricularAmplitude(3.0)
parameter_manager.setAtrialPulseWidth(2)
parameter_manager.setVentricularPulseWidth(2)
parameter_manager.setAtrialSensitivity(0.75)
parameter_manager.setVentricularSensitivity(0.75)
parameter_manager.setARP(250)
parameter_manager.setVRP(320)
parameter_manager.setPVARP(250)
parameter_manager.setActivityThreshold(1.6)
parameter_manager.setReactionTime(30.0)
parameter_manager.setResponseFactor(8)
parameter_manager.setRecoveryTime(5)  # 5 minutes

# Define the header and structure format for sending data
header_format = '<2B'
data_format = '<4B10f3H'

# Prepare values for the header and parameters
header_byte_1 = 0x16
header_byte_2 = 0x55

# Pack the header
header = struct.pack(header_format, header_byte_1, header_byte_2)

# Get the user parameters from ParameterManager
mode = 1  # Assuming mode 1 for testing
lrl = parameter_manager.getLowerRateLimit()
url = parameter_manager.getUpperRateLimit()
msr = parameter_manager.getMaximumSensorRate()
aa = parameter_manager.getAtrialAmplitude()
va = parameter_manager.getVentricularAmplitude()
apw = parameter_manager.getAtrialPulseWidth()
vpw = parameter_manager.getVentricularPulseWidth()
asens = parameter_manager.getAtrialSensitivity()
vsens = parameter_manager.getVentricularSensitivity()
arp = parameter_manager.getARP()
vrp = parameter_manager.getVRP()
pvarp = parameter_manager.getPVARP()
act_thresh = float(parameter_manager.getActivityThreshold())
react_time = float(parameter_manager.getReactionTime())()
response_factor = parameter_manager.getResponseFactor()
recovery_time = float(parameter_manager.getRecoveryTime())()

# Pack the data 4B8fHf3H
data = struct.pack(data_format, mode, lrl, url, msr, aa, va, apw, vpw, asens, vsens, arp, vrp, pvarp, act_thresh, float(react_time), response_factor, float(recovery_time))

# Combine header and data
full_packet = header + data

try:
    with serial.Serial(port="COM5", baudrate=115200, timeout=1) as pacemaker:
        # Write the packet to the pacemaker
        pacemaker.write(full_packet)
        print(f"Data sent: Mode={mode}, Lower Rate Limit={lrl}, Upper Rate Limit={url}, Maximum Sensor Rate={msr},"
              f" Atrial Amplitude={aa}, Ventricular Amplitude={va}, Atrial Pulse Width={apw}, Ventricular Pulse Width={vpw},"
              f" Atrial Sensitivity={asens}, Ventricular Sensitivity={vsens}, ARP={arp}, VRP={vrp}, PVARP={pvarp},"
              f" Activity Threshold={act_thresh}, Reaction Time={react_time}, Response Factor={response_factor}, Recovery Time={recovery_time}")

        # Read the response from the pacemaker
        expected_data_length = struct.calcsize(data_format) + 2  # Include header length
        received_data = pacemaker.read(expected_data_length)

        # Unpack the response
        if len(received_data) == expected_data_length:
            response_header = struct.unpack(header_format, received_data[:2])
            if response_header != (0x16, 0x22):
                print("Invalid header received.")
            else:
                unpacked_data = struct.unpack(data_format, received_data[2:])
                (modeV, lrlV, urlV, msrV, aaV, vaV, apwV, vpwV, asensV, vsensV, arpV, vrpV, pvarpV, act_threshV, react_timeV, response_factorV, recovery_timeV) = unpacked_data
                print(f"Data received: Mode={modeV}, Lower Rate Limit={lrlV}, Upper Rate Limit={urlV}, Maximum Sensor Rate={msrV},"
                      f" Atrial Amplitude={aaV}, Ventricular Amplitude={vaV}, Atrial Pulse Width={apwV}, Ventricular Pulse Width={vpwV},"
                      f" Atrial Sensitivity={asensV}, Ventricular Sensitivity={vsensV}, ARP={arpV}, VRP={vrpV}, PVARP={pvarpV},"
                      f" Activity Threshold={act_threshV}, Reaction Time={react_timeV}, Response Factor={response_factorV}, Recovery Time={recovery_timeV}")
        else:
            print("Received data is incomplete or incorrect length.")

except serial.SerialException as e:
    print(f"Error opening or using COM5: {e}")
