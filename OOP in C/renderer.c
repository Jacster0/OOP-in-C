#include "renderer_p.h"
#include <stdio.h>

//private behaviour functions impl
void __renderer_draw(void* ptr) {
    renderer_t* renderer = ptr;
    if (renderer->renderer_vtable.load_pipeline_func != NULL) {
        renderer->renderer_vtable.load_pipeline_func(renderer);
    }

    if (renderer->state == GOOD) {
        printf("state: good\n");
        if (renderer->mesh != NULL) {
            printf("Drawing mesh with %d vertices to screen...\n", renderer->mesh->num_vertices);
            if (renderer->mesh->has_texcoords) {
                printf("Applying texture to mesh...\n");
            }

            else {
                printf("Mesh does not support texturing\n");
            }
        }
    }
    else {
        printf("state: bad\n");
        printf("Cannot draw to screen...\n");
    }
}

//public behaviour functions impl
renderer_t* renderer_new() {
    return (renderer_t*)malloc(sizeof(renderer_t));
}

void renderer_ctor(renderer_t* renderer) {
    printf("creating renderer...\n");
    renderer->state = BAD;
    renderer->res.height = GetSystemMetrics(SM_CYSCREEN);
    renderer->res.width = GetSystemMetrics(SM_CXSCREEN);
    renderer->renderer_vtable = (vtable){ __renderer_draw, NULL };
    renderer->mesh = NULL;
}
void renderer_dtor(renderer_t* renderer) {
    printf("destroying renderer...\n");
}

void renderer_pure_virt_load_pipeline(renderer_t* renderer) { }

void renderer_draw(renderer_t* renderer) {
    renderer->renderer_vtable.draw_func(renderer);
}

void renderer_non_virt_display_screen_res(renderer_t* renderer) {
    printf("Height: %lu\nWidth: %lu\n", renderer->res.height, renderer->res.width);
}

void render_non_virt_load_mesh(renderer_t* renderer, mesh_t* mesh) {
    //Aggregation begins
    renderer->mesh = mesh;
}

void render_non_virt_unload_mesh(renderer_t* renderer, mesh_t* mesh) {
    //Aggregation ends
    renderer->mesh = NULL;
}