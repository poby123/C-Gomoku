#include"header.h"

int main(void) {
	int board[HEIGHT][WIDTH] = { 0 };
	bool gameIsRunning = true;
	enum GOMOKU_TYPE user = BLACK;

	/*hello();
	system("cls");*/
	drawBoard();

	do {
		sequence(user);
		checkRule(board, user);
		playGoStone(board, user);
		checkWin(board, &gameIsRunning);

		user = (user == BLACK) ? WHITE : BLACK;

	} while (gameIsRunning);

	if (user == BLACK + 1) {
		printMessage(BLACK_WINNING_MSG);
	}
	else {
		printMessage(WHITE_WINNING_MSG);
	}

	return 0;
}

void hello(void) {
	printf(" *** 안녕하십니까. 오목에 오신 것을 환영합니다. ***\n");
	Sleep(1500);
	printf(" *** 본 게임은 C언어로 제작 되어 있습니다. ***\n");
	Sleep(1500);
	printf(" *** 오목판 생성을 시작합니다. ***\n");
	Sleep(1500);
}

void drawLine(int num) {
	const char* line[10] = { " ┌", " ├", " └", "─┬", "─┼", "─┴", "─┐", "─┤", "─┘" };
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

void printMessage(const char* msg) {
	gotoxy(2, 21);
	puts(msg);
}

void sequence(enum GOMOKU_TYPE user) {
	if (user == BLACK) {
		printMessage(BLACK_TURN_MSG);
	}
	else if (user == WHITE) {
		printMessage(WHITE_TURN_MSG);
	}
}

void gotoxy(short x, short y) {
	COORD pos = { x * 2 - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 버그..?
void checkRule(int arr[20][20], enum GOMOKU_TYPE user) {
	if (user == BLACK) {
		for (int i = 1; i < HEIGHT; i++) { // 확인되면 X 표시 - MoNiSu
			for (int j = 1; j < WIDTH; j++) {
				if (arr[i][j] == 0) { // 33 조건 작성하기 - MoNiSu
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
		// 그리기 로직 중복... draw 재사용하기
		for (int i = 1; i < HEIGHT; i++) {
			for (int j = 1; j < WIDTH; j++) {
				if (arr[i][j] == BLOCKED) {
					gotoxy(i, j);
					if (j == 1) {
						if (i == 1) {
							printf("┌");
						}
						else if (i == HEIGHT - 1) {
							printf("└");
						}
						else {
							printf("├");
						}
					}
					else if (j == WIDTH - 1) {
						if (i == 1) {
							printf("┐");
						}
						else if (i == HEIGHT - 1) {
							printf("┘");
						}
						else {
							printf("┤");
						}
					}
					else {
						if (i == 1) {
							printf("┬");
						}
						else if (i == HEIGHT - 1) {
							printf("┴");
						}
						else {
							printf("┼");
						}
					}
					arr[i][j] = EMPTY;
				}
			}
		}
	}
}

void playGoStone(int arr[20][20], enum GOMOKU_TYPE user) {
	static int x = 10, y = 10;
	const int keyStatus = 0x0001;
	gotoxy(x, y);

	while (1) {
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
			if (arr[y][x] == EMPTY) {
				gotoxy(x, y);
				if (user == BLACK) {
					printf(BLACK_STONE);
					arr[y][x] = user;
				}
				else {
					printf(WHITE_STONE);
					arr[y][x] = user;
				}
				break;
			}
		}
		gotoxy(x, y);
	}
}

void checkWin(int(*arr)[WIDTH], bool* gameIsRunning) {
	bool gameIsEnd = checkHorizontal(arr) || checkVertical(arr) || checkDiagonal(arr);
	*gameIsRunning = !gameIsEnd;
}

bool checkHorizontal(int(*arr)[WIDTH]) {
	for (int i = 1; i < HEIGHT; i++) {
		int black_num = 0, white_num = 0;

		for (int j = 1; j < WIDTH; j++) {
			if (arr[i][j] == BLACK) {
				if (white_num == 5) {
					break;
				}
				white_num = 0;
				++black_num;
			}
			else if (arr[i][j] == WHITE) {
				if (black_num == 5) {
					break;
				}
				black_num = 0;
				++white_num;
			}
			else {
				if (black_num == 5 || white_num == 5) {
					break;
				}
				black_num = white_num = 0;
			}
		}
	
		if (black_num == 5 || white_num == 5) {
			return true;
		}
	}

	return false;
}

bool checkVertical(int(*arr)[WIDTH]) {
	for (int j = 1; j < WIDTH; j++) {
		int black_num = 0, white_num = 0;

		for (int i = 1; i < HEIGHT; i++) {
			if (arr[i][j] == BLACK) {
				if (white_num == 5) {
					break;
				}
				white_num = 0;
				++black_num;
			}
			else if (arr[i][j] == WHITE) {
				if (black_num == 5) {
					break;
				}
				black_num = 0;
				++white_num;
			}
			else {
				if (black_num == 5 || white_num == 5) {
					break;
				}
				black_num = white_num = 0;
			}
		}

		if (black_num == 5 || white_num == 5) {
			return true;
		}
	}
	return false;
}

bool isInBoard(int y, int x) {
	return 0 < y && y < HEIGHT && 0 < x && x < WIDTH;
}

bool checkDiagonal(int(*arr)[WIDTH]) {
	// iterate y-axis
	for (int i = 1; i < HEIGHT; i++) {
		bool result = iterateDiagonal(arr, i, 1, LEFT_TO_RIGHT) || iterateDiagonal(arr, i, WIDTH-1, RIGHT_TO_LEFT);
		if (result) {
			return result;
		}
	}

	// iterate x-axis
	for (int j = 1; j < WIDTH; j++) {
		bool result = iterateDiagonal(arr, 1, j, LEFT_TO_RIGHT) || iterateDiagonal(arr, 1, j, RIGHT_TO_LEFT);
		if (result) {
			return result;
		}
	}

	return false;
}

bool iterateDiagonal(int(*arr)[WIDTH], int y, int x, enum DIAGNOAL_TYPE type) {
	int black_num = 0, white_num = 0;

	while (isInBoard(y, x)) {
		if (arr[y][x] == BLACK) {
			if (white_num == 5) {
				break;
			}
			white_num = 0;
			++black_num;
		}
		else if (arr[y][x] == WHITE) {
			if (black_num == 5) {
				break;
			}
			black_num = 0;
			++white_num;
		}
		else {
			if (black_num == 5 || white_num == 5) {
				break;
			}
			black_num = white_num = 0;
		}

		++y; 
		type == LEFT_TO_RIGHT ? ++x : --x;
	}

	if (black_num == 5 || white_num == 5) {
		return true;
	}

	return false;
}