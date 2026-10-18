#include "math/u8vec3.h"
#include "math/vec3.h"

#include "math/util.h"

U8Vec3 u8vec3_from_vec3(Vec3 c) {
  return (U8Vec3){
      .r = MAX(0, MIN(255, 255 * c.r)),
      .g = MAX(0, MIN(255, 255 * c.g)),
      .b = MAX(0, MIN(255, 255 * c.b)),
  };
}
