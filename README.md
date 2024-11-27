# Teleoperated Anthropomorphic 3D-printed Robot Arm and Exoskeleton Controller

## **Problem Statement:**
Remotely perform a dextrous manipulation task using a robot that shadows the user's arm and hand motion.

## **Functional Requirements:**
- The robot is anthropomorphic to mirror the user's human arm anatomy.
- The robot shadows the user's joint flexion and extension  (shoulder [2 DoF], elbow [1 DoF], wrist [1 DoF], MCP joint and fingers [6 DoF]) 
- The robot uses a mechanical linkage-based transmission actuated by DC servo motors and is controlled using an Arduino Nano and Servo Driver.
- The Robot frame, linkages and exoskeleton controller are prototyped using 3D-printed PLA filament.
- The user's joint rotational positions are measured using potentiometers connected to a linkage-based exoskeleton. 
- The robot and controller are interfaced via a physical wire connection
- The robot is powered by a 5V 20A power supply.

## **Hardware Components:**
- 1x Arduino Nano microcontroller 
- 1x PCA9685 Servo Driver
- 6x MG90S DC Servo Motors
- 4x DSS32 25kg DC Servo Motors
- 1x Multiplexor
- 1x Breadboard
- Jumper wires
- 3D-printed exoskeleton
- 3D-printed robot frame
- 10x 10k Ohm Potentiometers
- Screws and nuts for joint pins and assembly
- 5V 20A power supply.

## **Software Packages:**
- **Arduino IDE** - https://www.arduino.cc/en/software/
- Servo Driver Library

## Appendix A

### A.0 - Robot Arm
![Arm + Linkage-Based Hand](https://github.com/user-attachments/assets/922b9d3a-7b0f-4399-889a-abc57fb3fd05)
![IMG_20221229_105605_668](https://github.com/user-attachments/assets/a86f1f93-8737-47b5-af52-26f54e4917eb)
![IMG_20221229_105605_763](https://github.com/user-attachments/assets/f70d29d4-824a-4ed6-b46c-c071aac840d8)

### A.1 - 3D-printed Exoskeleton
![321144525_1260601928137454_2570783908375072878_n](https://github.com/user-attachments/assets/8257dde6-8fd0-422e-b557-55b6c9fe34dd)
![312453402_2274205706075385_7042366949202713802_n](https://github.com/user-attachments/assets/7b7df6f8-1753-412b-9298-b7ff59167ece)
