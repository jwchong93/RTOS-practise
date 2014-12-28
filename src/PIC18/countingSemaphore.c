#include "countingSemaphore.h"
#include <malloc.h>
#include "PreemptiveOS.h"
#include "TCB.h"
#include "PriorityLinkedList.h"

extern TCB *runningTCB;
semaphoreData* initSemaphore(int numberOfTheSemaphore)
{
	semaphoreData *newSemaphore = malloc(sizeof(semaphoreData));
	newSemaphore->count = numberOfTheSemaphore;
	newSemaphore->maxCount = numberOfTheSemaphore;
	newSemaphore->waitingQueue.head = NULL;
	newSemaphore->waitingQueue.tail = NULL;
	return newSemaphore;
}

int acquireSemaphore(semaphoreData * data)
{
	data->count--;
	if(data->count<0)
	{
		addPriorityLinkedList(&data->waitingQueue,runningTCB);
		return 0;
	}
	
	return 1;
}

int releaseSemaphore(semaphoreData * data)
{
		
		if(data->count==0)
		{
			if(data->waitingQueue.head!=NULL)
			{
				runningTCB = removeFromHeadPriorityLinkedList(&data->waitingQueue);
			}
			else
			{
				data->count++;
			}
		}
		else
		{
			if(data->count<data->maxCount)
			{
				data->count++;
			}
		}
}