#ifndef RASTERIZER_ENGINE_H
#define RASTERIZER_ENGINE_H

#include "rasterizer/framebuffer.h"
#include "rasterizer/mesh.h"

typedef enum { CullMode_None, CullMode_CW, CullMode_CCW } CullMode;

typedef struct {
  Framebuffer *fb;
  CullMode cullMode;

  Mesh mesh;
} DrawCommand;

void draw(DrawCommand command);

#endif
