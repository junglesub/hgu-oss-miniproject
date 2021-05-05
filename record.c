#include "record.h"

#include "stdio.h"

void deleteRecord(Record *r[], int count, int delIndex) {
  // 지우려고 하는 아이템이 총 저장된 갯수보다 많거나 같으면 오류 메세지 출력.
  if (count <= delIndex) {
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
  for (int i = delIndex; i < count - 1; i++) {
    r[i] = r[i + 1];
  }
  r[count - 1] = NULL;  // 마지막 아이템은 NULL 으로 지정.
}