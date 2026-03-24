#ifndef INSTR_H
#define INSTR_H

#include "../cpu.h"
#include "../../util/util.h"

// Arithmetic instructions
void add(CPU* cpu, uint16_t r0, uint16_t r1);
void addi(CPU* cpu, uint16_t r0, uint16_t imm16);
void inc(CPU* cpu, uint16_t r0);
void dec(CPU* cpu, uint16_t r0);
void cmp(CPU* cpu, uint16_t r0, uint16_t r1);
void cmpi(CPU* cpu, uint16_t r0, uint16_t imm16);

// Data transfer instructions
void mov(CPU* cpu, uint16_t r0, uint16_t r1);
void movi(CPU* cpu, uint16_t r0, uint16_t imm16);
void ldr(CPU* cpu, uint16_t r0, uint16_t r1);
void ldri(CPU* cpu, uint16_t r0, uint16_t r1, uint16_t offset);
void str(CPU* cpu, uint16_t r0, uint16_t r1);
void stri(CPU* cpu, uint16_t r0, uint16_t r1, uint16_t offset);

// I/O instructions
void out(CPU* cpu, uint8_t port, uint16_t r0);
void outi(CPU* cpu, uint8_t port, uint16_t imm16);

// Program flow instructions
void hlt(CPU* cpu);

#endif