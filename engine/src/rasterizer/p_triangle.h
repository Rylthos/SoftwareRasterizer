#ifndef RASTERIZER_P_TRIANGLE_H
#define RASTERIZER_P_TRIANGLE_H

#include "rasterizer/triangle.h"

#include "stdbool.h"

#include "math/util.h"

typedef struct {
  float x_min;
  float x_max;
  float y_min;
  float y_max;
} BoundingBox;

BoundingBox triangle_bounding_box(Triangle t);

bool point_within_triangle(Triangle t, Vec3 p);

#endif
