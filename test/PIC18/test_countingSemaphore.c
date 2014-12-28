#include "unity.h"
#include "countingSemaphore.h"
#include <malloc.h>
#include "PreemptiveOS.h"
#include "TCB.h"
#include "PriorityLinkedList.h"

extern TCB *runningTCB;
void setUp(void)
{
}

void tearDown(void)
{
}
void test_initSemaphore_will_initialize_the_data_inside_the_structure_accrodingly(void)
{
	semaphoreData *testSemaphore = initSemaphore(5);
	TEST_ASSERT_EQUAL(5,testSemaphore->count);
	TEST_ASSERT_EQUAL(5,testSemaphore->maxCount);
	TEST_ASSERT_NULL(testSemaphore->waitingQueue.head);
	TEST_ASSERT_NULL(testSemaphore->waitingQueue.tail);
	free(testSemaphore);
}
void test_acquireSemaphore_will_decrease_the_count_and_remain_the_MaxCount(void)
{
	semaphoreData *testSemaphore = initSemaphore(5);
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(4,testSemaphore->count);
	TEST_ASSERT_EQUAL(5,testSemaphore->maxCount);
	free(testSemaphore);
}

void test_acquireSemaphore_will_decrease_the_count_respective_to_the_acquisition_called(void)
{
	semaphoreData *testSemaphore = initSemaphore(5);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(0,testSemaphore->count);
	TEST_ASSERT_EQUAL(5,testSemaphore->maxCount);
	free(testSemaphore);
}

void test_acquireSemaphore_change_the_count_into_negative_value_and_add_the_TCB_into_the_waitingQueue(void)
{
	semaphoreData *testSemaphore = initSemaphore(1);
	TCB TCB1,TCB2;
	runningTCB =&TCB1;
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(0,testSemaphore->count);
	runningTCB =&TCB2;
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(-1,testSemaphore->count);
	TEST_ASSERT_EQUAL(&TCB2,testSemaphore->waitingQueue.head);
	free(testSemaphore);
}

void test_acquireSemaphore_will_return_1_if_aquire_semaphore_successfully(void)
{
	semaphoreData *testSemaphore = initSemaphore(1);
	int status=1233;
	status = acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(1,status);
	free(testSemaphore);
}

void test_acquireSemaphore_will_return_0_if_aquire_semaphore_failed_and_go_to_the_waitingQueue(void)
{
	semaphoreData *testSemaphore = initSemaphore(0);
	int status=1233;
	status = acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(0,status);
	free(testSemaphore);
}

void test_acquireSemaphore_further_decrease_the_semaphore_count_and_add_the_third_TCB_into_waitingQUeue()
{
	semaphoreData *testSemaphore = initSemaphore(1);
	TCB TCB1,TCB2,TCB3;
	runningTCB =&TCB1;
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(0,testSemaphore->count);
	runningTCB =&TCB2;
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(-1,testSemaphore->count);
	TEST_ASSERT_EQUAL(&TCB2,testSemaphore->waitingQueue.head);
	runningTCB =&TCB3;
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(-2,testSemaphore->count);
	TEST_ASSERT_EQUAL(&TCB2,testSemaphore->waitingQueue.head);
	TEST_ASSERT_EQUAL(&TCB3,testSemaphore->waitingQueue.head->next);
	free(testSemaphore);
}

void test_releaseSemaphore_will_increase_the_semaphore_count()
{
	semaphoreData *testSemaphore = initSemaphore(1);
	TCB TCB1,TCB2,TCB3;
	runningTCB =&TCB1;
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(-4,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(-3,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(-2,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(-1,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(0,testSemaphore->count);
}

void test_releaseSemaphore_change_the_runningTCB_to_TCB2_when_TCB1_when_there_are_semaphore_available()
{
	semaphoreData *testSemaphore = initSemaphore(1);
	TCB TCB1,TCB2,TCB3;
	runningTCB =&TCB1;
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(0,testSemaphore->count);
	runningTCB =&TCB2;
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(-1,testSemaphore->count);
	TEST_ASSERT_EQUAL(&TCB2,testSemaphore->waitingQueue.head);
	runningTCB =&TCB3;
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(-2,testSemaphore->count);
	TEST_ASSERT_EQUAL(&TCB2,testSemaphore->waitingQueue.head);
	TEST_ASSERT_EQUAL(&TCB3,testSemaphore->waitingQueue.head->next);
	runningTCB = &TCB1;
	releaseSemaphore(testSemaphore);
	releaseSemaphore(testSemaphore);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(0,testSemaphore->count);
	TEST_ASSERT_EQUAL(&TCB2,runningTCB);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(0,testSemaphore->count);
	TEST_ASSERT_EQUAL(&TCB3,runningTCB);
	free(testSemaphore);
}


void test_releaseSemaphore_will_not_increase_the_semaphore_count_more_than_the_maxCount()
{
	semaphoreData *testSemaphore = initSemaphore(1);
	TCB TCB1,TCB2,TCB3;
	runningTCB =&TCB1;
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(0,testSemaphore->count);
	runningTCB =&TCB2;
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(-1,testSemaphore->count);
	TEST_ASSERT_EQUAL(&TCB2,testSemaphore->waitingQueue.head);
	runningTCB =&TCB3;
	acquireSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(-2,testSemaphore->count);
	TEST_ASSERT_EQUAL(&TCB2,testSemaphore->waitingQueue.head);
	TEST_ASSERT_EQUAL(&TCB3,testSemaphore->waitingQueue.head->next);
	runningTCB = &TCB1;
	releaseSemaphore(testSemaphore);
	releaseSemaphore(testSemaphore);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(0,testSemaphore->count);
	TEST_ASSERT_EQUAL(&TCB2,runningTCB);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(0,testSemaphore->count);
	TEST_ASSERT_EQUAL(&TCB3,runningTCB);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(testSemaphore->maxCount,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(testSemaphore->maxCount,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(testSemaphore->maxCount,testSemaphore->count);
	free(testSemaphore);
}

void test_releaseSemaphore_will_keep_increase_the_semaphore_count()
{
	semaphoreData *testSemaphore = initSemaphore(10);
	TCB TCB1,TCB2,TCB3;
	runningTCB =&TCB1;
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	acquireSemaphore(testSemaphore);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(1,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(2,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(3,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(4,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(5,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(6,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(7,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(8,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(9,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(10,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(testSemaphore->maxCount,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(testSemaphore->maxCount,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(testSemaphore->maxCount,testSemaphore->count);
	releaseSemaphore(testSemaphore);
	TEST_ASSERT_EQUAL(testSemaphore->maxCount,testSemaphore->count);
	
}






