#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef GOMOKU_H
#define GOMOKU_H

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

// constants
#define WIDTH 20
#define HEIGHT 20

#define BLACK_STONE "��"
#define WHITE_STONE "��"

#define BLACK_WINNING_MSG "***  ���� (�浹 / ��) �� �¸� �Ͽ����ϴ�. ***\n\n\n"
#define WHITE_WINNING_MSG "***  �İ� (�鵹 / ��) �� �¸� �Ͽ����ϴ�. ***\n\n\n"

#define BLACK_TURN_MSG "*** �浹 �����Դϴ� (�浹 / ��) ***"
#define WHITE_TURN_MSG "*** �鵹 �����Դϴ� (�鵹 / ��) ***"

// enum
enum GOMOKU_TYPE { EMPTY, BLOCKED, BLACK, WHITE };
enum DIAGONAL_TYPE {LEFT_TO_RIGHT, RIGHT_TO_LEFT};
enum KEY_TYPE { LEFT, RIGHT, UP, DOWN, SPACE };

// function declaration
void hello(void);
void drawLine(int num);
void drawBoard(void);
void sequence(enum GOMOKU_TYPE user);
void gotoxy(short x, short y);
void checkRule(int arr[20][20], enum GOMOKU_TYPE user);
void playGoStone(int arr[20][20], enum GOMOKU_TYPE user);
void printMessage(const char*);

bool isInBoard(int, int);
void checkWin(int(*)[WIDTH], bool*);
bool checkHorizontal(int(*)[WIDTH]);
bool checkVertical(int(*)[WIDTH]);

bool iterateDiagonal(int(*)[WIDTH], int, int, enum DIAGNOAL_TYPE type);
bool checkDiagonal(int(*)[WIDTH]);

#endif