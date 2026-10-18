#ifndef RASTERIZER_VERTEX_H
#define RASTERIZER_VERTEX_H

#include "math/vec2.h"

typedef struct {
  Vec2 pos;
  Vec2 uv;
} Vertex2D;

Vertex2D create_vertex2D(Vec2 pos, Vec2 uv);
Vertex2D create_vertex2D_position(Vec2 pos);

#endif
