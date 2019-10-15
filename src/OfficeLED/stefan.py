import serial
from time import sleep
import sys


DEV = '/dev/ttyUSB0'
BAUD = 9600

ser = serial.Serial(DEV, BAUD, timeout=0.1)
sleep(0.1)

def stefan(prefix="is in", line1="", line2=""):
    """
    Sent to LCD:

    Stefan {prefix}
    {line1}
    {line2}
    📱 510-701-4153
    """
    if len(prefix) > 13:
        raise ValueError("prefix too long")

    if (len(line1) > 20) or (len(line2) > 20):
        raise ValueError("line1/line2 limited to 20 chars")

    ser.write(f'{prefix}||{line1}||{line2}||\n'.encode())

stefan(*sys.argv[1:])
