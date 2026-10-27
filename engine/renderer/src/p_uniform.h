#ifndef RENDERER_P_UNIFORM_H
#define RENDERER_P_UNIFORM_H

#include "renderer/uniform.h"

ShaderUniform interpolate_uniform(Vec3 scalars, ShaderUniform *p1,
                                  ShaderUniform *p2, ShaderUniform *p3);

#endif
