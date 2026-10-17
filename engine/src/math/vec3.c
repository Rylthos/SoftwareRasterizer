#include "math/vec3.h"

#include "math.h"

Vec3 vec3_add(Vec3 a, Vec3 b) {
  Vec3 return_vec = {
      .x = a.x + b.x,
      .y = a.y + b.y,
      .z = a.z + b.z,
  };

  return return_vec;
}

Vec3 vec3_sub(Vec3 a, Vec3 b) {
  Vec3 return_vec = {
      .x = a.x - b.x,
      .y = a.y - b.y,
      .z = a.z - b.z,
  };

  return return_vec;
}

Vec3 vec3_scalar(Vec3 a, float b) {
  Vec3 return_vec = {
      .x = a.x * b,
      .y = a.y * b,
      .z = a.z * b,
  };

  return return_vec;
}

Vec3 vec3_cross(Vec3 a, Vec3 b) {
  Vec3 return_vec = {
      .x = a.y * b.z - a.z * b.y,
      .y = a.z * b.x - a.x * b.z,
      .z = a.x * b.y - a.y * b.x,
  };

  return return_vec;
}

float vec3_dot(Vec3 a, Vec3 b) { return a.x * b.x + a.y * b.x + a.z * b.z; }

float vec3_magnitude_sq(Vec3 v) { return vec3_dot(v, v); }
float vec3_magnitude(Vec3 v) { return sqrtf(vec3_magnitude_sq(v)); }
Vec3 vec3_norm(Vec3 v) { return vec3_scalar(v, 1.f / vec3_magnitude(v)); }
