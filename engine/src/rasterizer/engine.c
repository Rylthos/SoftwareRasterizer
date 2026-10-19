#include "rasterizer/engine.h"

#include "rasterizer/mesh.h"

#include "p_framebuffer.h"
#include "rasterizer/vertex2D.h"
#include "stdbool.h"

#include "math/vec2.h"

void draw_triangle(DrawCommand cmd, Triangle2D triangle) {
  bool triangle_cw =
      vec2_cross(vec2_sub(triangle.p2.pos, triangle.p1.pos),
                 vec2_sub(triangle.p3.pos, triangle.p1.pos)) > 0.f;

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
    Vertex2D t = triangle.p2;
    triangle.p2 = triangle.p1;
    triangle.p1 = t;
  }

  framebuffer_render_triangle2D(cmd.fb, triangle);
}

void draw(DrawCommand cmd) {
  for (uint32_t i = 0; i < mesh_vertex_count(&cmd.mesh); i += 3) {
    draw_triangle(cmd, mesh_get_triangle2D(&cmd.mesh, i));
  }
}
