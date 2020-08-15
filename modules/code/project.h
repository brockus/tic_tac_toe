#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#if defined _WIN32 || defined __CYGWIN__
#ifdef BUILDING_PROJECT
#define PROJECT_PUBLIC __declspec(dllexport)
#else
#define PROJECT_PUBLIC __declspec(dllimport)
#endif

#else
#ifdef BUILDING_PROJECT
#define PROJECT_PUBLIC __attribute__((visibility("default")))
#else
#define PROJECT_PUBLIC
#endif
#endif

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cstdlib>

enum class State
{
    WIN = 1000,
    DRAW = 0,
    LOSS = -1000
};

const char AI_MARKER = 'O';
const char PLAYER_MARKER = 'X';
const char EMPTY_SPACE = '-';

const int START_DEPTH = 0;

void mainExecution();
void printBoard(std::array<std::array<char, 3>, 3> board);
void printGameState(int state);
char getOpponentMarker(char marker);

//
// Testing prototypes
std::vector<std::pair<int, int>> getLegalMoves(std::array<std::array<char, 3>, 3> board);
bool positionOccupied(std::array<std::array<char, 3>, 3> board, std::pair<int, int> pos);
int getBoardState(std::array<std::array<char, 3>, 3> board, char marker);

#endif /* TICTACTOE_H_ */
