
/*
  Stepper Motor Control

  This program drives a bipolar motor when a button is pushed.
  The motor is attached to digital pins 9 - 12 of the Arduino.

  The motor should revolve until the gear(40mm) has made one revolution.
  The motor speed up at the beginning of the revolution and slow down at the end of the revolution.

  Created 22 Feb. 2018
  by Insiya Jafferjee

*/

#include <Stepper.h>

// initialize button on pin 5
const int buttonPin = 5;

// state when button is unpressed
int buttonPressed = 0;

// Number of steps per revolution for motor
const int stepsPerRevolution = 200;

// initialize the stepper library on pins 9 through 12:
Stepper myStepper(stepsPerRevolution, 9, 10, 11, 12);

// total number of revolutions to make small gear turn one round
const int gearRatio = 4;

// Controls the step of the servo at which speed starts to decrease
int pos = (stepsPerRevolution * gearRatio * 0.75);

// Controls the step of the servo at which speed stops
int pos2 = (stepsPerRevolution * gearRatio);

// Starting speed
int minSpeed = 30;

// Max speed
int maxSpeed = 60;

// Speed variable
int stepperSpeed;

//Integer repeat initial
int i;

//Integer repeat until
const int n = 1;

void setup() {
  // initialize the serial port:
  Serial.begin(9600);

  // set button to be input
  pinMode (buttonPin, INPUT);

  // set the speed at 0 speed to start//
  myStepper.setSpeed(maxSpeed);
  
}

void loop() {

  buttonPressed = digitalRead(buttonPin);
  Serial.println(buttonPressed);

  if(buttonPressed==1){

    for (i = 0; i < n; i++) {
 
      Serial.println("start");
      // start Stepper at min Speed
      myStepper.setSpeed(minSpeed);
      // makes the stpper revolve at max speed for three quarters of the rotation
      myStepper.step(pos);
      delay (2000);

      Serial.println ("speeding up");
      
      for (int p = pos; p < pos2; p = p + 2) {
        Serial.print("p =");
        Serial.println(p);
        myStepper.setSpeed(minSpeed + (p / 100));
        myStepper.step(stepsPerRevolution / 100);

        //makes the stepper pause at the center

        
      }
    }
  }
}

