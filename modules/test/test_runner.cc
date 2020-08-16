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
extern void test_validGridChar();
extern void test_validOpponentMarker();
extern void test_checkGetLegalMoves();
extern void test_checkPositionOccupied();
extern void test_checkGetOccupiedPositions();
extern void test_checkGameIsDone();

/*
 *  This function runs test from the external test
 *  file.
 */
int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_validGridChar);
    RUN_TEST(test_validOpponentMarker);
    RUN_TEST(test_checkGetLegalMoves);
    RUN_TEST(test_checkPositionOccupied);
    RUN_TEST(test_checkGetOccupiedPositions);
    RUN_TEST(test_checkGameIsDone);

    return UNITY_END();
} //end of function main
