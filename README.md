# APB 1 MIDI Guitar pedalboard

APB 1 is an **Arduino-based MIDI guitar pedalboard**, that works as a DIY, cheaper alternative to more expensive pedalboards for controlling VSTs and pedals.
It is written for **Arduino UNO** or **Arduino Nano** and currently supports **4 footswitches**.
It can send **CC messages** ranging from 20 to 23 through a **MIDI cable** or by using **Serial communication**.

## Bill of materials
- 1x Arduino UNO/Arduino Nano
- 4x momentary SPST footswitches
- 4x status LEDs
- 1x MIDI cable (optional)
- 4x (6x if using a MIDI cable) 220Ω resistors

## Setting up the Arduino
1. Clone this repository.
2. Open the `apb1.ino` file in Arduino IDE.
3. Directly upload `apb.ino` on your Arduino. You won't need any external library.

## Setting up the hardware
Connect the footswitches and the LEDs as specified in the included schematics file (`apb1-schematics.pdf`).

### Using a MIDI cable
Connect your MIDI cable's pins as specified in the included schematics file (`apb1-schematics.pdf`) or by referring to the following pinout:
- cable's pin 5 to D1/TX pin
- cable's pin 4 to +5V pin through a 220Ω resistor
- cable's pin 2 to GND through a 220Ω resistor

Lastly, make sure the baud rate of the Serial communication is set to 31250 in the `Serial.begin()` line inside of `main.ino`.
After setting it up as said above, the APB 1 is ready to be connected to any MIDI interface.

### Using Serial communication
To use Serial communication, follow these steps:
- Install loopMIDI (https://www.tobias-erichsen.de/software/loopmidi.html)
- Create a virtual MIDI port using loopMIDI
- Download Hairless MIDI (https://projectgus.github.io/hairless-midiserial/?source=post_page---------------------------)
- Run Hairless MIDI and select the used Arduino in the Serial port dropdown and the just created MIDI virtual port in the MIDI Out dropdown

## Table of CC messages sent by the footswitches
SW1 CC20
SW2 CC21
SW3 CC22
SW4 CC23

Lastly, make sure the baud rate of the Serial communication is set to 115200 in the `Serial.begin()` line inside of `main.ino`. Double-check the Hairless MIDI Serial communication baud rate settings too.
After setting it up as said above, the ABP 1 is ready to be used.
