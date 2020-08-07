/*
 * file: project.c
 * author: Michael Brockus
 * gmail: <michaelbrockus@gmail.com>
 */

/*
 Greet the user
 */
#include "project.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

enum
{
    MARK_X = -1,
    MARK_O = 1,
    MARK_EMPTY = 0
}; // end enum

struct Position
{
    int pos;

}; // end of struct Position

//
// Show grid char on the game board
//
char gridChar(int index)
{
    switch (index)
    {
    case MARK_X:
        return 'X';
    case MARK_EMPTY:
        return ' ';
    case MARK_O:
        return 'O';
    } // end switch
    return '\0';
} // end of function gridChar

//
// Output the game board to the player
//
void draw(int *board)
{
    std::cout << std::endl
    << " " << gridChar(board[0]) << " | " << gridChar(board[1]) << " | " << gridChar(board[2]) << " " << std::endl
    << "---+---+---" << std::endl
    << " " << gridChar(board[3]) << " | " << gridChar(board[4]) << " | " << gridChar(board[5]) << " " << std::endl
    << "---+---+---" << std::endl
    << " " << gridChar(board[6]) << " | " << gridChar(board[7]) << " | " << gridChar(board[8]) << " " << std::endl
    << "---+---+---" << std::endl;
} // end of function draw

//
// Determines if a player has won, returns 0 otherwise.
//
int win(const int *board)
{
    unsigned int wins[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (unsigned int index = 0; index < 8; ++index)
    {
        if (board[wins[index][0]] != 0 && board[wins[index][0]] == board[wins[index][1]] && board[wins[index][0]] == board[wins[index][2]])
        {
            return board[wins[index][2]];
        } // end if
    } // end for
    return 0;
} // end of function win

//
// How is the position like for player (their turn) on board?
//
int minimax(int *board, int player)
{
    int winner = win(board);
    if (winner != 0)
    {
        return winner * player;
    } // end if

    int move = -1;
    int score = -2; // Losing moves are preferred to no move

    for (unsigned int index = 0; index < 9; ++index)
    { 
        // For all moves,
        if (*(board + index) == 0)
        {
            *(board + index) = player; // Try the move
            int thisScore = -minimax(board, player * -1);
            if (thisScore > score)
            {
                // Pick the one that's worst for the opponent
                score = thisScore;
                move = index;
            } // end if
            *(board + index) = 0; // Reset board after try
        } // end if
    } // end for
    if (move == -1)
    {
        return 0;
    } // end if
    return score;
} // end of function minimax

//
// should perform a move for the computer
//
void computerMove(int *board)
{

    struct Position bestPos;
    bestPos.pos = -1;
    int score = -2;
    for (unsigned int index = 0; index < 9; ++index)
    {
        if (board[index] == 0)
        {
            *(board + index) = 1;
            int tempScore = -minimax(board, -1);
            *(board + index) = 0;
            if (tempScore > score)
            {
                score = tempScore;
                bestPos.pos = index;
            } // end if
        } // end if
    } // end for

    // returns a score based on minimax tree at a given node.
    *(board + bestPos.pos) = 1;
} // end of function computerMove

//
// should perform a move for the player
//
void playerMove(int *board)
{
    int move = 0;
    do
    {
        std::cout << std::endl << "Input move ([0..8]): ";
        std::cin >> move;
        if (*(board + move) != 0)
        {
            std::cout << "Its Already Occupied!" << std::endl;
        } // end if
        std::cout << std::endl;
    } while ((move >= 9 || move < 0) && (*(board + move) == 0 && *(board + move)) != 0);
    board[move] = -1;
} // end of function playerMove

//
// game main execution logic starts here
//
void mainExecution()
{
    int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned int player = 0;

    // computer squares are 1, player squares are -1.
    std::cout << "Dodo bird: O, You: X" << std::endl << "Play (1)st or (2)nd? ";
    std::cin >> player;
    std::cout << std::endl;
    for (unsigned int turn = 0; turn < 9 && !win(board); ++turn)
    {
        if ((turn + player) % 2 == 0)
        {
            computerMove(board);
        } // end if
        else
        {
            draw(board);
            playerMove(board);
        } // end else
    } // end for
    switch (win(board))
    {
    case 0:
        std::cout << "A draw." << std::endl;
        break;
    case 1:
        draw(board);
        std::cout << "You lose." << std::endl;
        break;
    case -1:
        std::cout << "You win." << std::endl;
        break;
    } // end switch
} // end of function mainExecution
