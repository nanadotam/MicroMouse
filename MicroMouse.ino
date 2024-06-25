#define TRIG_PIN 2
#define ECHO_PIN 3
#define LDR_PIN A0
#define MOTOR_LEFT_PWM 9  // EN_A
#define MOTOR_RIGHT_PWM 10  // EN_B
#define MOTOR_LEFT_DIR_1 7  // IN1
#define MOTOR_LEFT_DIR_2 8  // IN2
#define MOTOR_RIGHT_DIR_1 12  // IN3
#define MOTOR_RIGHT_DIR_2 13  // IN4


void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_LEFT_PWM, OUTPUT);
  pinMode(MOTOR_RIGHT_PWM, OUTPUT);
  pinMode(MOTOR_LEFT_DIR_1, OUTPUT);
  pinMode(MOTOR_LEFT_DIR_2, OUTPUT);
  pinMode(MOTOR_RIGHT_DIR_1, OUTPUT);
  pinMode(MOTOR_RIGHT_DIR_2, OUTPUT);
  Serial.begin(9600);
}

#define TRIG_PIN 2
#define ECHO_PIN 3
#define LDR_PIN A0
#define MOTOR_LEFT_PWM 9  // EN_A
#define MOTOR_RIGHT_PWM 10  // EN_B
#define MOTOR_LEFT_DIR_1 7  // IN1
#define MOTOR_LEFT_DIR_2 8  // IN2
#define MOTOR_RIGHT_DIR_1 12  // IN3
#define MOTOR_RIGHT_DIR_2 13  // IN4

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_LEFT_PWM, OUTPUT);
  pinMode(MOTOR_RIGHT_PWM, OUTPUT);
  pinMode(MOTOR_LEFT_DIR_1, OUTPUT);
  pinMode(MOTOR_LEFT_DIR_2, OUTPUT);
  pinMode(MOTOR_RIGHT_DIR_1, OUTPUT);
  pinMode(MOTOR_RIGHT_DIR_2, OUTPUT);
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
  digitalWrite(MOTOR_LEFT_DIR_1, HIGH);
  digitalWrite(MOTOR_LEFT_DIR_2, LOW);
  digitalWrite(MOTOR_RIGHT_DIR_1, HIGH);
  digitalWrite(MOTOR_RIGHT_DIR_2, LOW);
  analogWrite(MOTOR_LEFT_PWM, 200);
  analogWrite(MOTOR_RIGHT_PWM, 200);
}

void stopMotors() {
  analogWrite(MOTOR_LEFT_PWM, 0);
  analogWrite(MOTOR_RIGHT_PWM, 0);
}

void turnRight() {
  digitalWrite(MOTOR_LEFT_DIR_1, HIGH);
  digitalWrite(MOTOR_LEFT_DIR_2, LOW);
  digitalWrite(MOTOR_RIGHT_DIR_1, LOW);
  digitalWrite(MOTOR_RIGHT_DIR_2, HIGH);
  analogWrite(MOTOR_LEFT_PWM, 200);
  analogWrite(MOTOR_RIGHT_PWM, 200);
}

void turnLeft() {
  digitalWrite(MOTOR_LEFT_DIR_1, LOW);
  digitalWrite(MOTOR_LEFT_DIR_2, HIGH);
  digitalWrite(MOTOR_RIGHT_DIR_1, HIGH);
  digitalWrite(MOTOR_RIGHT_DIR_2, LOW);
  analogWrite(MOTOR_LEFT_PWM, 200);
  analogWrite(MOTOR_RIGHT_PWM, 200);
}
