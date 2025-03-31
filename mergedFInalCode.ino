// Copyright(c) 2025 Dr.Neeraj Mishra. All rights reserved.
// This code is proprietary and may not be used, copied, modified, or distributed
// without the express permission of Dr.Neeraj Mishra

#include <Servo.h>

// Create Servo objects to control all servo motors and ESC
Servo servo1;
Servo servo2;
Servo esc;

// Define pins
int servo1Pin = 9;     // Pin for the first servo
int servo2Pin = 10;    // Pin for the second servo
int escPin = 7;        // Pin for the ESC
int motorDir1 = 3;     // Direction control pin 1 (IN1 for L298N)
int motorDir2 = 4;     // Direction control pin 2 (IN2 for L298N)
int motorSpeedPin = 5; // PWM pin to control motor speed (ENA for L298N)
int pwmSignalPin = 6;  // Changed from 6 to 7 since 6 is now used for ESC

// ESC control values
int pwmValue = 1300;            // Set PWM value for running throttle
int stopValue = 1000;           // Set PWM value for stopping the motor
const long runInterval = 4000;  // 4 seconds on
const long stopInterval = 1500; // 1.5 seconds off

void setup()
{
  // Start serial monitor for debugging
  Serial.begin(9600);
  Serial.println("Starting initialization...");

  // Attach the servo motors to the specified pins
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  // Attach ESC to its pin
  esc.attach(escPin, 1000, 2000); // Min pulse 1000µs, max pulse 2000µs

  // Initialize both servos to 0 position
  servo1.write(0);
  servo2.write(0);

  // Set motor control pins as output
  pinMode(motorDir1, OUTPUT);
  pinMode(motorDir2, OUTPUT);
  pinMode(motorSpeedPin, OUTPUT);
  pinMode(pwmSignalPin, OUTPUT); // Set new PWM pin for continuous signal

  // Arming sequence for the ESC
  Serial.println("Starting ESC arming sequence...");
  esc.writeMicroseconds(1000); // Send minimum throttle to arm ESC
  delay(5000);                 // Wait 5 seconds for ESC to arm
  Serial.println("ESC should be armed and ready.");

  delay(2000); // Additional delay to make sure everything is initialized
}

void loop()
{
  Serial.println("=== Starting sequence ===");

  // STEP 1: First Servo (servo1) Operation: 0 to 90 then 90 to 0
  Serial.println("Operating second servo...");
  servo1.write(90);
  delay(1000); // Wait for 1 second at 90 degrees
  Serial.println("Second servo reached 90 degrees.");
  servo1.write(0);
  delay(1000); // Wait for 1 second at 0 degrees
  Serial.println("Second servo returned to 0 degrees.");

  // Start drone motor immediately after the first servo is at 90
  Serial.println("Starting drone motor...");
  esc.writeMicroseconds(pwmValue); // Start the motor
  Serial.print("Drone motor started at throttle: ");
  Serial.println(pwmValue);

  // Wait for the motor to run (4 seconds)
  delay(runInterval);

  // Stop motor and print the message
  Serial.println("Stopping drone motor...");
  esc.writeMicroseconds(stopValue); // Stop motor
  Serial.println("Drone motor stopped.");
  delay(stopInterval); // Wait for the motor to stop

  // STEP 2: Second Servo (servo2) Operation
  Serial.println("Operating second servo...");
  servo2.write(90);
  delay(1000); // Wait for 1 second at 90 degrees
  Serial.println("Second servo reached 90 degrees.");
  servo2.write(0);
  delay(1000); // Wait for 1 second at 0 degrees
  Serial.println("Second servo returned to 0 degrees.");

  // STEP 3: Vibration starts after the second servo
  Serial.println("Starting motor driver...");

  // Set motor direction (forward)
  digitalWrite(motorDir1, HIGH); // Set direction 1 (forward)
  digitalWrite(motorDir2, LOW);  // Set direction 2 (forward)

  // Set motor speed using PWM signal
  analogWrite(motorSpeedPin, 200); // 50% speed (range 0-255)

  delay(15000); // Run motor for 5 seconds

  // Stop motor after 5 seconds
  analogWrite(motorSpeedPin, 0); // Stop the motor (set PWM to 0)
  Serial.println("Motor driver stopped");

  // STEP 4: Wait before restarting the sequence
  Serial.println("Sequence complete, waiting before restart...");
  delay(5000); // Wait 5 seconds before restarting the whole sequence
}