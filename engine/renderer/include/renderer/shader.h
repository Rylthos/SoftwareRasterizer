#ifndef RENDERER_SHADER_H
#define RENDERER_SHADER_H

#include "math/vec3.h"
#include "math/vec4.h"

#include "renderer/vertex.h"

typedef struct {
  VertexLayout layout;
  uint8_t *data;
} InputVertexShader;

typedef struct {
  Vec4 vertex_position;
} OutputVertexShader;

typedef struct {
  Vec3 fragment_position;
} InputFragmentShader;

typedef struct {
  Vec3 colour;
} OutputFragmentShader;

#endif
