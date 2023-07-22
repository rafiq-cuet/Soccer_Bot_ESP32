#include "BluetoothSerial.h"
#include <Arduino.h>

BluetoothSerial serialBT;

//Bluetooth signal Store in this variable
char btSignal;

//initial Speed of the Bot
int Speed = 100;

/*FOR RIGHT MOTOR*/
int R1PWM = 19;
int R2PWM = 21;

/*FOR LEFT MOTOR*/
int L1PWM = 23;
int L2PWM = 22;

//declare channel for pwm Output
#define R1 0
#define R2 1
#define L1 2
#define L2 3

void setup() {
  Serial.begin(115200);

  //Bluetooth Name
  serialBT.begin("CUBIT 1.9");

  //output pin declare
  pinMode(R1PWM, OUTPUT);
  pinMode(R2PWM, OUTPUT);
  pinMode(L1PWM, OUTPUT);
  pinMode(L2PWM, OUTPUT);

  // Setup PWM channels
  ledcSetup(R1, 5000, 8);  // Channel 0 for Motor A, 5 kHz frequency, 8-bit resolution
  ledcAttachPin(R1PWM, R1);
  ledcSetup(R2, 5000, 8);  // Channel 1 for Motor B, 5 kHz frequency, 8-bit resolution
  ledcAttachPin(R2PWM, R2);
  ledcSetup(L1, 5000, 8);  // Channel 0 for Motor A, 5 kHz frequency, 8-bit resolution
  ledcAttachPin(L1PWM, L1);
  ledcSetup(L2, 5000, 8);  // Channel 1 for Motor B, 5 kHz frequency, 8-bit resolution
  ledcAttachPin(L2PWM, L2);
}

void loop() {

  while (serialBT.available()) {
    btSignal = serialBT.read();
    //Serial.println(btSignal);

    if (btSignal == '0') Speed = 100;
    if (btSignal == '1') Speed = 110;
    if (btSignal == '2') Speed = 120;
    if (btSignal == '3') Speed = 130;
    if (btSignal == '4') Speed = 140;
    if (btSignal == '5') Speed = 150;
    if (btSignal == '6') Speed = 180;
    if (btSignal == '7') Speed = 200;
    if (btSignal == '8') Speed = 220;
    if (btSignal == '9') Speed = 240;
    if (btSignal == 'q') Speed = 255;

    if (btSignal == 'F')  //forward
    {
      ledcWrite(R1, Speed);
      ledcWrite(R2, 0);
      ledcWrite(L1, Speed);
      ledcWrite(L2, 0);
    }

    else if (btSignal == 'B')  //backward
    {
      ledcWrite(R1, 0);
      ledcWrite(R2, Speed);

      ledcWrite(L1, 0);
      ledcWrite(L2, Speed);

    }

    else if (btSignal == 'L')  //LEFT
    {

      ledcWrite(R1, 0);
      ledcWrite(R2, Speed);

      ledcWrite(L1, Speed);
      ledcWrite(L2, 0);
    }

    else if (btSignal == 'R')  //RIGHT
    {
      ledcWrite(R1, Speed);
      ledcWrite(L1, 0);

      ledcWrite(R2, 0);
      ledcWrite(L2, Speed);
    }

    else if (btSignal == 'S')  //STOP
    {
      ledcWrite(R1, 0);
      ledcWrite(L1, 0);

      ledcWrite(R2, 0);
      ledcWrite(L2, 0);
    }

    else if (btSignal == 'I')  //FORWARD RIGHT
    {
      ledcWrite(R1, Speed);
      ledcWrite(R2, 0);

      ledcWrite(L1, 0);
      ledcWrite(L2, 0);
    }

    else if (btSignal == 'J')  //BACKWARD RIGHT
    {
      ledcWrite(R1, 0);
      ledcWrite(R2, Speed);

      ledcWrite(L1, 0);
      ledcWrite(L2, 0);
    }

    else if (btSignal == 'G')  //FORWARD LEFT
    {
      ledcWrite(R1, 0);
      ledcWrite(R2, 0);

      ledcWrite(L1, Speed);
      ledcWrite(L2, 0);
    }

    else if (btSignal == 'H')  //BACKWARD LEFT
    {
      ledcWrite(R1, 0);
      ledcWrite(R2, 0);

      ledcWrite(L1, 0);
      ledcWrite(L2, Speed);
    }
  }
}