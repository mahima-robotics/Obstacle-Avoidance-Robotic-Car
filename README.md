# Obstacle-Avoidance-Robotic-Car
An autonomous obstacle avoidance robotic car built using Arduino Uno, HC-SR04 Ultrasonic Sensor, Servo Motor, and L298N Motor Driver. The robot detects obstacles, scans its surroundings, and automatically changes direction to navigate without collisions.
# Obstacle Avoidance Robotic Car Using Arduino

## Overview

The Obstacle Avoidance Robotic Car is an autonomous mobile robot capable of detecting and avoiding obstacles without human intervention. The robot uses an HC-SR04 Ultrasonic Sensor mounted on a Servo Motor to continuously monitor its surroundings. When an obstacle is detected, the robot stops, scans different directions, and chooses a new path to continue moving safely.

This project demonstrates the fundamentals of robotics, autonomous navigation, sensor integration, motor control, and embedded programming using Arduino.

---

## Features

* Autonomous obstacle detection and avoidance
* Real-time distance measurement using ultrasonic sensor
* Servo-based environmental scanning
* Automatic forward movement
* Automatic stopping when obstacles are detected
* Reverse movement for collision prevention
* Direction changing mechanism
* Adjustable motor speed through PWM control
* Simple and beginner-friendly Arduino code

---

## Hardware Components Required

| Component                 | Quantity    |
| ------------------------- | ----------- |
| Arduino Uno               | 1           |
| HC-SR04 Ultrasonic Sensor | 1           |
| Servo Motor (SG90/MG90S)  | 1           |
| L298N Motor Driver Module | 1           |
| DC Gear Motors            | 2           |
| Robot Chassis             | 1           |
| Wheels                    | 2           |
| Caster Wheel              | 1           |
| Battery Pack              | 1           |
| Jumper Wires              | As Required |

---

## Circuit Connections

### Ultrasonic Sensor

| HC-SR04 Pin | Arduino Pin |
| ----------- | ----------- |
| VCC         | 5V          |
| GND         | GND         |
| Trig        | D9          |
| Echo        | D8          |

### Servo Motor

| Servo Pin | Arduino Pin |
| --------- | ----------- |
| Signal    | D10         |
| VCC       | 5V          |
| GND       | GND         |

### L298N Motor Driver

| L298N Pin | Arduino Pin |
| --------- | ----------- |
| ENA       | D3          |
| IN1 (MLa) | D4          |
| IN2 (MLb) | D5          |
| IN3 (MRa) | D6          |
| IN4 (MRb) | D7          |
| ENB       | D11         |

---

## Working Principle

### 1. Distance Measurement

The HC-SR04 Ultrasonic Sensor continuously measures the distance between the robot and nearby objects.

### 2. Forward Movement

When the measured distance is greater than 20 cm, the robot moves forward.

### 3. Obstacle Detection

If an obstacle is detected within 20 cm:

* The robot immediately stops.
* The servo rotates the ultrasonic sensor to scan the surroundings.
* The robot checks left and right directions.

### 4. Collision Prevention

After scanning:

* The robot moves backward for a short duration.
* Changes direction by turning.
* Continues navigation in the new path.

### 5. Continuous Navigation

The entire process repeats continuously, enabling autonomous movement.

---

## Algorithm

1. Start robot.
2. Measure distance using HC-SR04.
3. If distance > 20 cm:

   * Move Forward.
4. Else:

   * Stop.
   * Scan Left.
   * Scan Right.
   * Return Servo to Center.
   * Move Backward.
   * Turn.
5. Repeat.

---

## Pin Configuration

```cpp
#define trigPin 9
#define echoPin 8

#define ENA 3
#define ENB 11

#define MLa 4
#define MLb 5

#define MRa 6
#define MRb 7
```

---

## Software Used

* Arduino IDE
* Arduino AVR Boards Package
* Servo Library

---

## Applications

* Autonomous Robots
* Educational Robotics Projects
* Obstacle Detection Systems
* Smart Navigation Systems
* Robotics Learning and Research
* Indoor Navigation Robots

---

## Future Improvements

* Intelligent path selection based on scanned distance
* Bluetooth control mode
* Wi-Fi control using ESP32
* Line following functionality
* Voice control integration
* Mobile application control
* AI-based object recognition
* GPS navigation system

---

## Project Output

The robot autonomously moves forward and continuously monitors its environment. Whenever an obstacle appears in front of it, the robot stops, scans nearby directions using a servo-mounted ultrasonic sensor, reverses slightly, changes direction, and continues moving without colliding with objects.

---

## Learning Outcomes

Through this project, I learned:

* Arduino programming
* Sensor interfacing
* Motor driver control
* Servo motor operation
* Autonomous robot navigation
* Embedded systems development
* Robotics fundamentals

---

## Author

Deepak Kumar Anand

B.Voc Robotics and Automation
Central University of Rajasthan

---

## License

This project is open-source and available under the MIT License.
