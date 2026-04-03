# TauCPU

TauCPU is a custom 16-bit virtual CPU and instruction set architecture designed for experimenting with low-level systems programming, emulation, and assembly language development.

It includes a full CPU emulator and a custom instruction set. Programs can be written using a separate assembler (TASM), which is maintained in a different repository.

## Features

- 16-bit CPU architecture
- Register-based instruction set
- Arithmetic and logic operations
- Memory load/store system
- Port-mapped I/O
- Conditional branching and jumps
- Custom assembler (TASM)

## Architecture Overview

- Word size: 16-bit
- Supports registers, memory access, and immediate values
- Includes CPU flags: ZF, NF, CF, VF
- Supports port-mapped I/O devices

## Instruction Set

See [ISA reference](docs/instruction_set.txt) for full ISA reference.

## I/O Ports

The emulator supports port-mapped devices, including:

- Terminal output
- Debugging output
- Future display devices
- Future input hardware (keyboard, timers)

See [I/O ports](docs/io_ports.txt) for a full list of I/O ports.

## Project Structure

src/ - CPU emulator
docs/ - Documentation

## Assembler

Custom assembler for TauCPU:

- [TASM – TauCPU Assembler](https://github.com/Zennnii/TASM)

## Contributing

This is a personal project, but suggestions and improvements are welcome.

## Contact

For questions or feedback, feel free to reach me at: vukmitic81@gmail.com