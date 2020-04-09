# grandma2-diy-keyboard-arduino
GrandMA2 onPC DIY-Keyboard.


This project lets you create an MidiRemote for grandMA2 onPC.

You need to connect 2 4x4 Matrix to an arduino MEGA 2560. 
Also, you need to lookup the pins in the arduino.ino file

This Project was invented and tested with grandMA2 onPC 3.1.2.5, built on Arduino MEGA 2560 and it uses MIDI for Remote Control.
MIDI is sent via Serial.write method, which has advantages:
1. If your Arduino doesnt support "native" MIDI, you can use Hairless MIDI serial bridge. 
2. If it does, no need to worry. It can be set in the software.
