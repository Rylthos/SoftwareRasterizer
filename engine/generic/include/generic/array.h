#ifndef GENERIC_ARRAY_H
#define GENERIC_ARRAY_H

#include "stdint.h"
#include "stdlib.h"

typedef struct {
  size_t size;
  size_t length;
  size_t stride;
} ArrayHeader;

void *array_init(size_t element);
void array_free(void *array);

size_t array_len(void *array);
size_t array_capacity(void *array);

void *array_push(void **array);

#define ARRAY(T) T *

#define ARRAY_CREATE(T) array_init(sizeof(T))
#define ARRAY_FREE(A) array_free(A)
#define ARRAY_PUSH(A, E)                                                       \
  do {                                                                         \
    typeof(E) *_p = array_push((void **)&A);                                   \
    *_p = E;                                                                   \
  } while (0)

#define ARRAY_INIT_SIZE 8

#define ARRAY_LEN(A) array_len(A)
#define ARRAY_CAPACITY(A) array_capacity(A)

#endif
