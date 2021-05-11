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
        printf("종료됨!\n");
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
      case 5:
        // Update
        no = selectDataNo(r, count);
        if (no == 0) break;
        updateRecord(r, no - 1);
        break;
      case 6:
        printf(
            "검색하고 싶은 결제수단은? (현금:0, 카드:1, 계좌이체:2, 휴대폰:3, "
            "상품권:4, "
            "기타:5) ");
        scanf("%d", &no);
        printPaymentMethod(r, count, no);
        break;
      default:
        printf("잘못된 선택!\n");
    }
  }
}
