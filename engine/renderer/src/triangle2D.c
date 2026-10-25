#include "renderer/triangle2D.h"

#include "renderer/vertex2D.h"

#include "stdio.h"

#include "assert.h"

#include "math/util.h"

Triangle2D create_triangle2D_position(Vec2 a, Vec2 b, Vec2 c) {
  return (Triangle2D){
      .p1 = create_vertex2D_position(a),
      .p2 = create_vertex2D_position(b),
      .p3 = create_vertex2D_position(c),
  };
}

Triangle2D create_triangle2D_points(float x1, float y1, float x2, float y2,
                                    float x3, float y3) {
  return create_triangle2D_position(vec2_new(x1, y1), vec2_new(x2, y2),
                                    vec2_new(x3, y3));
}

Triangle2D create_triangle2D_vertices(Vertex2D v1, Vertex2D v2, Vertex2D v3) {
  return (Triangle2D){v1, v2, v3};
}
