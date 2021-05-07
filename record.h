#ifndef __RECORDS_H__
#define __RECORDS_H__

typedef struct {
  char date[20];       // 일시
  char type;           // 수입 또는 지출의 세부항목
  int category;        // 수입 (0) 또는 지출 (1)
  int price;           // 금액
  char paymentMethod;  // 계산수단
} Record;

// CRUD
void readRecord(Record *r[], int count, int readIndex);
int createRecord(Record *r[], int count);
int updateRecord(Record *r[], int record_num);
void deleteRecord(Record *r[], int *count, int delIndex);

// 검색 및 출력
void printMonthRecords(Record *r[], int count,
                       char *yearmonth);  // 월별 내역 확인
void searchBreakdown(Record *r[], char management_type);  // 항목별 내역 확인
void searchPrice(Record *r[], char management_type);  // 금액별 내역 확인
void printPaymentMethod(Record *r[], int count,
                        char paymentmethod);  // 계산 수단별 내역 확인

// 불러오기 및 저장
void save(Record *r[], int count, char *filename);
void load(Record *r[], int *count, char *filename);

// 기타
int selectMenu();
void listRecord(Record *r[], int count);
int selectDataNo(Record *r[], int count);

#endif
