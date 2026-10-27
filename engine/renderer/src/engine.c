#include "renderer/engine.h"

#include "p_mesh.h"
#include "renderer/mesh.h"

#include "p_framebuffer.h"
#include "renderer/shader.h"

#include "renderer/uniform.h"
#include "triangle.h"

#include "stdbool.h"

#include "assert.h"

#include "math/math.h"
#include "uniform.h"

void framebuffer_triangle(DrawCommand *cmd, const Triangle *triangle) {
  BoundingBox2D triangle_bounds = triangle_bounding_box(triangle);

  int32_t x_min = triangle_bounds.x.raw[0] * cmd->fb->width;
  int32_t x_max = triangle_bounds.x.raw[1] * cmd->fb->width;
  int32_t y_min = triangle_bounds.y.raw[0] * cmd->fb->height;
  int32_t y_max = triangle_bounds.y.raw[1] * cmd->fb->height;

  for (int32_t y = y_min; y <= y_max; y++) {
    for (int32_t x = x_min; x <= x_max; x++) {
      U8Vec3 *pixel = framebuffer_get_pixel(cmd->fb, x, y);
      if (!pixel)
        continue;

      Vec2 point = {{x / (float)cmd->fb->width, y / (float)cmd->fb->height}};

      if (!point_within_triangle(triangle, point))
        continue;

      ARRAY(ShaderUniform) interpolated_uniforms = ARRAY_CREATE(ShaderUniform);

      Vec3 scalars = triangle_barycentre(triangle, point);

      for (size_t i = 0; i < ARRAY_LEN(triangle->p1.uniforms); i++) {
        interpolated_uniforms[i] = interpolate_uniform(
            scalars, &triangle->p1.uniforms[i], &triangle->p2.uniforms[i],
            &triangle->p3.uniforms[i]);
      }

      InputFragmentShader fs = {
          .fragment_position = vec3_from_vec2(point, 0.f),
          .uniforms = interpolated_uniforms,
      };

      ARRAY_FREE(interpolated_uniforms);

      OutputFragmentShader frag;
      cmd->fragment_shader(fs, &frag);

      *pixel = u8vec3_from_vec3(frag.colour);
    }
  }
}

void verify_uniform_types(ARRAY(ShaderUniform) p1, ARRAY(ShaderUniform) p2,
                          ARRAY(ShaderUniform) p3) {
  assert(ARRAY_LEN(p1) == ARRAY_LEN(p2) && ARRAY_LEN(p1) == ARRAY_LEN(p3) &&
         "Uniforms are expected to be the same size");

  for (uint32_t i = 0; i < ARRAY_LEN(p1); i++) {
    assert(p1[i].type == p2[i].type && p1[i].type == p3[i].type &&
           "Uniform types expected to be equal");
  }
}

Triangle run_vertex_shader(DrawCommand *cmd, TriangleIndices indices) {
  InputVertexShader vs;
  OutputVertexShader vertices[3];

  for (int i = 0; i < 3; i++) {
    vertices[i].uniforms = ARRAY_CREATE(ShaderUniform);
  }

  vs.layout = cmd->mesh.layout;

  vs.data = cmd->mesh.vertices + cmd->mesh.layout.stride * indices.i1;
  cmd->vertex_shader(vs, &vertices[0]);

  vs.data = cmd->mesh.vertices + cmd->mesh.layout.stride * indices.i2;
  cmd->vertex_shader(vs, &vertices[1]);

  vs.data = cmd->mesh.vertices + cmd->mesh.layout.stride * indices.i3;
  cmd->vertex_shader(vs, &vertices[2]);

  return (Triangle){
      .p1 = (Vertex){.pos = vertices[0].vertex_position,
                     .uniforms = vertices[0].uniforms},
      .p2 = (Vertex){.pos = vertices[1].vertex_position,
                     .uniforms = vertices[1].uniforms},
      .p3 = (Vertex){.pos = vertices[2].vertex_position,
                     .uniforms = vertices[2].uniforms},
  };
}

void draw_triangle(DrawCommand *cmd, TriangleIndices indices) {
  Triangle triangle = run_vertex_shader(cmd, indices);

  bool triangle_cw =
      vec4_2d_det(vec4_sub(triangle.p2.pos, triangle.p1.pos),
                  vec4_sub(triangle.p3.pos, triangle.p1.pos)) > 0.f;

  bool swap_vertices = false;

  switch (cmd->cullMode) {
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

  verify_uniform_types(triangle.p1.uniforms, triangle.p2.uniforms,
                       triangle.p3.uniforms);

  framebuffer_triangle(cmd, &triangle);

  ARRAY_FREE(triangle.p1.uniforms);
  ARRAY_FREE(triangle.p2.uniforms);
  ARRAY_FREE(triangle.p3.uniforms);
}

void draw(DrawCommand cmd) {
  assert(cmd.vertex_shader && "Expected a vertex shader");
  assert(cmd.fragment_shader && "Expected a fragment shader");

  for (uint32_t i = 0; i < mesh_triangle_count(&cmd.mesh); i++) {
    TriangleIndices indices = mesh_get_triangle(&cmd.mesh, i * 3);
    draw_triangle(&cmd, indices);
  }
}
