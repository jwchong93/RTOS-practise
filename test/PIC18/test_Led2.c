#include "unity.h"
#include "Led2.h"
#include "Tasking.h"
#include "Blinky.h"
#include "p18f4520.h"
#include "mock_Clock.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void xtest_testingLed2SM(void) {
	Led2Data led2Data = {.state = 0, .ledStatus = LED_ON};
  
  testingLed2SM(&led2Data);
  testingLed2SM(&led2Data);
  testingLed2SM(&led2Data);
}

void test_led2SM(void) {
	Led2Data led2Data = {.state = 0, .ledStatus = LED_UNKNOWN_STATUS, .currentClock = 0};
  
  initTasking(&led2Data);
  
  getClock_ExpectAndReturn(250);
  led2SM(&led2Data);
  TEST_ASSERT_EQUAL(LED_OFF, led2Data.ledStatus);
  
  getClock_ExpectAndReturn(500);
  getClock_ExpectAndReturn(500);
  led2SM(&led2Data);
  TEST_ASSERT_EQUAL(LED_ON, led2Data.ledStatus);

  getClock_ExpectAndReturn(750);
  led2SM(&led2Data);
  TEST_ASSERT_EQUAL(LED_ON, led2Data.ledStatus);

  getClock_ExpectAndReturn(1000);
  getClock_ExpectAndReturn(1000);
  led2SM(&led2Data);
  TEST_ASSERT_EQUAL(LED_OFF, led2Data.ledStatus);
  
  getClock_ExpectAndReturn(1250);
  led2SM(&led2Data);
  TEST_ASSERT_EQUAL(LED_OFF, led2Data.ledStatus);
}
