#ifndef RASTERIZER_ENGINE_H
#define RASTERIZER_ENGINE_H

#include "rasterizer/framebuffer.h"
#include "rasterizer/triangle2D.h"

typedef enum { CullMode_None, CullMode_CW, CullMode_CCW } CullMode;

typedef struct {
  Framebuffer *fb;
  CullMode cullMode;

  Triangle2D t;
} DrawCommand;

void draw(DrawCommand command);

#endif
