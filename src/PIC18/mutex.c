#include "mutex.h"
#include <malloc.h>
#include "PreemptiveOS.h"
#include "TCB.h"
#include "PriorityLinkedList.h"
extern TCB *runningTCB;

mutexData* initMutex()
{
	mutexData *newMutex = malloc(sizeof(mutexData));
	newMutex->count = 0;
	newMutex->state = UNLOCKED;
	newMutex->waitingQueue.head= NULL;
	newMutex->waitingQueue.tail= NULL;
	newMutex->owner = NULL;
	return newMutex;
}

int acquireMutex(mutexData * data)
{
	if(runningTCB == data->owner || data->owner ==NULL)
	{
		data->state =LOCKED;
		data->count++;
		data->owner = runningTCB;
		return 1;
	}
	else
	{
		addPriorityLinkedList(&data->waitingQueue,runningTCB);
		return 0;
	}
	
}

int releaseMutex(mutexData *data)
{
	if(runningTCB == data->owner)
	{
		
		data->count--;
		if(data->count==0)
		{
			data->owner = removeFromHeadPriorityLinkedList(&data->waitingQueue);
			if(data->owner ==NULL)
				data->state = UNLOCKED;
		}
	}
}