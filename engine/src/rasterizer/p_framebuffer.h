#ifndef RASTERIZER_P_FRAMEBUFFER_H
#define RASTERIZER_P_FRAMEBUFFER_H

#include "rasterizer/framebuffer.h"

void framebuffer_render_triangle2D(const Framebuffer *framebuffer,
                                   Triangle2D t);

void framebuffer_render_triangle2D_uvs(const Framebuffer *framebuffer,
                                       Triangle2D t);

#endif
