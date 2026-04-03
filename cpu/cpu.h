#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdint.h>
#include <stdbool.h>

#define NUM_REGS 8

// Instruction opcodes
    // Arithmetic
    #define OP_ADD 10
    #define OP_ADDI 11
    #define OP_SUB 12
    #define OP_SUBI 13
    #define OP_INC 14
    #define OP_DEC 15
    #define OP_CMP 16
    #define OP_CMPI 17

    // Data transfer
    #define OP_MOV 20
    #define OP_MOVI 21
    #define OP_LDR 22
    #define OP_LDRI 23
    #define OP_STR 24
    #define OP_STRI 25

    // Program flow
    #define OP_HLT 30
    #define OP_JMP 31
    #define OP_JZ 32
    #define OP_JNZ 33
    #define OP_JN 34
    #define OP_JNN 35
    #define OP_JC 36
    #define OP_JNC 37
    #define OP_JV 38
    #define OP_JNV 39

    // I/O
    #define OP_IN 40
    #define OP_INI 41
    #define OP_OUT 42
    #define OP_OUTI 43

typedef struct {
    uint16_t regs[NUM_REGS];
    uint16_t PC;
    bool running;
    uint8_t memory[65536];
    uint8_t io[256];

    bool ZF;
    bool NF;
    bool CF;
    bool VF;
} CPU;

enum {
    IO_TERM_OUT = 0x01,
    IO_TERM_DEBUG = 0x02
};

void cpu_init(CPU *cpu);
void cpu_step(CPU *cpu);

#endif