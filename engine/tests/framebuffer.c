#include "framebuffer.h"

#include "test.h"

#include "math/u8vec3.h"
#include "rasterizer/framebuffer.h"

void clear_colour(void) {
  Framebuffer fb = framebuffer_init(1, 1);
  U8Vec3 clear_colour = {.r = 60, .g = 120, .b = 180};
  framebuffer_clear_colour(&fb, clear_colour);

  ASSERT(TVEC3_MATCH_TVEC3(*framebuffer_get_pixel(&fb, 0, 0), clear_colour));

  U8Vec3 clear_colour_2 = {.r = 180, .g = 120, .b = 60};
  framebuffer_clear_colour(&fb, clear_colour_2);

  ASSERT(TVEC3_MATCH_TVEC3(*framebuffer_get_pixel(&fb, 0, 0), clear_colour_2));
}

void framebuffer_tests(void) {}
