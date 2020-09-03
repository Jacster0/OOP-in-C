#pragma once
#include <Windows.h>
#include "resources.h"
#include "mesh.h"

//private attributes
typedef void(*renderer_draw_func_t)(void*);
typedef void(*renderer_load_pipeline_func_t)(void*);

typedef struct {
    DWORD height;
    DWORD width;
} resolution;

typedef struct {
    state_t state;
    struct device_t* device;
    mesh_t* mesh;
    resolution res;
    renderer_draw_func_t draw_func;
    renderer_load_pipeline_func_t load_pipeline_func;
} renderer_t;