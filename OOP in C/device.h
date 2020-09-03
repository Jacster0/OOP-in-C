#pragma once
#include <stdbool.h>

enum has_id_t;
struct device_t;

//Memory allocator
struct device_t* device_new();

//ctor/dtor
void device_ctor(struct device_t* device);
void device_dtor(struct device_t* device);

// public behavior functions
void device_creat(struct device_t* device);
void device_get_id(struct device_t* device, char* buffer);
bool device_has_id(struct device_t* device);