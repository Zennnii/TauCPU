#include <stdio.h>
#include <stdint.h>
#include "instr.h"

// OUT instr
void out(CPU* cpu, uint8_t port, uint16_t r0) {
    io_write(cpu, port, cpu->regs[r0]);
    cpu->PC += 3;
}

// OUTI instr
void outi(CPU* cpu, uint8_t port, uint16_t imm16) {
    io_write(cpu, port, imm16);
    cpu->PC += 4;
}