#include "Shape.h"

#include <string.h>
#include <assert.h>

static uint32_t ShapeArea(Shape const * const c_this) {
  assert(0);
  return 0;
}
static void ShapeDraw(Shape const * const c_this) {
  assert(0);
}

void ShapeMove(Shape * const c_this, uint16_t dx, uint16_t dy) {
  c_this->x_ += dx;
  c_this->y_ += dy;
}

uint16_t ShapeGetX(Shape const * const c_this) {
  return c_this->x_;
}

uint16_t ShapeGetY(Shape const * const c_this) {
  return c_this->y_;
}

void ShapeInit(Shape * const c_this, uint16_t x, uint16_t y) {
  memset(c_this, 0, sizeof(Shape));

  c_this->x_ = x;
  c_this->y_ = y;
  c_this->ops_.ShapeArea = &ShapeArea;
  c_this->ops_.ShapeDraw = &ShapeDraw;
}
