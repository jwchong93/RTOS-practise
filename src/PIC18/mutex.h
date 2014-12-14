#ifndef mutex_H
#define mutex_H
#include "PriorityLinkedList.h"
#include <stdio.h>



typedef enum {LOCKED,UNLOCKED}state;
typedef struct mutexData mutexData;
struct mutexData 
{
	int state;
	int count;
	PriorityLinkedList waitingList;
	
};

mutexData* initMutex();
int acquireMutex(mutexData * data);
int releaseMutex(mutexData * data);

#endif // mutex_H