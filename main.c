#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void hello(void); // 사용자에게 안내 - MoNisu
void drawLine(int num); // 줄 그리는 함수 - MoNiSu
void drawBoard(void); // 바둑판 그리는 함수 - MoNiSu
void sequence(int num); //순서 나타내는 함수 - 김성렬
void cursor(short x, short y); // 커서 입력 함수 - MoNiSu
void playGoStone(int arr[20][20], int num); // 커서 움직이기, 바둑돌 두는 함수 - MoNiSu, 함수 이름 변경과 포인터 이용 - 김성렬
void checkRule(int arr[20][20]); //오목 룰 확인 - 김성렬
void checkWin(int arr[20][20], bool* status); // 오목 승리 조건 - 김성렬, MoNiSu

void main(void) {
  int board[20][20] = { 0 }; // 0번칸은 안 씀 1번부터 시작 예) board[10][10] == 2 가로 세로 10번째 줄 검은돌 - MoNiSu
  bool gameStatus; // true == 게임 시작 아니면 게임 중, false == 게임 끝 - MoNiSu
  bool* pGameStatus = &gameStatus; // 포인터를 활용해 게임의 상황을 제어 - MoNiSu
  int user = 2; // 2 == 검은 돌, 3 == 흰 돌 - MoNiSu

  hello();
  system("cls"); // 콘솔 창 초기화 - MoNiSu
  drawBoard();

  *pGameStatus = true;

  do {
    sequence(user);
    playGoStone(board, user);
    checkWin(board, pGameStatus);
    if (user == 2) {
      ++user;
    }
    else {
      --user;
    }
  } while (gameStatus);

  system("cls");

  cursor(5, 5);
  if (user == 3) {
    printf("***  선공 (흑돌 / ○) 이 승리 하였습니다. ***\n\n\n");
  }
  else {
    printf("***  후공 (백돌 / ●) 이 승리 하였습니다. ***\n\n\n");
  }

  exit(0);
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
  const char* line[10] = { // int형 자료 선언을 char 포인터 선언으로 변경 후 잘 표시됨 - 김성렬
    " ┌", " ├", " └", "─┬", "─┼", "─┴", "─┐", "─┤", "─┘"
  };
  printf("%s", line[num]);
  // Sleep(1); // 테스트 할 시에는 주석 처리 - MoNiSu
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

void sequence(int num) {
  if (num == 2) { //흑돌 차례일때 - 김성렬
    cursor(2, 21);
    printf("*** 흑돌 차례입니다 (흑돌 / ○) ***");
  }
  else { //백돌 차례일때 - 김성렬
    cursor(2, 21);
    printf("*** 백돌 차례입니다 (백돌 / ●) ***");
  }
}

void cursor(short x, short y) {
  COORD pos = { x * 2 - 1, y - 1 }; // COORD는 short 변수 배열 - MoNiSu
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // 콘솔 출력 위치 조정 - MoNiSu
}

void playGoStone(int arr[20][20], int num) {
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
        if (arr[x][y] == 0) {
          cursor(x, y);
          if (num == 2) {
            printf("○");
            arr[x][y] = num; // board에 저장
          }
          else {
            printf("●");
            arr[x][y] = num;
          }
          break;
        }
      }
    }
  } while (true);
}

void checkRule(int arr[20][20]) {

}

void checkWin(int arr[20][20], bool* status) {
  for (int i = 1; i <= 19; i++) { // 구조 개선 - MoNiSu
    for (int j = 5; j <= 19; j++) {
      if (i <= 15) {
        if ( // 가로 확인 - 김성렬, MoNiSu
          arr[i][j] != 0 &&
          arr[i][j] == arr[i + 1][j] &&
          arr[i + 1][j] == arr[i + 2][j] &&
          arr[i + 2][j] == arr[i + 3][j] &&
          arr[i + 3][j] == arr[i + 4][j]
          ) {
          *status = false;
        }

        if (j >= 5) {
          if ( // /(슬래시) 대각선 확인 - 김성렬, MoNiSu
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
          if ( // 역슬래시 대각선 확인 - 김성렬, MoNiSu
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
        if ( // 세로 확인 - 김성렬, MoNiSu
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
