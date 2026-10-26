#ifndef RENDERER_FRAMEBUFFER_H
#define RENDERER_FRAMEBUFFER_H

#include "math/u8vec3.h"
#include <stdint.h>

typedef struct T_Framebuffer {
  int32_t width;
  int32_t height;
  U8Vec3 *data;
} Framebuffer;

Framebuffer framebuffer_init(uint32_t width, uint32_t height);
void framebuffer_free(Framebuffer framebuffer);

void framebuffer_export_to_ppm(const char *target,
                               const Framebuffer *framebuffer);

U8Vec3 *framebuffer_get_pixel(const Framebuffer *framebuffer, int32_t x,
                              int32_t y);

void framebuffer_clear_colour(const Framebuffer *framebuffer, U8Vec3 colour);

#endif
