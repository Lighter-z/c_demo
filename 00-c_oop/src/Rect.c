#include "Rect.h"

#include <stdio.h>
#include <string.h>

static uint32_t RectArea(Shape const * const shape) {
  Rect const * const c_this = (Rect const *)shape;

  return (uint32_t)c_this->height_ * (uint32_t)c_this->width_;
}

static void RectDraw(Shape const * const shape) {
  Rect const * const c_this = (Rect const *)shape;

  printf("RectDraw(x = %d, y = %d, width = %d, height = %d)\r\n",
          ShapeGetX(shape), ShapeGetY(shape), c_this->width_, c_this->height_);
}

void RectInit(Rect * const c_this, uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
  memset(c_this, 0, sizeof(Rect));

  ShapeInit(&c_this->parent_, x, y);
  c_this->width_ = width;
  c_this->height_ = height;

  ////< 多态，重新实现父类的操作方法
  c_this->parent_.ops_.ShapeArea = &RectArea;
  c_this->parent_.ops_.ShapeDraw = &RectDraw;
}

