#include "unity.h"
#include "mutex.h"
#include <malloc.h>
#include "PreemptiveOS.h"
#include "TCB.h"
#include "PriorityLinkedList.h"

extern TCB *runningTCB;
extern PriorityLinkedList readyQueue;
extern int addStatus;
void setUp(void)
{
	readyQueue.head = NULL;
	readyQueue.tail = NULL;
	addStatus = 0;
	
}

void tearDown(void)
{
	
}

void test_initMutex_will_create_a_Mutex_and_initialized_its_data()
{
	mutexData *pointerToMutex=NULL;
	pointerToMutex = initMutex();
	TEST_ASSERT_NOT_NULL(pointerToMutex );
	TEST_ASSERT_EQUAL(0,pointerToMutex->count);
	TEST_ASSERT_EQUAL(UNLOCKED,pointerToMutex->state);
	TEST_ASSERT_NULL(pointerToMutex->waitingQueue.head);
	TEST_ASSERT_NULL(pointerToMutex->waitingQueue.tail);
	TEST_ASSERT_NULL(pointerToMutex->owner);
	free(pointerToMutex);
}

void test_acquireMutex_will_change_the_state_to_LOCKED(void)
{
	mutexData *firstMutex = initMutex();
	acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	free(firstMutex);
}

void test_acquireMutex_been_acquire_multiple_time_will_increase_the_count_number(void)
{
	mutexData *firstMutex = initMutex();
	acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	TEST_ASSERT_EQUAL(1,firstMutex->count);
	acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(2,firstMutex->count);
	acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(3,firstMutex->count);
	acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(4,firstMutex->count);
	acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(5,firstMutex->count);
	acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(6,firstMutex->count);
	free(firstMutex);
	
}

void test_acquireMutex_return_1_when_succcessfully_acquire(void)
{
	mutexData *firstMutex = initMutex();
	int status;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	TEST_ASSERT_EQUAL(1,status);
	free(firstMutex);
}

void test_acquireMutex_will_change_owner_to_the_runningTCB()
{
	
	mutexData *firstMutex = initMutex();
	TCB TCB1;
	runningTCB = &TCB1;
	int status;
	firstMutex->state =UNLOCKED;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,firstMutex->owner);
	free(firstMutex);
}

void test_acquireMutex_will_not_change_owner_for_different_TCB()
{
	mutexData *firstMutex = initMutex();
	TCB TCB1,TCB2;
	runningTCB = &TCB1;
	int status;
	firstMutex->state =UNLOCKED;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,firstMutex->owner);
	runningTCB = &TCB2;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,firstMutex->owner);
	free(firstMutex);
}

void test_acquireMutex_return_0_for_different_TCB()
{
	
	mutexData *firstMutex = initMutex();
	TCB TCB1,TCB2;
	runningTCB = &TCB1;
	int status;
	firstMutex->state =UNLOCKED;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,firstMutex->owner);
	runningTCB = &TCB2;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(0,status);
	free(firstMutex);


}

void test_acquireMutex_will_add_the_next_TCB_into_the_waiting_queue()
{
	mutexData *firstMutex = initMutex();
	TCB TCB1,TCB2;
	runningTCB = &TCB1;
	int status;
	firstMutex->state =UNLOCKED;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,firstMutex->owner);
	runningTCB = &TCB2;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB2,firstMutex->waitingQueue.head);
	free(firstMutex);
}

void test_acquireMutex_for_different_TCB_will_not_change_the_state_and_count()
{
	mutexData *firstMutex = initMutex();
	TCB TCB1,TCB2;
	
	int status;
	firstMutex->state =UNLOCKED;
	firstMutex->count =0;
	runningTCB = &TCB1;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,firstMutex->owner);
	runningTCB = &TCB2;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	TEST_ASSERT_EQUAL(1,firstMutex->count);
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	TEST_ASSERT_EQUAL(1,firstMutex->count);
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	TEST_ASSERT_EQUAL(1,firstMutex->count);
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	TEST_ASSERT_EQUAL(1,firstMutex->count);
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	TEST_ASSERT_EQUAL(1,firstMutex->count);
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	TEST_ASSERT_EQUAL(1,firstMutex->count);
	free(firstMutex);

}


