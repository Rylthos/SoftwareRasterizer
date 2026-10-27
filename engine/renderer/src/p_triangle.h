#ifndef RENDERER_TRIANGLE_H
#define RENDERER_TRIANGLE_H

#include "math/vec2.h"
#include "math/vec4.h"

#include "generic/array.h"
#include "renderer/uniform.h"

#include <stdlib.h>

typedef struct {
  Vec4 pos;
  ARRAY(ShaderUniform) uniforms;
} Vertex;

typedef struct {
  Vertex p1;
  Vertex p2;
  Vertex p3;
} Triangle;

typedef struct {
  size_t i1;
  size_t i2;
  size_t i3;
} TriangleIndices;

typedef struct {
  Vec2 x;
  Vec2 y;
} BoundingBox2D;

BoundingBox2D triangle_bounding_box(const Triangle *t);

Vec3 triangle_barycentre(const Triangle *t, Vec2 point);

bool point_within_triangle(const Triangle *t, Vec2 p);

#endif
