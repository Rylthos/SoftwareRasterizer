#include "math/u8vec3.h"
#include "stdio.h"

#include "rasterizer/engine.h"
#include "rasterizer/framebuffer.h"

int main(void) {
  Framebuffer framebuffer = framebuffer_init(640, 480);

  Vec3 colour1 = {.r = 1.f, .g = 0.f, .b = 0.f};
  Vec3 colour2 = {.r = 0.f, .g = 1.f, .b = 1.f};

  framebuffer_clear_colour(&framebuffer, u8vec3_from_vec3(colour1));
  framebuffer_export_to_ppm("output_1.ppm", &framebuffer);

  framebuffer_clear_colour(&framebuffer, u8vec3_from_vec3(colour2));
  framebuffer_export_to_ppm("output_2.ppm", &framebuffer);

  framebuffer_free(framebuffer);

  return 0;
}
