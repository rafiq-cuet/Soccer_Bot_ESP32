/*FOR BLUETOOTH MODULE*/
char btSignal;

/* 1 means LEFT MOTOR; 2 means RIGHT MOTOR */
int Speed;

/*FOR LEFT MOTOR*/
int R1PWM = 6;
int L1PWM = 5;

/*FOR RIGHT MOTOR*/
int R2PWM = 11;
int L2PWM = 10;

void setup() {
  Serial.begin(9600);
  pinMode(R1PWM, OUTPUT);
  pinMode(L1PWM, OUTPUT);

  pinMode(R2PWM, OUTPUT);
  pinMode(L2PWM, OUTPUT);
}

void loop() {

  while (Serial.available() > 0) {
    btSignal = Serial.read();
    Serial.println(btSignal);


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

      analogWrite(R1PWM, Speed);
      analogWrite(L1PWM, 0);

      analogWrite(R2PWM, Speed);
      analogWrite(L2PWM, 0);

    }

    else if (btSignal == 'B')  //backward
    {
      analogWrite(R1PWM, 0);
      analogWrite(L1PWM, Speed);

      analogWrite(R2PWM, 0);
      analogWrite(L2PWM, Speed);

    }

    else if (btSignal == 'L')  //LEFT
    {

      analogWrite(R1PWM, 0);
      analogWrite(L1PWM, Speed);

      analogWrite(R2PWM, Speed);
      analogWrite(L2PWM, 0);
    }

    else if (btSignal == 'R')  //RIGHT
    {
      analogWrite(R1PWM, Speed);
      analogWrite(L1PWM, 0);

      analogWrite(R2PWM, 0);
      analogWrite(L2PWM, Speed);
    }

    else if (btSignal == 'S')  //STOP
    {
      analogWrite(R1PWM, 0);
      analogWrite(L1PWM, 0);

      analogWrite(R2PWM, 0);
      analogWrite(L2PWM, 0);
    }

    else if (btSignal == 'I')  //FORWARD RIGHT
    {
      analogWrite(R1PWM, Speed);
      analogWrite(L1PWM, 0);

      analogWrite(R2PWM, 0);
      analogWrite(L2PWM, 0);
    }

    else if (btSignal == 'J')  //BACKWARD RIGHT
    {
      analogWrite(R1PWM, 0);
      analogWrite(L1PWM, Speed);

      analogWrite(R2PWM, 0);
      analogWrite(L2PWM, 0);
    }

    else if (btSignal == 'G')  //FORWARD LEFT
    {
      analogWrite(R1PWM, 0);
      analogWrite(L1PWM, 0);

      analogWrite(R2PWM, Speed);
      analogWrite(L2PWM, 0);
    }

    else if (btSignal == 'H')  //BACKWARD LEFT
    {
      analogWrite(R1PWM, 0);
      analogWrite(L1PWM, 0);

      analogWrite(R2PWM, 0);
      analogWrite(L2PWM, Speed);
    }
  }
}