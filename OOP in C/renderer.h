#pragma once
#include "resources.h"

struct device_t;
struct renderer_t;

//Allocator
struct renderer_t* renderer_new();

//ctor/dtor
void renderer_ctor(struct renderer_t* renderer);
void renderer_dtor(struct renderer_t* renderer);

//public behaviour functions
void renderer_pure_virt_load_pipeline(struct renderer_t* renderer); //pure virtual function;
void renderer_draw(struct renderer_t* renderer); //virtual function;
void renderer_non_virt_display_screen_res(struct renderer_t* renderer);
void render_non_virt_load_mesh(struct renderer_t* renderer, struct mesh_t* mesh);
void render_non_virt_unload_mesh(struct renderer_t* renderer, struct mesh_t* mesh);
