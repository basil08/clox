#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCap, newCap) (type*) reallocate(pointer, sizeof(type) * (oldCap), sizeof(type) * newCap)

#define FREE_ARRAY(type, pointer, oldCap) reallocate(pointer, sizeof(type) * oldCap, 0);

// This reallocate() function is the single function we’ll use for all dynamic memory management in clox—allocating memory, freeing it, and changing the size of an existing allocation. Routing all of those operations through a single function will be important later when we add a garbage collector that needs to keep track of how much memory is in use.
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif