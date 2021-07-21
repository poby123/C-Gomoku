#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef GOMOKU_H
#define GOMOKU_H

// header files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

// constants
#define WIDTH 20
#define HEIGHT 20

#define BLACK_WINNING_MSG "***  선공 (흑돌 / ○) 이 승리 하였습니다. ***\n\n\n"
#define WHITE_WINNING_MSG "***  후공 (백돌 / ●) 이 승리 하였습니다. ***\n\n\n"

#define BLACK_TURN_MSG "*** 흑돌 차례입니다 (흑돌 / ○) ***"
#define WHITE_TURN_MSG "*** 백돌 차례입니다 (백돌 / ●) ***"

// structs
enum GOMOKU_TYPE { EMPTY, BLOCKED, BLACK, WHITE };

// function declaration
void hello(void);
void drawLine(int num);
void drawBoard(void);
void sequence(enum GOMOKU_TYPE user);
void gotoxy(short x, short y);
void checkRule(int arr[20][20], enum GOMOKU_TYPE user);
void playGoStone(int arr[20][20], enum GOMOKU_TYPE user);
void checkWin(int arr[20][20], bool* status);

#endif