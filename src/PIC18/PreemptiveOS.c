#include <stdio.h>
#include <stdlib.h>

#include "PreemptiveOS.h"
#include "TCB.h"
#include "PriorityLinkedList.h"


#if !(defined(__XC) || defined(__18CXX))
  #include "usart.h"
  #include "spi.h"
  #include "timers.h"
#else
  #include <usart.h>
  #include <spi.h>
  #include <timers.h>
#endif // __18CXX

void taskOne(void);
void taskTwo(void);

TCB *runningTCB;
TCB allTCBs[3];

PriorityLinkedList readyQueue;
#pragma udata BIGDATA
uint8 stacks[2][250];
#pragma udata

void createTask(TCB TCBs[], int index, void(*task)(void)) {
    TCBs[index].next = NULL;
    TCBs[index].priority = 0;
    TCBs[index].task = (uint16)task;
    TCBs[index].stackPointer = (int)&stacks[index-1];
    addPriorityLinkedList(&readyQueue, &allTCBs[index]);
}

void initPreemptiveMultitasking(void) {
    readyQueue.head=NULL;
    readyQueue.tail=NULL;
    runningTCB = &allTCBs[0];
    runningTCB->next = NULL;
    runningTCB->priority = 0;
    createTask(allTCBs, 1, taskOne);
    createTask(allTCBs, 2, taskTwo);
}

void taskOne(void) {
    int count1 = 0;
    while(1) {
        count1++;
    }
}

void taskTwo(void) {
    int count2 = 255;
    while(1) {
        count2--;
    }
}