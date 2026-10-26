#ifndef RENDERER_P_MESH_H
#define RENDERER_P_MESH_H

#include "renderer/mesh.h"

#include "triangle.h"

TriangleIndices mesh_get_triangle(Mesh *mesh, size_t starting_index);

#endif
