#include "mesh.h"
#include <stdio.h>

mesh_t* mesh_new() {
    return (mesh_t*)malloc(sizeof(mesh_t));
}

void mesh_ctor(mesh_t* mesh, int num_vertices, bool has_texcoords) {
    printf("Creating mesh...\n");
    mesh->num_vertices = num_vertices;
    mesh->has_texcoords = has_texcoords;
}
void mesh_dtor(mesh_t* mesh) {
    printf("Destroying mesh...\n");
}