#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

const int lockPin = 5;  // GPIO connected to transistor base

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Lock"); // Bluetooth name
  pinMode(lockPin, OUTPUT);
  digitalWrite(lockPin, LOW); // Initially locked
}

void loop() {
  if (SerialBT.available()) {
    char received = SerialBT.read();
    if (received == '1') {
      digitalWrite(lockPin, HIGH);  // Unlock
      delay(5000);                  // Keep unlocked 5 sec
      digitalWrite(lockPin, LOW);   // Lock again
    }
  }
}
