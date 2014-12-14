#ifndef TCB_H
#define TCB_H
//TCB(Task Control Block)

#if !(defined(_XC) || defined(__18CXX))
typedef char 				int8;
typedef short int			int16;
typedef int                             int32; //Pic18 is long
typedef unsigned char                   uint8;
typedef unsigned short int              uint16; //For pic18 this do not have short
typedef unsigned int                    uint32;
#else
typedef char 				int8;
typedef int                         	int16;
typedef long				int32;
typedef unsigned char                   uint8;
typedef unsigned int                    uint16;
typedef unsigned long                   uint32;
#endif


typedef struct TCB TCB;
struct TCB
{
	TCB *next;
	char priority;
	int taskId; //For debugging purpose
	//char PC[3];
	uint16 stackPointer;
	uint16 framePointer;
	//char Status;
	//char Bsr;
	//char WorkingRegister;
	//void (*task)(void);
        uint16 task;
};

int comparePriority(void *elementToInsert, void *elementInTheList);
int compareAddressAndRemove(void *elementToInsert, void *elementInTheList);

//Create a macro to utilize the function call
#define		addPriorityLinkedList(x,y)		_addPriorityLinkedList(x,y,comparePriority)
#define		removePriorityLinkedList(x,y)	_removePriorityLinkedList(x,y,compareAddressAndRemove)

#endif