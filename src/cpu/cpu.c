#include <stdio.h>
#include <string.h>
#include "cpu.h"
#include "instr/instr.h"

// Initializes CPU
void cpu_init(CPU *cpu) {
    memset(cpu, 0, sizeof(CPU));
    cpu->running = true;
}

// CPU step function
void cpu_step(CPU *cpu) {
    int opcode = cpu->memory[cpu->PC];

    switch (opcode) {
        case OP_ADD: {
            uint16_t r0 = cpu->memory[cpu->PC + 1];
            uint16_t r1 = cpu->memory[cpu->PC + 2];
            add(cpu, r0, r1);

            break;
        }
        
        case OP_ADDI: {
            uint8_t r0 = cpu->memory[cpu->PC + 1];
            uint16_t imm16 = cpu->memory[cpu->PC + 2] |
                            (cpu->memory[cpu->PC + 3] << 8);
            addi(cpu, r0, imm16);
            
            break;
        }

        case OP_INC: {
            uint16_t r0 = cpu->memory[cpu->PC + 1];
            inc(cpu, r0);
            
            break;
        }

        case OP_DEC: {
            uint16_t r0 = cpu->memory[cpu->PC + 1];
            dec(cpu, r0);
            
            break;
        }

        case OP_CMP: {
            uint16_t r0 = cpu->memory[cpu->PC + 1];
            uint16_t r1 = cpu->memory[cpu->PC + 2];
            cmp(cpu, r0, r1);
            
            break;
        }

        case OP_CMPI: {
            uint8_t r0 = cpu->memory[cpu->PC + 1];
            uint16_t imm16 = cpu->memory[cpu->PC + 2] |
                            (cpu->memory[cpu->PC + 3] << 8);
            cmpi(cpu, r0, imm16);
            
            break;
        }

        case OP_MOV: {
            uint16_t r0 = cpu->memory[cpu->PC + 1];
            uint16_t r1 = cpu->memory[cpu->PC + 2];
            mov(cpu, r0, r1);
            
            break;
        }

        case OP_MOVI: {
            uint8_t r0 = cpu->memory[cpu->PC + 1];
            uint16_t imm16 = cpu->memory[cpu->PC + 2] |
                            (cpu->memory[cpu->PC + 3] << 8);
            movi(cpu, r0, imm16);
            
            break;
        }

        case OP_LDR: {
            uint16_t r0 = cpu->memory[cpu->PC + 1];
            uint16_t r1 = cpu->memory[cpu->PC + 2];
            ldr(cpu, r0, r1);
            
            break;
        }
        
        case OP_LDRI: {
            uint8_t r0 = cpu->memory[cpu->PC + 1];
            uint8_t r1 = cpu->memory[cpu->PC + 2];
            uint16_t offset = cpu->memory[cpu->PC + 3] |
                             (cpu->memory[cpu->PC + 4] << 8);
            ldri(cpu, r0, r1, offset);
            
            break;
        }

        case OP_STR: {
            uint16_t r0 = cpu->memory[cpu->PC + 1];
            uint16_t r1 = cpu->memory[cpu->PC + 2];
            str(cpu, r0, r1);
            
            break;
        }

        case OP_STRI: {
            uint8_t r0 = cpu->memory[cpu->PC + 1];
            uint8_t r1 = cpu->memory[cpu->PC + 2];
            uint16_t offset = cpu->memory[cpu->PC + 3] |
                             (cpu->memory[cpu->PC + 4] << 8);
            stri(cpu, r0, r1, offset);
            
            break;
        }

        case OP_OUT: {
            uint8_t port = cpu->memory[cpu->PC + 1];
            uint8_t r0 = cpu->memory[cpu->PC + 2];
            out(cpu, port, r0);

            break;
        }

        case OP_OUTI: {
            uint8_t port = cpu->memory[cpu->PC + 1];
            uint16_t imm16 = cpu->memory[cpu->PC + 2] |
                            (cpu->memory[cpu->PC + 3] << 8);
            outi(cpu, port, imm16);

            break;
        }

        case OP_HLT: {
            hlt(cpu);
            
            break;
        }

        case OP_JZ: {
            uint16_t addr = cpu->memory[cpu->PC + 1] |
                   (cpu->memory[cpu->PC + 2] << 8);

            jz(cpu, addr);

            break;
        }

        case OP_JNZ: {
            uint16_t addr = cpu->memory[cpu->PC + 1] |
                   (cpu->memory[cpu->PC + 2] << 8);

            jnz(cpu, addr);

            break;
        }

        case OP_JN: {
            uint16_t addr = cpu->memory[cpu->PC + 1] |
                   (cpu->memory[cpu->PC + 2] << 8);

            cpu_jn(cpu, addr);

            break;
        }

        case OP_JNN: {
            uint16_t addr = cpu->memory[cpu->PC + 1] |
                   (cpu->memory[cpu->PC + 2] << 8);

            jnn(cpu, addr);

            break;
        }

        case OP_JC: {
            uint16_t addr = cpu->memory[cpu->PC + 1] |
                   (cpu->memory[cpu->PC + 2] << 8);

            jc(cpu, addr);

            break;
        }

        case OP_JNC: {
            uint16_t addr = cpu->memory[cpu->PC + 1] |
                   (cpu->memory[cpu->PC + 2] << 8);

            jnc(cpu, addr);

            break;
        }

        case OP_JV: {
            uint16_t addr = cpu->memory[cpu->PC + 1] |
                   (cpu->memory[cpu->PC + 2] << 8);

            jv(cpu, addr);

            break;
        }

        case OP_JNV: {
            uint16_t addr = cpu->memory[cpu->PC + 1] |
                   (cpu->memory[cpu->PC + 2] << 8);

            jnv(cpu, addr);

            break;
        }


        default: {
            printf("Unknown opcode %u at PC=%u\n", opcode, cpu->PC);
            cpu->running = false;
            break;
        }
    }
}