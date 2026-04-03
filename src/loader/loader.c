#include <stdio.h>
#include "loader.h"

void load_program(CPU *cpu, const char *filename) {
    FILE *f = fopen(filename, "rb");

    if (!f) {
        printf("Cannot open file\n");
        return;
    }

    size_t size = fread(cpu->memory, 1, sizeof(cpu->memory), f);

    if (size == 0) {
        printf("Program empty\n");
    }

    fclose(f);
}