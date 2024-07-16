const int trigPin = 9;
const int echoPin = 10;
const int LED = 5;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  float distanceInMeters = distance / 100.0;
  digitalWrite(LED, LOW); // Ensure LED is off by default

  if (distanceInMeters < 6.50) {
    digitalWrite(LED, HIGH);
    Serial.print("LED ON: ");
  }

  Serial.print("Distance: ");
  Serial.print(distanceInMeters);
  Serial.println(" meters");

  if (distanceInMeters >= 1.50) {
    Serial.print("LED OFF: ");
  }

  delay(1000); // Delay to avoid flooding the Serial Monitor
}