void test_releaseMutex_been_call_multiple_time_will_further_decrease_the_number_of_count(void)
{
	mutexData *firstMutex = initMutex();
	TCB TCB1,TCB2;
	int i;
	
	int status;
	runningTCB = &TCB1;
	firstMutex->state =LOCKED;
	firstMutex->count =9;
	status = acquireMutex(firstMutex);
	releaseMutex(firstMutex);
	TEST_ASSERT_EQUAL(9,firstMutex->count);
	releaseMutex(firstMutex);
	TEST_ASSERT_EQUAL(8,firstMutex->count);
	releaseMutex(firstMutex);
	TEST_ASSERT_EQUAL(7,firstMutex->count);
	releaseMutex(firstMutex);
	TEST_ASSERT_EQUAL(6,firstMutex->count);
	releaseMutex(firstMutex);
	TEST_ASSERT_EQUAL(5,firstMutex->count);
	releaseMutex(firstMutex);
	TEST_ASSERT_EQUAL(4,firstMutex->count);
	free(firstMutex);
}

void test_releaseMutex_will_reset_owner_to_NULL()
{
	mutexData *firstMutex = initMutex();
	TCB TCB1,TCB2;
	
	int status;
	firstMutex->state =UNLOCKED;
	firstMutex->count =0;
	runningTCB = &TCB1;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,firstMutex->owner);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	TEST_ASSERT_EQUAL(1,firstMutex->count);
	status = releaseMutex(firstMutex);
	TEST_ASSERT_NULL(firstMutex->owner);
	TEST_ASSERT_EQUAL(UNLOCKED,firstMutex->state);
	free(firstMutex);
}

void test_releaseMutex_will_not_change_any_data_if_the_TCB_is_different()
{
	mutexData *firstMutex = initMutex();
	TCB TCB1,TCB2;
	int i;
	
	int status;
	firstMutex->state =UNLOCKED;
	firstMutex->count =0;
	runningTCB = &TCB1;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,firstMutex->owner);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	runningTCB = &TCB2;
	status = releaseMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,firstMutex->owner);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	free(firstMutex);
	
}

void test_releaseMutex_must_be_execute_same_time_with_the_acquireMutex_to_release_the_mutex()
{
	mutexData *firstMutex = initMutex();
	TCB TCB1,TCB2;
	
	int status;
	firstMutex->state =UNLOCKED;
	firstMutex->count =0;
	runningTCB = &TCB1;
	status = acquireMutex(firstMutex);
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,firstMutex->owner);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	status = releaseMutex(firstMutex);
	status = releaseMutex(firstMutex);
	TEST_ASSERT_NULL(firstMutex->owner);
	TEST_ASSERT_EQUAL(UNLOCKED,firstMutex->state);
	TEST_ASSERT_EQUAL(0,firstMutex->count);
	free(firstMutex);
}

void test_releaseMutex_will_not_release_the_mutex_if_the_it_does_not_execute_same_times_with_acqurie()
{
	mutexData *firstMutex = initMutex();
	TCB TCB1,TCB2;
	
	int status;
	firstMutex->state =UNLOCKED;
	firstMutex->count =0;
	runningTCB = &TCB1;
	status = acquireMutex(firstMutex);
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,firstMutex->owner);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	status = releaseMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB1,firstMutex->owner);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	TEST_ASSERT_EQUAL(1,firstMutex->count);
	free(firstMutex);
}

void test_releaseMutex_change_owner_to_the_second_TCB_if_its_tried_to_acquire_before()
{
	mutexData *firstMutex = initMutex();
	TCB TCB1,TCB2;
	
	int status;
	firstMutex->state =UNLOCKED;
	firstMutex->count =0;
	runningTCB = &TCB1;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(1,firstMutex->count);
	runningTCB = &TCB2;
	status = acquireMutex(firstMutex);
	TEST_ASSERT_EQUAL(1,firstMutex->count);
	TEST_ASSERT_EQUAL(&TCB1,firstMutex->owner);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	runningTCB = &TCB1;
	status = releaseMutex(firstMutex);
	TEST_ASSERT_EQUAL(&TCB2,firstMutex->owner);
	TEST_ASSERT_EQUAL(LOCKED,firstMutex->state);
	free(firstMutex);
}
