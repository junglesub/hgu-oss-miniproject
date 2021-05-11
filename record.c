#include "record.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char category[][20] = {"수입", "지출"};
char exp_type[][20] = {"\t식비",     "\t월세",   "\t공과금", "교통/통신비",
                       "문화생활비", "\t교육비", "\t저축",   "\t기타지출"};
char inc_type[][20] = {"근로소득", "금융소득", "기타"};
char paymentMethod[][20] = {"현금",   "카드",   "계좌이체",
                            "휴대폰", "상품권", "기타"};

int createRecord(Record *r[], int count) {
  r[count] = malloc(sizeof(Record));

  printf("일시는? (ex:2021-05-05) ");
  scanf(" %[^\n]s", r[count]->date);
  printf("관리하고자 하는 category는? (수입:0 지출:1) ");
  scanf("%d", &r[count]->category);
  if (r[count]->category % 2 == 0) {
    printf("수입 항목은? (근로소득:0, 금융소득:1, 기타소득:2) ");
    scanf(" %d", &r[count]->type);
  } else {
    printf(
        "지출 항목은? (식비:0, 월세:1, 공과금:2, 교통/통신비:3, 문화생활비:4, "
        "교육비:5, 저축:6, 기타지출:7) ");
    scanf(" %d", &r[count]->type);
  }
  printf("금액은? ");
  scanf("%d", &r[count]->price);
  printf(
      "결제수단은? (현금:0, 카드:1, 계좌이체:2, 휴대폰:3, 상품권:4, 기타:5) ");
  scanf(" %d", &r[count]->paymentMethod);
  printf("기록이 추가되었습니다!\n");
  return 1;
}

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
  printf("\nNo\tdate\t\tcategory\ttype\tprice\tpaymentMethod\n");
  printf(
      "===================================================================\n");
  printf("%d\t%s\t%s\t%s\t%d\t%s\n", readIndex, r[readIndex]->date,
         category[r[readIndex]->category],
         r[readIndex]->category % 2 == 0 ? inc_type[r[readIndex]->type]
                                         : exp_type[r[readIndex]->type],
         r[readIndex]->price, paymentMethod[r[readIndex]->paymentMethod]);
}

int updateRecord(Record *r[], int updIndex) {
  printf("기록 내역을 업데이트하겠습니다.\n");

  printf("일시는? (ex:2021-05-05) ");
  scanf(" %[^\n]s", r[updIndex]->date);
  printf("관리하고자 하는 category는? (수입:0 지출:1) ");
  scanf("%d", &r[updIndex]->category);
  if (r[updIndex]->category % 2 == 0) {
    printf("수입 항목은? (근로소득:0, 금융소득:1, 기타소득:2) ");
    scanf(" %d", &r[updIndex]->type);
  } else {
    printf(
        "지출 항목은? (식비:0, 월세:1, 공과금:2, 교통/통신비:3, 문화생활비:4, "
        "교육비:5, 저축:6, 기타지출:7) ");
    scanf(" %d", &r[updIndex]->type);
  }
  printf("금액은? ");
  scanf("%d", &r[updIndex]->price);
  printf(
      "결제수단은? (현금:0, 카드:1, 계좌이체:2, 휴대폰:3, 상품권:4, 기타:5) ");
  scanf(" %d", &r[updIndex]->paymentMethod);
  printf("기록이 업데이트 되었습니다!\n");
  return 1;
}

void deleteRecord(Record *r[], int *count, int delIndex) {
  // 지우려고 하는 아이템이 총 저장된 갯수보다 많거나 같으면 오류 메세지 출력.
  if (*count <= delIndex) {
    printf("[ERROR] Attempting to Delete out of index\n");  // 애러 메세지 출력
    return;  // 해당 함수 종료
  }

  // 지정된 인덱스가 이미 삭제 되었거나 존재하지 않을경우.
  if (r[delIndex] == NULL) {
    printf("[ERROR] 존재하지 않는 인덱스입니다.\n");  // 애러 메세지 출력
    return;                                           // 해당 함수 종료
  }

  // 해당 인덱스 위치 삭제
  free(r[delIndex]);   // 해당 메모리 공간 비우기.
  r[delIndex] = NULL;  //

  // 끌어오기 기능
  for (int i = delIndex; i < *count - 1; i++) {
    r[i] = r[i + 1];
  }
  r[*count - 1] = NULL;  // 마지막 아이템은 NULL 으로 지정.
  (*count)--;
  printf("%d번째 항목 삭제 완료!\n", delIndex + 1);
}

