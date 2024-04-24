import serial
import time

ser = serial.Serial('COM3', 9600)  
while True:
    try:
        line = ser.readline().decode().strip()
        null_checker = line.split()
        if null_checker[1] == '-127.00':
            print(f"null: {null_checker}")
            pass
        else:
            if line:
                f = open('output.txt', 'w')
                f.write(line + '\n')
                print(line)
                f.close()
                time.sleep(1)
            else:
                time.sleep(1)
    except Exception as e:
        print(e)
