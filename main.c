#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <conio.h>

void hello(void); // 사용자에게 안내 - MoNisu
void drawLine(int num); // 줄 그리는 함수 - MoNiSu
void drawBoard(void); // 바둑판 그리는 함수 - MoNiSu
void cursor(short x, short y); // 커서 입력 함수 - MoNiSu
void moveCursor(int arr[20][20], int num); // 커서 움직이기, 바둑돌 두는 함수 - MoNiSu

int test(int t); // 기능 테스트 하는 함수 - MoNiSu

void main(void) {
  int board[20][20]; // 0번칸은 안 씀 1번부터 시작 예) board[10][10] == 2 가로 세로 10번째 줄 검은돌 - MoNiSu
  bool gameStatus; // true == 게임 시작 아니면 게임 중, false == 게임 끝 - MoNiSu
  int user = 2; // 2 == 검은 돌, 3 == 흰 돌 - MoNiSu

  // hello(); 
  // enterKey();
  // system("cls"); // 콘솔 창 초기화 - MoNiSu
  drawBoard();

  gameStatus = true;

  do {
    moveCursor(board, user);
    if (user == 2) {
      ++user;
    }
    else {
      --user;
    }
  } while (gameStatus);

  // test(1); // 다 쓰면 꼭 주석 처리 해둘 것 - MoNiSu
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
  char* line[10] = { // int형 자료 선언을 char 포인터 선언으로 변경 후 잘 표시됨 - 김성렬
    " ┌", " ├", " └", "─┬", "─┼", "─┴", "─┐", "─┤", "─┘"
  };
  printf("%s", line[num]);
  Sleep(1); // 테스트 할 시에는 주석 처리 - MoNiSu
}

void drawBoard(void) {
  for (int i = 1; i <= 19; i++) {
    for (int j = 1; j <= 19; j++) {
      if (j == 1) {
        if (i == 1) {
          drawLine(0);
        }
        else if (i == 19) {
          drawLine(2);
        }
        else {
          drawLine(1);
        }
      }
      else if (j == 19) {
        if (i == 1) {
          drawLine(6);
        }
        else if (i == 19) {
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
        else if (i == 19) {
          drawLine(5);
        }
        else {
          drawLine(4);
        }
      }
    }
  }
}

void cursor(short x, short y) {
  COORD pos = { x * 2 - 1, y - 1 }; // COORD는 short 변수 배열 - MoNiSu
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // 콘솔 출력 위치 조정 - MoNiSu
}

void moveCursor(int arr[20][20], int num) {
  int x = 10, y = 10, key;
  cursor(x, y);

  do {
    if (_kbhit()) {
      key = _getch();
      if (key == 224) { // 224 + a == 방향키 - MoNiSu
        key = _getch();
        switch (key) {
        case 72: // 72 == 아래 - MoNiSu
          --y;
          if (y < 1) {
            y = 1;
          }
          cursor(x, y);
          break;
        case 75: // 75 == 왼쪽 - MoNiSu
          --x;
          if (x < 1) {
            x = 1;
          }
          cursor(x, y);
          break;
        case 77: // 77 == 오른쪽 - MoNiSu
          ++x;
          if (x > 19) {
            x = 19;
          }
          cursor(x, y);
          break;
        case 80: // 80 == 위쪽 - MoNiSu
          ++y;
          if (y > 19) {
            y = 19;
          }
          cursor(x, y);
          break;
        }
      }
      else if (key == 32) { // 32 == 스페이스 바 - MoNiSu
        if (arr[x][y] != 2 && arr[x][y] != 3) {
          cursor(x, y);
          if (num == 2) {
            printf("●");
            arr[x][y] = num; // board에 저장
          }
          else {
            printf("○");
            arr[x][y] = num;
          }
          break;
        }
      }
    }
  } while (true);
}

int test(int t) { // 기능 실험 후 비워 둘 것 - MoNiSu
  
  return 0;
}
