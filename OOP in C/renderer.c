#include "renderer_p.h"
#include <stdio.h>

//private behaviour functions impl
void __renderer_draw(void* ptr) {
    renderer_t* renderer = ptr;
    if (renderer->load_pipeline_func != NULL) {
        renderer->load_pipeline_func(renderer);
    }
    if (renderer->state == GOOD) {
        printf("state: good\n");
        printf("Drawing to screen...\n");
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
    printf("creating renderer\n");
    renderer->state = BAD;
    renderer->res.height = GetSystemMetrics(SM_CYSCREEN);
    renderer->res.width = GetSystemMetrics(SM_CXSCREEN);
    renderer->draw_func = __renderer_draw;
    renderer->load_pipeline_func = NULL;
}
void renderer_dtor(renderer_t* renderer) {
    printf("destroying renderer\n");
}

void renderer_pure_virt_load_pipeline(renderer_t* renderer) { }

void renderer_draw(renderer_t* renderer) {
    renderer->draw_func(renderer);
}

void renderer_non_virt_display_screen_res(renderer_t* renderer) {
    printf("Height: %lu\nWidth: %lu\n", renderer->res.height, renderer->res.width);
}