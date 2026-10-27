#ifndef RENDERER_SHADER_H
#define RENDERER_SHADER_H

#include "generic/array.h"

#include "math/vec3.h"
#include "math/vec4.h"

#include "renderer/uniform.h"
#include "renderer/vertex.h"

typedef struct {
  VertexLayout layout;
  uint8_t *data;
} InputVertexShader;

typedef struct {
  Vec4 vertex_position;
  ARRAY(ShaderUniform) uniforms;
} OutputVertexShader;

typedef struct {
  Vec3 fragment_position;
  ARRAY(ShaderUniform) uniforms;
} InputFragmentShader;

typedef struct {
  Vec3 colour;
} OutputFragmentShader;

#endif
