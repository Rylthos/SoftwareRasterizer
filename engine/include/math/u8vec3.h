#ifndef MATH_U8VEC3_H
#define MATH_U8VEC3_H

#include "stdint.h"

#include "math/vec3.h"

typedef union {
  struct {
    uint8_t x;
    uint8_t y;
    uint8_t z;
  };
  struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
  };
  uint8_t raw[3];
} U8Vec3;

U8Vec3 u8vec3_from_vec3(Vec3 c);

#endif
