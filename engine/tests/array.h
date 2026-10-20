#ifndef TEST_ARRAY_H
#define TEST_ARRAY_H

#include "generic/array.h"
#include "test.h"

ADD_TEST("array", basic, {
  int *array = ARRAY_CREATE(int);

  ARRAY_PUSH(array, 0);

  assert(array[0] == 0);

  ARRAY_FREE(array);
})

ADD_TEST("array", expand_test, {
  uint32_t *array = ARRAY_CREATE(uint32_t);

  size_t init_capacity = ARRAY_CAPACITY(array);

  const uint32_t elements = 10;

  for (uint32_t i = 0; i < elements; i++) {
    ARRAY_PUSH(array, i);
  }

  for (uint32_t i = 0; i < elements; i++) {
    ASSERT_MSG(array[i] == i, "Expected %u == %u\n", array[i], i);
  }

  ASSERT(ARRAY_LEN(array) == elements);

  size_t new_capacity = ARRAY_CAPACITY(array);

  ASSERT_MSG(ARRAY_CAPACITY(array) != init_capacity, "%lu, %lu\n",
             init_capacity, new_capacity);

  ARRAY_FREE(array);
})

#endif
