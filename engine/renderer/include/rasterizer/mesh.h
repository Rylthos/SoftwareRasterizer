#ifndef RASTERIZER_MESH_H
#define RASTERIZER_MESH_H

#include "generic/array.h"
#include "rasterizer/triangle2D.h"
#include "rasterizer/vertex2D.h"

#include "rasterizer/shader.h"

#include <stdio.h>

typedef struct {
  ARRAY(Vertex2D) vertices;
  ARRAY(uint32_t) indices;
} Mesh;

Mesh create_mesh(void);
Mesh create_indexed_mesh(void);

void mesh_add_vertex(Mesh *mesh, Vertex2D vertex);
void mesh_add_index(Mesh *mesh, uint32_t index);
void mesh_add_triangle_indices(Mesh *mesh, uint32_t i1, uint32_t i2,
                               uint32_t i3);

size_t mesh_vertex_count(const Mesh *mesh);
size_t mesh_triangle_count(const Mesh *mesh);

Triangle2D mesh_get_triangle2D(Mesh *mesh, size_t starting_index);

#endif
