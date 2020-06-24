#ifndef _MINE_H
#define _MINE_H

#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>

#pragma warning (disable:4996)

#define ROW 12       //行数
#define COL 12       //列数
#define MINE 20      //雷数

void Game();
void InitBoard(char Board[][COL], int row, int col, char elem); 
void ShowBoard(char Board[][COL], int row, int col);
void SetMine(char Mine[][COL], int row, int col);
char GetMine(char Mine[][COL], int x, int y);



#endif