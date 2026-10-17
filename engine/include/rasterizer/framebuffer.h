#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "math/u8vec3.h"
#include <stdint.h>

#include "rasterizer/triangle.h"

typedef struct T_Framebuffer {
  uint32_t width;
  uint32_t height;
  U8Vec3 *data;
} Framebuffer;

Framebuffer framebuffer_init(uint32_t width, uint32_t height);
void framebuffer_free(Framebuffer framebuffer);

void framebuffer_export_to_ppm(const char *target,
                               const Framebuffer *framebuffer);

U8Vec3 *framebuffer_get_pixel(const Framebuffer *framebuffer, uint32_t x,
                              uint32_t y);

void framebuffer_clear_colour(const Framebuffer *framebuffer, U8Vec3 colour);

void framebuffer_render_triangle(const Framebuffer *framebuffer, Triangle t);

#endif
