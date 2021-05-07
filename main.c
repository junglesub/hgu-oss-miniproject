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
