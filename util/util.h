#ifndef UTIL_H
#define UTIL_H

#include "../cpu/cpu.h"

uint8_t mem_read8(CPU* cpu, uint16_t addr);
uint16_t mem_read16(CPU* cpu, uint16_t addr);
void mem_write8(CPU* cpu, uint16_t addr, uint8_t value);
void mem_write16(CPU* cpu, uint16_t addr, uint16_t value);
void io_write(CPU* cpu, uint8_t port, uint16_t value);
void update_znc_flags(CPU* cpu, uint16_t result16, uint32_t temp);
void update_zf(CPU* cpu, uint16_t result);
void update_nf(CPU* cpu, uint16_t result);
void update_cf(CPU* cpu, uint32_t result);

#endif