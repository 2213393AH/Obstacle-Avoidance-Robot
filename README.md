# Obstacle-Avoidance-Robot

This project demonstrates how to build a robotic car using an Arduino Uno, L298N motor controller, 4 DC motors, and an ultrasonic sensor (HC-SR04) for obstacle detection and avoidance. The car moves forward and automatically turns when it detects an obstacle within a certain distance.

## Table of Contents
- [Project Overview](#project-overview)
- [Components](#components)
- [Wiring](#wiring)
- [Arduino Code](#arduino-code)
- [How It Works](#how-it-works)
- [Usage](#usage)
- [License](#license)

## Project Overview
This robotic car uses four DC motors controlled by an L298N motor driver, and an ultrasonic sensor for obstacle detection. The car moves forward until an obstacle is detected within a set range (e.g., 20 cm), after which it stops and turns to avoid the obstacle.

## Components
- Arduino Uno
- L298N Motor Driver Module
- 4x DC Motors
- Ultrasonic Sensor (HC-SR04)
- 9V Battery or External Power Supply
- Breadboard and Jumper Wires

## Wiring
- **Ultrasonic Sensor (HC-SR04):**
  - VCC → 5V (Arduino)
  - GND → GND (Arduino)
  - Trig → Pin 9 (Arduino)
  - Echo → Pin 10 (Arduino)

- **Motor Driver (L298N):**
  - IN1 → Pin 2 (Arduino)
  - IN2 → Pin 3 (Arduino)
  - IN3 → Pin 4 (Arduino)
  - IN4 → Pin 5 (Arduino)
  - ENA → Pin 6 (PWM) (Arduino)
  - ENB → Pin 7 (PWM) (Arduino)
  - Motor connections:
    - M1 and M2 → Left-side motors
    - M3 and M4 → Right-side motors

## Arduino Code
```cpp
// Arduino code goes here (refer to your main Arduino sketch)
