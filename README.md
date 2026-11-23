# Smart Donation Box

## Overview
The Smart Donation Box is an innovative system designed to tackle the issue of untracked money in temples and other cash-heavy environments. This automated solution segregates a stash of cash by denomination using advanced sorting technology, then counts and logs the total amount with precision. Integrated with secure digital reporting, it ensures transparency and accountability, reducing the risk of financial mismanagement or illicit funds circulating undetected. Beyond temples, it addresses problems like tax evasion in donation-based organizations, cash-handling errors in small businesses, and the lack of audit trails in informal economies, promoting trust and compliance in financial operations.

## Copyright
Copyright (c) 2025 Dr. Neeraj Mishra. All rights reserved.

This project and its code are proprietary. It is shared here for demonstration and educational purposes only. No permission is granted to use, copy, modify, distribute, or create derivative works from this code without the express consent of Dr. Neeraj Mishra.

## Contact
For inquiries or permission requests, contact us at mishraneeraj@mitsgwalior.in.

## Author
- Written and maintained by Moksh Dandotiya.
- Contact: moksh@duck.com

---

## ️ Installation & Hardware Setup

### 1. Hardware Requirements
- **Microcontroller**: Arduino Uno / Mega / Nano
- **Motor Driver**: L298N Dual H-Bridge Motor Driver
- **Actuators**: 2x Servo Motors (SG90 or MG996R) + 1x High-Torque DC Motor + ESC
- **Power Supply**: 12V DC External Battery / Adapter (with common ground to Arduino)

### 2. Pin Mapping
| Component | Arduino Pin | Description |
| :--- | :--- | :--- |
| **Servo 1** | Pin 9 | First denomination sorting flap |
| **Servo 2** | Pin 10 | Second denomination sorting flap |
| **ESC Signal** | Pin 7 | Electronic Speed Controller throttle pulse |
| **Motor IN1** | Pin 3 | Direction control 1 (L298N) |
| **Motor IN2** | Pin 4 | Direction control 2 (L298N) |
| **Motor ENA** | Pin 5 | PWM speed control |

### 3. Software Installation
1. Install [Arduino IDE](https://www.arduino.cc/en/software) (version 2.0+ recommended).
2. Clone this repository:
   ```bash
   git clone https://github.com/danMoksh/smartDonationBox.git
   ```
3. Open `mergedFInalCode.ino` in Arduino IDE.
4. Ensure the standard `Servo` library is installed via the Library Manager.

---

## Usage & Operation

### 1. Flashing Firmware
1. Connect your Arduino board via USB.
2. Select your board model (`Tools > Board > Arduino Uno`) and serial port (`Tools > Port`).
3. Click **Upload** to compile and flash the firmware.

### 2. Operational Sequence
1. Open the Serial Monitor (`9600 baud`).
2. The ESC executes an arming sequence (`1000µs` pulse delay).
3. The sorting flaps calibrate to neutral 0-degree resting positions.
4. Continuous cash feed sorting and logging loops begin.

---

## Security

For security reporting and vulnerability handling, see [SECURITY.md](SECURITY.md).

---
*Note: This is not open-source software. See the LICENSE file for details.*