#include <stdlib.h>
#include "memory.h"


void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    // when oldSize == 0, call to realloc() === call to malloc()
    void* result = realloc(pointer, newSize);

    if (result == NULL) exit(1);
    
    return result;
}