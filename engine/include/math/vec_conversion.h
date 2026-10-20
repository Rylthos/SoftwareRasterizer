#ifndef MATH_VEC_CONVERSION_H
#define MATH_VEC_CONVERSION_H

#include "math/u8vec3.h"
#include "math/vec2.h"
#include "math/vec3.h"
#include "math/vec4.h"

Vec2 vec2_from_vec3(Vec3 v);
Vec2 vec2_from_vec4(Vec4 v);

Vec3 vec3_from_vec2(Vec2 v, float z);
Vec3 vec3_from_vec4(Vec4 v);

Vec4 vec4_from_vec2(Vec2 v, float z, float w);
Vec4 vec4_from_vec3(Vec3 v, float w);

U8Vec3 u8vec3_from_vec3(Vec3 c);

#endif
