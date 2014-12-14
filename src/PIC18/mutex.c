#include "mutex.h"
#include <malloc.h>
#include "PreemptiveOS.h"
#include "TCB.h"
#include "PriorityLinkedList.h"
PriorityLinkedList waitingQueue;
extern TCB *runningTCB;
TCB *AcquiredMutexTCB;
// PriorityLinkedList waitingQueue;
// TCB runningTCB;

mutexData* initMutex()
{
	mutexData *newMutex = malloc(sizeof(mutexData));
	newMutex->count = 0;
	newMutex->state = UNLOCKED;
	readyQueue.head=NULL;
	readyQueue.tail=NULL;
	AcquiredMutexTCB = NULL;
	return newMutex;
}

int acquireMutex(mutexData * data)
{
	if(runningTCB == AcquiredMutexTCB || AcquiredMutexTCB ==NULL)
	{
		data->state =LOCKED;
		data->count++;
		AcquiredMutexTCB = runningTCB;
		return 1;
	}
	else
	{
		addPriorityLinkedList(&waitingQueue,runningTCB);
		return 0;
	}
	
}

int releaseMutex(mutexData *data)
{
	if(runningTCB == AcquiredMutexTCB)
	{
		
		data->count--;
		if(data->count==0)
		{
			AcquiredMutexTCB = NULL;
			data->state = UNLOCKED;
		}
	}
}