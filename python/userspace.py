#!/usr/bin/env python3
import serial
import os
import select
import time

DEV = "/dev/arduino_buzzer"   # Device criado pelo kernel module
ARDUINO_PORT = "/dev/ttyACM0" # Ajuste conforme seu Arduino
BAUD = 9600

# Abre porta serial do Arduino
ser = serial.Serial(ARDUINO_PORT, BAUD, timeout=1)
time.sleep(2)  # Espera Arduino resetar

# Abre device do kernel em modo não-bloqueante
fd = os.open(DEV, os.O_RDONLY | os.O_NONBLOCK)

print("Forwarder iniciado: /dev/arduino_buzzer -> Arduino")

try:
    while True:
        r, _, _ = select.select([fd], [], [], 1.0)
        if fd in r:
            data = os.read(fd, 128)
            if data:
                # Envia cada byte individualmente
                for b in data:
                    ser.write(bytes([b]))
except KeyboardInterrupt:
    print("Saindo...")
finally:
    os.close(fd)
    ser.close()
