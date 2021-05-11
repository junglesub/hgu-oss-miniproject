#include <stdio.h>

#include "record.h"

int main(void) {
  int sel;
  Record *r[10000];
  int count = 0;

  while (1) {
    sel = selectMenu();
    int no, no2;
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
      case 7:
        printf("검색하고자 하는 category는? (수입:0 지출:1) ");
        scanf("%d", &no);  // no 는 category
        if (no % 2 == 0) {
          printf("수입 항목은? (근로소득:0, 금융소득:1, 기타소득:2) ");
          scanf(" %d", &no2);  // no2 는 항목
        } else {
          printf(
              "지출 항목은? (식비:0, 월세:1, 공과금:2, 교통/통신비:3, "
              "문화생활비:4, "
              "교육비:5, 저축:6, 기타지출:7) ");
          scanf(" %d", &no2);
        }
        searchBreakdown(r, count, no, no2);
        break;
      default:
        printf("잘못된 선택!\n");
    }
  }
}
