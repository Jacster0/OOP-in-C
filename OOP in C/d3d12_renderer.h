#pragma once
struct d3d12_renderer_t;

//Allocator
struct d3d12_renderer_t* d3d12_renderer_new();

//ctor/dtor
void d3d12_renderer_ctor(struct d3d12_renderer_t* d3d12_renderer);
void d3d12_renderer_dtor(struct d3d12_renderer_t* d3d12_renderer);