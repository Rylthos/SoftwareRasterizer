#ifndef RASTERIZER_P_TRIANGLE2D_H
#define RASTERIZER_P_TRIANGLE2D_H

#include "rasterizer/triangle2D.h"

#include "stdbool.h"

typedef struct {
  Vec2 x;
  Vec2 y;
} BoundingBox2D;

BoundingBox2D triangle2D_bounding_box(Triangle2D t);

bool point_within_triangle2D(Triangle2D t, Vec2 p);

#endif
