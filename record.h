#ifndef __RECORDS_H__
#define __RECORDS_H__

typedef struct {
	char date[20];
	int management_type;
	int price;
	char paymentMethod[20];
} Record;

// CRUD
int createRecord(Record *r);
void readRecord(Record *r);
int updateRecord(Record *r); 
void deleteRecord(Record r[], int count, int delIndex);

// 검색 및 출력
void searchBreakdown(Record *r, int management_type); // 항목별 내역 확인
void searchPrice(Record *r, int management_type); // 금액별 내역 확인
void printMonthRecords(Record r[], int count, char* yearmonth);
void printPaymentMethod(Record r[], int count, char paymentmethod);

// 불러오기 및 저장
void save(Record r[], int count, char* filename);
void load(Record r[], int* count, char* filename);

// 기타
int selectMenu();
void listRecord(Record *r, int record_num);
int selectDataNo(Record *r, int record_num);

#endif
