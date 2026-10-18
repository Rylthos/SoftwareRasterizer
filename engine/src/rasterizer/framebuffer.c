#include "rasterizer/framebuffer.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "math/u8vec3.h"
#include "p_triangle2D.h"

void ppm_write_header(FILE *file, uint32_t width, uint32_t height) {
  int length = snprintf(NULL, 0, "P3\n%d %d\n255\n", width, height);
  char *header = malloc(length * sizeof(char) + 1);
  snprintf(header, length + 1, "P3\n%d %d\n255\n", width, height);

  fwrite(header, sizeof(char), length, file);

  free(header);
}

Framebuffer framebuffer_init(uint32_t width, uint32_t height) {
  Framebuffer framebuffer = {
      .width = width,
      .height = height,
  };

  framebuffer.data = malloc(sizeof(U8Vec3) * width * height);

  return framebuffer;
}

void framebuffer_free(Framebuffer framebuffer) { free(framebuffer.data); }

void framebuffer_export_to_ppm(const char *target,
                               const Framebuffer *framebuffer) {
  FILE *file = fopen(target, "w");

  const size_t buf_length = 3 + 1 + 3 + 1 + 3 + 1; // XXX XXX XXX\n
  char buf[buf_length];

  if (!file) {
    fprintf(stderr, "Failed to open output file %s\n", target);
    goto close_file;
  }

  ppm_write_header(file, framebuffer->width, framebuffer->height);

  for (uint32_t y = 0; y < framebuffer->height; y++) {
    for (uint32_t x = 0; x < framebuffer->width; x++) {
      U8Vec3 *pixel = framebuffer_get_pixel(framebuffer, x, y);
      int len =
          snprintf(buf, buf_length, "%d %d %d\n", pixel->r, pixel->g, pixel->b);
      fwrite(buf, sizeof(char), len, file);
    }
  }

close_file:
  fclose(file);
}

U8Vec3 *framebuffer_get_pixel(const Framebuffer *framebuffer, uint32_t x,
                              uint32_t y) {
  if (x >= 0 && x < framebuffer->width && y >= 0 && y < framebuffer->height)
    return framebuffer->data + x + framebuffer->width * y;

  return NULL;
}

void framebuffer_clear_colour(const Framebuffer *framebuffer, U8Vec3 colour) {
  for (uint32_t y = 0; y < framebuffer->height; y++) {
    for (uint32_t x = 0; x < framebuffer->width; x++) {
      *framebuffer_get_pixel(framebuffer, x, y) = colour;
    }
  }
}

void framebuffer_render_triangle2D(const Framebuffer *fb, Triangle2D t) {
  BoundingBox2D triangle_bounds = triangle2D_bounding_box(t);

  uint32_t x_min = triangle_bounds.x.raw[0] * fb->width;
  uint32_t x_max = triangle_bounds.x.raw[1] * fb->width;
  uint32_t y_min = triangle_bounds.y.raw[0] * fb->height;
  uint32_t y_max = triangle_bounds.y.raw[1] * fb->height;

  const U8Vec3 colour = {{0, 255, 255}};

  for (uint32_t y = y_min; y <= y_max; y++) {
    for (uint32_t x = x_min; x <= x_max; x++) {
      U8Vec3 *pixel = framebuffer_get_pixel(fb, x, y);
      if (!pixel)
        continue;

      Vec2 point = {{x / (float)fb->width, y / (float)fb->height}};

      if (!point_within_triangle2D(t, point))
        continue;

      *pixel = colour;
    }
  }
}

void framebuffer_render_triangle2D_uvs(const Framebuffer *fb, Triangle2D t) {
  BoundingBox2D triangle_bounds = triangle2D_bounding_box(t);

  uint32_t x_min = triangle_bounds.x.raw[0] * fb->width;
  uint32_t x_max = triangle_bounds.x.raw[1] * fb->width;
  uint32_t y_min = triangle_bounds.y.raw[0] * fb->height;
  uint32_t y_max = triangle_bounds.y.raw[1] * fb->height;

  const U8Vec3 colour = {{0, 255, 255}};

  for (uint32_t y = y_min; y <= y_max; y++) {
    for (uint32_t x = x_min; x <= x_max; x++) {
      U8Vec3 *pixel = framebuffer_get_pixel(fb, x, y);
      if (!pixel)
        continue;

      Vec2 point = {{x / (float)fb->width, y / (float)fb->height}};

      if (!point_within_triangle2D(t, point))
        continue;

      Vec2 uv = triangle2D_interpolate_uv(t, point);

      *pixel = u8vec3_from_vec3(vec3_new(uv.x, uv.y, 0.));
    }
  }
}
