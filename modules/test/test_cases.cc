/*
 * file: test_cases.cc
 * author: Michael Brockus
 * gmail: <michaelbrockus@gmail.com>
 */
#include <unity.h>

/*
 * This function is called from project.c
 */
extern const char *greet();

/*
 *  Prototype functions from the external test file.
 */
void test_simpleAssertTrue();
void test_simpleAssertNull();
void test_simpleAssertCall();

/*
 *  Functions for setup and teardown.
 */
void setUp()
{
    // TODO.
} //end of function setUp

void tearDown()
{
    // TODO.
} //end of function tearDown

void test_simpleAssertTrue()
{
    TEST_ASSERT_TRUE(true);
} //end of test case

void test_simpleAssertNull()
{
    TEST_ASSERT_NULL(NULL);
} //end of test case

void test_simpleAssertCall()
{
    TEST_ASSERT_EQUAL_STRING("Hello, C++ Developer.", greet());
} //end of test case