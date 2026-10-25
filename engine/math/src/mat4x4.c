#include "math/mat4x4.h"

#include "math.h"

Mat4x4 mat4x4_scalar(float v) {
  return (Mat4x4){
      // clang-format off
      {
          v, 0.f, 0.f, 0.f,
          0.f, v, 0.f, 0.f,
          0.f, 0.f, v, 0.f,
          0.f, 0.f, 0.f, v,
      },
      // clang-format on
  };
}

Mat4x4 mat4x4_zero() { return mat4x4_scalar(0.f); }
Mat4x4 mat4x4_identity() { return mat4x4_scalar(1.f); }

Mat4x4 mat4x4_translate(Mat4x4 base, Vec3 translate) {
  Mat4x4 translate_matrix = mat4x4_identity();
  translate_matrix.d03 = translate.x;
  translate_matrix.d13 = translate.y;
  translate_matrix.d23 = translate.z;

  return mat4x4_mul_mat4x4(translate_matrix, base);
}

Mat4x4 mat4x4_scale(Mat4x4 base, float scale) {
  Mat4x4 scale_matrix = mat4x4_identity();
  scale_matrix.d00 = scale;
  scale_matrix.d11 = scale;
  scale_matrix.d22 = scale;

  return mat4x4_mul_mat4x4(scale_matrix, base);
}

Mat4x4 mat4x4_rotate_x(Mat4x4 base, float angle) {
  Mat4x4 rot_x_matrix = mat4x4_identity();

  rot_x_matrix.d11 = cos(angle);
  rot_x_matrix.d12 = -sin(angle);
  rot_x_matrix.d21 = sin(angle);
  rot_x_matrix.d22 = cos(angle);

  return mat4x4_mul_mat4x4(rot_x_matrix, base);
}

Mat4x4 mat4x4_rotate_y(Mat4x4 base, float angle) {
  Mat4x4 rot_y_matrix = mat4x4_identity();

  rot_y_matrix.d00 = cos(angle);
  rot_y_matrix.d02 = sin(angle);
  rot_y_matrix.d20 = -sin(angle);
  rot_y_matrix.d22 = cos(angle);

  return mat4x4_mul_mat4x4(rot_y_matrix, base);
}

Mat4x4 mat4x4_rotate_z(Mat4x4 base, float angle) {
  Mat4x4 rot_z_matrix = mat4x4_identity();

  rot_z_matrix.d00 = cos(angle);
  rot_z_matrix.d01 = -sin(angle);
  rot_z_matrix.d10 = sin(angle);
  rot_z_matrix.d11 = cos(angle);

  return mat4x4_mul_mat4x4(rot_z_matrix, base);
}

Mat4x4 mat4x4_mul_mat4x4(Mat4x4 left, Mat4x4 right) {
  Mat4x4 result = mat4x4_zero();

  for (int x = 0; x < 4; x++) {
    for (int y = 0; y < 4; y++) {
      for (int i = 0; i < 4; i++) {
        result.raw[x + y * 4] += left.raw[i + y * 4] * right.raw[x + i * 4];
      }
    }
  }

  return result;
}

Vec4 mat4x4_mul_vec4(Mat4x4 left, Vec4 right) {
  return (Vec4){
      .x = vec4_dot(right, vec4_new(left.d00, left.d01, left.d02, left.d03)),
      .y = vec4_dot(right, vec4_new(left.d10, left.d11, left.d12, left.d13)),
      .z = vec4_dot(right, vec4_new(left.d20, left.d21, left.d22, left.d23)),
      .w = vec4_dot(right, vec4_new(left.d30, left.d31, left.d32, left.d33)),
  };
}
