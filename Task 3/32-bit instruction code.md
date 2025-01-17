

### 1. Instruction: lui a0, 0x21
- **Opcode:** `0110111` (7 bits)
- **Immediate (upper 20 bits of 0x21 shifted left by 12):** `00000000000000000010` (20 bits)
- **Destination Register (rd):** `a0 (x10)`: `01010` (5 bits)

**Breakdown:**
```
| imm[31:12]         | rd   | opcode  |
|--------------------|-------|--------|
|00000000000000000010 | 01010 | 0110111 |
```

### 2. Instruction: addi sp, sp, -16
- **Opcode:** `0010011` (7 bits)
- **Immediate:** `1111111111110000` (12 bits)
- **Source Register (rs1):** `sp (x2)`: `00010` (5 bits)
- **Destination Register (rd):** `sp (x2)`: `00010` (5 bits)
- **Function (funct3):** `000` (3 bits)

**Breakdown:**
```
| imm[11:0]  | rs1   | funct3 | rd   | opcode  |
|-------------|-------|--------|-----|----------|
|111111111111 | 00010 | 000    | 00010 | 0010011|
```

### 3. Instruction: li a1, 20
- **Opcode:** `0010011` (7 bits)
- **Immediate:** `00000000010100` (12 bits)
- **Source Register (rs1):** `zero (x0)`: `00000` (5 bits)
- **Destination Register (rd):** `a1 (x11)`: `01011` (5 bits)
- **Function (funct3):** `000` (3 bits)

**Breakdown:**
```
|  imm[11:0]  | rs1   | funct3 | rd   | opcode  |
|--------------|------|---------|-------|---------|
|00000000010100 | 00000 | 000    | 01011 | 0010011 |
```

### 4. Instruction: jal ra, 10404 <printf>
- **Opcode:** `1101111` (7 bits)
- **Immediate:** `10404(0x28B4)` (21 bits)
- **Destination Register (rd):** `ra (x1)`: `00001` (5 bits)

**Breakdown:**
```
|imm[20] | imm[10:1] | imm[11] | imm[19:12]  | rd   | opcode |
|--------|-----------|---------|------------|-------|--------|
|   0   | 0101101010 |   1     | 00000000    | 00001 | 1101111 |
```

### 5. Instruction: `sd ra, 8(sp)`
- **Opcode:** `0100011` (7 bits)
- **Immediate:** `0000000001000` (12 bits, split into two parts)
- **Source Register (rs2):** `ra (x1)`: `00001` (5 bits)
- **Base Register (rs1):** `sp (x2)`: `00010` (5 bits)
- **Function (funct3):** `011` (3 bits)

**Breakdown:**
```
|  imm[11:5] | rs2   | rs1   | funct3 | imm[4:0] | opcode |
|-------------|-------|-------|-------|----------|----------|
|  0000000   | 00001 | 00010 | 011    | 01000    | 0100011  |
```

### 6. Instruction: `ld ra, 8(sp)`
- **Opcode:** `0000011` (7 bits)
- **Immediate:** `0000000001000` (12 bits)
- **Source Register (rs1):** `sp (x2)`: `00010` (5 bits)
- **Destination Register (rd):** `ra (x1)`: `00001` (5 bits)
- **Function (funct3):** `011` (3 bits)

**Breakdown:**
```
|imm[11:0] | rs1   | funct3 | rd   | opcode |
|-------------|------|-----|-------|---------|
|0000000001000 | 00010 | 011    | 00001 | 0000011|
```

### 7. Instruction: `jalr zero, ra, 0` (ret)
- **Opcode:** `1100111` (7 bits)
- **Immediate:** `000000000000` (12 bits)
- **Source Register (rs1):** `ra (x1)`: `00001` (5 bits)
- **Destination Register (rd):** `zero (x0)`: `00000` (5 bits)
- **Function (funct3):** `000` (3 bits)

**Breakdown:**
```
|imm[11:0] | rs1   | funct3 | rd   | opcode  |
|-----------|-------|-------|-------|---------|
|000000000000 | 00001 | 000    | 00000 | 1100111|
```

### 8. Instruction: `auipc a5, 0xffff0`
- **Opcode:** `0010111` (7 bits)
- **Immediate:** `0xffff0` (20 bits)
- **Destination Register (rd):** `a5 (x15)`: `01111` (5 bits)

