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
