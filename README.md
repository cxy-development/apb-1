# APB 1 MIDI Guitar pedalboard

APB 1 is an Arduino-based MIDI guitar pedalboard.
It is written for **Arduino UNO** or **Arduino Nano** and currently supports **4 footswitches**.
It can send **CC messages** ranging from 20 to 23 through a **MIDI cable** or by using **Serial communication**.

## Setting up the Arduino
1. Clone this repository.
2. Open the `apb1.ino` file in Arduino IDE.
3. Directly upload `apb.ino` on your Arduino. You won't need any external library.

## Setting up the hardware
Connect the footswitches and the LEDs as specified in the included schematics file (`apb1-schematics.pdf`).

### Using a MIDI cable
Connect your MIDI cable's pins as specified in the included schematics file (`apb1-schematics.pdf`) or by referring to the following pinout:
- cable's pin 5 to D1/TX pin
- cable's pin 4 to +5V pin
- cable's pin 2 to GND
After setting it up as said above, the APB 1 is ready to be connected to any MIDI interface.

### Using Serial communication
To use Serial communication two softwares are needed to be installed on the used computer.
