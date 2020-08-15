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

///////////////////////////////////////////////////////////////////////////////
// test_checkPositionOccupied:
//
// Verify valid and invalid combinations of calls to positionOccupied
// return the expected correct value.
//
void test_checkPositionOccupied()
{
    //
    // Start with an empty board.
    std::array<std::array<char, 3>, 3> board = {{
        {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
        {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
        {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE}
        }};

    //
    // Verify the empty board shows all valid positions as not occupied.
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            TEST_ASSERT_EQUAL(false, positionOccupied(board, {row, col}));
        }
    }

    //
    // Verify setting a single board position will only show occupied
    // for that location and no others.
    for (int orow = 0; orow < 3; ++orow)
    {
        for (int ocol = 0; ocol < 3; ++ocol)
        {
            // Mark the current occupied board location
            board[orow][ocol] = PLAYER_MARKER;
            for (int row = 0; row < 3; ++row)
            {
                for (int col = 0; col < 3; ++col)
                {
                    TEST_ASSERT_EQUAL((orow == row && ocol == col), positionOccupied(board, {row, col}));
                }
            }
            // Reset the current occupied board location
            board[orow][ocol] = EMPTY_SPACE;
        }
    }

    //
    // Verify checking out of bounds board positions shows as being occupied.
    TEST_ASSERT_EQUAL(true, positionOccupied(board, {-1, 0}));
    TEST_ASSERT_EQUAL(true, positionOccupied(board, {0, -1}));
    TEST_ASSERT_EQUAL(true, positionOccupied(board, {-1, -1}));
    TEST_ASSERT_EQUAL(true, positionOccupied(board, {1, 3}));
    TEST_ASSERT_EQUAL(true, positionOccupied(board, {3, 1}));
    TEST_ASSERT_EQUAL(true, positionOccupied(board, {3, 3}));
} // end of test case
