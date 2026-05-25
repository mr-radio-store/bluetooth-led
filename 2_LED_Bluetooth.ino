/*
Bluetooth control led simultanously 
UNO, 2 led, 2 resistor, and Serial Bluetooth Terminal

Wire Connection:
🔴 Red LED (Pin 3)
    Pin 8 → 220Ω resistor → long leg (anode, +) of red LED
    Short leg (cathode, -) → GND
🟢 Green LED (Pin 4)
    Pin 9 → 220Ω resistor → long leg of green LED
    Short leg → GND
    Note: If you connect the LED backward, it won't light up.

*/

#include <SoftwareSerial.h>

#define RED_LED    8  // Red LED controlled by 'Y'
#define GREEN_LED  9  // Green LED controlled by 'R'

SoftwareSerial btSerial(10, 11); // RX = D10, TX = D11 (Connect HC-05 TX to D11, RX to D10)

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(9600);
  btSerial.begin(9600); // HC-05 default baud rate

  Serial.println("Send 'Y' for RED LED (Pin 8), 'R' for GREEN LED (Pin 9)");
}

void loop() {
  if (btSerial.available()) {
    char command = btSerial.read();
    command = toupper(command); // Accept lowercase input too

    Serial.print("Received: ");
    Serial.println(command);

    // Control LEDs
    if (command == 'Y') {
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
      Serial.println("Red LED ON");
    } else if (command == 'R') {
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
      Serial.println("Green LED ON");
    } else {
      Serial.println("Invalid command. Use 'Y' or 'R'");
    }
  }
}
