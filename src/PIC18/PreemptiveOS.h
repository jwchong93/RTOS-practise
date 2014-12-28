#ifndef PreemptiveOS_H
#define PreemptiveOS_H

#include "TCB.h"
#include "PriorityLinkedList.h"

extern TCB *runningTCB;
extern TCB allTCBs[3];
extern PriorityLinkedList readyQueue;

void initPreemptiveMultitasking(void);
TCB *loadANewTaskToRunningTCB(void);
#endif // PreemptiveOS_H
