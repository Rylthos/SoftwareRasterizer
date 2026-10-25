#ifndef RASTERIZER_ENGINE_H
#define RASTERIZER_ENGINE_H

#include "rasterizer/framebuffer.h"
#include "rasterizer/mesh.h"
#include "rasterizer/shader.h"

typedef enum { CullMode_None, CullMode_CW, CullMode_CCW } CullMode;

typedef struct {
  Framebuffer *fb;
  CullMode cullMode;

  void((*vertex_shader)(InputVertexShader, OutputVertexShader *));
  void((*fragment_shader)(InputFragmentShader, OutputFragmentShader *));

  Mesh mesh;
} DrawCommand;

void draw(DrawCommand command);

#endif
