#ifndef INC_RECT_H__
#define INC_RECT_H__

#include "Shape.h"

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct _Rect Rect;

/**
 * @brief		Rect类
 * @details
 */
struct _Rect {
  Shape parent_;     ////< 继承Shape类

  uint16_t width_;
  uint16_t height_;
};

/**
 * @brief		Shape类构造函数
 * @details
 * @param[in]	  c_this 构造对象指针
 * @param[in]	  x 初始化x值
 * @param[in]	  y 初始化y值
 * @param[in]	  width 初始化x值
 * @param[in]	  height 初始化y值
 * @retval		  void
 */
void RectInit(Rect * const c_this, uint16_t x, uint16_t y, uint16_t width, uint16_t height);

#ifdef __cplusplus
}
#endif

#endif /* INC_RECT_H__ */
