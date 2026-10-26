#ifndef RENDERER_MESH_H
#define RENDERER_MESH_H

#include "generic/array.h"

#include "renderer/vertex.h"

#include <stdio.h>

typedef struct {
  VertexLayout layout;
  uint8_t *vertices;
  ARRAY(uint32_t) indices;

  size_t vertex_count;
} Mesh;

Mesh create_mesh(void);
Mesh create_indexed_mesh(void);

void mesh_set_vertex_layout(Mesh *mesh, VertexLayout vertex);
void mesh_resize_vertices(Mesh *mesh, size_t vertex_count);
// void mesh_add_vertex(Mesh *mesh, Vertex vertex);
void mesh_add_index(Mesh *mesh, uint32_t index);
void mesh_add_triangle_indices(Mesh *mesh, uint32_t i1, uint32_t i2,
                               uint32_t i3);

size_t mesh_vertex_count(const Mesh *mesh);
size_t mesh_triangle_count(const Mesh *mesh);

#endif
