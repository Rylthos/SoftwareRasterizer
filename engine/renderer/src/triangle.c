#include "triangle.h"

#include "float.h"

#include "assert.h"
#include "math/math.h"

#include "stdio.h"

BoundingBox2D triangle_bounding_box(const Triangle *t) {
  BoundingBox2D return_box = {
      vec2_new(MIN3(t->p1.pos.x, t->p2.pos.x, t->p3.pos.x),
               MAX3(t->p1.pos.x, t->p2.pos.x, t->p3.pos.x)),
      vec2_new(MIN3(t->p1.pos.y, t->p2.pos.y, t->p3.pos.y),
               MAX3(t->p1.pos.y, t->p2.pos.y, t->p3.pos.y)),
  };
  return return_box;
}

Vec3 triangle_barycentre(const Triangle *t, Vec2 point) {
  float denom = vec4_2d_det(vec4_sub(t->p1.pos, t->p3.pos),
                            vec4_sub(t->p2.pos, t->p3.pos));

  float alpha =
      vec4_2d_det(vec4_sub(vec4_from_vec2(point, 0.f, 0.f), t->p3.pos),
                  vec4_sub(t->p2.pos, t->p3.pos)) /
      denom;

  float beta = vec4_2d_det(vec4_sub(vec4_from_vec2(point, 0.f, 0.f), t->p3.pos),
                           vec4_sub(t->p3.pos, t->p1.pos)) /
               denom;
  float gamma = 1.f - alpha - beta;

  assert(alpha >= -FLT_EPSILON && "Point expected inside triangle");
  assert(beta >= -FLT_EPSILON && "Point expected inside triangle");
  assert(gamma >= -FLT_EPSILON && "Point expected inside triangle");

  return vec3_new(alpha, beta, gamma);
}

bool vec_right_of(Vec4 a, Vec4 b) { return vec4_2d_det(a, b) >= 0; }

bool point_within_triangle(const Triangle *t, Vec2 p) {
  Vec4 ab = vec4_sub(t->p2.pos, t->p1.pos);
  Vec4 bc = vec4_sub(t->p3.pos, t->p2.pos);
  Vec4 ca = vec4_sub(t->p1.pos, t->p3.pos);

  Vec4 ap = vec4_sub(vec4_from_vec2(p, 0.f, 0.f), t->p1.pos);
  Vec4 bp = vec4_sub(vec4_from_vec2(p, 0.f, 0.f), t->p2.pos);
  Vec4 cp = vec4_sub(vec4_from_vec2(p, 0.f, 0.f), t->p3.pos);

  return vec_right_of(ab, ap) && vec_right_of(bc, bp) && vec_right_of(ca, cp);
}
