#include "rasterizer/triangle.h"

#include "p_triangle.h"

Triangle create_triangle(Vec3 a, Vec3 b, Vec3 c) {
  Triangle return_triangle = {
      .p1 = a,
      .p2 = b,
      .p3 = c,
  };

  return return_triangle;
}

Triangle create_triangle_points(float x1, float y1, float x2, float y2,
                                float x3, float y3) {
  Vec3 a = {.x = x1, .y = y1, .z = 0.f};
  Vec3 b = {.x = x2, .y = y2, .z = 0.f};
  Vec3 c = {.x = x3, .y = y3, .z = 0.f};
  return create_triangle(a, b, c);
}

BoundingBox triangle_bounding_box(Triangle t) {
  BoundingBox return_box = {
      .x_min = MIN3(t.p1.x, t.p2.x, t.p3.x),
      .x_max = MAX3(t.p1.x, t.p2.x, t.p3.x),
      .y_min = MIN3(t.p1.y, t.p2.y, t.p3.y),
      .y_max = MAX3(t.p1.y, t.p2.y, t.p3.y),
  };
  return return_box;
}

bool vec_right_of(Vec3 a, Vec3 b) { return vec3_cross(a, b).z > 0; }

bool point_within_triangle(Triangle t, Vec3 p) {
  Vec3 ab = vec3_sub(t.p2, t.p1);
  Vec3 bc = vec3_sub(t.p3, t.p2);
  Vec3 ca = vec3_sub(t.p1, t.p3);

  Vec3 ap = vec3_sub(p, t.p1);
  Vec3 bp = vec3_sub(p, t.p2);
  Vec3 cp = vec3_sub(p, t.p3);

  return vec_right_of(ab, ap) && vec_right_of(bc, bp) && vec_right_of(ca, cp);
}
