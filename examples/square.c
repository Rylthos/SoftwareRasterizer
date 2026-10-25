#include "math/u8vec3.h"

#include "math/vec_conversion.h"
#include "renderer/engine.h"
#include "renderer/framebuffer.h"
#include "renderer/mesh.h"
#include "renderer/shader.h"

#include "math/math.h"
#include <stdint.h>

void vertex_shader(InputVertexShader input, OutputVertexShader *output) {
  output->vertex_position = vec4_from_vec3(
      vec3_scalar(vec3_add(input.vertex_position, vec3_new_scalar(-0.2f)),
                  1.0 / 0.6),
      1.f);
  // output->vertex_position = vec4_from_vec3(input.vertex_position, 1.f);
}

void fragment_shader(InputFragmentShader input, OutputFragmentShader *output) {
  output->colour = input.fragment_position;
}

int main(void) {
  Framebuffer framebuffer = framebuffer_init(400, 400);

  framebuffer_clear_colour(&framebuffer,
                           u8vec3_from_vec3(vec3_new_scalar(0.2f)));

  Mesh mesh = create_indexed_mesh();
  mesh_add_vertex(&mesh,
                  create_vertex2D(vec2_new(0.2, 0.2), vec2_new(0.f, 0.f)));
  mesh_add_vertex(&mesh,
                  create_vertex2D(vec2_new(0.8, 0.2), vec2_new(1.f, 0.f)));
  mesh_add_vertex(&mesh,
                  create_vertex2D(vec2_new(0.2, 0.8), vec2_new(0.f, 1.f)));
  mesh_add_vertex(&mesh,
                  create_vertex2D(vec2_new(0.8, 0.8), vec2_new(1.f, 1.f)));

  mesh_add_triangle_indices(&mesh, 0, 1, 2);
  mesh_add_triangle_indices(&mesh, 1, 3, 2);

  draw((DrawCommand){
      .fb = &framebuffer,
      .cullMode = CullMode_None,
      .mesh = mesh,
      .vertex_shader = vertex_shader,
      .fragment_shader = fragment_shader,
  });

  framebuffer_export_to_ppm("square.ppm", &framebuffer);

  framebuffer_free(framebuffer);

  return 0;
}
