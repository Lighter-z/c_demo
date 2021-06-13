#include "main.h"

//继承
static void InheritanceMethod(void) {
  ////< 实例化对象
  Rect rect1, rect2;

  RectInit(&rect1, 0, 5, 10, 15);
  RectInit(&rect2, 10, 20, 10, 20);

  printf("rect 1: x = %d, y = %d, width = %d, height = %d \r\n", ShapeGetX(&rect1.parent_), ShapeGetY(&rect1.parent_), rect1.width_, rect1.height_);
  printf("rect 2: x = %d, y = %d, width = %d, height = %d \r\n", ShapeGetX(&rect2.parent_), ShapeGetY(&rect2.parent_), rect2.width_, rect2.height_);

  /* 注意: 传递父类指针时有两种方法
   * 方法一: 通过子类指向父类地址.
   * 方法二: 子类地址直接强转为父类指针
   * 建议使用方法一
   */
  ShapeMove(&rect1.parent_, 10, 10);
  ShapeMove((Shape *)&rect2, 10, 10);

  printf("rect 1: x = %d, y = %d, width = %d, height = %d \r\n", ShapeGetX(&rect1.parent_), ShapeGetY(&rect1.parent_), rect1.width_, rect1.height_);
  printf("rect 2: x = %d, y = %d, width = %d, height = %d \r\n", ShapeGetX(&rect2.parent_), ShapeGetY(&rect2.parent_), rect2.width_, rect2.height_);

}

//多态
static void PolymorphismMethod(void) {
  ////< 实例化对象
  Rect rect;

  RectInit(&rect, 0, 5, 10, 15);

  printf("rect : x = %d, y = %d, width = %d, height = %d \r\n", ShapeGetX(&rect.parent_), ShapeGetY(&rect.parent_), rect.width_, rect.height_);
  printf("rect area = %d\r\n", rect.parent_.ops_.ShapeArea(&rect.parent_));
  rect.parent_.ops_.ShapeDraw(&rect.parent_);

}

int main(void) {

  printf("------------ c oop example ------------\r\n");
  printf("----- InheritanceMethod -----\r\n");
  InheritanceMethod();
  printf("----- PolymorphismMethod -----\r\n");
  PolymorphismMethod();
  printf("------------       end     ------------\r\n");
  system("pause");
}