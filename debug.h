#ifndef CRAFTING_INTERPRETERS__DEBUG_H_
#define CRAFTING_INTERPRETERS__DEBUG_H_

#include "chunk.h"

void disassembleChunk(Chunk* chunk, const char *name);
// We return the number of bytes/offset to the next instruction
// this is done since different OpCodes can have different sizes
int disassembleInstruction(Chunk* chunk, int offset);

#endif
