#include "renderer/uniform.h"
#include "p_uniform.h"

#include "assert.h"

float interpolate_float(Vec3 scalars, float p1, float p2, float p3) {
  return p1 * scalars.x + p2 * scalars.y + p3 * scalars.z;
}

Vec2 interpolate_vec2(Vec3 scalars, Vec2 p1, Vec2 p2, Vec2 p3) {
  return vec2_add(
      vec2_scalar(p1, scalars.x),
      vec2_add(vec2_scalar(p2, scalars.y), vec2_scalar(p3, scalars.z)));
}

Vec3 interpolate_vec3(Vec3 scalars, Vec3 p1, Vec3 p2, Vec3 p3) {
  return vec3_add(
      vec3_scalar(p1, scalars.x),
      vec3_add(vec3_scalar(p2, scalars.y), vec3_scalar(p3, scalars.z)));
}

Vec4 interpolate_vec4(Vec3 scalars, Vec4 p1, Vec4 p2, Vec4 p3) {
  return vec4_add(
      vec4_scalar(p1, scalars.x),
      vec4_add(vec4_scalar(p2, scalars.y), vec4_scalar(p3, scalars.z)));
}

ShaderUniform interpolate_uniform(Vec3 scalars, ShaderUniform *p1,
                                  ShaderUniform *p2, ShaderUniform *p3) {
  assert(p1->type == p2->type && p1->type == p3->type &&
         "Expected shader uniform types to be equivalent");

  ShaderUniform returnUniform;
  returnUniform.type = p1->type;

  switch (returnUniform.type) {
  case U_FLOAT:
    returnUniform.f = interpolate_float(scalars, p1->f, p2->f, p3->f);
    break;

  case U_VEC2:
    returnUniform.vec2 =
        interpolate_vec2(scalars, p1->vec2, p2->vec2, p3->vec2);
    break;

  case U_VEC3:
    returnUniform.vec3 =
        interpolate_vec3(scalars, p1->vec3, p2->vec3, p3->vec3);
    break;

  case U_VEC4:
    returnUniform.vec4 =
        interpolate_vec4(scalars, p1->vec4, p2->vec4, p3->vec4);
    break;
  }

  return returnUniform;
}
