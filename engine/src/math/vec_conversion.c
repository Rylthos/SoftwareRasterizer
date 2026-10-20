#include "math/vec_conversion.h"

#include "math/util.h"

Vec2 vec2_from_vec3(Vec3 v) { return (Vec2){{v.x, v.y}}; }
Vec2 vec2_from_vec4(Vec4 v) { return (Vec2){{v.x / v.w, v.y / v.w}}; }

Vec3 vec3_from_vec2(Vec2 v, float z) { return (Vec3){{v.x, v.y, z}}; }
Vec3 vec3_from_vec4(Vec4 v) {
  return (Vec3){{v.x / v.w, v.y / v.w, v.z / v.w}};
}

Vec4 vec4_from_vec2(Vec2 v, float z, float w) {
  return (Vec4){{v.x, v.y, z, w}};
}
Vec4 vec4_from_vec3(Vec3 v, float w) { return (Vec4){{v.x, v.y, v.z, w}}; }

U8Vec3 u8vec3_from_vec3(Vec3 c) {
  return (U8Vec3){
      .r = MAX(0, MIN(255, 255 * c.r)),
      .g = MAX(0, MIN(255, 255 * c.g)),
      .b = MAX(0, MIN(255, 255 * c.b)),
  };
}
