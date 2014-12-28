#include "mutex.h"
//#include <malloc.h>
#include "PreemptiveOS.h"
#include "TCB.h"
#include "PriorityLinkedList.h"
#include "Interrupt.h"
#include "../18c.h"
extern TCB *runningTCB;
extern PriorityLinkedList readyQueue;
mutexData mutex1,mutex2;
/*
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
*/
void acquireMutex(mutexData * data)
{
    TCB *newTCB;
    uint8 tosH;
    uint8 tosL;
    disableGlobalInterrupt();
    /*runningTCB == data->owner ||*/
	if(data->owner ==NULL)
	{
		data->state =LOCKED;
		data->count++;
		data->owner = runningTCB;
	}
	else
	{
            //addPriorityLinkedList(&(data->waitingQueue),runningTCB);//Manual testing
            newTCB = removeFromHeadPriorityLinkedList(&readyQueue);
            addPriorityLinkedList(&data->waitingQueue,runningTCB); //TDD passed
            runningTCB = newTCB;
            tosL = runningTCB->task;
            tosH = (runningTCB->task)>>8;
            FSR1 = runningTCB->stackPointer;
            FSR1H = runningTCB->stackPointer>>8;
            TOSH=tosH;
            TOSL=tosL;


/*
_asm
movff   tosH, WREG
movwf   TOSH, ACCESS
movff   tosL, WREG
movwf   TOSL, ACCESS
_endasm
*/

	}
    enableGlobalInterrupt();
	
}

int releaseMutex(mutexData *data)
{
	TCB * tempData =NULL;
        TCB *newTCB;
        int number;
        uint8 tosH;
        uint8 tosL;
        disableGlobalInterrupt();
	if(runningTCB == data->owner)
	{
		
		data->count--;
		if(data->count==0)
		{
                    addPriorityLinkedList(&readyQueue,runningTCB);
                    runningTCB = removeFromHeadPriorityLinkedList(&data->waitingQueue);
                    
                    tosL = runningTCB->task;
                    tosH = (runningTCB->task)>>8;
                    FSR1 = runningTCB->stackPointer;
                    FSR1H = runningTCB->stackPointer>>8;
                    TOSH=tosH;
                    TOSL=tosL;
                    data->owner =NULL;
		}
	}
        enableGlobalInterrupt();
}