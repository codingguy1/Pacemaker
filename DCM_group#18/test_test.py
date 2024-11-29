import serial
import struct

header_byte_1 = 0x16
header_byte_2 = 0x55 #PACEMAKER recive is 55    PACEMAKER send is 22
mode = 1

# < little-endian,
# B 8-bit unsigned int
# f float (4 bytes)
# H 16-bit unsigned int
struct_format = '<3B11fH4f'

# Pack the data into a binary format


data = struct.pack(struct_format,header_byte_1,header_byte_2, mode, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

try:
    with serial.Serial(port="COM9", baudrate=115200, timeout=1) as pacemaker:
        # Write
        pacemaker.write(data)
        print(f"Data sent: header_byte_1={header_byte_1}, header_byte_2={header_byte_2}, "
              f"mode={mode}")

        

except serial.SerialException as e:
    print(f"Error opening or using COM9: {e}")