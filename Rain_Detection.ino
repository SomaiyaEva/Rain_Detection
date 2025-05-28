#include <Servo.h>

Servo clothServo;

const int rainSensorPin = 2;   // Digital pin connected to rain sensor DO
const int servoPin = 9;        // Servo signal pin

bool isRaining = false;

void setup() {
  pinMode(rainSensorPin, INPUT);
  clothServo.attach(servoPin);
  clothServo.write(0);  // Initial servo position
  Serial.begin(9600);
}

void loop() {
  int rainState = digitalRead(rainSensorPin);

  if (rainState == LOW) {  // Rain detected
    if (!isRaining) {
      Serial.println("Rain detected!");
      clothServo.write(90);       // Rotate servo (adjust angle if needed)
      isRaining = true;
    }
  } else {
    if (isRaining) {
      Serial.println("Dry again.");
      clothServo.write(0);         // Return to original position
      isRaining = false;
    }
  }

  delay(500);  // Delay for stability
}
