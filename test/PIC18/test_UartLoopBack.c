#include "unity.h"
#include "UartLoopBack.h"
#include "mock_usart.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_uartLoopBackSM_given_WAIT_DATA_should_change_to_next_state(void)
{
	LoopBackData data;
	data.state = WAIT_DATA;
	DataRdyUSART_ExpectAndReturn(1);
	getcUSART_ExpectAndReturn(0x5a);
	uartLoopBackSM(&data);
	TEST_ASSERT_EQUAL(WAIT_FOR_TX,data.state);
}

void test_uartLoopBackSM_given_WAIT_DATA_and_byte_arrive_should_read_and_transition_to_WAIT_FOR_TX(void)
{
	LoopBackData data;
	data.state = WAIT_DATA;
	DataRdyUSART_ExpectAndReturn(1);
	getcUSART_ExpectAndReturn(0x5a);
	uartLoopBackSM(&data);
	TEST_ASSERT_EQUAL(WAIT_FOR_TX,data.state);
}

void test_uartLoopBackSM_given_WAIT_DATA_and_the_read_value_should_stored_inside_the_LoopBackData(void)
{
	LoopBackData data;
	data.state = WAIT_DATA;
	DataRdyUSART_ExpectAndReturn(1);
	getcUSART_ExpectAndReturn(0x5a);
	uartLoopBackSM(&data);
	TEST_ASSERT_EQUAL(0x5a,data.dataByte);

}

void test_uartLoopBackSM_given_WAIT_FOR_TX_should_change_back_to_WAIT_DATA(void)
{
	LoopBackData data;
	data.state = WAIT_FOR_TX;
	data.dataByte = 0x70;
	BusyUSART_ExpectAndReturn(0);
	putcUSART_Expect(0x70);
	uartLoopBackSM(&data);
	TEST_ASSERT_EQUAL(WAIT_DATA,data.state);
}

void test_uartLoopBackSm_given_WAIT_DATA_will_change_the_state_everytime_calling_the_function()
{
	LoopBackData data;
	data.state = WAIT_FOR_TX;
	data.dataByte = 0x70;
	BusyUSART_ExpectAndReturn(0);
	putcUSART_Expect(0x70);
	uartLoopBackSM(&data);
	TEST_ASSERT_EQUAL(WAIT_DATA,data.state);
	DataRdyUSART_ExpectAndReturn(1);
	getcUSART_ExpectAndReturn(0x5a);
	uartLoopBackSM(&data);
	TEST_ASSERT_EQUAL(WAIT_FOR_TX,data.state);
	TEST_ASSERT_EQUAL(0x5a,data.dataByte);
	BusyUSART_ExpectAndReturn(0);
	putcUSART_Expect(0x5a);
	uartLoopBackSM(&data);
	TEST_ASSERT_EQUAL(WAIT_DATA,data.state);
	DataRdyUSART_ExpectAndReturn(1);
	getcUSART_ExpectAndReturn(0x40);
	uartLoopBackSM(&data);
	TEST_ASSERT_EQUAL(WAIT_FOR_TX,data.state);
	TEST_ASSERT_EQUAL(0x40,data.dataByte);
	
}





















