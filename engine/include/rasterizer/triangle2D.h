#ifndef RASTERIZER_TRIANGLE_H
#define RASTERIZER_TRIANGLE_H

#include "math/vec2.h"
#include "math/vec3.h"

#include "rasterizer/vertex2D.h"

typedef struct {
  Vertex2D p1;
  Vertex2D p2;
  Vertex2D p3;
} Triangle2D;

Triangle2D create_triangle2D_position(Vec2 a, Vec2 b, Vec2 c);
Triangle2D create_triangle2D_points(float x1, float y1, float x2, float y2,
                                    float x3, float y3);
Triangle2D create_triangle2D_vertices(Vertex2D v1, Vertex2D v2, Vertex2D v3);

Vec3 triangle2D_barcentre(Triangle2D t, Vec2 point);

#endif
