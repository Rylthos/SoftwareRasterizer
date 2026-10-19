#include "rasterizer/engine.h"

#include "stdio.h"

#include "p_framebuffer.h"
#include "rasterizer/vertex2D.h"
#include "stdbool.h"

#include "math/vec2.h"

void draw(DrawCommand cmd) {
  bool triangle_cw = vec2_cross(vec2_sub(cmd.t.p2.pos, cmd.t.p1.pos),
                                vec2_sub(cmd.t.p3.pos, cmd.t.p1.pos)) > 0.f;

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
    Vertex2D t = cmd.t.p2;
    cmd.t.p2 = cmd.t.p1;
    cmd.t.p1 = t;
  }

  framebuffer_render_triangle2D(cmd.fb, cmd.t);
}
