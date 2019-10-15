import serial
from time import sleep
import sys


DEV = '/dev/ttyUSB0'
BAUD = 9600

ser = serial.Serial(DEV, BAUD, timeout=0.5)

print(f'Waiting for device {ser.name}');

while True:
    line = str(ser.readline().decode())
    print(line, end="", flush=True)
