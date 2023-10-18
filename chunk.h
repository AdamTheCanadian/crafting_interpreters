#ifndef CRAFTING_INTERPRETERS__CHUNK_H_
#define CRAFTING_INTERPRETERS__CHUNK_H_

/**
 * \brief "chunk" refers to sequences of bytecode
 */

#include "common.h"
#include "value.h"

// Operation Code == OpCode
// Add, subtraction, look up, etc
typedef enum {
  // Return from the current function
  OP_RETURN,
} OpCode;

// Chunk (bytecode) is a series of instructions
typedef struct {
  // number of element in use
  int count;
  // number of elements allocated
  int capacity;
  // Series of single byte instructions
  uint8_t *code;
  ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte);
int addConstant(Chunk *chunk, Value value);

#endif
