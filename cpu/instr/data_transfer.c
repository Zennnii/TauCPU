#include <stdio.h>
#include <stdint.h>
#include "instr.h"

// MOV instr
void mov(CPU* cpu, uint16_t r0, uint16_t r1) {
    cpu->regs[r0] = cpu->regs[r1];

    cpu->PC += 3;
}

// MOVI instr
void movi(CPU* cpu, uint16_t r0, uint16_t imm16) {
    //printf("MOVI r%u, %u at PC=%u\n", r0, imm16, cpu->PC);
    cpu->regs[r0] = imm16;

    cpu->PC += 4;
    
    //printf("PC after MOVI=%u\n", cpu->PC);
}

// LDR instr
void ldr(CPU* cpu, uint16_t r0, uint16_t r1) {
    cpu->regs[r0] = mem_read16(cpu, cpu->regs[r1]);

    cpu->PC += 3;
}

// LDRI instr
void ldri(CPU* cpu, uint16_t r0, uint16_t r1, uint16_t offset) {
    uint16_t addr = cpu->regs[r1] + offset;
    cpu->regs[r0] = mem_read16(cpu, addr);

    cpu->PC += 5; 
}

// STR instr
void str(CPU* cpu, uint16_t r0, uint16_t r1) {
    uint16_t addr = cpu->regs[r1];
    mem_write16(cpu, addr, cpu->regs[r0]);

    cpu->PC += 3;
}

// STRI instr
void stri(CPU* cpu, uint16_t r0, uint16_t r1, uint16_t offset) {
    uint16_t addr = cpu->regs[r1] + offset;
    mem_write16(cpu, addr, cpu->regs[r0]);

    cpu->PC += 5;
}