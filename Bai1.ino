const int trigPin = 12; // Trigger pin of ultrasonic sensor
const int echoPin = 13; // Echo pin of ultrasonic sensor

const int ledPins[] = {4, 5, 6, 7, 8}; // Pins for LEDs
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize LED pins
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  long distance = duration * 0.034 / 2;

  // Display distance on Serial Monitor (for debugging)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Display LEDs based on distance
  if (distance < 5 || distance > 400) { // Out of range
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], HIGH); // Turn on all LEDs
    }
  } else {
    int numLedsToDisplay = map(distance, 5, 400, 0, numLeds);
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], i < numLedsToDisplay ? HIGH : LOW);
    }
  }

  delay(50); 
}
