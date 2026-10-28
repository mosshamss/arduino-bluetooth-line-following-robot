
# Arduino Bluetooth-Controlled and Line-Following Robot

## Project Overview

An Arduino-based robotic car designed to operate in two modes: Bluetooth remote control and autonomous line following.

The robot uses two infrared (IR) sensors to detect a line and adjust its direction. In Bluetooth mode, users can control the robot's movement and motor speed wirelessly.

This project demonstrates embedded systems programming, hardware integration, serial communication, sensor-based automation, and motor control.

## Key Features

- Bluetooth remote-controlled movement
- Autonomous line following using IR sensors
- Two operating modes
- Adjustable motor speed using PWM
- Forward, backward, left, right, and stop functions
- Serial communication at 9600 baud

## Hardware Components

- Arduino microcontroller
- Bluetooth serial communication module
- Two IR sensors
- DC motors
- Motor driver module
- Robotic car chassis
- Power supply and connecting wires

## Technologies Used

- Arduino IDE
- Embedded C/C++
- Serial Communication
- Pulse Width Modulation (PWM)
- Infrared Sensor Integration
- Motor Control

## Operating Modes

### 1. Bluetooth Remote Control

The Arduino receives movement commands through serial communication with the Bluetooth module.

| Command | Function |
|---------|----------|
| F0 | Move forward |
| B0 | Move backward |
| R0 | Turn right |
| L0 | Turn left |
| S0 | Stop |
| I0 | Increase speed |
| D0 | Decrease speed |
| IR0 | Activate line-following mode |

Motor speed can be adjusted between 0 and 250 in increments of 50.

### 2. Autonomous Line Following

The robot uses two IR sensors to detect the line and adjust motor movement.

| Left Sensor | Right Sensor | Action |
|-------------|--------------|--------|
| HIGH | HIGH | Forward |
| HIGH | LOW | Right |
| LOW | HIGH | Left |

In line-following mode, the PWM motor speed is set to 65.

## Arduino Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Left IR Sensor | A0 |
| Right IR Sensor | A2 |
| Motor Driver IN1 | 9 |
| Motor Driver IN2 | 8 |
| Motor Driver IN3 | 5 |
| Motor Driver IN4 | 4 |
| Motor Enable ENA | 11 |
| Motor Enable ENB | 3 |

## Software Implementation

The robot is programmed using Arduino C/C++.

The Arduino continuously reads incoming serial commands and controls the motors accordingly.

Digital output pins determine motor direction, while PWM signals regulate motor speed.

In line-following mode, sensor readings determine the direction of movement.

## Project Testing

The robotic car was physically assembled and tested.

Bluetooth-controlled movement and autonomous line-following functionality were verified through practical testing.

## Source Code

The complete Arduino source code is available in:

[View Arduino Source Code](arduino-bluetooth-line-following-robot.ino)

## Project Demonstration

Watch the robotic car in operation:

[Watch the Robot Demonstration](media/robot-demonstration.mp4)

## Skills Demonstrated

- Embedded Systems Programming
- Hardware and Software Integration
- Sensor-Based Automation
- Wireless Communication
- PWM Motor Speed Control
- Robotics and Control Logic
- Arduino Development

## Author

Mohamed Hassanien
