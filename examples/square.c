#include "math/u8vec3.h"

#include "math/vec_conversion.h"
#include "renderer/engine.h"
#include "renderer/framebuffer.h"
#include "renderer/mesh.h"
#include "renderer/shader.h"

#include "math/math.h"
#include "renderer/uniform.h"
#include "renderer/vertex.h"

#include <stdlib.h>
#include <string.h>

void vertex_shader(InputVertexShader input, OutputVertexShader *output) {
  float *data = (float *)input.data;
  output->vertex_position = vec4_new(data[0], data[1], 0.f, 0.f);

  ShaderUniform colour = {
      .type = U_VEC3,
      .vec3 = vec3_new(data[2], data[3], data[4]),
  };

  ARRAY_PUSH(output->uniforms, colour);
}

void fragment_shader(InputFragmentShader input, OutputFragmentShader *output) {
  output->colour = input.uniforms[0].vec3;
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

  AttributeDefinition colour = {
      .id = 0,
      .offset = 0,
      .size = sizeof(Vec3),
  };

  VertexLayout layout = {
      .attributes = malloc(sizeof(AttributeDefinition) * 2),
      .count = 2,
      .stride = position.size + colour.size,
  };

  layout.attributes[0] = position;
  layout.attributes[1] = colour;

  float data[] = {
      // clang-format off
    0.2f, 0.2f, 1.f, 1.f, 1.f,
    0.8f, 0.2f, 1.f, 0.f, 0.f,
    0.2f, 0.8f, 0.f, 1.f, 0.f,
    0.8f, 0.8f, 0.f, 0.f, 1.f,
      // clang-format on
  };

  Mesh mesh = create_indexed_mesh();
  mesh_set_vertex_layout(&mesh, layout);
  mesh_resize_vertices(&mesh, 4);
  memcpy(mesh.vertices, data, sizeof(float) * 4 * 5);

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
