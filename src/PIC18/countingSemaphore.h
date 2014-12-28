#ifndef countingSemaphore_H
#define countingSemaphore_H

#include "PriorityLinkedList.h"
typedef struct semaphoreData semaphoreData;
struct semaphoreData 
{

	int count;
	int maxCount;
	PriorityLinkedList waitingQueue;
};

semaphoreData* initSemaphore(int numberOfTheSemaphore);
int acquireSemaphore(semaphoreData * data);
int releaseSemaphore(semaphoreData * data);
#endif // countingSemaphore_H
