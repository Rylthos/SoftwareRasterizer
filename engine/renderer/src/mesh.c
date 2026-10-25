#include "renderer/mesh.h"

#include "renderer/triangle2D.h"
#include "renderer/vertex2D.h"

#include "assert.h"

Mesh create_mesh(void) {
  return (Mesh){
      .vertices = ARRAY_CREATE(Vertex2D),
      .indices = NULL,
  };
}

Mesh create_indexed_mesh(void) {
  return (Mesh){
      .vertices = ARRAY_CREATE(Vertex2D),
      .indices = ARRAY_CREATE(uint32_t),
  };
}

void mesh_add_vertex(Mesh *mesh, Vertex2D vertex) {
  ARRAY_PUSH(mesh->vertices, vertex);
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
    return ARRAY_LEN(mesh->vertices) / 3;
  }
}

Triangle2D mesh_get_triangle2D(Mesh *mesh, size_t starting_index) {
  if (mesh->indices) {
    assert((starting_index + 3) <= ARRAY_LEN(mesh->indices) &&
           "Index addresses invalid indices");

    return create_triangle2D_vertices(
        mesh->vertices[mesh->indices[starting_index + 0]],
        mesh->vertices[mesh->indices[starting_index + 1]],
        mesh->vertices[mesh->indices[starting_index + 2]]);
  } else {
    assert((starting_index + 3) <= ARRAY_LEN(mesh->vertices) &&
           "Index addresses invalid triangle");

    return create_triangle2D_vertices(mesh->vertices[starting_index + 0],
                                      mesh->vertices[starting_index + 1],
                                      mesh->vertices[starting_index + 2]);
  }
}
