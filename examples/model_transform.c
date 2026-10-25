#include "renderer/engine.h"
#include "renderer/framebuffer.h"
#include "renderer/mesh.h"
#include "renderer/shader.h"

#include "math/math.h"
#include <stdint.h>

Mat4x4 triangle_transform;

void vertex_shader(InputVertexShader input, OutputVertexShader *output) {
  output->vertex_position = mat4x4_mul_vec4(
      triangle_transform, vec4_from_vec3(input.vertex_position, 1.f));
}

void fragment_shader(InputFragmentShader input, OutputFragmentShader *output) {
  output->colour = input.fragment_position;
}

int main(void) {
  Framebuffer framebuffer = framebuffer_init(400, 400);

  framebuffer_clear_colour(&framebuffer,
                           u8vec3_from_vec3(vec3_new_scalar(0.2f)));

  Mesh mesh = create_mesh();
  mesh_add_vertex(&mesh,
                  create_vertex2D(vec2_new(0.1, 0.0), vec2_new(0.f, 0.f)));
  mesh_add_vertex(&mesh,
                  create_vertex2D(vec2_new(0.1, 0.1), vec2_new(1.f, 0.f)));
  mesh_add_vertex(&mesh,
                  create_vertex2D(vec2_new(0.0, 0.1), vec2_new(0.f, 1.f)));

  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      triangle_transform = mat4x4_identity();
      triangle_transform = mat4x4_translate(triangle_transform,
                                            vec3_new(x / 10.f, y / 10.f, 0.f));

      draw((DrawCommand){
          .fb = &framebuffer,
          .cullMode = CullMode_None,
          .mesh = mesh,
          .vertex_shader = vertex_shader,
          .fragment_shader = fragment_shader,
      });
    }
  }

  framebuffer_export_to_ppm("model_transform.ppm", &framebuffer);

  framebuffer_free(framebuffer);

  return 0;
}
