#include "renderer.h"
#include "d3d12_renderer.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    struct renderer_t* renderer = renderer_new();

    renderer_ctor(renderer);
    //call to base class non virtual func
    renderer_non_virt_display_screen_res(renderer);
    //call to base class pure virtual func, illegal
    renderer_pure_virt_load_pipeline(renderer);
    //call to base class virtual func
    renderer_draw(renderer);

    renderer_dtor(renderer);


    printf("\n\n");

    struct d3d12_renderer_t* d3d12_renderer = d3d12_renderer_new();
    d3d12_renderer_ctor(d3d12_renderer);
    //call to base class non virtual func
    renderer_non_virt_display_screen_res(d3d12_renderer);
    //call to child class overriden func
    renderer_pure_virt_load_pipeline(d3d12_renderer);
    // call to child class overriden func
    renderer_draw(d3d12_renderer);
    //access base class public member
    d3d12_renderer_dtor(d3d12_renderer);
    
    free(d3d12_renderer);
    free(renderer);
    getchar();
}