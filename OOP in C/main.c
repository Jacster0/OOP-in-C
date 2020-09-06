#include "renderer.h"
#include "d3d12_renderer.h"
#include "mesh.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    mesh_t* mesh = mesh_new();
    mesh_ctor(mesh, 3000, true);

    struct renderer_t* renderer = renderer_new();
    renderer_ctor(renderer);
    //call to base class non virtual func
    renderer_non_virt_display_screen_res(renderer);
    render_non_virt_load_mesh(renderer, mesh);
    //call to base class pure virtual func, illegal
    renderer_pure_virt_load_pipeline(renderer);
    //call to base class virtual func
    renderer_draw(renderer);
    render_non_virt_unload_mesh(renderer, mesh);

    renderer_dtor(renderer);

    printf("\n\n");

    struct d3d12_renderer_t* d3d12_renderer = d3d12_renderer_new();
    d3d12_renderer_ctor(d3d12_renderer);
    //call to base class non virtual func
    renderer_non_virt_display_screen_res(d3d12_renderer);
    render_non_virt_load_mesh(d3d12_renderer, mesh);
    //call to child class overriden func
    renderer_pure_virt_load_pipeline(d3d12_renderer);
    // call to child class overriden func
    renderer_draw(d3d12_renderer);
    render_non_virt_unload_mesh(d3d12_renderer, mesh);

    d3d12_renderer_dtor(d3d12_renderer);
    mesh_dtor(mesh);

    free(mesh);
    free(d3d12_renderer);
    free(renderer);
    getchar();
}