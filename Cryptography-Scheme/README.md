# Binary XOR Decryptor (C++)

## Overview

This program reads an encrypted binary file, decrypts it using two keys, reconstructs the original message, and prints the decoded text to standard output.

The encryption scheme operates block-by-block using XOR operations and shuffled byte indexing.



## File Structure

```
binary-xor-decryptor.cpp
msg0.enc      (encrypted binary file)
msg0.key      (contains dkey and nkey)
msg0.plain    (expected decrypted output)
README.md
```



## Build

```bash
g++ -std=c++11 -O2 -Wall -Wextra -o decrypt binary-xor-decryptor.cpp
```



## Run

```bash
./decrypt <encrypted_file> <dkey> <nkey>
```

### Example

```bash
./decrypt msg0.enc B 127
```

Output:

```
Hello
```



## Encryption Scheme Description

Each encrypted file is composed of 8-byte blocks.

Each block contains:

- 1 byte → Encrypted data
- 3 bytes → Padding (ignored)
- 4 bytes → Encrypted index (integer)



## Decryption Process

For each block:

1. Read encrypted data byte
2. Skip 3 padding bytes
3. Read encrypted 4-byte index
4. Decrypt:
   - `data ^= dkey`
   - `index ^= nkey`
5. Place decrypted data into the output array at position `index`

After all blocks are processed, the reconstructed character array is printed.



## Keys

Two keys are required:

- **dkey (Data Key)** — 1 byte (char)
- **nkey (Index Key)** — 32-bit integer

Example from `msg0.key`:

```
B 127
```

- dkey = 'B'
- nkey = 127

Both keys must match those used during encryption.



## Error Handling

The program checks:

- Incorrect number of arguments
- Failure to open file
- Index out of bounds

If an index is invalid, the program prints:

```
error, index is out of bounds
```



## Concepts Demonstrated

- Binary file I/O (`fopen`, `fread`, `fseek`)
- XOR-based encryption/decryption
- Block-based file parsing
- Manual memory allocation (`new[]`, `delete[]`)
- Index-based message reconstruction
- Command-line argument parsing



## Notes

- File size must be divisible by 8
- Padding bytes are ignored
- The output is reconstructed using decrypted indices
- Designed to demonstrate low-level binary parsing and symmetric XOR encryption

