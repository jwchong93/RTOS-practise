#include "TCB.h"

/***********************************************************************************************
	Compare the priority of two TCB
	input: 	void *elementToInsert     	->The element that going to be insert
			void *elementInTheList		->The element that being in the list
			
	return:	1							->The inserted element have a higher priority
			0							->The inserted element have a lower priority
			
	Example: Inserted element contain priority of 1 and the list element contain priority of 2
			comparePriority(void *elementToInsert, void *elementInTheList) will return **1** 
			
	Priority grade:
	Lower number contain higher priority
					1,2,3,4,......,n
					High--------->Low 
*************************************************************************************************/

int comparePriority(void *elementToInsert, void *elementInTheList)
{
	TCB *insertElement;
	TCB *listElement;
	insertElement = (TCB *)elementToInsert;
	listElement = (TCB *)elementInTheList;
	if(insertElement->priority<listElement->priority)
	return 1;
	else
	return 0;
}

int compareAddressAndRemove(void *elementToInsert, void *elementInTheList)
{
	if(elementToInsert==elementInTheList)
	return 1;
	else
	return 0;
}