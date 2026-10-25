#include "renderer/engine.h"

#include "renderer/mesh.h"

#include "p_framebuffer.h"
#include "renderer/shader.h"
#include "renderer/vertex2D.h"

#include "triangle.h"

#include "stdbool.h"

#include "math/math.h"

void base_vertex_shader(InputVertexShader args, OutputVertexShader *output) {
  output->vertex_position =
      vec4_new(args.vertex_position.x, args.vertex_position.y,
               args.vertex_position.z, 1.f);
}

void base_fragment_shader(InputFragmentShader args,
                          OutputFragmentShader *output) {
  output->colour = vec3_new(1.f, 1.f, 1.f);
}

void framebuffer_triangle(DrawCommand cmd, Triangle triangle) {
  BoundingBox2D triangle_bounds = triangle_bounding_box(triangle);

  int32_t x_min = triangle_bounds.x.raw[0] * cmd.fb->width;
  int32_t x_max = triangle_bounds.x.raw[1] * cmd.fb->width;
  int32_t y_min = triangle_bounds.y.raw[0] * cmd.fb->height;
  int32_t y_max = triangle_bounds.y.raw[1] * cmd.fb->height;

  for (int32_t y = y_min; y <= y_max; y++) {
    for (int32_t x = x_min; x <= x_max; x++) {
      U8Vec3 *pixel = framebuffer_get_pixel(cmd.fb, x, y);
      if (!pixel)
        continue;

      Vec2 point = {{x / (float)cmd.fb->width, y / (float)cmd.fb->height}};

      if (!point_within_triangle(triangle, point))
        continue;

      InputFragmentShader fs = {
          .fragment_position = vec3_from_vec2(point, 0.f),
      };
      OutputFragmentShader frag;
      cmd.fragment_shader(fs, &frag);

      *pixel = u8vec3_from_vec3(frag.colour);
    }
  }
}

Triangle run_vertex_shader(DrawCommand cmd, Triangle2D *triangle) {
  InputVertexShader vs;
  OutputVertexShader vertices[3];

  vs.vertex_position = vec3_from_vec2(triangle->p1.pos, 0.f);
  cmd.vertex_shader(vs, &vertices[0]);

  vs.vertex_position = vec3_from_vec2(triangle->p2.pos, 0.f);
  cmd.vertex_shader(vs, &vertices[1]);

  vs.vertex_position = vec3_from_vec2(triangle->p3.pos, 0.f);
  cmd.vertex_shader(vs, &vertices[2]);

  return (Triangle){
      .p1 = (Vertex){.pos = vertices[0].vertex_position},
      .p2 = (Vertex){.pos = vertices[1].vertex_position},
      .p3 = (Vertex){.pos = vertices[2].vertex_position},
  };
}

void draw_triangle(DrawCommand cmd, Triangle2D input_triangle) {
  Triangle triangle = run_vertex_shader(cmd, &input_triangle);

  bool triangle_cw =
      vec4_2d_det(vec4_sub(triangle.p2.pos, triangle.p1.pos),
                  vec4_sub(triangle.p3.pos, triangle.p1.pos)) > 0.f;

  bool swap_vertices = false;

  switch (cmd.cullMode) {
  case CullMode_CW:
    if (!triangle_cw)
      return;
    break;
  case CullMode_CCW:
    if (triangle_cw)
      return;

    swap_vertices = true;

    break;
  case CullMode_None:
    if (!triangle_cw)
      swap_vertices = true;

    break;
  }

  if (swap_vertices) {
    Vertex t = triangle.p2;
    triangle.p2 = triangle.p1;
    triangle.p1 = t;
  }

  framebuffer_triangle(cmd, triangle);
}

void draw(DrawCommand cmd) {
  if (!cmd.vertex_shader)
    cmd.vertex_shader = base_vertex_shader;

  if (!cmd.fragment_shader)
    cmd.fragment_shader = base_fragment_shader;

  for (uint32_t i = 0; i < mesh_triangle_count(&cmd.mesh); i++) {
    draw_triangle(cmd, mesh_get_triangle2D(&cmd.mesh, i * 3));
  }
}
