#pragma once
#include <Windows.h>
typedef enum { GOOD, BAD } state_t;

//private attributes
typedef void(*renderer_draw_func_t)(void*);
typedef void(*renderer_load_pipeline_func_t)(void*);

typedef struct {
    DWORD height;
    DWORD width;
} resolution;

typedef struct {
    state_t state;
    resolution res;
    renderer_draw_func_t draw_func;
    renderer_load_pipeline_func_t load_pipeline_func;
} renderer_t;