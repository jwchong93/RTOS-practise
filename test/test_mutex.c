#include "unity.h"
#include "mutex.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_acquireMutex_will_change_the_status_of_the_data_to_1_which_indicate_acquired(void)
{
	mutexData firstMutex;
	firstMutex.status =0; //Make sure the initial data will fail the program
	acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(1,firstMutex.status);
}

void test_acquireMutex_will_increase_the_count_when_the_function_call_the_aquisition(void)
{
	mutexData firstMutex;
	firstMutex.count =0; //Make sure the initial data will fail the program
	acquireMutex(&firstMutex);
	TEST_ASSERT_EQUAL(1,firstMutex.count);
}
