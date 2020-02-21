#!/usr/bin/env python3
########################################################################
# Filename    : Doorbell.py
# Description : Make doorbell with buzzer and button
# Author      : www.freenove.com
# modification: 2019/12/27
########################################################################
from gpiozero import LED, Button
from signal import pause

print ('Program is starting...')

buzzer = LED(17)
button = Button(18)

def onButtonPressed():
    buzzer.on()
    print("Button is pressed, buzzer turned on >>>")
    
def onButtonReleased():
    buzzer.off()
    print("Button is released, buzzer turned off <<<")

button.when_pressed = onButtonPressed
button.when_released = onButtonReleased

pause()

