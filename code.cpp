// Define motor control pins
const int motor1Pin1 = 2;
const int motor1Pin2 = 3;
const int motor2Pin1 = 4;
const int motor2Pin2 = 5;
const int enable1Pin = 6;
const int enable2Pin = 7;

// Define ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;

// Define variables for ultrasonic sensor
long duration;
int distance;

void setup() {
  // Set motor control pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start serial communication
  Serial.begin(9600);

  // Set motor speed
  analogWrite(enable1Pin, 255); // Max speed
  analogWrite(enable2Pin, 255); // Max speed
}

void loop() {
  // Measure distance using ultrasonic sensor
  distance = getDistance();

  // Display distance on serial monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 20) {  // If obstacle is detected within 20 cm
    stopCar();          // Stop the car
    delay(1000);
    turnRight();        // Turn the car to avoid obstacle
    delay(1000);
  } else {
    moveForward();      // Move forward if no obstacle
  }
  delay(100);
}

void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void stopCar() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void turnRight() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

// Function to measure distance using the ultrasonic sensor
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Convert to cm
  return distance;
}
