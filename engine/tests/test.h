#ifndef TEST_H
#define TEST_H

#include "assert.h"
#include "stdio.h"

#define ASSERT_MSG(cond, ...)                                                  \
  do {                                                                         \
    if (!(cond)) {                                                             \
      fprintf(stderr, "[%s:%d] ", __FILE__, __LINE__);                         \
      fprintf(stderr, __VA_ARGS__);                                            \
    }                                                                          \
  } while (0)

#define ASSERT(cond) ASSERT_MSG((cond), "" #cond "\n")

#endif
