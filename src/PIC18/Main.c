
#include <stdio.h>
#include <stdlib.h>
#include "Blinky.h"
#include "Loopback.h"
#include "Clock.h"
//#include "LEDSM.h"
#include "Led2.h"
#include "SevenSeg.h"
#include "Tasking.h"
#include "Interrupt.h"
#include "PreemptiveOS.h"
#include "../18c.h"
#include "mutex.h"
#if !(defined(__XC) || defined(__18CXX))
  #include "usart.h"
  #include "spi.h"
  #include "timers.h"
#else
  #include <usart.h>
  #include <spi.h>
  #include <timers.h>
#endif // __18CXX

#pragma config OSC = INTIO67, PWRT = ON, WDT = OFF, LVP = OFF, DEBUG = ON
extern mutexData mutex1,mutex2;
#define setFreq8MHz() (OSCCONbits.IRCF = 7)

#define configureUsartTo8Bits9600Baud()\
          OpenUSART(USART_TX_INT_OFF &\
                    USART_RX_INT_OFF &\
                    USART_ASYNCH_MODE &\
                    USART_EIGHT_BIT &\
                    USART_CONT_RX &\
                    USART_BRGH_HIGH, 51);

void main(void) {
  int count;
  
  mutex1.count=0;
  mutex1.owner=NULL;
  mutex1.state=UNLOCKED;
  mutex1.waitingQueue.head = NULL;
  mutex1.waitingQueue.tail = NULL;

  mutex2.count=0;
  mutex2.owner=NULL;
  mutex2.state=UNLOCKED;
  mutex2.waitingQueue.head = NULL;
  mutex2.waitingQueue.tail = NULL;
  initPreemptiveMultitasking();
  initClock();
  while(1)
  {
      count++;
  }
}

void xmain(void) {
  Led2Data led2Data;
  SevenSegmentData sevenSegData;

  setFreq8MHz();
  configureUsartTo8Bits9600Baud();

  initClock();
  configureLED();
  initTasking(&led2Data);
  init7Segment(&sevenSegData);
  while(1) {
    led2SM(&led2Data);
    sevenSegmentSM(&sevenSegData);
  }
}
