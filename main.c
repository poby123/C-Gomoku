#include"header.h"

int main(void) {
	int board[HEIGHT][WIDTH] = { 0 };
	bool gameIsRunning = true;
	enum GOMOKU_TYPE user = BLACK;

	// hello();
	system("cls"); // �ܼ� â �ʱ�ȭ - MoNiSu
	drawBoard();

	do {
		sequence(user);
		checkRule(board, user);
		playGoStone(board, user);
		checkWin(board, &gameIsRunning);
		if (user == BLACK) {
			++user;
		}
		else {
			--user;
		}
	} while (gameIsRunning);

	system("cls");

	gotoxy(5, 5);

	if (user == BLACK + 1) {
		printf(BLACK_WINNING_MSG);
	}
	else {
		printf(WHITE_WINNING_MSG);
	}

	return 0;
}

void hello(void) {
	printf(" *** �ȳ��Ͻʴϱ�. ���� ���� ���� ȯ���մϴ�. ***\n");
	Sleep(1500);
	printf(" *** �� ������ C���� ���� �Ǿ� �ֽ��ϴ�. ***\n");
	Sleep(1500);
	printf(" *** ������ ������ �����մϴ�. ***\n");
	Sleep(1500);
}

void drawLine(int num) {
	const char* line[10] = { " ��", " ��", " ��", "����", "����", "����", "����", "����", "����" };
	printf("%s", line[num]);
}

void drawBoard(void) {
	for (int i = 1; i < HEIGHT; i++) {
		for (int j = 1; j < WIDTH; j++) {
			if (j == 1) {
				if (i == 1) {
					drawLine(0);
				}
				else if (i == HEIGHT - 1) {
					drawLine(2);
				}
				else {
					drawLine(1);
				}
			}
			else if (j == WIDTH - 1) {
				if (i == 1) {
					drawLine(6);
				}
				else if (i == HEIGHT - 1) {
					drawLine(8);
				}
				else {
					drawLine(7);
				}
				printf("\n");
			}
			else {
				if (i == 1) {
					drawLine(3);
				}
				else if (i == HEIGHT - 1) {
					drawLine(5);
				}
				else {
					drawLine(4);
				}
			}
		}
	}
}

void sequence(enum GOMOKU_TYPE user) {
	gotoxy(2, 21);
	if (user == BLACK) {
		printf(BLACK_TURN_MSG);
	}
	else if (user == WHITE) {
		printf(WHITE_TURN_MSG);
	}
}

