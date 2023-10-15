#ifndef CRAFTING_INTERPRETERS__MEMORY_H_
#define CRAFTING_INTERPRETERS__MEMORY_H_

#include "common.h"

// Min value of 8 chosen arbitrarily
// In the case of capacity 0 we default straight to 8 elements
// So waste a few bytes but avoid extra memory churn when array is very small
#define GROW_CAPACITY(capacity) \
  ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
  (type*)reallocate(pointer, sizeof(type) * (oldCount), \
    sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0);

/**
 * Types of operations for reallocate
 * oldSize == 0, newSize > 0, allocate new block of memory
 * oldSize != 0, newSize == 0, free allocation
 * oldSize != 0, newSize < oldSize, shrink existing allocation
 * oldSize != 0, newSize > oldSize, grow existing allocation
 */
void* reallocate(void* pointer, size_t oldSize, size_t newSize);
#endif
