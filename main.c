#include <stdio.h>

#include "record.h"

int main(void) {
  int sel;
  Record *r[100];
  int count = 0;

  while (1) {
    sel = selectMenu();
    int no;
    switch (sel) {
      case 0:
        return 1;
      case 1:
        count += createRecord(r, count);
        break;
      case 2:
        listRecord(r, count);
        break;
      case 3:
        no = selectDataNo(r, count);
        if (no == 0) break;
        readRecord(r, count, no - 1);
        break;
      case 4:
        // Delete
        no = selectDataNo(r, count);
        if (no == 0) break;
        deleteRecord(r, &count, no - 1);
        break;
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