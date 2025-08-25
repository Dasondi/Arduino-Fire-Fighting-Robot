# Arduino Fire-Fighting Robot

An autonomous robot built with Arduino that detects fire using IR sensors, navigates towards it, and extinguishes it with a servo-mounted water pump. It also sends an SMS alert using a SIM800 GSM module.



## Project Overview
This robot operates by constantly scanning its surroundings with three infrared (IR) flame sensors (left, front, and right). When a sensor detects the specific IR signature of a flame, the robot stops, activates a water pump, and aims the nozzle using a servo motor to extinguish the fire. It then sends an SMS notification to a pre-programmed phone number.

## Hardware Required
* Arduino UNO (or any compatible board)
* L298N Motor Driver Module
* Robot Chassis with 2 DC Motors
* 3x IR Flame Sensors (Analog)
* SG90 Micro Servo Motor
* 5V Mini Water Pump
* SIM800L (or similar) GSM Module
* 7.4V Li-Ion or 9V Battery Pack for motors
* Jumper Wires and a small breadboard

## Circuit Diagram
A clear circuit diagram is essential for others to replicate your project. You can create one using a free tool like [Fritzing](https://fritzing.org/) and insert the image here.

*(You would place your circuit diagram image here)*

## How to Use
1.  **Assemble the circuit** according to the diagram.
2.  **Clone this repository** or download the `FireFightingRobot.ino` file.
3.  **Update the Phone Number:** Open the code and change the phone number in the `sendSMS` function to your own.
    ```cpp
    sim800.println("AT+CMGS=\"+XXXXXXXXXX\""); // <-- Change this number
    ```
4.  **Upload the code** to your Arduino board using the Arduino IDE.
5.  Power up the robot and test its functionality.

---
Created by Priyank Dasondi, 2024
