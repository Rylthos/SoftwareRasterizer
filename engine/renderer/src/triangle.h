#ifndef RASTERIZER_TRIANGLE_H
#define RASTERIZER_TRIANGLE_H

#include "math/vec2.h"
#include "math/vec4.h"

typedef struct {
  Vec4 pos;
} Vertex;

typedef struct {
  Vertex p1;
  Vertex p2;
  Vertex p3;
} Triangle;

typedef struct {
  Vec2 x;
  Vec2 y;
} BoundingBox2D;

BoundingBox2D triangle_bounding_box(Triangle t);

bool point_within_triangle(Triangle t, Vec2 p);

// Vec2 triangle2D_interpolate_uv(Triangle t, Vec2 p);

#endif
