#ifndef TEST_H
#define TEST_H

#include "assert.h"
#include "stdio.h"

#define TVEC3_MATCH_COMP(v1, a, b, c)                                          \
  ((v1).x == (a) && (v1).y == (b) && (v1).z == (c))

#define TVEC3_MATCH_TVEC3(v1, v2)                                              \
  ((v1).x == (v2).x && (v1).y == (v2).y && (v1).z == (v2).z)

#define VEC3_FORMAT "(%.3f, %.3f, %.3f)"
#define U8VEC3_FORMAT "(%d, %d, %d)"

#define TVEC3_PRINT(v) (v).x, (v).y, (v).z

#define ASSERT_MSG(cond, ...)                                                  \
  do {                                                                         \
    if (!(cond)) {                                                             \
      fprintf(stderr, "[%s:%d] ", __FILE__, __LINE__);                         \
      fprintf(stderr, __VA_ARGS__);                                            \
    }                                                                          \
  } while (0)

#define ASSERT(cond) ASSERT_MSG((cond), "" #cond "\n")

#endif
