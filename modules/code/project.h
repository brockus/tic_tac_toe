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

char gridChar(int index);
void mainExecution();

#endif /* TICTACTOE_H_ */