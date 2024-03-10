#define leftMotor1 2
#define leftMotor2 3
#define rightMotor1 4
#define rightMotor2 5

// Define pins for line sensors
#define leftLineSensor A0
#define rightLineSensor A1

void setup() {
  // Set motor control pins as output
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);

  // Set line sensor pins as input
  pinMode(leftLineSensor, INPUT);
  pinMode(rightLineSensor, INPUT);
}

void loop() {
  int leftSensorValue = analogRead(leftLineSensor);
  int rightSensorValue = analogRead(rightLineSensor);

  // Adjust these values according to the sensitivity of your sensors
  int threshold = 500;

  // If both sensors detect the black line, move forward
  if (leftSensorValue < threshold && rightSensorValue < threshold) {
    moveForward();
  }
  // If only left sensor detects the black line, turn right
  else if (leftSensorValue < threshold && rightSensorValue >= threshold) {
    turnRight();
  }
  // If only right sensor detects the black line, turn left
  else if (leftSensorValue >= threshold && rightSensorValue < threshold) {
    turnLeft();
  }
  // If no sensor detects the black line, stop
  else {
    stopMoving();
  }
}

void moveForward() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}
void turnLeft() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void turnRight() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
}

void stopMoving() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
}
