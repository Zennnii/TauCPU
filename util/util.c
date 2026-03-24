#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "../cpu/cpu.h"

// Reads a 8 bit value from memory to a specified address
uint8_t mem_read8(CPU* cpu, uint16_t addr) {
    return cpu->memory[addr];
}

// Reads a 16 bit value from memory to a specified address
uint16_t mem_read16(CPU* cpu, uint16_t addr) {
    return cpu->memory[addr] |
          (cpu->memory[addr + 1] << 8);
}

// Writes a 8 bit value to memory to a specified address
void mem_write8(CPU* cpu, uint16_t addr, uint8_t value) {
    cpu->memory[addr] = value;
}

// Writes a 16 bit value to memory to a specified address
void mem_write16(CPU* cpu, uint16_t addr, uint16_t value) {
    cpu->memory[addr]     = value & 0xFF;
    cpu->memory[addr + 1] = (value >> 8) & 0xFF;
}

// Writes to I/O to a specified port
void io_write(CPU* cpu, uint8_t port, uint16_t value) {
    cpu->io[port] = (uint8_t)(value & 0xFF);

    switch (port) {
        case IO_TERM_OUT:
            // Print numeric value
            fprintf(stdout, "port 0x%02X: %u", port, value);

            // Print ASCII character if printable
            if (value <= 0xFF && isprint((unsigned char)value)) {
                fprintf(stdout, " ('%c')", (unsigned char)value);
            }

            fprintf(stdout, "\n");
            break;

        case IO_TERM_DEBUG:
            // Print numeric value
            fprintf(stderr, "[DEBUG] port 0x%02X: %u", port, value);

            // Print ASCII character if printable
            if (value <= 0xFF && isprint((unsigned char)value)) {
                fprintf(stderr, " ('%c')", (unsigned char)value);
            }

            fprintf(stderr, "\n");
            break;

        default:
            break;
    }
}

// Updates the ZF, NF and CF flags
void update_znc_flags(CPU* cpu, uint16_t result16, uint32_t temp) {
    cpu->ZF = (result16 == 0);
    cpu->NF = ((result16 & 0x8000) != 0);
    cpu->CF = (temp > 0xFFFF);
}

// Updates the ZF flag
void update_zf(CPU* cpu, uint16_t result) {
    cpu->ZF = (result == 0);
}

// Updates the NF flag
void update_nf(CPU* cpu, uint16_t result) {
    cpu->NF = ((result & 0x8000) != 0);
}

// Updates the CF flag
void update_cf(CPU* cpu, uint32_t result) {
    cpu->CF = result > 0xFFFF;
}