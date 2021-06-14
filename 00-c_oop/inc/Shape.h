#ifndef INC_SHAPE_H__
#define INC_SHAPE_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct _Shape Shape;

/**
 * @brief		Shape类操作方法
 * @details
 */
typedef struct _ShapeOps {
  uint32_t (* ShapeArea)(Shape const * const c_this);
  void (* ShapeDraw)(Shape const * const c_this);
} ShapeOps;

/**
 * @brief		Shape类
 * @details
 */
struct _Shape {
  uint16_t x_;
  uint16_t y_;
  ShapeOps ops_;
};

/**
 * @brief		移动Shape
 * @details
 * @param[in]	  c_this 构造对象指针
 * @param[in]	  dx 
 * @param[in]	  dy 
 * @retval		  void
 */
void ShapeMove(Shape * const c_this, uint16_t dx, uint16_t dy);

/**
 * @brief		获取X参数
 * @details 
 * @param[in]	  c_this 构造对象指针
 * @retval		  X value
 */
uint16_t ShapeGetX(Shape const * const c_this);

/**
 * @brief		获取Y参数
 * @details 
 * @param[in]	  c_this 构造对象指针
 * @retval		  Y value
 */
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

#ifdef __cplusplus
}
#endif

#endif /* INC_SHAPE_H__ */
