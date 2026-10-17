#include "math/vec3.h"

Vec3 vec3_add(Vec3 a, Vec3 b) {
  Vec3 return_vec = {
      .x = a.x + b.x,
      .y = a.y + b.y,
      .z = a.z + b.z,
  };

  return return_vec;
}
