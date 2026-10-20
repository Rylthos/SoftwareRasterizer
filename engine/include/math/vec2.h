#ifndef MATH_VEC2_H
#define MATH_VEC2_H

#include "math/vec4.h"

typedef union {
  struct {
    float x;
    float y;
  };
  struct {
    float r;
    float g;
  };
  float raw[2];
} Vec2;

Vec2 vec2_new_zero(void);
Vec2 vec2_new_scalar(float v);
Vec2 vec2_new(float x, float y);

Vec2 vec2_add(Vec2 a, Vec2 b);
Vec2 vec2_sub(Vec2 a, Vec2 b);
float vec2_dot(Vec2 a, Vec2 b);
float vec2_cross(Vec2 a, Vec2 b);

Vec2 vec2_scalar(Vec2 a, float t);

#endif
