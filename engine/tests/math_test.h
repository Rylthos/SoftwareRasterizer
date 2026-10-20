#ifndef TEST_MATH_H
#define TEST_MATH_H

#include "math/mat4x4.h"
#include "test.h"

#include "math/math.h"

ADD_TEST("math", min_max, {
  ASSERT(MIN(0, 1) == 0);
  ASSERT(MIN(1, 1) == 1);
  ASSERT(MAX(0, 1) == 1);
  ASSERT(MAX(1, 1) == 1);
})

ADD_TEST("math", u8vec3_from_vec3, {
  Vec3 vec1 = vec3_new(1.0f, 1.0f, 1.0f);
  Vec3 vec2 = vec3_new(0.0f, 0.0f, 0.0f);
  Vec3 vec3 = vec3_new(0.5f, 0.5f, 0.5f);
  Vec3 vec4 = vec3_new(0.f, 0.5f, 1.f);

  U8Vec3 u8vec1 = u8vec3_from_vec3(vec1);
  U8Vec3 u8vec2 = u8vec3_from_vec3(vec2);
  U8Vec3 u8vec3 = u8vec3_from_vec3(vec3);
  U8Vec3 u8vec4 = u8vec3_from_vec3(vec4);

  ASSERT_MSG(TVEC3_MATCH_COMP(u8vec1, 255, 255, 255),
             "Expected (255, 255, 255) got" U8VEC3_FORMAT "\n",
             TVEC3_PRINT(u8vec1));

  ASSERT_MSG(TVEC3_MATCH_COMP(u8vec2, 0, 0, 0),
             "Expected (0, 0, 0) got" U8VEC3_FORMAT "\n", TVEC3_PRINT(u8vec2));

  ASSERT_MSG(TVEC3_MATCH_COMP(u8vec3, 127, 127, 127),
             "Expected (127, 127, 127) got" U8VEC3_FORMAT "\n",
             TVEC3_PRINT(u8vec3));

  ASSERT_MSG(TVEC3_MATCH_COMP(u8vec4, 0, 127, 255),
             "Expected (0, 127, 255) got" U8VEC3_FORMAT "\n",
             TVEC3_PRINT(u8vec4));
})

ADD_TEST("math", vec3_add, {
  Vec3 vec1 = vec3_new(0.f, 1.f, 2.f);
  Vec3 vec2 = vec3_new(1.f, 2.f, 3.f);

  Vec3 result = vec3_add(vec1, vec2);
  ASSERT_MSG(TVEC3_MATCH_COMP(result, 1.f, 3.f, 5.f),
             "Expected (1., 1., 1.) got " VEC3_FORMAT "\n",
             TVEC3_PRINT(result));
})

ADD_TEST("math", mat4x4_mul_mat4x4, {
  Mat4x4 m1 = mat4x4_scalar(1.f);
  Mat4x4 m2 = mat4x4_scalar(1.f);
  Mat4x4 result = mat4x4_mul_mat4x4(m1, m2);

  ASSERT(MAT4x4_MATCH_MAT4x4(result, mat4x4_scalar(1.f)));

  m2 = mat4x4_scalar(2.f);
  result = mat4x4_mul_mat4x4(m1, m2);
  ASSERT(MAT4x4_MATCH_MAT4x4(result, mat4x4_scalar(2.f)));

  m1 = mat4x4_scalar(2.f);
  result = mat4x4_mul_mat4x4(m1, m2);
  ASSERT(MAT4x4_MATCH_MAT4x4(result, mat4x4_scalar(4.f)));
})

ADD_TEST("math", mat4x4_mul_vec4, {
  Mat4x4 m1 = mat4x4_scalar(1.f);
  Vec4 vec = vec4_new_scalar(1.f);
  Vec4 result = mat4x4_mul_vec4(m1, vec);
  ASSERT_MSG(TVEC4_MATCH_COMP(result, 1.f, 1.f, 1.f, 1.f),
             "Got " VEC4_FORMAT "\n", TVEC4_PRINT(result));

  m1 = mat4x4_scalar(2.f);
  result = mat4x4_mul_vec4(m1, vec);
  ASSERT_MSG(TVEC4_MATCH_COMP(result, 2.f, 2.f, 2.f, 2.f),
             "Got " VEC4_FORMAT "\n", TVEC4_PRINT(result));
})

ADD_TEST("math", mat4x4_transform, {
  Mat4x4 base = mat4x4_identity();
  base = mat4x4_scale(base, 2.f);
  base = mat4x4_translate(base, vec3_new(2.f, 2.f, 2.f));

  Vec4 vec = vec4_new_scalar(1.f);

  Vec4 result = mat4x4_mul_vec4(base, vec);

  ASSERT_MSG(TVEC4_MATCH_COMP(result, 4.f, 4.f, 4.f, 1.f),
             "Scale Translate: " VEC4_FORMAT "\n", TVEC4_PRINT(result));

  base = mat4x4_identity();
  base = mat4x4_rotate_x(base, -HALF_PI);
  vec = vec4_new(1.f, 1.f, 0.f, 1.f);
  result = mat4x4_mul_vec4(base, vec);
  ASSERT_MSG(TVEC4_MATCH_COMP(result, 1.f, 0.f, -1.f, 1.f),
             "Rot X: " VEC4_FORMAT "\n", TVEC4_PRINT(result));

  base = mat4x4_identity();
  base = mat4x4_rotate_y(base, -HALF_PI);
  vec = vec4_new(1.f, 1.f, 0.f, 1.f);
  result = mat4x4_mul_vec4(base, vec);
  ASSERT_MSG(TVEC4_MATCH_COMP(result, 0.f, 1.f, 1.f, 1.f),
             "Rot Y: " VEC4_FORMAT "\n", TVEC4_PRINT(result));

  base = mat4x4_identity();
  base = mat4x4_rotate_z(base, -HALF_PI);
  vec = vec4_new(1.f, 1.f, 0.f, 1.f);
  result = mat4x4_mul_vec4(base, vec);
  ASSERT_MSG(TVEC4_MATCH_COMP(result, 1.f, -1.f, 0.f, 1.f),
             "Rot Z: " VEC4_FORMAT "\n", TVEC4_PRINT(result));
})

#endif
