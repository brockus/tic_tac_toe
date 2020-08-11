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
    TEST_ASSERT_EQUAL_CHAR('O', AI_MARKER);
    TEST_ASSERT_EQUAL_CHAR('X', PLAYER_MARKER);
    TEST_ASSERT_EQUAL_CHAR('-', EMPTY_SPACE);
} // end of test case

void test_validOpponentMarker()
{
    TEST_ASSERT_EQUAL_CHAR('X', getOpponentMarker(AI_MARKER));
    TEST_ASSERT_EQUAL_CHAR('O', getOpponentMarker(PLAYER_MARKER));
} // end of test case
