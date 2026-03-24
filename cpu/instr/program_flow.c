#include <stdio.h>
#include <stdint.h>
#include "instr.h"

// HLT instr
void hlt(CPU* cpu) {
    cpu->running = false;
}