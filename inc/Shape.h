#ifndef INCLUDE_SHAPE_H__
#define INCLUDE_SHAPE_H__

#include <stdint.h>

typedef struct _Shape Shape;

typedef struct _ShapeOps {
  uint32_t (* ShapeArea)(Shape const * const c_this);
  void (* ShapeDraw)(Shape const * const c_this);
} ShapeOps;

struct _Shape {
  uint16_t x_;
  uint16_t y_;
  ShapeOps ops_;
};

void ShapeMove(Shape * const c_this, uint16_t dx, uint16_t dy);
uint16_t ShapeGetX(Shape const * const c_this);
uint16_t ShapeGetY(Shape const * const c_this);

 /**
 * @brief		Shape类构造函数
 * @details
 * @param[in]	  c_this 构造对象指针
 * @param[in]	  x 初始化x值
 * @param[in]	  y 初始化y值
 * @retval		  void
 */
void ShapeInit(Shape * const c_this, uint16_t x, uint16_t y);

#endif /* INCLUDE_SHAPE_H__ */
