#include "rasterizer/triangle2D.h"

#include "p_triangle2D.h"
#include "rasterizer/vertex2D.h"

#include "stdio.h"

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

BoundingBox2D triangle2D_bounding_box(Triangle2D t) {
  BoundingBox2D return_box = {
      vec2_new(MIN3(t.p1.pos.x, t.p2.pos.x, t.p3.pos.x),
               MAX3(t.p1.pos.x, t.p2.pos.x, t.p3.pos.x)),
      vec2_new(MIN3(t.p1.pos.y, t.p2.pos.y, t.p3.pos.y),
               MAX3(t.p1.pos.y, t.p2.pos.y, t.p3.pos.y)),
  };
  return return_box;
}

bool vec_right_of(Vec2 a, Vec2 b) { return (a.x * b.y - a.y * b.x) > 0; }

bool point_within_triangle2D(Triangle2D t, Vec2 p) {
  Vec2 ab = vec2_sub(t.p2.pos, t.p1.pos);
  Vec2 bc = vec2_sub(t.p3.pos, t.p2.pos);
  Vec2 ca = vec2_sub(t.p1.pos, t.p3.pos);

  Vec2 ap = vec2_sub(p, t.p1.pos);
  Vec2 bp = vec2_sub(p, t.p2.pos);
  Vec2 cp = vec2_sub(p, t.p3.pos);

  return vec_right_of(ab, ap) && vec_right_of(bc, bp) && vec_right_of(ca, cp);
}
