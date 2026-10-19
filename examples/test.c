#include "math/u8vec3.h"
#include "rasterizer/triangle2D.h"
#include "rasterizer/vertex2D.h"
#include "stdio.h"

#include "rasterizer/engine.h"
#include "rasterizer/framebuffer.h"

int main(void) {
  Framebuffer framebuffer = framebuffer_init(640, 480);

  Vec3 colour1 = {.r = 1.f, .g = 0.f, .b = 0.f};

  framebuffer_clear_colour(&framebuffer, u8vec3_from_vec3(colour1));

  Triangle2D t1 = create_triangle2D_points(0.2, 0.2, 0.4, 0.3, 0.3, 0.4);
  draw((DrawCommand){.fb = &framebuffer, .cullMode = CullMode_None, .t = t1});
  // framebuffer_render_triangle2D(&framebuffer, t1);

  Triangle2D t2 = create_triangle2D_points(0.8, 0.2, 0.7, 0.4, 0.6, 0.3);
  draw((DrawCommand){.fb = &framebuffer, .cullMode = CullMode_None, .t = t2});

  // Triangle2D t3 = create_triangle2D_points(0.22, 0.6, 0.78, 0.6, 0.5, 0.9);
  Triangle2D t3 = {
      create_vertex2D(vec2_new(0.78, 0.6), vec2_new(1.f, 0.f)),
      create_vertex2D(vec2_new(0.22, 0.6), vec2_new(0.f, 0.f)),
      create_vertex2D(vec2_new(0.5, 0.9), vec2_new(0.f, 1.f)),
  };
  draw((DrawCommand){.fb = &framebuffer, .cullMode = CullMode_None, .t = t3});

  framebuffer_export_to_ppm("output_1.ppm", &framebuffer);

  framebuffer_free(framebuffer);

  return 0;
}
