/*
 * file: test_runner.cc
 * author: Michael Brockus
 * gmail: <michaelbrockus@gmail.com>
 */
#include <unity.h>

/*
 *  Prototype functions for setup and teardown.
 */
extern void setUp();
extern void tearDown();

/*
 *  Prototype functions from the external test file.
 */
extern void test_simpleAssertTrue();
extern void test_simpleAssertNull();
extern void test_simpleAssertCall();

/*
 *  This function runs test from the external test
 *  file.
 */
int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_simpleAssertTrue);
    RUN_TEST(test_simpleAssertNull);
    RUN_TEST(test_simpleAssertCall);

    return UNITY_END();
} //end of function main