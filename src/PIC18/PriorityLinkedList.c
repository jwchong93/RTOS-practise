#include "PriorityLinkedList.h"
#include <stdio.h>
void _addPriorityLinkedList(PriorityLinkedList *list,void *data,int compare(void *, void *)) 
{
	
	Element *temp =(Element*) data;
	Element *tempPointer=NULL;
	Element *previousPointer = NULL;
	temp ->next = NULL;
	if(list->head == NULL)
	{
		list->head = temp;
		list->tail = temp;
	}
	else
	{
		tempPointer = list->head;
		while(tempPointer!=NULL)
		{
			if(compare(temp,tempPointer))
			{
				if(tempPointer==list->head)
				{
					temp->next = list->head;
					list->head = temp;
					
					
				}
				else
				{
					previousPointer->next = temp;
					temp->next = tempPointer;
				}
				return;
				
			}
			previousPointer = tempPointer;
			tempPointer = tempPointer->next;
		}
		previousPointer->next = temp;
		list->tail = temp;
		
	}
		
}

void *removeFromHeadPriorityLinkedList(PriorityLinkedList *list) {
  Element *itemPointer = list->head;
  if(itemPointer != NULL) {
    list->head = itemPointer->next;
    if(itemPointer->next == NULL)
      list->tail = NULL;
  }
  return itemPointer;
}