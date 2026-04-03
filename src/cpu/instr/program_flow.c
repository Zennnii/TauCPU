#include <stdio.h>
#include <stdint.h>
#include "instr.h"

// HLT instr
void hlt(CPU* cpu) {
    cpu->running = false;
}

// JMP instr
void jmp(CPU* cpu, uint16_t addr) {
    cpu->PC = addr;
}

// JZ instr
void jz(CPU* cpu, uint16_t addr) {
    if (cpu->ZF) {
        cpu->PC = addr;
    } else {
        cpu->PC += 3; // advance if not jumping
    }
}

// JNZ instr
void jnz(CPU* cpu, uint16_t addr) {
    if (!cpu->ZF) {
        cpu->PC = addr;
    } else {
        cpu->PC += 3; // advance if not jumping
    }
}

// JN instr
void cpu_jn(CPU* cpu, uint16_t addr) {
    if (cpu->NF) {
        cpu->PC = addr;
    } else {
        cpu->PC += 3; // advance if not jumping
    }
}

// JNN instr
void jnn(CPU* cpu, uint16_t addr) {
    if (!cpu->NF) {
        cpu->PC = addr;
    } else {
        cpu->PC += 3; // advance if not jumping
    }
}

// JC instr
void jc(CPU* cpu, uint16_t addr) {
    if (cpu->CF) {
        cpu->PC = addr;
    } else {
        cpu->PC += 3; // advance if not jumping
    }
}

// JNC instr
void jnc(CPU* cpu, uint16_t addr) {
    if (!cpu->CF) {
        cpu->PC = addr;
    } else {
        cpu->PC += 3; // advance if not jumping
    }
}

void jv(CPU* cpu, uint16_t addr) {
    if (cpu->VF) {
        cpu->PC = addr;
    } else {
        cpu->PC += 3; // advance if not jumping
    }
}

void jnv(CPU* cpu, uint16_t addr) {
    if (!cpu->VF) {
        cpu->PC = addr;
    } else {
        cpu->PC += 3; // advance if not jumping
    }
}