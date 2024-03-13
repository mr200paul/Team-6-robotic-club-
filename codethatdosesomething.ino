//this code it stop on white moves on black
int enA = 10;
int in1 = 9;
int in2 = 8;
int enB = 5;
int in3 = 7;
int in4 = 6;

// Sensor pins
int leftSensor = A0;
int rightSensor = A1;

// Threshold for detecting the line
int threshold = 500;

void setup() {
  // Set motor pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Set sensor pins as inputs
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
}

void loop() {
  int leftValue = analogRead(leftSensor);
  int rightValue = analogRead(rightSensor);

  // If both sensors detect the line, move forward
  if (leftValue < threshold && rightValue < threshold) {
    forward();
  }
  // If only the left sensor detects the line, turn right
  else if (leftValue < threshold) {
    turnRight();
  }
  // If only the right sensor detects the line, turn left
  else if (rightValue < threshold) {
    turnLeft();
  }
  // If neither sensor detects the line, stop
  else {
    stop();
  }
}

void forward() {
  // Turn on motors forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Set speed to maximum
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void turnLeft() {
  // Turn left
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to maximum
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void turnRight() {
  // Turn right
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Set speed to maximum
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void stop() {
  // Stop motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Stop motor speed
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
int enA = 10;
int in1 = 9;
int in2 = 8;
int enB = 5;
int in3 = 7;
int in4 = 6;

// Sensor pins
int leftSensor = A0;
int rightSensor = A1;

// Threshold for detecting the line
int threshold = 500;

void setup() {
  // Set motor pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Set sensor pins as inputs
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
}

void loop() {
  int leftValue = analogRead(leftSensor);
  int rightValue = analogRead(rightSensor);

  // If both sensors detect the line, move forward
  if (leftValue < threshold && rightValue < threshold) {
    forward();
  }
  // If only the left sensor detects the line, turn right
  else if (leftValue < threshold) {
    turnRight();
  }
  // If only the right sensor detects the line, turn left
  else if (rightValue < threshold) {
    turnLeft();
  }
  // If neither sensor detects the line, stop
  else {
    stop();
  }
}

void forward() {
  // Turn on motors forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Set speed to maximum
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void turnLeft() {
  // Turn left
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to maximum
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void turnRight() {
  // Turn right
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Set speed to maximum
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void stop() {
  // Stop motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Stop motor speed
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
