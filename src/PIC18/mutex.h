#ifndef mutex_H
#define mutex_H
#include "PriorityLinkedList.h"
#include <stdio.h>



typedef enum {LOCKED,UNLOCKED}state;
typedef struct mutexData mutexData;
struct mutexData 
{
	state state;
	int count;
	TCB *owner; //AcquiredMutexTCB
	PriorityLinkedList waitingQueue;
};
extern mutexData mutex1,mutex2;
mutexData* initMutex();
void acquireMutex(mutexData * data);
int releaseMutex(mutexData * data);

#endif // mutex_H
