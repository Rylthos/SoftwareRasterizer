#ifndef RENDERER_VERTEX_H
#define RENDERER_VERTEX_H

#include "stdint.h"
#include "stdlib.h"

typedef struct {
  uint32_t id;
  size_t offset;
  size_t size;
} AttributeDefinition;

typedef struct {
  AttributeDefinition *attributes;
  size_t count;
  size_t stride;
} VertexLayout;

#endif
