#include "unity.h"

#include "PriorityLinkedList.h"
#include "TCB.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_comparePriority_will_return_1_when_the_inserted_element_have_a_largert_priority(void)
{
	int result=0;
	TCB insertData;
	TCB dataInList;
	insertData.priority = 1;
	dataInList.priority = 50;
	result = comparePriority(&insertData,&dataInList);
	TEST_ASSERT_EQUAL(1,result);
}

void test_comparePriority_will_return_0_when_the_inserted_element_have_a_lower_priority(void)
{
	int result=0;
	TCB insertData;
	TCB dataInList;
	insertData.priority = 100;
	dataInList.priority = 50;
	result = comparePriority(&insertData,&dataInList);
	TEST_ASSERT_EQUAL(0,result);
}

void test_addPriorityLinkedList_will_store_the_address_of_the_TCB_into_the_head_of_the_list()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData;
	newTestData.priority = 50;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData);
	TEST_ASSERT_EQUAL(&newTestData,testList.head);
	TEST_ASSERT_EQUAL(&newTestData,testList.tail);
	TEST_ASSERT_NULL(testList.tail->next);
	TEST_ASSERT_NULL(testList.head->next);
}


void test_addPriorityLinkedList_will_store_the_address_after_the_first_element()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	newTestData1.priority = 30;
	newTestData2.priority = 50;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head);
	TEST_ASSERT_EQUAL(&newTestData2,testList.head->next);
	
}


void test_addPriorityLinkedList_will_store_the_address_before_the_first_element()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	newTestData1.priority = 50;
	newTestData2.priority = 30;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	TEST_ASSERT_EQUAL(&newTestData2,testList.head);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head->next);
	
}

void test_addPriorityLinkedList_will_store_the_address_after_the_first_element_if_the_priority_is_the_same()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	newTestData1.priority = 50;
	newTestData2.priority = 50;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head);
	TEST_ASSERT_EQUAL(&newTestData2,testList.head->next);
	
}


void test_addPriorityLinkedList_will_store_the_address_after_the_last_elements()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	TCB newTestData4;
	newTestData1.priority = 50;
	newTestData2.priority = 50;
	newTestData3.priority = 50;
	newTestData4.priority = 50;
	
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	addPriorityLinkedList(&testList,&newTestData4);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head);
	TEST_ASSERT_EQUAL(&newTestData2,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head->next->next);
	TEST_ASSERT_EQUAL(&newTestData4,testList.head->next->next->next);
	
}

void test_addPriorityLinkedList_will_store_the_address_after_the_first_two_elements()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	newTestData1.priority = 50;
	newTestData2.priority = 30;
	newTestData3.priority = 80;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	TEST_ASSERT_EQUAL(&newTestData2,testList.head);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head->next->next);
	
}

void test_addPriorityLinkedList_will_store_the_address_after_the_first_three_elements()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	TCB newTestData4;
	newTestData1.priority = 50;
	newTestData2.priority = 30;
	newTestData3.priority = 80;
	newTestData4.priority = 100;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	addPriorityLinkedList(&testList,&newTestData4);
	TEST_ASSERT_EQUAL(&newTestData2,testList.head);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head->next->next);
	TEST_ASSERT_EQUAL(&newTestData4,testList.head->next->next->next);
	TEST_ASSERT_NULL(testList.head->next->next->next->next);
	TEST_ASSERT_EQUAL(testList.tail,testList.head->next->next->next);
	
}

void test_addPriorityLinkedList_will_store_the_address_before_the_first_two_elements()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	newTestData1.priority = 50;
	newTestData2.priority = 30;
	newTestData3.priority = 20;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head);
	TEST_ASSERT_EQUAL(&newTestData2,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head->next->next);
	TEST_ASSERT_EQUAL(testList.tail,testList.head->next->next);
	
}

void test_addPriorityLinkedList_will_store_the_address_in_between_the_two_elements()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	newTestData1.priority = 50;
	newTestData2.priority = 30;
	newTestData3.priority = 40;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	TEST_ASSERT_EQUAL(&newTestData2,testList.head);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head->next->next);
	TEST_ASSERT_EQUAL(testList.tail,testList.head->next->next);
	
	
}

