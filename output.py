import serial
import time

ser = serial.Serial('COM3', 9600)  
while True:
    try:
        f = open('output.txt', 'w')
        line = ser.readline().decode().strip()
        f.write(line + '\n')
        print(line)
        f.close()
        time.sleep(1)
    except Exception as e:
        print(e)