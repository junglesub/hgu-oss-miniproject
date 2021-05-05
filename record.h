#ifndef __RECORDS_H__
#define __RECORDS_H__

typedef struct {
  char date[20];
  char type;     // 수입 또는 지출의 항목.
  int category;  // 수입 (0) 또는 지출 (1)
  int price;
  char paymentMethod;
} Record;

// CRUD
int createRecord(Record *r[]);
void readRecord(Record *r[]);
int updateRecord(Record *r[]);
void deleteRecord(Record *r[], int count, int delIndex);

// 검색 및 출력
void searchBreakdown(Record *r[], char management_type);  // 항목별 내역 확인
void searchPrice(Record *r[], char management_type);  // 금액별 내역 확인
void printMonthRecords(Record *r[], int count,
                       char *yearmonth);  // 월별 내역 확인
void printPaymentMethod(Record *r[], int count,
                        char paymentmethod);  // 계산 수단별 내역 확인

// 불러오기 및 저장
void save(Record *r[], int count, char *filename);
void load(Record *r[], int *count, char *filename);

// 기타
int selectMenu();
void listRecord(Record *r[], int record_num);
int selectDataNo(Record *r[], int record_num);

#endif
