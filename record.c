#include "record.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readRecord(Record *r[], int count, int readIndex) {
  // 읽으려고 하는 아이템이 총 저장된 갯수보다 많거나 같으면 오류 메세지 출력.
  if (count <= readIndex) {
    printf("[ERROR] Attempting to Read out of index\n");  // 애러 메세지 출력
    return;  // 해당 함수 종료
  }

  // 지정된 인덱스가 이미 삭제 되었거나 존재하지 않을경우.
  if (r[readIndex] == NULL) {
    printf("[ERROR] 존재하지 않는 인덱스입니다.\n");  // 애러 메세지 출력
    return;                                           // 해당 함수 종료
  }

  // 아래는 출력할 내용들.
  printf("%s\t%c\t%d\t%d\t%c\n", r[readIndex]->date, r[readIndex]->type,
         r[readIndex]->category, r[readIndex]->price,
         r[readIndex]->paymentMethod);
}

int createRecord(Record *r[], int count) {
  r[count] = malloc(sizeof(Record));

  printf("일시는? (ex:2020-05-05) ");
  scanf(" %[^\n]s", r[count]->date);
  printf("관리하고자 하는 category는? (수업:0 지출:1) ");
  scanf("%d", &r[count]->category);
  if (r[count]->category % 2 == 0) {
    printf("수입 항목은? (근로소득:0, 금융소득:1, 기타소득:2) ");
    scanf(" %c", &r[count]->type);
  } else {
    printf(
        "지출 항목은?\n(식비:0, 월세:1, 공과금:2, 교통/통신비:3, 문화생활비:4, "
        "교육비:5, 저축:6, 기타지출:7) ");
    scanf(" %c", &r[count]->type);
  }
  printf("금액은? ");
  scanf("%d", &r[count]->price);
  printf(
      "계산수단은? (현금:0, 카드:1, 계좌이체:2, 휴대폰:3, 상품권:4, 기타:5) ");
  scanf(" %c", &r[count]->paymentMethod);
  printf("기록이 추가되었습니다!\n");
  return 1;
}

int updateRecord(Record *r[], int record_num) {
  printf("기록 내역을 업데이트하겠습니다.\n");

  printf("일시는? (ex:2020-05-05) ");
  scanf(" %[^\n]s", r[record_num]->date);
  printf("관리하고자 하는 category는? (수업:0 지출:1) ");
  scanf("%d", &r[record_num]->category);
  if (r[record_num]->category % 2 == 0) {
    printf("수입 항목은? (근로소득:0, 금융소득:1, 기타소득:2) ");
    scanf(" %c", &r[record_num]->type);
  } else {
    printf(
        "지출 항목은?\n(식비:0, 월세:1, 공과금:2, 교통/통신비:3, 문화생활비:4, "
        "교육비:5, 저축:6, 기타지출:7) ");
    scanf(" %c", &r[record_num]->type);
  }
  printf("금액은? ");
  scanf("%d", &r[record_num]->price);
  printf(
      "계산수단은? (현금:0, 카드:1, 계좌이체:2, 휴대폰:3, 상품권:4, 기타:5) ");
  scanf(" %c", &r[record_num]->paymentMethod);
  printf("기록이 업데이트 되었습니다!\n");
  return 1;
}

int selectDataNo(Record *r[], int count) {
  int no;
  listRecord(r, count);
  printf("번호는? (취소:0)? ");
  scanf("%d", &no);
  return no;
}