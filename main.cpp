#include <errno.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <softPwm.h>
#include <wiringPi.h>
#include <sys/time.h>

using namespace std;

#define EchoPin 12
#define TrigPin 16
#define SERVOPIN 26
#define MotorPin1 5
#define MotorPin2 6
#define RelayPin 13

extern "C" {
  void asmprogram();
}

void ultraInit(void)  {
  pinMode(EchoPin, INPUT);
  pinMode(TrigPin, OUTPUT);
}

void motorsOn(void) {
  digitalWrite(MotorPin1, HIGH);
  digitalWrite(MotorPin2, HIGH);
  delay(3000);
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, LOW);
}

float disMeasure(void)  {

  struct timeval tv1;
  struct timeval tv2;
  long time1, time2;
  float dis;

  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10); //send out ultrasonic pulses

  while(!(digitalRead(EchoPin) == 1));
  gettimeofday(&tv1, NULL); //get current time

  while(!(digitalRead(EchoPin) == 0));
  gettimeofday(&tv2, NULL); //get current time

  time1 = tv1.tv_sec * 1000000 + tv1.tv_usec; //microsecond time
  time2 = tv2.tv_sec * 1000000 + tv2.tv_usec;

  dis = (float)(time2 - time1) / 1000000 * 34000 / 2; //calculate the distance

  return dis;
}

int searchLeft(void)  {

  for (int i = 0; i <= 18; i++) {

    softPwmWrite(SERVOPIN, i);

    float dis = disMeasure();

    cout << dis << endl;
    
    if (dis <= 3)
      return 1;

    delay(200);

  }

return 0;

}

int searchRight(void) {

  for (int i = 18; i >= 0; i--) {

    softPwmWrite(SERVOPIN, i);

    float dis = disMeasure();

    if (dis <= 3)
      return 1;

    delay(200);

  }

  return 0;

}

int main(void) {
/*
  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n", strerror(errno));
    return 1;
  }
*/
  float dis;
  ultraInit();
  softPwmCreate(SERVOPIN, 0, 100);
  pinMode(RelayPin, OUTPUT);
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  digitalWrite(RelayPin, HIGH);
  int x;

  //asmprogram();

  while(1)  {
    
    cout << "test" << endl;
    
    x = searchLeft();
    
    if(x==1) {
      digitalWrite(MotorPin1, HIGH);
      digitalWrite(MotorPin2, HIGH);
      delay(3000);
    }

    delay(200);
    
    x = searchRight();

    if(x==1) {
      digitalWrite(MotorPin1, HIGH);
      digitalWrite(MotorPin2, HIGH);
      delay(3000);
    }

    delay(200);

    digitalWrite(MotorPin1, LOW);
    digitalWrite(MotorPin2, LOW);
  }

  digitalWrite(RelayPin, LOW);

  return 0;
}
