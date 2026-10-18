#include "rasterizer/triangle2D.h"

#include "p_triangle2D.h"
#include "rasterizer/vertex2D.h"

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

Vec3 triangle2D_barcentre(Triangle2D t, Vec2 point) {
  float denom =
      vec2_cross(vec2_sub(t.p1.pos, t.p3.pos), vec2_sub(t.p2.pos, t.p3.pos));

  float alpha =
      vec2_cross(vec2_sub(point, t.p3.pos), vec2_sub(t.p2.pos, t.p3.pos)) /
      denom;
  float beta =
      vec2_cross(vec2_sub(point, t.p3.pos), vec2_sub(t.p3.pos, t.p1.pos)) /
      denom;
  float gamma = 1.f - alpha - beta;

  assert(alpha >= 0.f && "Point expected inside triangle");
  assert(beta >= 0.f && "Point expected inside triangle");
  assert(gamma >= 0.f && "Point expected inside triangle");

  return vec3_new(alpha, beta, gamma);
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

Vec2 triangle2D_interpolate_uv(Triangle2D t, Vec2 p) {
  Vec3 uvs = triangle2D_barcentre(t, p);

  Vec2 p1 = vec2_scalar(t.p1.uv, uvs.x);
  Vec2 p2 = vec2_scalar(t.p2.uv, uvs.y);
  Vec2 p3 = vec2_scalar(t.p3.uv, uvs.z);

  return vec2_add(vec2_add(p1, p2), p3);
}
