#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef enum { YES, NO } has_id_t;

typedef struct {
    //private attribute
    char* id;
    has_id_t has_id;
} device_t;


// private behavior functions impl
void make_id(char* buffer, int length) {
    srand(time(0));
    char charset[] = "0123456789" "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (length-- > 0) {
        size_t index = (double)rand() / RAND_MAX * (sizeof charset - 1);
        *buffer++ = charset[index];
    }
    *buffer = '\0';
}

// public behavior functions impl
struct device_t* device_new() {
    return (device_t*)malloc(sizeof(device_t));
}

void device_ctor(device_t* device) {
    printf("Creating device...\n");
    device->id = (char*)malloc(32 * sizeof(char));
    device->has_id = NO;
}
void device_dtor(device_t* device) {
    printf("Destroying device...\n");
    free(device->id);
}

void device_creat(device_t* device) {
    make_id(device->id, 31);
    device->has_id = YES;
}

void device_get_id(device_t* device, char* buffer) {
    strcpy(buffer, device->id);
}

bool device_has_id(device_t* device) {
    return device->has_id == YES;
}