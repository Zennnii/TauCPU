#include <stdio.h>
#include <stdint.h>
#include "instr.h"

// ADD instr
void add(CPU* cpu, uint16_t r0, uint16_t r1) {
    uint32_t temp = cpu->regs[r0] + cpu->regs[r1];
    uint16_t result = (uint16_t)temp;

    update_znc_flags(cpu, result, temp);
    update_vf_add(cpu, cpu->regs[r0], cpu->regs[r1], result);

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

// SUB instr
void sub(CPU* cpu, uint16_t r0, uint16_t r1) {
    uint32_t temp = cpu->regs[r0] - cpu->regs[r1];
    uint16_t result = (uint16_t)temp;

    update_znc_flags(cpu, result, temp);
    update_vf_sub(cpu, cpu->regs[r0], cpu->regs[r1], result);

    cpu->regs[r0] = result; // store back in destination register

    cpu->PC += 3;
}

// SUBI instr
void subi(CPU* cpu, uint16_t r0, uint16_t imm16) {
    uint32_t temp = cpu->regs[r0] - imm16;
    uint16_t result = (uint16_t)temp;

    update_znc_flags(cpu, result, temp);
    update_vf_sub(cpu, cpu->regs[r0], cpu->regs[imm16], result);

    cpu->regs[r0] = result;

    cpu->PC += 4;
}

// INC instr
void inc(CPU* cpu, uint16_t r0) {
    uint16_t a = cpu->regs[r0];
    uint16_t result = a + 1;

    cpu->regs[r0] = result;

    update_zf(cpu, result);
    update_nf(cpu, result);
    update_vf_add(cpu, a, 1, result);

    cpu->PC += 2;
}

// DEC instr
void dec(CPU* cpu, uint16_t r0) {
    uint16_t a = cpu->regs[r0];
    uint16_t result = a - 1;

    cpu->regs[r0] = result;

    update_zf(cpu, result);
    update_nf(cpu, result);
    update_vf_sub(cpu, a, 1, result);

    cpu->PC += 2;
}

// CMP instr
void cmp(CPU* cpu, uint16_t r0, uint16_t r1) {
    uint32_t temp = cpu->regs[r0] - cpu->regs[r1];
    uint16_t result = (uint16_t)temp;

    update_znc_flags(cpu, result, temp);
    update_vf_sub(cpu, cpu->regs[r0], cpu->regs[r1], result);

    cpu->PC += 3;
}

// CMPI instr
void cmpi(CPU* cpu, uint16_t r0, uint16_t imm16) {
    uint32_t temp = cpu->regs[r0] - imm16;
    uint16_t result = (uint16_t)temp;

    update_znc_flags(cpu, result, temp);
    update_vf_sub(cpu, cpu->regs[r0], cpu->regs[imm16], result);

    cpu->PC += 4;
}