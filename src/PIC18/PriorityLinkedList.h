#ifndef PriorityLinkedList_H
#define PriorityLinkedList_H

#include "TCB.h"

typedef struct Element Element;

struct Element {
  Element *next;
};

typedef struct PriorityLinkedList PriorityLinkedList;

struct PriorityLinkedList {
  Element *head;
  Element *tail;
};

void _addPriorityLinkedList(PriorityLinkedList *list,void *data,int compare(void *, void *));
                           
void *removeFromHeadPriorityLinkedList(PriorityLinkedList *list);

#endif // PriorityLinkedList_H