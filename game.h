#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void IniBoard(char Board[ROWS][COLS], char set);

void DisplayBoard(char Board[ROWS][COLS], int row, int col);

void SetMine(char Board[ROWS][COLS], int row, int col);

void FindMine(char InnerBoard[ROWS][COLS], char OutBoard[ROWS][COLS], int x, int y);

int GetMineCount(char InnerBoard[ROWS][COLS], int x, int y);