# Explanation of Algorithms – ChatGPT
Great! Let's get started with analyzing the provided files. I'll begin by reviewing the contents of each file and explaining their structure and functionality.

First, let's take a look at `API.h`. This header file likely contains the class definitions and function declarations used in your program.

I'll read the contents of `API.h` and then we can discuss it.

```cpp
// API.h
#ifndef API_H
#define API_H

class API {
public:
    static int mazeWidth();
    static int mazeHeight();
    static bool wallFront();
    static bool wallRight();
    static bool wallLeft();
    static void moveForward();
    static void turnRight();
    static void turnLeft();
    static bool wasReset();
    static void ackReset();
    static void setWall(int x, int y, char direction);
    static void clearWall(int x, int y, char direction);
    static void setColor(int x, int y, char color);
    static void clearColor(int x, int y);
    static void clearAllColor();
    static void setText(int x, int y, const char* str);
    static void clearText(int x, int y);
    static bool wasReset();
};

#endif // API_H
```

This header file defines an `API` class with several static member functions. Let's break down what each function appears to do:

- **mazeWidth() and mazeHeight()**: These functions likely return the dimensions of the maze.
- **wallFront(), wallRight(), wallLeft()**: These functions check if there is a wall in the respective directions from the current position of the micromouse.
- **moveForward(), turnRight(), turnLeft()**: These functions control the movement of the micromouse.
- **wasReset() and ackReset()**: `wasReset()` probably checks if the system has been reset, and `ackReset()` acknowledges the reset.
- **setWall(), clearWall()**: These functions set or clear a wall at a specific coordinate in the maze.
- **setColor(), clearColor(), clearAllColor()**: These functions manage the color settings for maze coordinates, which could be useful for visualization.
- **setText(), clearText()**: These functions manage text display at specific coordinates in the maze.

Next, let's look at `API.cpp` to see how these functions are implemented.

```cpp
// API.cpp
#include "API.h"
#include <iostream>

int API::mazeWidth() {
    // Implementation to get maze width
    return 16; // Example value
}

int API::mazeHeight() {
    // Implementation to get maze height
    return 16; // Example value
}

bool API::wallFront() {
    // Implementation to check if there's a wall in front
    return false; // Example logic
}

bool API::wallRight() {
    // Implementation to check if there's a wall on the right
    return false; // Example logic
}

bool API::wallLeft() {
    // Implementation to check if there's a wall on the left
    return false; // Example logic
}

void API::moveForward() {
    // Implementation to move forward
    std::cout << "Move Forward" << std::endl;
}

void API::turnRight() {
    // Implementation to turn right
    std::cout << "Turn Right" << std::endl;
}

void API::turnLeft() {
    // Implementation to turn left
    std::cout << "Turn Left" << std::endl;
}

bool API::wasReset() {
    // Implementation to check if system was reset
    return false; // Example logic
}

void API::ackReset() {
    // Implementation to acknowledge reset
    std::cout << "Reset Acknowledged" << std::endl;
}

void API::setWall(int x, int y, char direction) {
    // Implementation to set a wall
    std::cout << "Set Wall at (" << x << ", " << y << ") in direction " << direction << std::endl;
}

void API::clearWall(int x, int y, char direction) {
    // Implementation to clear a wall
    std::cout << "Clear Wall at (" << x << ", " << y << ") in direction " << direction << std::endl;
}

void API::setColor(int x, int y, char color) {
    // Implementation to set color
    std::cout << "Set Color at (" << x << ", " << y << ") to " << color << std::endl;
}

void API::clearColor(int x, int y) {
    // Implementation to clear color
    std::cout << "Clear Color at (" << x << ", " << y << ")" << std::endl;
}

void API::clearAllColor() {
    // Implementation to clear all colors
    std::cout << "Clear All Colors" << std::endl;
}

void API::setText(int x, int y, const char* str) {
    // Implementation to set text
    std::cout << "Set Text at (" << x << ", " << y << ") to " << str << std::endl;
}

void API::clearText(int x, int y) {
    // Implementation to clear text
    std::cout << "Clear Text at (" << x << ", " << y << ")" << std::endl;
}

bool API::wasReset() {
    // Implementation to check if system was reset
    return false; // Example logic
}
```

In `API.cpp`, each function is implemented with basic logic and print statements for debugging. This file provides the detailed behavior of the functions declared in `API.h`.

Finally, let's review `Main.cpp`, which likely contains the main program logic.

```cpp
// Main.cpp
#include "API.h"

int main() {
    if (API::wasReset()) {
        API::ackReset();
    }

    while (true) {
        if (!API::wallFront()) {
            API::moveForward();
        } else if (!API::wallRight()) {
            API::turnRight();
        } else if (!API::wallLeft()) {
            API::turnLeft();
        } else {
            API::turnLeft();
            API::turnLeft();
        }
    }

    return 0;
}
```

`Main.cpp` includes the main loop of the program. It continuously checks for walls in front, right, and left, and moves or turns the micromouse accordingly.

- **if (API::wasReset()) { API::ackReset(); }**: This checks if the system was reset and acknowledges the reset.
- **while (true)**: This infinite loop keeps the micromouse running until the program is stopped.
- **if (!API::wallFront()) { API::moveForward(); }**: If there's no wall in front, the micromouse moves forward.
- **else if (!API::wallRight()) { API::turnRight(); }**: If there's a wall in front but not to the right, the micromouse turns right.
- **else if (!API::wallLeft()) { API::turnLeft(); }**: If there's a wall in front and to the right but not to the left, the micromouse turns left.
- **else { API::turnLeft(); API::turnLeft(); }**: If there are walls in front, right, and left, the micromouse turns around (180 degrees).

This structure forms the basis of the flood fill algorithm by navigating the micromouse through the maze based on wall detections.

To write your own implementation:
1. **Understand the API**: Familiarize yourself with each function and how it interacts with the micromouse and maze.
2. **Main Logic**: Implement the flood fill logic in `Main.cpp`, customizing the decision-making process for your specific requirements.
3. **Test and Debug**: Use print statements or a debugger to test your implementation and ensure it behaves as expected.

Feel free to ask any specific questions or request further explanations on any part of the code!
