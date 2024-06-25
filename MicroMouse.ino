#define TRIG_PIN 2
#define ECHO_PIN 3
#define LDR_PIN A0
#define MOTOR_LEFT_PWM 9
#define MOTOR_RIGHT_PWM 10
#define MOTOR_LEFT_DIR 7
#define MOTOR_RIGHT_DIR 8

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_LEFT_PWM, OUTPUT);
  pinMode(MOTOR_RIGHT_PWM, OUTPUT);
  pinMode(MOTOR_LEFT_DIR, OUTPUT);
  pinMode(MOTOR_RIGHT_DIR, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the LDR value
  int ldrValue = analogRead(LDR_PIN);
  
  // Measure distance using the ultrasonic sensor
  long distance = measureDistance();

  // Maze navigation logic
  if (distance < 20) {
    // If obstacle detected, stop and turn
    stopMotors();
    delay(500);
    turnRight();
    delay(1000);
  } else {
    // Move forward
    moveForward();
  }

  // Add more logic for LDR if needed
}

long measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  
  return distance;
}

void moveForward() {
  digitalWrite(MOTOR_LEFT_DIR, HIGH);
  digitalWrite(MOTOR_RIGHT_DIR, HIGH);
  analogWrite(MOTOR_LEFT_PWM, 200);
  analogWrite(MOTOR_RIGHT_PWM, 200);
}

void stopMotors() {
  analogWrite(MOTOR_LEFT_PWM, 0);
  analogWrite(MOTOR_RIGHT_PWM, 0);
}

void turnRight() {
  digitalWrite(MOTOR_LEFT_DIR, HIGH);
  digitalWrite(MOTOR_RIGHT_DIR, LOW);
  analogWrite(MOTOR_LEFT_PWM, 200);
  analogWrite(MOTOR_RIGHT_PWM, 200);
}

void turnLeft() {
  digitalWrite(MOTOR_LEFT_DIR, LOW);
  digitalWrite(MOTOR_RIGHT_DIR, HIGH);
  analogWrite(MOTOR_LEFT_PWM, 200);
  analogWrite(MOTOR_RIGHT_PWM, 200);
}
