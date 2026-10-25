#ifndef MATH_VEC4_H
#define MATH_VEC4_H

typedef union {
  struct {
    float x;
    float y;
    float z;
    float w;
  };
  struct {
    float r;
    float g;
    float b;
    float a;
  };
  float raw[4];
} Vec4;

Vec4 vec4_new_zero(void);
Vec4 vec4_new_scalar(float v);
Vec4 vec4_new(float x, float y, float z, float w);

Vec4 vec4_add(Vec4 a, Vec4 b);
Vec4 vec4_sub(Vec4 a, Vec4 b);
Vec4 vec4_scalar(Vec4 a, float b);

float vec4_2d_det(Vec4 a, Vec4 b);

float vec4_dot(Vec4 a, Vec4 b);
float vec4_magnitude_sq(Vec4 v);
float vec4_magnitude(Vec4 v);
Vec4 vec4_norm(Vec4 v);

#endif
