#include <stdio.h>

#include "record.h"

int main(void) {
  int sel;
  Record *r[10000];
  int count = 0;
  count = loadRecord(r);

  while (1) {
    sel = selectMenu();
    int no;
    char yearmonth[8];
    switch (sel) {
      case 0:
        printf("종료됨!\n");
        return 1;
      case 1:
        // create
        count += createRecord(r, count);
        break;
      case 2:
        // read
        no = selectDataNo(r, count);
        if (no == 0) break;
        readRecord(r, count, no - 1);
        break;
      case 3:
        // Update
        no = selectDataNo(r, count);
        if (no == 0) break;
        updateRecord(r, no - 1);
        break;
      case 4:
        // Delete
        no = selectDataNo(r, count);
        if (no == 0) break;
        deleteRecord(r, &count, no - 1);
        break;
      case 5:
        saveRecord(r, count);
        break;
      case 6:
        printf("검색하고 싶은 일시는? (ex:2021-05-05) ");
        scanf(" %[^\n]s", yearmonth);
        printMonthRecords(r,count,yearmonth);
        break;
      case 7:
        // searchBreakdown(r, management_type);
      case 8:
        // searchPrice(r, management_type);
      case 9:
        printf(
            "검색하고 싶은 결제수단은? (현금:0, 카드:1, 계좌이체:2, 휴대폰:3, "
            "상품권:4, "
            "기타:5) ");
        scanf("%d", &no);
        printPaymentMethod(r, count, no);
        break;
      case 10:
        listRecord(r, count);
        break;
      default:
        printf("잘못된 선택!\n");
    }
  }
}
