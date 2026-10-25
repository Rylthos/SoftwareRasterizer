#ifndef MATH_MAT4X4_H
#define MATH_MAT4X4_H

#include "math/vec3.h"

typedef union {
  struct {
    float d00, d01, d02, d03;
    float d10, d11, d12, d13;
    float d20, d21, d22, d23;
    float d30, d31, d32, d33;
  };
  float raw[16];
} Mat4x4;

Mat4x4 mat4x4_scalar(float v);
Mat4x4 mat4x4_zero();
Mat4x4 mat4x4_identity();

Mat4x4 mat4x4_translate(Mat4x4 base, Vec3 translate);
Mat4x4 mat4x4_scale(Mat4x4 base, float scale);

Mat4x4 mat4x4_rotate_x(Mat4x4 base, float angle);
Mat4x4 mat4x4_rotate_y(Mat4x4 base, float angle);
Mat4x4 mat4x4_rotate_z(Mat4x4 base, float angle);

Mat4x4 mat4x4_mul_mat4x4(Mat4x4 left, Mat4x4 right);
Vec4 mat4x4_mul_vec4(Mat4x4 left, Vec4 right);

#endif
