#include "record.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char category[][20] = {"수입", "지출"};
char type[][8][20] = {{"식비", "월세", "공과금", "교통/통신비", "문화생활비",
                       "교육비", "저축", "기타지출"},
                      {"근로소득", "금융소득", "기타"}};
char paymentMethod[][20] = {"현금",   "카드",   "계좌이체",
                            "휴대폰", "상품권", "기타"};

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
  printf("No|\tdate|\tcategory|\ttype|\tprice|\tpaymentMethod\n");
  printf("===================================================================\n");
  printf(" %d %s\t%s\t%s\t%d\t%s\n", readIndex, r[readIndex]->date,
         category[r[readIndex]->category], 
         type[r[count]->category % 2][r[readIndex]->type],
         r[readIndex]->price, paymentMethod[r[readIndex]->paymentMethod]);
}

int createRecord(Record *r[], int count) {
  r[count] = malloc(sizeof(Record));

  printf("일시는? (ex:2020-05-05) ");
  scanf(" %[^\n]s", r[count]->date);
  printf("관리하고자 하는 category는? (수업:0 지출:1) ");
  scanf("%d", &r[count]->category);
  if (r[count]->category % 2 == 0) {
    printf("수입 항목은? (근로소득:0, 금융소득:1, 기타소득:2) ");
    scanf(" %d", &r[count]->type);
  } else {
    printf(
        "지출 항목은?\n(식비:0, 월세:1, 공과금:2, 교통/통신비:3, 문화생활비:4, "
        "교육비:5, 저축:6, 기타지출:7) ");
    scanf(" %d", &r[count]->type);
  }
  printf("금액은? ");
  scanf("%d", &r[count]->price);
  printf(
      "계산수단은? (현금:0, 카드:1, 계좌이체:2, 휴대폰:3, 상품권:4, 기타:5) ");
  scanf(" %d", &r[count]->paymentMethod);
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
    scanf(" %d", &r[record_num]->type);
  } else {
    printf(
        "지출 항목은?\n(식비:0, 월세:1, 공과금:2, 교통/통신비:3, 문화생활비:4, "
        "교육비:5, 저축:6, 기타지출:7) ");
    scanf(" %d", &r[record_num]->type);
  }
  printf("금액은? ");
  scanf("%d", &r[record_num]->price);
  printf(
      "계산수단은? (현금:0, 카드:1, 계좌이체:2, 휴대폰:3, 상품권:4, 기타:5) ");
  scanf(" %d", &r[record_num]->paymentMethod);
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

void listRecord(Record *r[], int count) {
    printf("No|\tdate|\tcategory|\ttype|\tprice|\tpaymentMethod\n");
    printf("===================================================================\n");
    for(int i=0; i<count; i++){
        printf(" %d %s\t%c\t%d\t%d\t%c\n", i+1, r[i]->date, 
         r[i]->category, r[i]->type,
         r[i]->price, r[i]->paymentMethod);
    }
}