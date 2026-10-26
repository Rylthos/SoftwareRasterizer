#include "renderer/engine.h"
#include "renderer/framebuffer.h"
#include "renderer/mesh.h"
#include "renderer/shader.h"

#include "math/math.h"
#include <stdint.h>

#include <string.h>

Mat4x4 triangle_transform;

void vertex_shader(InputVertexShader input, OutputVertexShader *output) {
  float *data = (float *)input.data;
  output->vertex_position =
      mat4x4_mul_vec4(triangle_transform, vec4_new(data[0], data[1], 0.f, 1.f));
}

void fragment_shader(InputFragmentShader input, OutputFragmentShader *output) {
  output->colour = input.fragment_position;
}

int main(void) {
  Framebuffer framebuffer = framebuffer_init(400, 400);

  framebuffer_clear_colour(&framebuffer,
                           u8vec3_from_vec3(vec3_new_scalar(0.2f)));

  AttributeDefinition position = {
      .id = 0,
      .offset = 0,
      .size = sizeof(Vec2),
  };
  VertexLayout layout = {
      .attributes = malloc(sizeof(AttributeDefinition)),
      .count = 1,
      .stride = position.size,
  };

  layout.attributes[0] = position;

  float data[] = {
      // clang-format off
    0.5f, -0.5f,
    0.5f, 0.5f,
    -0.5f, 0.5f,
      // clang-format on
  };

  Mesh mesh = create_mesh();
  mesh_set_vertex_layout(&mesh, layout);
  mesh_resize_vertices(&mesh, 3);
  memcpy(mesh.vertices, data, sizeof(Vec2) * 3);

  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      triangle_transform = mat4x4_identity();
      triangle_transform =
          mat4x4_rotate_z(triangle_transform, (x + y * 10) / 100.f * TWO_PI);
      triangle_transform = mat4x4_scale(triangle_transform, 0.1f);
      triangle_transform = mat4x4_translate(triangle_transform,
                                            vec3_new(x / 10.f, y / 10.f, 0.f));
      triangle_transform =
          mat4x4_translate(triangle_transform, vec3_new(0.05f, 0.05f, 0.0f));

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
