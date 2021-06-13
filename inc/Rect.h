#ifndef INCLUDE_RECT_H__
#define INCLUDE_RECT_H__

#include "Shape.h"

typedef struct _Rect Rect;

struct _Rect {
  Shape parent_;

  uint16_t width_;
  uint16_t height_;
};

void RectInit(Rect * const c_this, uint16_t x, uint16_t y, uint16_t width, uint16_t height);

#endif /* INCLUDE_RECT_H__ */
