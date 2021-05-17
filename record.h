#ifndef __RECORD_H__
#define __RECORD_H__

#define RECORDS_MAX 10000

typedef struct {
  char date[20];      // 일시
  int category;       // 수입(0) 또는 지출(1)
  int type;           // 수입 또는 지출의 세부 항목
  int price;          // 금액
  int paymentMethod;  // 결제수단
} Record;

// CRUD
int createRecord(Record *r[], int count); // 기록 추가
void readRecord(Record *r, int redIndex); // 기록(1개) 조회
int updateRecord(Record *r[], int updIndex); // 기록 업데이트
void deleteRecord(Record *r[], int *count, int delIndex); // 기록 삭제

// 파일 불러오기 및 저장
void saveRecord(Record *r[], int count); // 파일 불러오기
int loadRecord(Record *r[]); // 파일 저장

// 검색 및 출력
void searchMonth(Record *r[], int count, int cat,
                       char *yearmonth);  // 월간 내역 검색
void searchItem(Record *r[], int count, int management_category,
                     int management_type);  // 항목별 내역 검색
void searchPrice(Record *r[], int count,
                 int management_category);  // 금액별 내역 검색
void searchPaymentMethod(Record *r[], int count, int cat,
                        int paymentmethod);  // 결제수단별 내역 검색

// 기타
int selectMenu(); // 메뉴 선택
int selectDataNo(Record *r[], int count); // 특정 기록 인덱스 선택 
void listRecord(Record *r[], int count); // 전체 기록 조회

#endif
