#include "generic/array.h"

#include "assert.h"
#include "stdio.h"
#include "string.h"

ArrayHeader *get_array_header(void *array) {
  return (ArrayHeader *)((uint8_t *)array - sizeof(ArrayHeader));
}

void array_expand(void **array) {
  ArrayHeader *header = get_array_header(*array);

  size_t new_size = header->size * 2;

  void *tmp = malloc(sizeof(ArrayHeader) + new_size * header->stride);
  ArrayHeader *new_header = (ArrayHeader *)tmp;
  uint8_t *new_array = (uint8_t *)tmp + sizeof(ArrayHeader);

  memcpy(new_array, (uint8_t *)*array, header->length * header->stride);

  new_header->stride = header->stride;
  new_header->length = header->length;
  new_header->size = new_size;

  array_free(*array);

  *array = new_array;
}

void *array_init(size_t size) {
  void *array = malloc(sizeof(ArrayHeader) + size * ARRAY_INIT_SIZE);

  ArrayHeader *header = (ArrayHeader *)array;

  header->length = 0;
  header->size = ARRAY_INIT_SIZE;
  header->stride = size;

  return (void *)((uint8_t *)array + sizeof(ArrayHeader));
}

void array_free(void *array) { free((uint8_t *)array - sizeof(ArrayHeader)); }

size_t array_len(void *array) {
  ArrayHeader *header = get_array_header(array);
  return header->length;
}

size_t array_capacity(void *array) {
  ArrayHeader *header = get_array_header(array);
  return header->size;
}

void *array_push(void **array) {
  ArrayHeader *header = get_array_header(*array);

  if (header->length == header->size) {
    array_expand(array);
    header = get_array_header(*array);
  }

  void *ptr = (void *)((uint8_t *)*array + (header->stride * header->length));

  header->length += 1;

  return ptr;
}
