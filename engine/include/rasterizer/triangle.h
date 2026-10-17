#ifndef RASTERIZER_TRIANGLE_H
#define RASTERIZER_TRIANGLE_H

#include "math/vec3.h"

typedef struct {
  Vec3 p1;
  Vec3 p2;
  Vec3 p3;
} Triangle;

Triangle create_triangle(Vec3 a, Vec3 b, Vec3 c);
Triangle create_triangle_points(float x1, float y1, float x2, float y2,
                                float x3, float y3);

#endif
