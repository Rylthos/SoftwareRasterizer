#ifndef TEST_MATH_H
#define TEST_MATH_H

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

#endif
