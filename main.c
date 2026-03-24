#include <stdio.h>
#include "cpu/cpu.h"
#include "loader/loader.h"

int main(int argc, char **argv) {

    CPU cpu;

    if (argc < 2) {
        printf("Usage: %s <program>\n", argv[0]);
        return 1;
    }

    cpu_init(&cpu);

    load_program(&cpu, argv[1]);

    while (cpu.running)
        cpu_step(&cpu);

    return 0;
}