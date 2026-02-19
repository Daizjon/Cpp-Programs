# RISC-V Disassembler (C++)

## Overview

This project implements a basic RISC-V disassembler in C++.  
It reads a raw binary file containing 32-bit little-endian machine instructions and converts each instruction into human-readable assembly format.

The program supports two register naming conventions:

- ABI register names (default): `zero`, `ra`, `sp`, `a0`, `t0`, etc.
- x-register names: `x0`–`x31`



## Features

- Reads binary instruction streams (4 bytes per instruction)
- Decodes RISC-V instruction fields using bit masking and shifting
- Supports multiple instruction types:
  - I-Type ALU (`addi`, `xori`, `ori`, `andi`, `slli`, `srli`, `srai`)
  - R-Type (`add`, `sub`, `xor`, `sll`, `srl`, `sra`, `and`, `or`)
  - Loads (`lb`, `lh`, `lw`, `ld`, `lwu`)
  - Stores (`sb`, `sh`, `sw`, `sd`)
  - `lui`
  - `jalr`
- Optional ABI or x-register output formatting
- Outputs to file or stdout



## Build

Compile with:

```bash
g++ -std=c++11 -O2 -o disassembler riscv-disassembler.cpp
```



## Usage

```bash
./disassembler <input_binary> <output_file_or_dash> [a|x]
```

### Arguments

- `<input_binary>`  
  Binary file containing 32-bit RISC-V instructions (little-endian).

- `<output_file_or_dash>`  
  Output destination:
  - `-` → write to stdout
  - filename → write to file

- `[a|x]` (optional)
  - `a` → ABI register names (default)
  - `x` → x-register format (`x0–x31`)



## Examples

Write decoded instructions to terminal using ABI registers:

```bash
./disassembler program.bin - a
```

Write to a file using default ABI registers:

```bash
./disassembler program.bin output.s
```

Use x-register format:

```bash
./disassembler program.bin output.s x
```



## Implementation Notes

- Instructions are read in 4-byte chunks.
- Opcode and funct3 fields are extracted using bitwise operations.
- Register fields and immediates are decoded based on instruction type.
- Unsupported or unrecognized instructions output `"invalid"`.
- Supports both ABI register naming and raw `x` register formatting.



## Technical Focus

- Binary file parsing
- Instruction decoding via bit manipulation
- Assembly formatting logic
- Register abstraction (ABI vs x-register)
- Systems-level C++ programming
