// Define the PIR sensor pin
const int PIRSensorPin = 2; // Connect the sensor's OUT pin to Digital pin 2

// Variable to hold the sensor status
int sensorStatus = LOW; // Assume no motion detected initially

void setup() {
  // Initialize Serial Communication
  Serial.begin(9600);
  // Initialize the PIR sensor pin as an input
  pinMode(PIRSensorPin, INPUT);

  Serial.println("Sensor warming up, please wait...");
  delay(2000); // Give time for sensor to stabilize, usually 1-2 minutes is recommended for real applications
  Serial.println("Ready to detect motion!");
}

void loop() {
  // Read the value from the PIR sensor
  sensorStatus = digitalRead(PIRSensorPin);

  // Check if the sensor status has changed
  if (sensorStatus == HIGH) {
    // Motion detected
    Serial.println("Motion detected!");
    // Additional actions can be added here (e.g., turn on a light, send a notification, etc.)
  } else {
    // No motion detected
    Serial.println("No motion detected.");
    // Here you can add actions to take when no motion is detected
  }

  // Wait for a short period before reading again to avoid flooding the serial output
  delay(1000);
}
