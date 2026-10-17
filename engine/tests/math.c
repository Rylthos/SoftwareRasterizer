#include "math.h"

#include "test.h"

#include "math/u8vec3.h"
#include "math/util.h"
#include "math/vec3.h"

void test_min_max(void) {
  ASSERT(MIN(0, 1) == 0);
  ASSERT(MIN(1, 1) == 1);
  ASSERT(MAX(0, 1) == 1);
  ASSERT(MAX(1, 1) == 1);
}

void test_u8vec3_from_vec3(void) {
  Vec3 vec1 = {
      .x = 1.0f,
      .y = 1.0f,
      .z = 1.0f,
  };

  Vec3 vec2 = {
      .x = 0.f,
      .y = 0.f,
      .z = 0.f,
  };

  Vec3 vec3 = {
      .x = 0.5f,
      .y = 0.5f,
      .z = 0.5f,
  };

  U8Vec3 u8vec1 = u8vec3_from_vec3(vec1);
  U8Vec3 u8vec2 = u8vec3_from_vec3(vec2);
  U8Vec3 u8vec3 = u8vec3_from_vec3(vec3);

  ASSERT_MSG(TVEC3_MATCH_COMP(u8vec1, 255, 255, 255),
             "Expected (255, 255, 255) got" U8VEC3_FORMAT "\n",
             TVEC3_PRINT(u8vec1));

  ASSERT_MSG(TVEC3_MATCH_COMP(u8vec2, 0, 0, 0),
             "Expected (0, 0, 0) got" U8VEC3_FORMAT "\n", TVEC3_PRINT(u8vec2));

  ASSERT_MSG(TVEC3_MATCH_COMP(u8vec3, 127, 127, 127),
             "Expected (127, 127, 127) got" U8VEC3_FORMAT "\n",
             TVEC3_PRINT(u8vec3));
}

void test_vec3_add(void) {
  Vec3 vec1 = {
      .x = 0.f,
      .y = 0.f,
      .z = 0.f,
  };
  Vec3 vec2 = {
      .x = 1.f,
      .y = 1.f,
      .z = 1.f,
  };

  Vec3 result = vec3_add(vec1, vec2);
  ASSERT_MSG(TVEC3_MATCH_COMP(result, 1.f, 1.f, 1.f),
             "Expected (1., 1., 1.) got " VEC3_FORMAT "\n",
             TVEC3_PRINT(result));
}

void run_tests(void) {
  test_min_max();
  test_u8vec3_from_vec3();
}
