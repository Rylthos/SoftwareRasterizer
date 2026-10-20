#ifndef TEST_FRAMEBUFFER_H
#define TEST_FRAMEBUFFER_H

#include "test.h"

#include "math/math.h"
#include "rasterizer/framebuffer.h"

ADD_TEST("framebuffer", clear_colour, {
  Framebuffer fb = framebuffer_init(1, 1);
  U8Vec3 clear_colour = u8vec3_new(60, 120, 180);
  framebuffer_clear_colour(&fb, clear_colour);

  ASSERT(TVEC3_MATCH_TVEC3(*framebuffer_get_pixel(&fb, 0, 0), clear_colour));

  U8Vec3 clear_colour_2 = u8vec3_new(180, 120, 60);
  framebuffer_clear_colour(&fb, clear_colour_2);

  ASSERT(TVEC3_MATCH_TVEC3(*framebuffer_get_pixel(&fb, 0, 0), clear_colour_2));
})

#endif
