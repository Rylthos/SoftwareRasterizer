#ifndef MATH_VEC3_H
#define MATH_VEC3_H

#include "vec2.h"

typedef union {
  struct {
    float x;
    float y;
    float z;
  };
  struct {
    float r;
    float g;
    float b;
  };
  float raw[3];
} Vec3;

Vec3 vec3_new_zero(void);
Vec3 vec3_new_scalar(float v);
Vec3 vec3_new(float x, float y, float z);

Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_sub(Vec3 a, Vec3 b);
Vec3 vec3_scalar(Vec3 a, float b);
Vec3 vec3_cross(Vec3 a, Vec3 b);

float vec3_dot(Vec3 a, Vec3 b);
float vec3_magnitude_sq(Vec3 v);
float vec3_magnitude(Vec3 v);
Vec3 vec3_norm(Vec3 v);

#endif
