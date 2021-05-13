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
    switch (sel) {
      case 0:
        printf("종료됨!\n");
        return 1;
      case 1:
        // create
        count += createRecord(r, count);
        break;
      case 2:
        //read
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
       // printMonthRecords(r,count,yearmonth);
      case 7:
       // searchBreakdown(r, management_type);
      case 8:
        printf("수입/지출 중 어떤 cateory의 가격을 검색하시겠습니까? (수입:0, 지출:1) ");
        scanf("%d", &no);
        while(1){
          if(no == 0 || no == 1) {
            searchPrice(r, count, no);
            break;
          }
          printf("0 또는 1을 입력해주세요!\n");
        }
        break;
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
