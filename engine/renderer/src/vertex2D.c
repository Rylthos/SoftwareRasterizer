#include "renderer/vertex2D.h"

#include "math/vec2.h"

Vertex2D create_vertex2D(Vec2 pos, Vec2 uv) { return (Vertex2D){pos, uv}; }

Vertex2D create_vertex2D_position(Vec2 pos) {
  return (Vertex2D){pos, vec2_new_zero()};
}
