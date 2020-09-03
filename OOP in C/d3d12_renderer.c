#include <stdio.h>
#include "renderer_p.h"
#include "device.h"

typedef struct {
    //private attribute
    renderer_t renderer;
} d3d12_renderer_t;

//private behaviour functions impl
void __d3d12_renderer_draw(void* ptr) {
    char buffer[32];
    renderer_t* renderer = ptr;
    if (renderer->load_pipeline_func != NULL) {
        renderer->load_pipeline_func(renderer);

        if (renderer->state == GOOD) {
            device_get_id(renderer->device, buffer);
            printf("device id: %s\n", buffer);
            printf("state: good\n");

            if (renderer->mesh != NULL) {
                printf("Using d3d12 API to draw mesh with %d vertices to screen...\n", renderer->mesh->num_vertices);
                if (renderer->mesh->has_texcoords) {
                    printf("Applying texture to mesh\n");
                }
                else {
                    printf("Mesh does not support texturing\n");
                }
            }
        }
        else {
            printf("state: bad\n");
            printf("Cannot draw to screen because there was an error loading the pipeline\n");
        }
    }
}
   
void __d3d12_renderer_load_pipeline(void* ptr) {
    renderer_t* renderer = ptr;
    device_creat(renderer->device);

    if (device_has_id(renderer->device)) {
        renderer->state = GOOD;
    }
}

//public behaviour functions impl
d3d12_renderer_t* d3d12_renderer_new() {
    return (d3d12_renderer_t*)malloc(sizeof(d3d12_renderer_t));
}

void d3d12_renderer_ctor(d3d12_renderer_t* d3d12_renderer) {
    renderer_ctor(d3d12_renderer);
    printf("creating d3d12_renderer...\n");
    d3d12_renderer->renderer.draw_func = __d3d12_renderer_draw;
    d3d12_renderer->renderer.load_pipeline_func = __d3d12_renderer_load_pipeline;
    d3d12_renderer->renderer.device = device_new();
    device_ctor(d3d12_renderer->renderer.device);
}

void d3d12_renderer_dtor(d3d12_renderer_t* d3d12_renderer) {
    device_dtor(d3d12_renderer->renderer.device);
    free(d3d12_renderer->renderer.device);
    printf("destroying d3d12_renderer...\n");
    renderer_dtor(d3d12_renderer);
}