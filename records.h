#ifndef __RECORDS_H__
#define __RECORDS_H__

typedef struct {
} Record;

// CRUD
void deleteRecord(Record r[], int count, int delIndex);

// 검색 및 출력
void printMonthRecords(Record r[], int count, char* yearmonth);
void printPaymentMethod(Record r[], int count, char paymentmethod);

// 불러오기 및 저장
void save(Record r[], int count, char* filename);
void load(Record r[], int* count, char* filename);

#endif