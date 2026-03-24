#include <stdio.h>
#include <stdint.h>
#include "instr.h"

// ADD instr
void add(CPU* cpu, uint16_t r0, uint16_t r1) {
    uint32_t temp = cpu->regs[r0] + cpu->regs[r1];
    uint16_t result = (uint16_t)temp;

    update_znc_flags(cpu, result, temp);

    cpu->regs[r0] = result; // store back in destination register

    cpu->PC += 3;
}

// ADDI instr
void addi(CPU* cpu, uint16_t r0, uint16_t imm16) {
    uint32_t temp = cpu->regs[r0] + imm16;
    uint16_t result = (uint16_t)temp;

    update_znc_flags(cpu, result, temp);

    cpu->regs[r0] = result;

    cpu->PC += 4;
}

// INC instr
void inc(CPU* cpu, uint16_t r0) {
    cpu->regs[r0] += 1;

    update_zf(cpu, r0);
    update_nf(cpu, r0);

    cpu->PC += 2;
}

// DEC instr
void dec(CPU* cpu, uint16_t r0) {
    cpu->regs[r0] -= 1;

    update_zf(cpu, r0);
    update_nf(cpu, r0);

    cpu->PC += 2;
}

// CMP instr
void cmp(CPU* cpu, uint16_t r0, uint16_t r1) {
    uint32_t temp = cpu->regs[r0] - cpu->regs[r1];
    uint16_t result = (uint16_t)temp;

    update_znc_flags(cpu, result, temp);

    cpu->PC += 3;
}

// CMPI instr
void cmpi(CPU* cpu, uint16_t r0, uint16_t imm16) {
    uint32_t temp = cpu->regs[r0] - imm16;
    uint16_t result = (uint16_t)temp;

    update_znc_flags(cpu, result, temp);

    cpu->PC += 4;
}