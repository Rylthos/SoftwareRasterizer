#include "renderer/mesh.h"

// #include "renderer/triangle2D.h"
#include "generic/array.h"
#include "renderer/vertex.h"

#include "assert.h"
#include "triangle.h"
#include <threads.h>

Mesh create_mesh(void) {
  return (Mesh){
      .vertices = NULL,
      .indices = NULL,
      .vertex_count = 0,
  };
}

Mesh create_indexed_mesh(void) {
  return (Mesh){
      .vertices = NULL,
      .indices = ARRAY_CREATE(uint32_t),
      .vertex_count = 0,
  };
}

void mesh_set_vertex_layout(Mesh *mesh, VertexLayout layout) {
  mesh->layout = layout;
}

void mesh_resize_vertices(Mesh *mesh, size_t vertex_count) {
  if (!mesh->vertices)
    free(mesh->vertices);

  mesh->vertex_count = vertex_count;
  mesh->vertices = malloc(vertex_count * mesh->layout.stride);
}

void mesh_add_index(Mesh *mesh, uint32_t index) {
  assert(mesh->indices && "Indexing not supported on this mesh");

  ARRAY_PUSH(mesh->indices, index);
}

void mesh_add_triangle_indices(Mesh *mesh, uint32_t i1, uint32_t i2,
                               uint32_t i3) {
  mesh_add_index(mesh, i1);
  mesh_add_index(mesh, i2);
  mesh_add_index(mesh, i3);
}

size_t mesh_vertex_count(const Mesh *mesh) { return ARRAY_LEN(mesh->vertices); }

size_t mesh_triangle_count(const Mesh *mesh) {
  if (mesh->indices) {
    return ARRAY_LEN(mesh->indices) / 3;
  } else {
    return mesh->vertex_count / 3;
  }
}

TriangleIndices mesh_get_triangle(Mesh *mesh, size_t starting_index) {
  if (mesh->indices) {
    assert((starting_index + 3) <= ARRAY_LEN(mesh->indices) &&
           "Index addresses invalid indices");

    return (TriangleIndices){
        .i1 = mesh->indices[starting_index + 0],
        .i2 = mesh->indices[starting_index + 1],
        .i3 = mesh->indices[starting_index + 2],
    };
  } else {
    assert((starting_index + 3) <= mesh->vertex_count &&
           "Index addresses invalid triangle");

    return (TriangleIndices){
        .i1 = starting_index + 0,
        .i2 = starting_index + 1,
        .i3 = starting_index + 2,
    };
  }
}
