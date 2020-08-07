/*
 * file: test_cases.cc
 * author: Michael Brockus
 * gmail: <michaelbrockus@gmail.com>
 */
#include <unity.h>
#include "project.h"

/*
 *  Functions for setup and teardown.
 */
void setUp()
{
    // TODO.
} // end of function setUp

void tearDown()
{
    // TODO.
} // end of function tearDown

void test_validGridChar()
{
    TEST_ASSERT_EQUAL_CHAR('X', gridChar(-1));
    TEST_ASSERT_EQUAL_CHAR(' ', gridChar(0));
    TEST_ASSERT_EQUAL_CHAR('O', gridChar(1));
} // end of test case

void test_invalidGridChar()
{
    TEST_ASSERT_EQUAL_CHAR('\0', gridChar(42));
} // end of test case