void test_addPriorityLinkedList_will_store_the_address_in_after_the_first_two_elements_before_the_last_element()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	TCB newTestData4;
	newTestData1.priority = 50;
	newTestData2.priority = 30;
	newTestData3.priority = 40;
	newTestData4.priority = 45;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	addPriorityLinkedList(&testList,&newTestData4);
	TEST_ASSERT_EQUAL(&newTestData2,testList.head);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData4,testList.head->next->next);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head->next->next->next);
	TEST_ASSERT_EQUAL(testList.tail,testList.head->next->next->next);
	
}
/*
void test_removePriorityLinkedList_will_remove_the_target_element()
{
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	TCB newTestData4;
	void *returnedElement = NULL;
	newTestData1.priority = 50;
	newTestData2.priority = 30;
	newTestData3.priority = 40;
	newTestData4.priority = 45;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	addPriorityLinkedList(&testList,&newTestData4);
	returnedElement = removePriorityLinkedList(&testList,&newTestData4);
	TEST_ASSERT_NOT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData4,returnedElement);
	TEST_ASSERT_EQUAL(&newTestData2,testList.head);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head->next->next);
	TEST_ASSERT_EQUAL(testList.tail,testList.head->next->next);
}

void test_removePriorityLinkedList_will_remove_the_first_element()
{
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	TCB newTestData4;
	void *returnedElement = NULL;
	newTestData1.priority = 50;
	newTestData2.priority = 30;
	newTestData3.priority = 40;
	newTestData4.priority = 45;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	addPriorityLinkedList(&testList,&newTestData4);
	returnedElement = removePriorityLinkedList(&testList,&newTestData2);
	TEST_ASSERT_NOT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData2,returnedElement);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head);
	TEST_ASSERT_EQUAL(&newTestData4,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head->next->next);
	TEST_ASSERT_EQUAL(testList.tail,testList.head->next->next);
}

void test_removePriorityLinkedList_will_remove_the_last_element()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	TCB newTestData4;
	void *returnedElement = NULL;
	newTestData1.priority = 50;
	newTestData2.priority = 30;
	newTestData3.priority = 40;
	newTestData4.priority = 45;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	addPriorityLinkedList(&testList,&newTestData4);
	returnedElement = removePriorityLinkedList(&testList,&newTestData1);
	TEST_ASSERT_NOT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData1,returnedElement);
	TEST_ASSERT_EQUAL(&newTestData2,testList.head);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData4,testList.head->next->next);
	TEST_ASSERT_EQUAL(testList.tail,testList.head->next->next);
	
}

void test_removePriorityLinkedList_will_return_NULL_if_the_element_is_not_being_in_the_list()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	TCB newTestData4;
	TCB newTestData5;
	void *returnedElement = (void*)1000;
	newTestData1.priority = 50;
	newTestData2.priority = 30;
	newTestData3.priority = 40;
	newTestData4.priority = 45;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	addPriorityLinkedList(&testList,&newTestData4);
	returnedElement = removePriorityLinkedList(&testList,&newTestData5);
	TEST_ASSERT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData2,testList.head);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData4,testList.head->next->next);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head->next->next->next);
	TEST_ASSERT_EQUAL(testList.tail,testList.head->next->next->next);
	
}

void test_removePriorityLinkedList_will_remove_the_only_element_inside_the_list()
{
	PriorityLinkedList testList;
	TCB newTestData;
	newTestData.priority = 50;
	void *returnedElement = NULL;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData);
	TEST_ASSERT_EQUAL(&newTestData,testList.head);
	TEST_ASSERT_EQUAL(&newTestData,testList.tail);
	TEST_ASSERT_NULL(testList.tail->next);
	TEST_ASSERT_NULL(testList.head->next);
	
	returnedElement = removePriorityLinkedList(&testList,&newTestData);
	TEST_ASSERT_NOT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData,returnedElement);
	TEST_ASSERT_NULL(testList.tail);
	TEST_ASSERT_NULL(testList.head);
}
*/

void test_removeFromHeadPriorityLinkedList_will_return_the_first_element()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	TCB newTestData4;
	void * returnedElement=NULL;
	newTestData1.priority = 50;
	newTestData2.priority = 30;
	newTestData3.priority = 40;
	newTestData4.priority = 45;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	addPriorityLinkedList(&testList,&newTestData4);
	
	TEST_ASSERT_EQUAL(&newTestData2,testList.head);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData4,testList.head->next->next);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head->next->next->next);
	TEST_ASSERT_EQUAL(testList.tail,testList.head->next->next->next);
	
	returnedElement = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_NOT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData2,returnedElement);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head);
	TEST_ASSERT_EQUAL(&newTestData4,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head->next->next);
	TEST_ASSERT_EQUAL(testList.tail,testList.head->next->next);
	
}

void test_removeFromHeadPriorityLinkedList_will_return_the_accordingly()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	TCB newTestData4;
	void * returnedElement=NULL;
	newTestData1.priority = 50;
	newTestData2.priority = 30;
	newTestData3.priority = 40;
	newTestData4.priority = 45;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	addPriorityLinkedList(&testList,&newTestData4);
	
	TEST_ASSERT_EQUAL(&newTestData2,testList.head);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData4,testList.head->next->next);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head->next->next->next);
	TEST_ASSERT_EQUAL(testList.tail,testList.head->next->next->next);
	
	returnedElement = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_NOT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData2,returnedElement);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head);
	TEST_ASSERT_EQUAL(&newTestData1,testList.tail);
	returnedElement = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_NOT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData3,returnedElement);
	TEST_ASSERT_EQUAL(&newTestData4,testList.head);
	TEST_ASSERT_EQUAL(&newTestData1,testList.tail);
	returnedElement = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_NOT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData4,returnedElement);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head);
	TEST_ASSERT_EQUAL(&newTestData1,testList.tail);
	returnedElement = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_NOT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData1,returnedElement);
	TEST_ASSERT_NULL(testList.head);
	TEST_ASSERT_NULL(testList.tail);
	
	
}

