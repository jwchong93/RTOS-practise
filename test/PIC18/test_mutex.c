#include "unity.h"
#include "mutex.h"
#include <malloc.h>
#include "PreemptiveOS.h"
#include "TCB.h"
#include "PriorityLinkedList.h"
extern PriorityLinkedList readyQueue;
extern TCB *runningTCB;
extern TCB *AcquiredMutexTCB;
void setUp(void)
{
}

void tearDown(void)
{
}

void test_initMutex_will_create_a_Mutex_and_initialized_its_data()
{
	mutexData *pointerToMutex=NULL;
	readyQueue.head = (void*)100;
	readyQueue.tail = (void*)100;
	pointerToMutex = initMutex();
	TEST_ASSERT_NOT_NULL(pointerToMutex );
	TEST_ASSERT_EQUAL(0,pointerToMutex->count);
	TEST_ASSERT_EQUAL(UNLOCKED,pointerToMutex->state);
	TEST_ASSERT_NULL(readyQueue.head);
	TEST_ASSERT_NULL(readyQueue.tail);
	TEST_ASSERT_NULL(AcquiredMutexTCB);
	free(pointerToMutex);
}

void test_acquireMutex_will_change_the_state_to_LOCKED(void)
{
	mutexData firstMutex;
	firstMutex.state =UNLOCKED;
	acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex.state);
}
void test_acquireMutex_been_acquire_multiple_time_will_increase_the_count_number(void)
{
	mutexData firstMutex;
	firstMutex.state =UNLOCKED;
	firstMutex.count =0;
	acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex.state);
	TEST_ASSERT_EQUAL(1,firstMutex.count);
	acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(2,firstMutex.count);
	acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(3,firstMutex.count);
	acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(4,firstMutex.count);
	acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(5,firstMutex.count);
	acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(6,firstMutex.count);
	
}

void test_acquireMutex_return_1_when_succcessfully_acquire(void)
{
	mutexData firstMutex;
	int status;
	firstMutex.state =UNLOCKED;
	status = acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex.state);
	TEST_ASSERT_EQUAL(1,status);
}

void test_acquireMutex_will_change_AcquiredMutexTCB_to_the_runningTCB()
{
	mutexData firstMutex;
	TCB TCB1;
	runningTCB = &TCB1;
	int status;
	firstMutex.state =UNLOCKED;
	status = acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,AcquiredMutexTCB);
	
}

void test_acquireMutex_will_not_change_AcquiredMutexTCB_for_different_TCB()
{
	mutexData firstMutex;
	TCB TCB1,TCB2;
	runningTCB = &TCB1;
	int status;
	firstMutex.state =UNLOCKED;
	status = acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,AcquiredMutexTCB);
	runningTCB = &TCB2;
	status = acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,AcquiredMutexTCB);
}

void test_acquireMutex_return_0_for_different_TCB()
{
	mutexData firstMutex;
	TCB TCB1,TCB2;
	runningTCB = &TCB1;
	int status;
	firstMutex.state =UNLOCKED;
	status = acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,AcquiredMutexTCB);
	runningTCB = &TCB2;
	status = acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(0,status);

}

void test_acquireMutex_will_add_the_next_TCB_into_the_waiting_queue()
{
	mutexData firstMutex;
	TCB TCB1,TCB2;
	runningTCB = &TCB1;
	int status;
	firstMutex.state =UNLOCKED;
	status = acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,AcquiredMutexTCB);
	runningTCB = &TCB2;
	status = acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL();
}

void test_releaseMutex_will_change_the_state_to_UNLOCKED(void)
{
	mutexData firstMutex;
	firstMutex.state =LOCKED;
	firstMutex.count =10;
	releaseMutex(&firstMutex);
	TEST_ASSERT_EQUAL(UNLOCKED,firstMutex.state);
	TEST_ASSERT_EQUAL(9,firstMutex.count);
	
}


void test_releaseMutex_been_call_multiple_time_will_further_decrease_the_number_of_count(void)
{
	mutexData firstMutex;
	firstMutex.state =LOCKED;
	firstMutex.count =10;
	releaseMutex(&firstMutex);
	TEST_ASSERT_EQUAL(UNLOCKED,firstMutex.state);
	TEST_ASSERT_EQUAL(9,firstMutex.count);
	releaseMutex(&firstMutex);
	TEST_ASSERT_EQUAL(8,firstMutex.count);
	releaseMutex(&firstMutex);
	TEST_ASSERT_EQUAL(7,firstMutex.count);
	releaseMutex(&firstMutex);
	TEST_ASSERT_EQUAL(6,firstMutex.count);
	releaseMutex(&firstMutex);
	TEST_ASSERT_EQUAL(5,firstMutex.count);
	releaseMutex(&firstMutex);
	TEST_ASSERT_EQUAL(4,firstMutex.count);
}



