#pragma once
#include <stdbool.h>

typedef struct {
    //public attributes
    int num_vertices;
    bool has_texcoords;
} mesh_t;

//Allocator
mesh_t* mesh_new();

//ctor/dtor
void mesh_ctor(mesh_t* mesh, int num_vertices, bool has_texcoords);
void mesh_dtor(mesh_t* mesh);