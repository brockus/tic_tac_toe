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
void printPoard(char board[3][3]);
void printGameState(int state);
char getOpponentMarker(char marker);

#endif /* TICTACTOE_H_ */