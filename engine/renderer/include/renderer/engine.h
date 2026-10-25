#ifndef RENDERER_ENGINE_H
#define RENDERER_ENGINE_H

#include "renderer/framebuffer.h"
#include "renderer/mesh.h"
#include "renderer/shader.h"

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
