#include "math/u8vec3.h"

U8Vec3 u8vec3_new(uint8_t r, uint8_t g, uint8_t b) {
  return (U8Vec3){{r, g, b}};
}
