#include <stdio.h>
#include <stdlib.h>

#include "CBList.h"

#define BUFFER_NUM (10)

static void CBListExample(void) {
  int value[BUFFER_NUM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  CBList list_buf[BUFFER_NUM];
  CBList list;
  CBList *list_p = NULL;
  int i = 0;

  ////< 初始化list
  CBListInit(&list, NULL);

  ////< 判断list是否为空
  if(CBListIsEmpty(&list)) {
    printf("list is empty\r\n");
  } else {
    printf("list is not empty\r\n");
  }

  ////< 初始化list_buf，采用尾插法向list中添加节点
  for(i = 0; i < BUFFER_NUM; i++) {
    CBListInit(&list_buf[i], (void *)&value[i]);
    printf("list_buf[%d].data_ = %d\r\n", i, *((int *)list_buf[i].data_));

    CBListInsertAfter(&list, &list_buf[i]);
  }
  
  ////< 判断list是否为空
  if(CBListIsEmpty(&list)) {
    printf("list is empty\r\n");
  } else {
    printf("list is not empty\r\n");
  }

  ////< list长度
  printf("list len = %d\r\n", CBListLen(&list));

  ////< remove list_buf[5]
  CBListRemove(&list_buf[5]);

  ////< 打印移除节点5后的数据
  list_p = &list;
  for(i = 0; i < CBListLen(&list); i++) {
    list_p = list_p->next_;
    printf("data = %d\r\n", *((int *)list_p->data_));
  }

}

int main(void) {

  printf("------------ c list example ------------\r\n");

  CBListExample();

  printf("------------       end      ------------\r\n");
  system("pause");
}
