#include "renderer.h"
#include <stdio.h>

int main() {
    struct render_t* renderer = renderer_new();

    renderer_ctor(renderer);
    //call to base class non virtual func
    renderer_non_virt_display_screen_res(renderer);
    //call to base class pure virtual func, illegal
    renderer_pure_virt_load_pipeline(renderer);
    //call to base class virtual func
    renderer_draw(renderer);

    renderer_dtor(renderer);
    free(renderer);
    
    getchar();
}