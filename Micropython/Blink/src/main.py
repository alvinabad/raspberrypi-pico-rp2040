import time
import machine

DELAY_ON = 0.2
DELAY_OFF = 0.1

def blink(pin):
    p = machine.Pin(pin, machine.Pin.OUT)

    while True:
        p.on()
        time.sleep(DELAY_ON)
        p.off()
        time.sleep(DELAY_OFF)

if __name__ == '__main__':
    print("Blink RP2040 at pin 25 with delay = %f secs" % DELAY_ON)
    blink(25)
