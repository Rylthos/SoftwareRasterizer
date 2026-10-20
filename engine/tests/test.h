#ifndef TEST_H
#define TEST_H

#include "assert.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"

typedef enum {
  TEST_SUCCESS = 0,
  TEST_FAILURE,
} TestResult;

#define MAX_FAILURE_MSG_LEN 1024
static char test_messages[MAX_FAILURE_MSG_LEN];
static int test_message_index = 0;

void add_test_message(const char *msg);
void print_test_messages(const char *test_name, TestResult result);

#define TVEC3_MATCH_COMP(v1, a, b, c)                                          \
  ((int)(v1).x == (int)(a) && (int)(v1).y == (int)(b) &&                       \
   (int)(v1).z == (int)(c))

#define TVEC4_MATCH_COMP(v1, a, b, c, d)                                       \
  (round((v1).x) == a && round((v1).y) == (b) && round((v1).z) == (c) &&       \
   round((v1).w) == d)

#define TVEC3_MATCH_TVEC3(v1, v2)                                              \
  ((v1).x == (v2).x && (v1).y == (v2).y && (v1).z == (v2).z)

#define MAT4x4_MATCH_MAT4x4(m1, m2)                                            \
  memcmp(m1.raw, m2.raw, 16 * sizeof(float)) == 0

#define VEC3_FORMAT "(%.3f, %.3f, %.3f)"
#define VEC4_FORMAT "(%.3f, %.3f, %.3f, %.3f)"
#define U8VEC3_FORMAT "(%d, %d, %d)"

#define MAT4x4_FORMAT                                                          \
  "([%.3f, %.3f, %.3f, %.3f], [%.3f, %.3f, %.3f, %.3f], [%.3f, %.3f, %.3f, "   \
  "%.3f], [%.3f, %.3f, %.3f, %.3f])"

#define TVEC3_PRINT(v) (v).x, (v).y, (v).z
#define TVEC4_PRINT(v) (v).x, (v).y, (v).z, (v).w

#define MAT4x4_PRINT(v)                                                        \
  (v).raw[0], (v).raw[1], (v).raw[2], (v).raw[3], (v).raw[4], (v).raw[5],      \
      (v).raw[6], (v).raw[7], (v).raw[8], (v).raw[9], (v).raw[10],             \
      (v).raw[11], (v).raw[12], (v).raw[13], (v).raw[14], (v).raw[15]

#define ASSERT_MSG(cond, ...)                                                  \
  do {                                                                         \
    if (!(cond)) {                                                             \
      char MSG[1024];                                                          \
      int len = sprintf(MSG, "\t[%s:%d] ", __FILE__, __LINE__);                \
      len += sprintf(MSG + len, __VA_ARGS__);                                  \
      sprintf(MSG + len, "\n");                                                \
      add_test_message(MSG);                                                   \
      _test_result = TEST_FAILURE;                                             \
    }                                                                          \
  } while (0)

#define ASSERT(cond) ASSERT_MSG((cond), "" #cond)

typedef void (*test_func_t)(const char *);

typedef struct {
  const char *name;
  test_func_t func;
} TestCase;

#define MAX_TESTS 100
static TestCase test_registry[MAX_TESTS];
static int test_count = 0;

void register_test(const char *name, test_func_t func);

#define ADD_TEST(region_name, func_name, ...)                                  \
  static void test_##func_name(const char *);                                  \
  __attribute__((constructor)) static void register_##func_name(void) {        \
    register_test("[" region_name "] " #func_name, test_##func_name);          \
  }                                                                            \
  static void test_##func_name(const char *_test_name) {                       \
    TestResult _test_result = TEST_SUCCESS;                                    \
    {__VA_ARGS__} print_test_messages(_test_name, _test_result);               \
  }

#endif
