#ifndef __RECORDS_H__
#define __RECORDS_H__

#define RECORDS_MAX 10000

typedef struct {
  char date[20];      // 일시
  int category;       // 수입 (0) 또는 지출 (1)
  int type;           // 수입 또는 지출의 세부항목
  int price;          // 금액
  int paymentMethod;  // 결제수단
} Record;

// CRUD
int createRecord(Record *r[], int count);
void readRecord(Record *r[], int count, int readIndex);
int updateRecord(Record *r[], int updIndex);
void deleteRecord(Record *r[], int *count, int delIndex);

// 검색 및 출력
void printMonthRecords(Record *r[], int count,
                       char *yearmonth);  // 월별 내역 확인
void searchBreakdown(Record *r[], int count, int management_category,
                     int management_type);            // 항목별 내역 확인
void searchPrice(Record *r[], char management_type);  // 금액별 내역 확인
void printPaymentMethod(Record *r[], int count,
                        int paymentmethod);  // 결제수단별 내역 확인

// 불러오기 및 저장
void saveRecord(Record *r[], int count);
int loadRecord(Record *r[]);

// 기타
int selectMenu();
int selectDataNo(Record *r[], int count);
void listRecord(Record *r[], int count);

#endif