**Breakdown:**
```
| imm[31:12]   | rd   | opcode |
|--------------|-------|--------|
|0xffff0 (20 bits) | 01111 | 0010111  |
```

### 9. Instruction: `addi a5, a5, -216`
- **Opcode:** `0010011` (7 bits)
- **Immediate: 11111100101000 (12 bits  in 2's complement for -216)
- **Source Register 1 (rs1):** `a5 (x15)`: `01111` (5 bits)
- **Destination Register (rd):** `a5 (x15)`: `01111` (5 bits)
- **Function (funct3):** `000` (3 bits)

**Breakdown:**
```
|imm[11:0]  | rs1   | funct3 | rd   | opcode|
|------------|--------|-------|-------|-------|
| 111111001010 | 01111 | 000    | 01111 | 0010011|
```

### 10. Instruction: addi sp, sp, 16
- **Opcode:** `0010011` (7 bits)
- **Immediate:** `000000010000` (12 bits for 16)
- **Source Register (rs1):** `ap (x2)`: `00010` (5 bits)
- **Destination Register (rd):** `sp (x2)`: `00010` (5 bits)
- **Function (funct3):** `000` (3 bits)

**Breakdown:**
```
|imm[11:0]  | rs1   | funct3 | rd   | opcode|
|------------|--------|-------|-------|-------|
|000000010000 | 00010 | 000    | 00010 | 0010011|
```

### 11. Instruction: `addi a0, a0, 272`
- **Opcode:** `0010011` (7 bits)
- **Immediate:** `000100010000` (12 bits)
- **Source Register (rs1):** `a0 (x10)`: `01010` (5 bits)
- **Destination Register (rd):** `a0 (x10)`: `01010` (5 bits)
- **Function (funct3):** `000` (3 bits)

**Breakdown:**
```
|imm[11:0]  | rs1   | funct3 | rd   | opcode |
|-------------|------|--------|-------|----------|
|000100010000 | 01010 | 000    | 01010 | 0010011 |
```

### 12. Instruction: j 101ac <atexit> encoded as jal x0,101ac
- **Opcode:** `1101111` (7 bits)
- **Immediate:** `0x101ac`= 000000100000110101100(21 bits)
- **Destination Register (rd):** `x0`: `00000` (5 bits)

**Breakdown:**
```
|imm[20] | imm[10:1] | imm[11] | imm[19:12]  | rd   | opcode |
|---------|----------|---------|--------------|------|--------|
| 0       | 0001101011 | 0       | 00000010  | 00001 | 1101111 |
```

### 13. Instruction: `addi a0, a0, 368`
- **Opcode:** `0010011` (7 bits)
- **Immediate:** `000101110000` (12 bits for 368)
- **Source Register (rs1):** `a0 (x10)`: `01010` (5 bits)
- **Destination Register (rd):** `a0 (x10)`: `01010` (5 bits)
- **Function (funct3):** `000` (3 bits)

**Breakdown:**
```
|imm[11:0]  | rs1   | funct3 | rd   | opcode |
|------------|-------|---------|------|---------|
|000101110000 | 01010 | 000    | 01010 | 0010011  |
```

### 14. Instruction: `addi a2, a2, 264`
- **Opcode:** `0010011` (7 bits)
- **Immediate:** `000100001000` (12 bits for 264 )
- **Source Register (rs1):** `a2 (x12)`: `01100` (5 bits)
- **Destination Register (rd):** `a2 (x12)`: `01100` (5 bits)
-  **Function (funct3):** `000` (3 bits)

**Breakdown:**
```
| imm[11:0]   | rs1  |funct3| rd  | opcode  |
|-------------|------|-------|------|-----------|
 |000100001000| 01100 |000   | 01100| 1101111 |
```

### 15. Instruction: `addi a1, sp, 8`
- **Opcode:** `0010011` (7 bits)
- **Immediate:** `0000000001000` (12 bits for 8)
- **Source Register (rs2):** `a1 (x11)`: `01011` (5 bits)
- **Base Register (rs1):** `sp (x2)`: `00010` (5 bits)
- **Function (funct3):** `000` (3 bits)

**Breakdown:**
```
| imm[11:0]   | rs1  |funct3| rd  | opcode  |
|-------------|------|-------|------|-----------|
 |0000000001000| 00010 |000   | 01011| 0010011 |