void test_removeFromHeadPriorityLinkedList_will_return_the_correct_task_data()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	uint8 A,B;
	A = 0x80;
	B = 0x00;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	TCB newTestData4;
	void * returnedElement=NULL;
	newTestData1.priority = 50;
	newTestData1.task = 0x1000;
	newTestData2.priority = 30;
	newTestData2.task = ((((uint16)A)<<8)|B);
	newTestData3.priority = 40;
	newTestData3.task = 0x3000;
	newTestData4.priority = 45;
	newTestData4.task = 0x4000;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	addPriorityLinkedList(&testList,&newTestData4);
	
	TEST_ASSERT_EQUAL(&newTestData2,testList.head);
	TEST_ASSERT_EQUAL(&newTestData3,testList.head->next);
	TEST_ASSERT_EQUAL(&newTestData4,testList.head->next->next);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head->next->next->next);
	TEST_ASSERT_EQUAL(testList.tail,testList.head->next->next->next);
	
	returnedElement = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_NOT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData2,returnedElement);
	TEST_ASSERT_EQUAL(30,((TCB*)returnedElement)->priority);
	TEST_ASSERT_EQUAL(0x8000,((TCB*)returnedElement)->task);
	
	B=(uint8)(((TCB*)returnedElement)->task>>8); //Does not assign the real address*
    A=(uint8)(((TCB*)returnedElement)->task);
	
	TEST_ASSERT_EQUAL(0x80,B);
	TEST_ASSERT_EQUAL(0x00,A);
	
	TEST_ASSERT_EQUAL(&newTestData3,testList.head);
	TEST_ASSERT_EQUAL(&newTestData1,testList.tail);
	returnedElement = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_NOT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData3,returnedElement);
	TEST_ASSERT_EQUAL(40,((TCB*)returnedElement)->priority);
	// TEST_ASSERT_EQUAL(0x3000,((TCB*)returnedElement)->task);
	TEST_ASSERT_EQUAL(&newTestData4,testList.head);
	TEST_ASSERT_EQUAL(&newTestData1,testList.tail);
	returnedElement = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_NOT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData4,returnedElement);
	TEST_ASSERT_EQUAL(45,((TCB*)returnedElement)->priority);
	// TEST_ASSERT_EQUAL(0x4000,((TCB*)returnedElement)->task);
	TEST_ASSERT_EQUAL(&newTestData1,testList.head);
	TEST_ASSERT_EQUAL(&newTestData1,testList.tail);
	returnedElement = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_NOT_NULL(returnedElement);
	TEST_ASSERT_EQUAL(&newTestData1,returnedElement);
	TEST_ASSERT_EQUAL(50,((TCB*)returnedElement)->priority);
	// TEST_ASSERT_EQUAL(0x1000,((TCB*)returnedElement)->task);
	TEST_ASSERT_NULL(testList.head);
	TEST_ASSERT_NULL(testList.tail);
	
	
}

void test_removeFromHeadPriorityLinkedList_will_return_the_last_insert_value()
{
	//Make sure the element is added to the list 
	PriorityLinkedList testList;
	TCB newTestData1;
	TCB newTestData2;
	TCB newTestData3;
	TCB newTestData4;
	TCB * returnedElement=NULL;
	TCB * returnedElement2=NULL;
	void * returnedAnswer=NULL;
	newTestData1.priority = 50;
	newTestData2.priority = 30;
	newTestData3.priority = 30;
	newTestData4.priority = 45;
	newTestData1.task = 0x1000;
	newTestData2.task = 0x2000;
	newTestData3.task = 0x3000;
	newTestData4.task = 0x4000;
	testList.head = NULL;
	testList.tail = NULL;
	addPriorityLinkedList(&testList,&newTestData1);
	addPriorityLinkedList(&testList,&newTestData2);
	addPriorityLinkedList(&testList,&newTestData3);
	addPriorityLinkedList(&testList,&newTestData4);
	
	returnedAnswer = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_EQUAL(&newTestData2,returnedAnswer);
	
	
	returnedElement = (TCB*)returnedAnswer;
	TEST_ASSERT_EQUAL(0x2000,returnedElement->task);
	returnedAnswer = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_EQUAL(&newTestData3,returnedAnswer);
	addPriorityLinkedList(&testList,returnedElement);
	
	returnedElement2 = (TCB*)returnedAnswer;
	TEST_ASSERT_EQUAL(0x3000,returnedElement2->task);
	returnedAnswer = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_EQUAL(&newTestData2,returnedAnswer);
	addPriorityLinkedList(&testList,returnedElement2);
	
	returnedElement = (TCB*)returnedAnswer;
	TEST_ASSERT_EQUAL(0x2000,returnedElement->task);
	returnedAnswer = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_EQUAL(&newTestData3,returnedAnswer);
	addPriorityLinkedList(&testList,returnedElement);
	
	returnedElement = (TCB*)returnedAnswer;
	TEST_ASSERT_EQUAL(0x3000,returnedElement->task);
	returnedAnswer = removeFromHeadPriorityLinkedList(&testList);
	TEST_ASSERT_EQUAL(&newTestData2,returnedAnswer);
	
}







