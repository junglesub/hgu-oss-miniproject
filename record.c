#include <stdlib.h>
#include <stdio.h>
#include "record.h"

int createRecord(Record *r[], int count){
    r[count] = malloc(sizeof(Record));

    printf("일시는? (ex:2020-05-05) ");
    scanf(" %[^\n]s", r[count]->date);
    printf("관리하고자 하는 category는? (수업:0 지출:1) ");
    scanf("%d", &r[count]->category);
    if(r[count]->category %2 == 0){
        printf("수입 항목은? (근로소득:0, 금융소득:1, 기타소득:2) ");
        scanf(" %c", &r[count]->type);
    }
    else{
        printf("지출 항목은?\n(식비:0, 월세:1, 공과금:2, 교통/통신비:3, 문화생활비:4, 교육비:5, 저축:6, 기타지출:7) ");
        scanf(" %c", &r[count]->type);
    }
    printf("금액은? ");
    scanf("%d", &r[count]->price);
    printf("계산수단은? (현금:0, 카드:1, 계좌이체:2, 휴대폰:3, 상품권:4, 기타:5) ");
    scanf(" %c", &r[count]->paymentMethod);
    printf("기록이 추가되었습니다!\n");
    return 1;
}

int updateRecord(Record *r[], int record_num){
    printf("기록 내역을 업데이트하겠습니다.\n");

    printf("일시는? (ex:2020-05-05) ");
    scanf(" %[^\n]s", r[record_num]->date);
    printf("관리하고자 하는 category는? (수업:0 지출:1) ");
    scanf("%d", &r[record_num]->category);
    if(r[record_num]->category %2 == 0){
        printf("수입 항목은? (근로소득:0, 금융소득:1, 기타소득:2) ");
        scanf(" %c", &r[record_num]->type);
    }
    else{
        printf("지출 항목은?\n(식비:0, 월세:1, 공과금:2, 교통/통신비:3, 문화생활비:4, 교육비:5, 저축:6, 기타지출:7) ");
        scanf(" %c", &r[record_num]->type);
    }
    printf("금액은? ");
    scanf("%d", &r[record_num]->price);
    printf("계산수단은? (현금:0, 카드:1, 계좌이체:2, 휴대폰:3, 상품권:4, 기타:5) ");
    scanf(" %c", &r[record_num]->paymentMethod);
    printf("기록이 업데이트 되었습니다!\n");
    return 1;
}

int main(){
    Record *r[100];
    int count;
    
    count = createRecord(r,0);
    count = updateRecord(r,0);
}