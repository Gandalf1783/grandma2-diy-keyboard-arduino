# grandma2-diy-keyboard-arduino
grandMA2 onPC DIY-Keyboard.


This project lets you create an MidiRemote for grandMA2 onPC.

You need to connect 2 4x4 Matrix to an arduino.
Additionally you can add 3 LEDs to the following pins: 13, 12, 11. These represent different States of the device. Not needed, but can be added.
Also, you need to lookup the pins in the arduino.ino file

This Project was invented and tested with grandMA2 onPC 3.1.2.5, built on Arduino MEGA 2560 and it uses MIDI for Remote Control.
MIDI is sent via Serial.write method, which has advantages:
1. If your Arduino doesnt support "native" MIDI, you can use Hairless MIDI serial bridge. 
2. If it does, no need to worry. It can be set in the software.

A deeper explanation and how to use it, with the exact keymapping will be added later.

# What you need

First of all, an compatible Arduino. 

I chose the Arduino MEGA 2560 R3, but you can use any other, as long as it provides all the Input pins.
Also, you need cables (of course), 2 times a 4x4 Matrix. I buyed myself little buttons on an pcb for around 10€, but you can also create one yourself. I recommend keyswitches, like the cherry mx series.
Additionally, you need 3 different LEDs. I prefer a red one as an Error LED, a green for RUNNING, and a white or blue one the STATUS LED.

Optionally, you can add a led stripe. THIS FEATURE ISN'T IMPLEMENTED YET; BUT WILL IN A FUTURE UPDATE. This will light up the key switches, if you have those that can be illuminated. The Target is here a WS2812B LED-Strip

I added the grandMA2-MidiShowControl-Example so you can see and implement yourself the needed faders, e.g. if you want more.

# Disclaimer
grandMA, Arduino, MIDI and used Libraries are part of their respective Owners. This is not meant to copy the work, but instead use the work to create something new. If you are not okay with it, please contact me and i will take it down.
