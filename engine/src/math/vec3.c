#include "math/vec3.h"

#include "math.h"

Vec3 vec3_new_zero(void) { return (Vec3){{0.f, 0.f, 0.f}}; }
Vec3 vec3_new_single(float v) { return (Vec3){{v, v, v}}; }
Vec3 vec3_new(float x, float y, float z) { return (Vec3){{x, y, z}}; }

Vec3 vec3_add(Vec3 a, Vec3 b) {
  return (Vec3){
      .x = a.x + b.x,
      .y = a.y + b.y,
      .z = a.z + b.z,
  };
}

Vec3 vec3_sub(Vec3 a, Vec3 b) {
  return (Vec3){
      .x = a.x - b.x,
      .y = a.y - b.y,
      .z = a.z - b.z,
  };
}

Vec3 vec3_scalar(Vec3 a, float b) {
  return (Vec3){
      .x = a.x * b,
      .y = a.y * b,
      .z = a.z * b,
  };
}

Vec3 vec3_cross(Vec3 a, Vec3 b) {
  return (Vec3){
      .x = a.y * b.z - a.z * b.y,
      .y = a.z * b.x - a.x * b.z,
      .z = a.x * b.y - a.y * b.x,
  };
}

float vec3_dot(Vec3 a, Vec3 b) { return a.x * b.x + a.y * b.x + a.z * b.z; }

float vec3_magnitude_sq(Vec3 v) { return vec3_dot(v, v); }
float vec3_magnitude(Vec3 v) { return sqrtf(vec3_magnitude_sq(v)); }
Vec3 vec3_norm(Vec3 v) { return vec3_scalar(v, 1.f / vec3_magnitude(v)); }
