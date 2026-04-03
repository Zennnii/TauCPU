# TauCPU

A small custom 16-bit CPU emulator and instruction set architecture built for experimenting and running simple assembly programs.

It includes arithmetic, data movement, memory access, comparison instructions, basic port-mapped output, conditional jumps and a halt instruction.

## Architecture Overview

The CPU operates on 16-bit values and supports:

- Arithmetic
- Register-to-register operations
- Immediate values
- Memory access
- Port-mapped I/O
- Halting execution
- Conditional jumps

## Instruction Set

See [instruction_set.txt](docs/instruction_set.txt) for the full instruction reference

## I/O Ports

The emulator supports port-mapped devices, including:

- Terminal output
- Debugging output
- Future display devices
- Future keyboard or timer hardware

See [io_ports.txt](docs/io_ports.txt) For a full list of I/O ports

## Contributing

This is a personal project, but contributions and suggestions are welcome.

## Contact

For questions or feedback, feel free to reach me at: [vukmitic81@gmail.com](mailto:vukmitic81@gmail.com)

## Assembler (TASM)

[TASM – TauCPU Assembler](https://github.com/Zennnii/TASM)