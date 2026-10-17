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

#endif
