#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

void hello(void); // 사용자에게 안내 - MoNisu
void drawLine(int num); // 줄 그리는 함수 - MoNiSu
void drawBoard(void); // 바둑판 그리는 함수 - MoNiSu

int test(int t); // 기능 테스트 하는 함수 - MoNiSu


void main(void) {
  // hello(); // 실행 시간이 길어져 테스트 하기 힘들어 주석 처리함 - MoNiSu
  system("cls"); // 콘솔 창 초기화 - MoNiSu
  drawBoard();

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
    "┌", "├", "└", "─┬", "─┼", "─┴", "─┐", "─┤", "─┘", "│"
  };
  printf("%s", line[num]);
  Sleep(5);
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

int test(int t) { // 기능 실험 후 비워 둘 것 - MoNiSu

  return 0;
}