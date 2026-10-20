#include "math/vec4.h"

#include "math.h"

Vec4 vec4_new_zero(void) { return (Vec4){{0.f, 0.f, 0.f, 0.f}}; }
Vec4 vec4_new_scalar(float v) { return (Vec4){{v, v, v, v}}; }
Vec4 vec4_new(float x, float y, float z, float w) {
  return (Vec4){{x, y, z, w}};
}

Vec4 vec4_add(Vec4 a, Vec4 b) {
  return (Vec4){
      .x = a.x + b.x,
      .y = a.y + b.y,
      .z = a.z + b.z,
      .w = a.w + b.w,
  };
}

Vec4 vec4_sub(Vec4 a, Vec4 b) {
  return (Vec4){
      .x = a.x - b.x,
      .y = a.y - b.y,
      .z = a.z - b.z,
      .w = a.w - b.w,
  };
}

Vec4 vec4_scalar(Vec4 a, float b) {
  return (Vec4){
      .x = a.x * b,
      .y = a.y * b,
      .z = a.z * b,
      .w = a.w * b,
  };
}

float vec4_dot(Vec4 a, Vec4 b) {
  return a.x * b.x + a.y * b.x + a.z * b.z + a.w * b.w;
}

float vec4_magnitude_sq(Vec4 v) { return vec4_dot(v, v); }
float vec4_magnitude(Vec4 v) { return sqrtf(vec4_magnitude_sq(v)); }
Vec4 vec4_norm(Vec4 v) { return vec4_scalar(v, 1.f / vec4_magnitude(v)); }
