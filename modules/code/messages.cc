/*
 * file: messages.cc
 * author: Michael Brockus
 * gmail: <michaelbrockus@gmail.com>
 */
#include "project.h"

//
// Print the current board state
//
void printPoard(std::array<std::array<char, 3>, 3> board)
{
    std::cout << std::endl;
    std::cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl << std::endl;
} // end of function printPoard

//
// Print game state
//
void printGameState(int state)
{
    if (static_cast<int>(State::WIN) == state) {
        std::cout << "WIN" << std::endl;
    } // end if
    else if (static_cast<int>(State::DRAW) == state) {
        std::cout << "DRAW" << std::endl;
    } // end else if
    else if (static_cast<int>(State::LOSS) == state) {
        std::cout << "LOSS" << std::endl;
    } // end else if
} // end of function printGameState