void gotoxy(short x, short y) {
	COORD pos = { x * 2 - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// ����..?
void checkRule(int arr[20][20], enum GOMOKU_TYPE user) {
	if (user == BLACK) {
		for (int i = 1; i < HEIGHT; i++) { // Ȯ�εǸ� X ǥ�� - MoNiSu
			for (int j = 1; j < WIDTH; j++) {
				if (arr[i][j] == 0) { // 33 ���� �ۼ��ϱ� - MoNiSu
					if (i >= 3 && j >= 3) {
						if (arr[i - 1][j] == 2 &&
							arr[i][j - 1] == 2 &&
							arr[i - 1][j] == arr[i - 2][j] &&
							arr[i][j - 1] == arr[i][j - 2]) {
							arr[i][j] = BLOCKED;
						}
					}
					if (i <= 17 && j >= 3 && j <= 17) {
						if (arr[i + 1][j - 1] == 2 &&
							arr[i + 1][j + 1] == 2 &&
							arr[i + 1][j - 1] == arr[i + 2][j - 2] &&
							arr[i + 1][j + 1] == arr[i + 2][j + 2]) {
							arr[i][j] = BLOCKED;
						}
					}
					if (i <= 17 && j <= 17) {
						if (arr[i + 1][j] == 2 &&
							arr[i][j + 1] == 2 &&
							arr[i + 1][j] == arr[i + 2][j] &&
							arr[i][j + 1] == arr[i][j + 2]) {
							arr[i][j] = BLOCKED;
						}
					}
					if (i >= 3 && i <= 17 && j <= 17) {
						if (arr[i + 1][j + 1] == 2 &&
							arr[i - 1][j + 1] == 2 &&
							arr[i + 1][j + 1] == arr[i + 2][j + 2] &&
							arr[i - 1][j + 1] == arr[i - 2][j + 2]) {
							arr[i][j] = BLOCKED;
						}
					}
					if (i >= 3 && j <= 17) {
						if (arr[i - 1][j] == 2 &&
							arr[i][j + 1] == 2 &&
							arr[i - 1][j] == arr[i - 2][j] &&
							arr[i][j + 1] == arr[i][j + 2]) {
							arr[i][j] = BLOCKED;
						}
					}
					if (i >= 3 && j >= 3 && j <= 17) {
						if (arr[i - 1][j - 1] == 2 &&
							arr[i - 1][j + 1] == 2 &&
							arr[i - 1][j - 1] == arr[i - 2][j - 2] &&
							arr[i - 1][j + 1] == arr[i - 2][j + 2]) {
							arr[i][j] = BLOCKED;
						}
					}
					if (i >= 3 && j >= 3) {
						if (arr[i - 1][j] == 2 &&
							arr[i][j - 1] == 2 &&
							arr[i - 1][j] == arr[i - 2][j] &&
							arr[i][j - 1] == arr[i][j - 2]) {
							arr[i][j] = BLOCKED;
						}
					}
					if (i >= 3 && i <= 17 && j >= 3) {
						if (arr[i - 1][j - 1] == 2 &&
							arr[i + 1][j - 1] == 2 &&
							arr[i - 1][j - 1] == arr[i - 2][j - 2] &&
							arr[i + 1][j - 1] == arr[i + 2][j - 2]) {
							arr[i][j] = BLOCKED;
						}
					}
				}
				if (arr[i][j] == BLOCKED) {
					gotoxy(i, j);
					printf("X");
				}
			}
		}
	}
	else if (user == WHITE) {
		// �׸��� ���� �ߺ�... draw �����ϱ�
		for (int i = 1; i < HEIGHT; i++) {
			for (int j = 1; j < WIDTH; j++) {
				if (arr[i][j] == BLOCKED) {
					gotoxy(i, j);
					if (j == 1) {
						if (i == 1) {
							printf("��");
						}
						else if (i == HEIGHT - 1) {
							printf("��");
						}
						else {
							printf("��");
						}
					}
					else if (j == WIDTH - 1) {
						if (i == 1) {
							printf("��");
						}
						else if (i == HEIGHT - 1) {
							printf("��");
						}
						else {
							printf("��");
						}
					}
					else {
						if (i == 1) {
							printf("��");
						}
						else if (i == HEIGHT - 1) {
							printf("��");
						}
						else {
							printf("��");
						}
					}
					arr[i][j] = EMPTY;
				}
			}
		}
	}
}

void playGoStone(int arr[20][20], enum GOMOKU_TYPE user) {
	int x = 10, y = 10;
	gotoxy(x, y);

	const int keyStatus = 0x0001;

	do {
		if (GetAsyncKeyState(VK_LEFT) & keyStatus) {
			--x;
			if (x < 1) {
				x = 1;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & keyStatus) {
			++x;
			if (x >= WIDTH) {
				x = WIDTH - 1;
			}
		}
		if (GetAsyncKeyState(VK_UP) & keyStatus) {
			--y;
			if (y < 1) {
				y = 1;
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & keyStatus) {
			++y;
			if (y >= HEIGHT) {
				y = HEIGHT - 1;
			}
		}
		if (GetAsyncKeyState(VK_SPACE) & keyStatus) {
			if (arr[x][y] == EMPTY) {
				gotoxy(x, y);
				if (user == BLACK) {
					printf("��");
					arr[x][y] = user;
				}
				else {
					printf("��");
					arr[x][y] = user;
				}
				break;
			}
		}
		gotoxy(x, y);
	} while (true);
}

void checkWin(int arr[20][20], bool* status) {
	for (int i = 1; i < HEIGHT; i++) {
		for (int j = 5; j < WIDTH; j++) {
			if (i <= 15) {
				if ( // ���� Ȯ�� - �輺��, MoNiSu
					arr[i][j] != 0 &&
					arr[i][j] == arr[i + 1][j] &&
					arr[i + 1][j] == arr[i + 2][j] &&
					arr[i + 2][j] == arr[i + 3][j] &&
					arr[i + 3][j] == arr[i + 4][j]
					) {
					*status = false;
				}

				if (j >= 5) {
					if ( // /(������) �밢�� Ȯ�� - �輺��, MoNiSu
						arr[i][j] != 0 &&
						arr[i][j] == arr[i + 1][j - 1] &&
						arr[i + 1][j - 1] == arr[i + 2][j - 2] &&
						arr[i + 2][j - 2] == arr[i + 3][j - 3] &&
						arr[i + 3][j - 3] == arr[i + 4][j - 4]
						) {
						*status = false;
					}
				}

				if (j <= 15) {
					if ( // �������� �밢�� Ȯ�� - �輺��, MoNiSu
						arr[i][j] != 0 &&
						arr[i][j] == arr[i + 1][j + 1] &&
						arr[i + 1][j + 1] == arr[i + 2][j + 2] &&
						arr[i + 2][j + 2] == arr[i + 3][j + 3] &&
						arr[i + 3][j + 3] == arr[i + 4][j + 4]
						) {
						*status = false;
					}
				}
			}

			if (j <= 15) {
				if ( // ���� Ȯ�� - �輺��, MoNiSu
					arr[i][j] != 0 &&
					arr[i][j] == arr[i][j + 1] &&
					arr[i][j + 1] == arr[i][j + 2] &&
					arr[i][j + 2] == arr[i][j + 3] &&
					arr[i][j + 3] == arr[i][j + 4]
					) {
					*status = false;
				}
			}
		}
	}
}
