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

#define BLACK_WINNING_MSG "***  ���� (�浹 / ��) �� �¸� �Ͽ����ϴ�. ***\n\n\n"
#define WHITE_WINNING_MSG "***  �İ� (�鵹 / ��) �� �¸� �Ͽ����ϴ�. ***\n\n\n"

#define BLACK_TURN_MSG "*** �浹 �����Դϴ� (�浹 / ��) ***"
#define WHITE_TURN_MSG "*** �鵹 �����Դϴ� (�鵹 / ��) ***"

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