
int pinLed = 13;
int pinNoise = 3;
//
int pinStop = 7;
int pinLeft = 8;
int pinRight = 12;

int pinMotor_0 = 0;
int pinMotor_1 = 1;
int pinMotor_5 = 5;

int pinMotor_4 = 4;
int pinMotor_2 = 2;
int pinMotor_6 = 6;

int NORMAL = 100;
int FAST = 255;

long time;
int movingRobot;

void setup()
{
  // pyour setup code here, to run once:
//  Serial.begin(9600);
//
//  
  pinMode(pinNoise, OUTPUT);
//  
  pinMode(pinStop, INPUT_PULLUP);
  pinMode(pinLeft, INPUT_PULLUP);
  pinMode(pinRight, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);


  /* settings for all the motor pins */
  pinMode(pinMotor_0, OUTPUT);
  pinMode(pinMotor_1, OUTPUT);
  pinMode(pinMotor_5, OUTPUT);
  pinMode(pinMotor_2, OUTPUT);
  pinMode(pinMotor_4, OUTPUT);
  pinMode(pinMotor_6, OUTPUT);

  digitalWrite(pinStop, LOW);


  time = millis();
}



void dealIntruder()
 {
    // if (GAME_OVER_BUTTON_ON) EXIT;
    
    noTone(pinNoise);

   
    /*
   
    boolean isReverse = true;
    move(FAST, isReverse);
    
    */
   
 }


 

/* bigger number --> closer; smaller number --> farther */
void loop2()
{

  moveF(0, false);
  
  int noiseMakingCount = 1;
  while (noiseMakingCount <= 3)
  {
      if (analogRead(A5) >= 250)
      { 
          dealIntruder();
          // exit while loop
      }

      else
      {
          tone(pinNoise, 128, 50);
      }

      noiseMakingCount++;
  }
  noTone(pinNoise);
  
  while (movingRobot <= 200000)
  {
      if (analogRead(A5) >= 250)
      { 
          dealIntruder();
          // exit while loop
      }

      else
      {
            int speed = 100;
            int isReverse = false;
            moveF(speed, isReverse);
      }

      movingRobot++;
  }
 

}

boolean intruderPresent = false;
boolean noisyTime = false;
long noisyTimeStart = millis();
long noisyTimeInterval = 5000;
long noisyTimeLength = 1000;
long rtime;
boolean gameOver = false;

void loop() {
  if(gameOver) {
    moveF(0, false);
    noTone(pinNoise);
  } else {
    moveF(100,true);
    //game_loop();
  }
}

void game_loop() {
  if(millis() - noisyTimeStart > noisyTimeLength) {
    tone(pinNoise, 128, 10);
  } else {
    noTone(pinNoise);
  }
  if(millis() - noisyTimeStart >=  noisyTimeInterval) {
      noisyTimeStart = millis();
  } 
  if (analogRead(A5) >= 250)
  { 
    intruderPresent = true;
  }
  if(intruderPresent) {
    
    moveF(255, true);
    rtime = millis();
  } else {
    moveF(100, false);
  }
  if(millis() - rtime > 1000) {
    intruderPresent = false;
  }
  
  if(digitalRead(pinStop == LOW)) {
    gameOver = true;
  }
  
}



void moveF(int speed, boolean reverse)
{
    if (reverse)
    {
      analogWrite(pinMotor_5, speed);
      analogWrite(pinMotor_6, speed);

      
      digitalWrite(pinMotor_0, LOW);
      digitalWrite(pinMotor_1, HIGH);

      digitalWrite(pinMotor_4, HIGH);
      digitalWrite(pinMotor_2, LOW);
    }
    
    else
    {
      analogWrite(pinMotor_5, speed);
      analogWrite(pinMotor_6, speed);

      digitalWrite(pinMotor_0, LOW);
      digitalWrite(pinMotor_1, HIGH);

      digitalWrite(pinMotor_4, LOW);
      digitalWrite(pinMotor_2, HIGH);

    }
  
}




  
  
 







