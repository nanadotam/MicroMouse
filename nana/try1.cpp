// flood fill - dfs test
/*

#define WIDTH 5
#define HEIGHT 5

int maze[WIDTH][HEIGHT] = {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}
};

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);  // Initialize the LED pin
    Serial.begin(9600);
    
    floodFillDFS(0, 0, 2);  // Start filling from the top-left corner with value 2

    // Print the maze to the serial monitor
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            Serial.print(maze[i][j]);
            Serial.print(" ");
        }
        Serial.println();
    }
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);  // Wait for 1000 milliseconds
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);  // Wait for 1000 milliseconds
}

void floodFillDFS(int x, int y, int fillValue) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;  // Out of bounds
    if (maze[x][y] != 0) return;  // Not empty or already filled

    maze[x][y] = fillValue;  // Fill the cell

    // Recursive calls for the four directions
    floodFillDFS(x + 1, y, fillValue);  // Down
    floodFillDFS(x - 1, y, fillValue);  // Up
    floodFillDFS(x, y + 1, fillValue);  // Right
    floodFillDFS(x, y - 1, fillValue);  // Left
}


*/










#define WIDTH 16
#define HEIGHT 16

int maze[WIDTH][HEIGHT] = { 
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};


const int trigPin1 = 9;  // Front ultrasonic sensor
const int echoPin1 = 10;
const int trigPin2 = 11; // Left ultrasonic sensor
const int echoPin2 = 12;
const int trigPin3 = 13; // Right ultrasonic sensor
const int echoPin3 = 14;

const int motor1Pin1 = 2; // Motor A
const int motor1Pin2 = 3;
const int motor2Pin1 = 4; // Motor B
const int motor2Pin2 = 5;

void setup() {
    // Sensor setup
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT);
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);
    pinMode(trigPin3, OUTPUT);
    pinMode(echoPin3, INPUT);

    // Motor setup
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    // Navigation logic and sensor reading
    int distanceFront = getDistance(trigPin1, echoPin1);
    int distanceLeft = getDistance(trigPin2, echoPin2);
    int distanceRight = getDistance(trigPin3, echoPin3);

    // Decision making based on sensor input
    navigate(distanceFront, distanceLeft, distanceRight);

    delay(100);
}

int getDistance(int trigPin, int echoPin) {
    // Send a pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure the pulse duration
    long duration = pulseIn(echoPin, HIGH);

    // Convert to distance (in cm)
    int distance = duration * 0.034 / 2;
    return distance;
}

void navigate(int front, int left, int right) {
    // Basic navigation logic
    if (front > 10) {
        moveForward();
    } else if (left > 10) {
        turnLeft();
    } else if (right > 10) {
        turnRight();
    } else {
        turnAround();
    }
}

void moveForward() {
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
}

void turnLeft() {
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
}

void turnRight() {
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
}

void turnAround() {
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    delay(1000);  // Turn 180 degrees
} 


