#include <stdio.h>

#include "record.h"

int main(void) {
  int sel;

  while (1) {
    sel = selectMenu();

    switch (sel) {
      case 0:
        return 1;
      default:
        printf("잘못된 선택!\n");
    }
  }
}

int selectMenu(void) {
  printf("\n===== 메뉴 =====\n");
  printf("1. 새로운 항목 추가\n");
  printf("2. 모든 항목 읽기\n");
  printf("3. 하나 항목 읽기\n");
  printf("4. 항목 삭제\n");
  printf("0. 나가기\n");
  printf("메뉴 선택: ");

  int sel;
  scanf("%d", &sel);
  return sel;
}