void saveRecord(Record *r[], int count) {
  FILE *fp;
  fp = fopen("Record.txt", "wt");
  for (int i = 0; i < count; i++) {
    fprintf(fp, "%s %d %d %d %d\n", r[i]->date, r[i]->category, r[i]->type,
            r[i]->price, r[i]->paymentMethod);
  }
  fclose(fp);
  printf("Record.txt 파일에 기록이 저장되었습니다!\n");
}

int loadRecord(Record *r[]) {
  int i = 0;
  FILE *fp;
  fp = fopen("Record.txt", "rt");

  if (fp == NULL) {
    printf("Record.txt 파일이 없습니다!\n");
    return 0;
  }
  for (; i < RECORDS_MAX; i++) {
    if (feof(fp)) break;
    r[i] = malloc(sizeof(Record));
    fscanf(fp, "%s", r[i]->date);
    fscanf(fp, "%d", &r[i]->category);
    fscanf(fp, "%d", &r[i]->type);
    fscanf(fp, "%d", &r[i]->price);
    fscanf(fp, "%d\n", &r[i]->paymentMethod);
  }
  fclose(fp);
  printf("Record.txt 파일 기록을 읽어왔습니다!\n");
  return i;
}

int selectMenu(void) {
  int sel;
  printf("\n===== 가계부 프로그램 =====\n");
  printf("1. 기록 추가\n");
  printf("2. 특정 기록 조회\n");
  printf("3. 기록 업데이트\n");
  printf("4. 기록 삭제\n");
  printf("5. 파일 저장\n");
  printf("6. 월간 내역 검색\n");
  printf("7. 항목별 내역 검색\n");
  printf("8. 금액별 내역 검색\n");
  printf("9. 결제수단별 내역 검색\n");
  printf("10. 전체 기록 조회\n");
  printf("0. 종료\n");
  printf("=> 원하는 메뉴는? ");

  scanf("%d", &sel);
  return sel;
}

int selectDataNo(Record *r[], int count) {
  int no;
  listRecord(r, count);
  printf("번호는? (취소:0)? ");
  scanf("%d", &no);
  return no;
}

void listRecord(Record *r[], int count) {
  printf("\nNo\tdate\t\tcategory\ttype\tprice\tpaymentMethod\n");
  printf(
      "===================================================================\n");
  for (int i = 0; i < count; i++) {
    printf(
        "%d\t%s\t%s\t%s\t%d\t%s\n", i + 1, r[i]->date, category[r[i]->category],
        r[i]->category % 2 == 0 ? inc_type[r[i]->type] : exp_type[r[i]->type],
        r[i]->price, paymentMethod[r[i]->paymentMethod]);
  }
}

void printPaymentMethod(Record *r[], int count, int paymentmethod) {
  printf("\nNo\tdate\t\tcategory\ttype\tprice\tpaymentMethod\n");
  printf(
      "===================================================================\n");
  for (int i = 0; i < count; i++) {
    if (r[i]->paymentMethod != paymentmethod) continue;
    printf(
        "%d\t%s\t%s\t%s\t%d\t%s\n", i + 1, r[i]->date, category[r[i]->category],
        r[i]->category % 2 == 0 ? inc_type[r[i]->type] : exp_type[r[i]->type],
        r[i]->price, paymentMethod[r[i]->paymentMethod]);
  }
}

void searchBreakdown(Record *r[], int count, int management_category,
                     int management_type) {
  printf("\nNo\tdate\t\tcategory\ttype\tprice\tpaymentMethod\n");
  printf(
      "===================================================================\n");
  for (int i = 0; i < count; i++) {
    if (!(r[i]->category == management_category &&
          r[i]->type == management_type))
      continue;
    printf(
        "%d\t%s\t%s\t%s\t%d\t%s\n", i + 1, r[i]->date, category[r[i]->category],
        r[i]->category % 2 == 0 ? inc_type[r[i]->type] : exp_type[r[i]->type],
        r[i]->price, paymentMethod[r[i]->paymentMethod]);
  }
}