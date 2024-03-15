// Motor pins
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

// Proportional control constants
float kp = 0.5;  // Proportional gain

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
  // Read sensor values
  int leftValue = analogRead(leftSensor);
  int rightValue = analogRead(rightSensor);

  // Calculate error (difference between sensor readings)
  int error = rightValue - leftValue;

  // Adjust motor speeds based on error
  int leftSpeed = 255;
  int rightSpeed = 255;

  // Apply proportional control
  leftSpeed -= kp * error;
  rightSpeed += kp * error;

  // Ensure motor speeds are within valid range
  leftSpeed = constrain(leftSpeed, 0, 255);
  rightSpeed = constrain(rightSpeed, 0, 255);

  // Check if any sensor detects the line
  if (leftValue < threshold || rightValue < threshold) {
    // Move forward with adjusted speeds
    forward(leftSpeed, rightSpeed);
  } else {
    // Stop if no line detected
    stop();
    return; // Exit loop immediately after stopping
  }
}

void forward(int leftSpeed, int rightSpeed) {
  // Turn on motors forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Set motor speeds
  analogWrite(enA, leftSpeed);
  analogWrite(enB, rightSpeed);
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
