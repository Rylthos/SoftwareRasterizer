#include "math/math.h"

#include "renderer/engine.h"
#include "renderer/framebuffer.h"
#include "renderer/mesh.h"

#include "string.h"

void vertex_shader(InputVertexShader input, OutputVertexShader *output) {
  float *data = (float *)input.data;
  output->vertex_position = vec4_new(data[0], data[1], 0.f, 0.f);
}

void fragment_shader(InputFragmentShader _, OutputFragmentShader *output) {
  output->colour = vec3_new(1.f, 1.f, 1.f);
}

int main(void) {
  Framebuffer framebuffer = framebuffer_init(640, 480);

  Vec3 colour1 = {.r = 1.f, .g = 0.f, .b = 0.f};

  framebuffer_clear_colour(&framebuffer, u8vec3_from_vec3(colour1));

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

  float eye_data[] = {
      // clang-format off
    0.2f, 0.2f,
    0.4f, 0.3f,
    0.3f, 0.4f,
    0.8f, 0.2f,
    0.7f, 0.4f,
    0.6f, 0.3f,
      // clang-format on
  };

  Mesh eyes = create_mesh();
  mesh_set_vertex_layout(&eyes, layout);
  mesh_resize_vertices(&eyes, 6);
  memcpy(eyes.vertices, eye_data, sizeof(float) * 2 * 6);

  float mouth_data[] = {
      // clang-format off
    0.78f, 0.6f,
    0.22f, 0.6f,
    0.5f, 0.9f,
      // clang-format on
  };

  Mesh mouth = create_mesh();
  mesh_set_vertex_layout(&mouth, layout);
  mesh_resize_vertices(&mouth, 3);
  memcpy(mouth.vertices, mouth_data, sizeof(float) * 2 * 3);

  draw((DrawCommand){
      .fb = &framebuffer,
      .cullMode = CullMode_None,
      .mesh = eyes,
      .vertex_shader = vertex_shader,
      .fragment_shader = fragment_shader,
  });

  draw((DrawCommand){
      .fb = &framebuffer,
      .cullMode = CullMode_None,
      .mesh = mouth,
      .vertex_shader = vertex_shader,
      .fragment_shader = fragment_shader,
  });

  framebuffer_export_to_ppm("output_1.ppm", &framebuffer);

  framebuffer_free(framebuffer);

  return 0;
}
