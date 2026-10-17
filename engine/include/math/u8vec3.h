#ifndef MATH_U8VEC3_H
#define MATH_U8VEC3_H

#include "stdint.h"

#include "math/vec3.h"

typedef struct {
  union {
    uint8_t x;
    uint8_t r;
  };
  union {
    uint8_t y;
    uint8_t g;
  };
  union {
    uint8_t z;
    uint8_t b;
  };
} U8Vec3;

U8Vec3 u8vec3_from_vec3(Vec3 c);

#endif
