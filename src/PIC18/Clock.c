#include "Clock.h"
#include "Interrupt.h"
#include "PreemptiveOS.h"
#include "TCB.h"
#include "../18c.h"
#if !(defined(__XC) || defined(__18CXX))
  #include "timers.h"
#else
  #include <timers.h>
#endif // __18CXX

volatile unsigned long clock;
uint8 workingReg, bankSelectReg, statusReg, tosH, tosL;
uint16 task, stackPointer;

#pragma code high_vector = 0x08
void highPriorityIsr(void) {
  _asm
  goto timer0Isr
  _endasm
}
#pragma code

#pragma interruptlow timer0Isr save=FSR2L
void timer0Isr(void) {
    TCB *newTCB;
    
    tosH = TOSH;
    tosL = TOSL;
  
    task = ((uint16)tosH)<<8 | tosL;
    runningTCB->task = task;
    runningTCB->stackPointer = (uint16)FSR1H<<8 | FSR1;
    
    newTCB = removeFromHeadPriorityLinkedList(&readyQueue);
    addPriorityLinkedList(&readyQueue, runningTCB);
    runningTCB = newTCB;
    tosL = runningTCB->task;
    tosH = (runningTCB->task)>>8;
    FSR1 = runningTCB->stackPointer;
    FSR1H = runningTCB->stackPointer>>8;



_asm
    movff   tosH, WREG
    movwf   TOSH, ACCESS
    movff   tosL, WREG
    movwf   TOSL, ACCESS
_endasm


    clearTimer0Overflowed();
   
}

void initClock(void) {
  clock = 0;
  enableGlobalInterrupt();
  OpenTimer0( TIMER_INT_ON &
              T0_8BIT &
              T0_SOURCE_INT &
              T0_PS_1_8);
}

/**
 * Return the micro-controller's clock since power-up.
 * 1 clock means 1.024 msec.
 */
unsigned long getClock(void) {
  /*
  if(hasTimer0Overflowed()) {
    clearTimer0Overflowed();
    clock++;
  }
  */
  return clock;
}

/////////////////////////////////////////
// These functions are for internal use
/////////////////////////////////////////
char hasTimer0Overflowed(void) {
  return INTCONbits.TMR0IF;
}

void clearTimer0Overflowed(void) {
  INTCONbits.TMR0IF = 0;
}
