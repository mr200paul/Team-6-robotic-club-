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
//int threshold = 500;

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

  // Start serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  int leftValue = digitalRead(leftSensor);
  int rightValue = digitalRead(rightSensor);

  // Print sensor values
  Serial.print("Left Sensor: ");
  Serial.print(leftValue);
  Serial.print(" Right Sensor: ");
  Serial.println(rightValue);

if (leftValue == 0 && rightValue == 0) {
    Serial.println("Moving Forward");
    forward();
  }
  // If only the left sensor detects a line, turn right
  else if (leftValue == 1 && rightValue == 0) {
    Serial.println("Turning Left");
    turnLeft();
    delay(200);
  }
  // If only the right sensor detects a line, turn left
  else if (rightValue == 1 && leftValue == 0) {
    Serial.println("Turning Right");
    turnRight();
    delay(200);
  }
  // If neither sensor detects a line, stop
  else {
    Serial.println("Stopping");
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
  analogWrite(enA, 175);
  analogWrite(enB, 175);
}
void turnLeft() {
  // Turn left
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to maximum
  analogWrite(enA, 255);
  analogWrite(enB, 255);
    
}

void turnRight() {
  // Turn right
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
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
