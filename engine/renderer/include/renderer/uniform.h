#ifndef RENDERER_UNIFORM_H
#define RENDERER_UNIFORM_H

#include "math/math.h"

typedef enum {
  U_FLOAT,
  U_VEC2,
  U_VEC3,
  U_VEC4,
} ShaderUniformType;

typedef struct {
  ShaderUniformType type;

  union {
    float f;
    Vec2 vec2;
    Vec3 vec3;
    Vec4 vec4;
  };
} ShaderUniform;

#endif
