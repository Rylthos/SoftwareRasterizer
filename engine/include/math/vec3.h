#ifndef MATH_VEC3_H
#define MATH_VEC3_H

typedef struct {
  union {
    float x;
    float r;
  };
  union {
    float y;
    float g;
  };
  union {
    float z;
    float b;
  };
} Vec3;

Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_sub(Vec3 a, Vec3 b);
Vec3 vec3_scalar(Vec3 a, float b);
Vec3 vec3_cross(Vec3 a, Vec3 b);

float vec3_dot(Vec3 a, Vec3 b);
float vec3_magnitude_sq(Vec3 v);
float vec3_magnitude(Vec3 v);
Vec3 vec3_norm(Vec3 v);

#endif
