#include "math/u8vec3.h"

#include "rasterizer/engine.h"
#include "rasterizer/framebuffer.h"
#include "rasterizer/triangle2D.h"
#include "rasterizer/vertex2D.h"

int main(void) {
  Framebuffer framebuffer = framebuffer_init(400, 400);

  framebuffer_clear_colour(&framebuffer,
                           u8vec3_from_vec3(vec3_new_scalar(0.2f)));

  Mesh mesh = create_mesh();
  mesh_add_vertex(&mesh,
                  create_vertex2D(vec2_new(0.2, 0.2), vec2_new(0.f, 0.f)));
  mesh_add_vertex(&mesh,
                  create_vertex2D(vec2_new(0.8, 0.2), vec2_new(1.f, 0.f)));
  mesh_add_vertex(&mesh,
                  create_vertex2D(vec2_new(0.2, 0.8), vec2_new(0.f, 1.f)));
  mesh_add_vertex(&mesh,
                  create_vertex2D(vec2_new(0.8, 0.2), vec2_new(1.f, 0.f)));
  mesh_add_vertex(&mesh,
                  create_vertex2D(vec2_new(0.8, 0.8), vec2_new(1.f, 1.f)));
  mesh_add_vertex(&mesh,
                  create_vertex2D(vec2_new(0.2, 0.8), vec2_new(0.f, 1.f)));

  draw((DrawCommand){
      .fb = &framebuffer, .cullMode = CullMode_None, .mesh = mesh});

  framebuffer_export_to_ppm("square.ppm", &framebuffer);

  framebuffer_free(framebuffer);

  return 0;
}
