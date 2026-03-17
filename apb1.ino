/*
  APB 1
  by cxydev, 2026

  DESCRIPTION
  APB 1 is a MIDI guitar pedalboard, written for Arduino UNO or Arduino Nano.
  It supports 4 SPST momentary footswitches, each one sending CC messages ranging from 20 to 23.
  The signal can be sent to a computer through a MIDI cable or by using serial communication. 

  CHANGE LOG
  : 2026-03-15 : Program writing ended : cxydev :
  : 2026-03-16 : Implemented LEDs      : cxydev :
*/

const uint8_t cc = 0xb0; // CC message byte
// Maximum and minimum values the CC message can have
#define CC_ON  127
#define CC_OFF 0

typedef struct Footswitch
{
  uint8_t pin; // Pin the footswitch is connected to
  uint8_t led_pin; // Pin the associated LED is connected to
  uint8_t state; // State of the footswitch (on/off, i.e. LOW/HIGH)
  uint8_t prev_state; // Previous state of the footswitch
  uint8_t contr; // Control byte
  uint8_t val; // Value byte (0 = off, 127 = on)
};

// Footswitches connected to the Arduino
#define FOOTSWITCHES_NUM 4
Footswitch footswitches[FOOTSWITCHES_NUM] = {
  { 2, 6, HIGH, HIGH, 20, CC_OFF },
  { 3, 7, HIGH, HIGH, 21, CC_OFF },
  { 4, 8, HIGH, HIGH, 22, CC_OFF },
  { 5, 9, HIGH, HIGH, 23, CC_OFF }
};

void setup() {
  for (uint8_t i = 0; i < FOOTSWITCHES_NUM; i++) {
    pinMode(footswitches[i].pin, INPUT_PULLUP);
    pinMode(footswitches[i].led_pin, OUTPUT);
  }
  Serial.begin(115200); // 115200 baud rate serial communication
}

void loop() {
  for (uint8_t i = 0; i < FOOTSWITCHES_NUM; i++) { // Loop through every connected footswitch
    footswitches[i].state = digitalRead(footswitches[i].pin); // Read the state of the current footswitch
    if (footswitches[i].state != footswitches[i].prev_state && footswitches[i].state == LOW) { // If the current footswitch is pressed:
      // Invert the value (on/off, 127/0)
      footswitches[i].val = (footswitches[i].val == 127) ? 0 : 127;
      
      // Write CC command
      Serial.write(cc);
      Serial.write(footswitches[i].contr);
      Serial.write(footswitches[i].val);

      // Turn on or off the associated LED basing on the current footswitch's state
      digitalWrite(footswitches[i].led_pin, (footswitches[i].val > 0) ? CC_ON : CC_OFF);

      // Wait until the current footswitch is released
      while (digitalRead(footswitches[i].pin) == LOW);
    }
    footswitches[i].prev_state = footswitches[i].state; // Save the current footswitch's state
  }
}