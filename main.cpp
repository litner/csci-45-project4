#include <errno.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <wiringPi.h>

using namespace std;

int main(void) {
  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n", strerror(errno));
    return 1;
  }

asmprogram(); 

  return 0;
}
