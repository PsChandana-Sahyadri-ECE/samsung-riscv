# Samsung RISC-V  
This program is based on the RISC-V  architecture and uses open-source tools to teach people about vlsi chip design and RISC-V. The instructor for this internship is Kunal Ghosh Sir.

# Basic Details
Name: PS Chandana

College: Sahyadri College of Engineering and Management

Email ID: chandana250404@gmail.com

GitHub Profile: PsChandana-Sahyadri-ECE

LinkedIN Profile: PS Chandana




---

<details>
<summary> <b>Task 1:</b> The task involves  reviewing the C based lab video and the RISC-V architecture based lab video to gain a comprehensive understanding of both topics.Then the C code is compiled using two different compilers: the GCC compiler and the RISC-V compiler.</summary> 
<br>
Task is to refer to C based and RISCV based lab videos and execute the task of compiling the C code using gcc and riscv compiler.

**C Language based LAB**

**C and RISC-V Based Labs**

This repository demonstrates the processes involved in compiling C programs and generating assembly code using both a standard GCC compiler and a RISC-V GCC compiler. It includes comprehensive steps and explanations to guide users through each stage of the compilation and debugging workflow.

**C Language-Based Lab**

Steps to Compile a .c File on Your Machine:

1. Open the bash terminal and navigate to the directory where you want to create your file.
2. Use the following command to create and edit a new .c file:
   ```sh
   leafpad sum1ton.c


**Steps to Compile a .c File on our Machine:**
 ```sh
 gcc sum1ton.c
 ./a.out
```

 
Compilation and execution complete.
 
![2](Task1/sum1ton_gcc.png
)
![2](Task1/gcc_compile.png
)

RISC-V Based Lab

**Steps to Compile Using RISC-V GCC Compiler:**
1. Ensure the RISC-V GCC compiler is installed and accessible on your system.
2. Verify the .c file contents using the cat command:
   ```sh
   cat sum1ton.c


3. Compile the C program for RISC-V architecture using 01 option:
 ```sh
riscv64-unknown-elf-gcc -o1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
```
4. Disassemble the object file to view its assembly code using:
 ```sh
riscv64-unknown-elf-objdump -d sum1ton.o
```
5.minimize the assembly by using following code:
```sh
riscv64-unknown-elf-objdump -d sum1ton.o | less
```
 a)we extract main function's assembly code by using:
   ```sh
/main
```
6. Use /main in the terminal to locate the main function in the assembly output.
![4](Task1/objdump_O1_mode.png
)

7.Compile the C program for RISC-V architecture using ofast option:
```sh
riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
```
8.Disassemble the object file to view its assembly code using:
```sh
riscv64-unknown-elf-objdump -d sum1ton.o
```
9.minimize the assembly by using following code:
```sh
riscv64-unknown-elf-objdump -d sum1ton.o | less
```
 a)we extract main function's assembly code by using:
 ```sh
  /main
```
10. Use /main in the terminal to locate the main function in the assembly output.
![4](Task1/objdump_Ofast_mode.png)
)

Explanation of Key Commands and Options: 
1. -mabi=lp64: Specifies the Application Binary Interface (ABI) for 64-bit integers, pointers, and long data types, suitable for 64-bit RISC-V architecture.

2. -march=rv64i: Indicates the 64-bit RISC-V base integer instruction set architecture.

3. -O1: Enables basic optimization for better performance without significantly increasing compilation time.

4. -Ofast: Optimize the code aggressively for the best possible speed.

5. riscv64-unknown-elf-objdump: A tool for disassembling RISC-V binaries to examine the code structure and debug it effectively.
 
   </details>

---

<details>
<summary> <b>Task 2:</b> The task involves reviewing both C-based and RISC-V-based lab videos to understand the nuances of compiling C code for different architectures. Afterward, you are required to execute the process of compiling the C code using two distinct tools: the GCC compiler and the RISC-V compiler simulator. This will allow you to demonstrate your ability to work with both compilers, providing insights into how the C code is processed and converted into machine-readable code for each specific architecture.</summary> 
<br>

Task is to analyze the SPIKE simulation performance using RISC-V GCC with -O1 and -Ofast optimization levels.  

*SPIKE Simulation and Compiler Optimization*

This repository demonstrates how to compile a C program using RISC-V GCC, simulate it using SPIKE, and compare the performance of different optimization levels (-O1 and -Ofast). It includes detailed steps and explanations to ensure clarity.  

**Steps to Complete the Task**  

1.Write a Simple C Program  

2.The following program calculates the addition of two numbers: 

3.Compile Using RISC-V GCC

4.Compile with -O1 Optimization.

*Use the following command to compile the program with the -O1 optimization flag:*
```sh
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o swift.o swift.c
```
**Disassemble Object Files to View Assembly Code(in new terminal)**
*Generate Dump for -O1 Optimization*
```sh
riscv64-unknown-elf-objdump -d swift.o
```
*Minimize the assembly by using following code:*
```sh
riscv64-unknown-elf-objdump -d swift.o | less
```
![main program for O1 option](Task 2/task2_c_program.png)


**Run SPIKE Simulation**
*Run a compiled RISC-V program on the SPIKE simulator in non-debug mode.*
```sh
spike pk swift.o
```
*Invoke the debug mode of the SPIKE RISC-V simulator.*
```sh
spike -d pk swift.o
```
![compiling with O1 option](Task 2/task2_O1_objdump.png)


**Compile with -Ofast Optimization.**
*Use the following command to compile the program with the -Ofast optimization flag:*
```sh
riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o swift.o swift.c
```
**Disassemble Object Files to View Assembly Code(in new terminal)**
*Generate Dump for -Ofast Optimization*
```sh
riscv64-unknown-elf-objdump -d swift.o
```
*Minimize the assembly by using following code:*
```sh
riscv64-unknown-elf-objdump -d swift.o | less
```
![main program for ofast option](Task 2/Ofast_objdump_optimization.png)


**Run SPIKE Simulation**
*Run -O1 Binary in SPIKE*
```sh
spike pk swift.o
```
*Invoke the debug mode of the SPIKE RISC-V simulator*
```sh
spike -d pk swift.o
```
![compiling with Ofast option]Task 2/task2_Ofast_objdump.png)


**After(spike -d pk swift.o) Observe the Instructions:**

1)After loading, SPIKE initializes and displays the Program Counter (PC) and Stack Pointer (SP).

2)Press Enter repeatedly to step through the execution.

3)Each press displays the next instruction executed by the program.

4)The displayed instructions directly correspond to the C code of the main program, providing insights into the program's execution flow.
**Explanation of Key Commands and Options:**

1. spike:RISC-V simulator that runs RISC-V programs on a virtual machine.

2. pk:Proxy kernel that acts as a minimal runtime environment for RISC-V programs, handling system calls like I/O and memory management.

3. swift.o:The compiled RISC-V binary of your program (created using a RISC-V GCC compiler).

4. -d (for debugging):Debugging mode in SPIKE, allows stepping through the instructions and inspecting the program's behavior.

5. riscv64-unknown-elf-gcc:RISC-V GCC compiler used to compile the C program into a RISC-V object file (.o).

6. -O1, -Ofast:Compiler optimization flags:
      a.-O1: Basic optimizations for performance.
      b.-Ofast: Aggressive optimizations for maximum speed.

7. riscv64-unknown-elf-objdump:Disassembles RISC-V binaries to examine assembly code.

These tools together enable compiling, running, and debugging RISC-V programs on a simulated environment.

</details>

---

---
<details>
<summary><b>Task 3:</b> The goal is to analyze and categorize each of the provided instructions based on their type, whether it be R-type, I-type, or J-type, and then translate them into their respective 32-bit machine instruction codes. These instruction codes should be represented in the appropriate format, ensuring that each instruction is properly encoded according to the specific structure and opcode requirements of the given architecture. The result should provide a detailed mapping of the instructions to their corresponding binary code representations.</summary>

# Understanding RISC-V and Its Instruction Formats

## What is RISC-V?
RISC-V is an open-source Instruction Set Architecture (ISA) that enables developers to design processors tailored to specific applications. Based on Reduced Instruction Set Computer (RISC) principles, RISC-V represents the fifth generation of processors built on this concept. Its open and free nature means developers can utilize RISC-V without purchasing licenses, making it a compelling alternative to proprietary processor technologies.

## Instruction Formats in RISC-V
The instruction format of a processor defines how machine language instructions are structured for execution. These instructions are composed of binary data (0s and 1s), each segment providing details about data location and operations to be performed. In RISC-V, there are six primary instruction formats:

1. **R-format**
2. **I-format**
3. **S-format**
4. **B-format**
5. **U-format**
6. **J-format**
<img width="772" alt="instructions_types" src="https://github.com/user-attachments/assets/7ca6b3ea-bd59-4419-8410-1e14e40e911e" />


---

### 1. R-type Instruction
R-type (Register-type) instructions operate on registers rather than memory locations. These are used for arithmetic and logical operations. Each instruction is 32 bits and divided into six fields:

#### Structure:

| Field Name | Size  | Description                            |
|------------|-------|----------------------------------------|
| Opcode     | 7 bits| Determines the instruction type        |
| rd         | 5 bits| Destination register                  |
| func3      | 3 bits| Specifies the type of operation       |
| rs1        | 5 bits| First source register                 |
| rs2        | 5 bits| Second source register                |
| func7      | 7 bits| Additional operation specification    |

#### Example: ADD r9, r2, r5
- **Operation:** Adds values in registers r2 and r5, storing the result in r9.
- **Field Breakdown:**

  - Opcode: `0110011`
  - rd (Destination): `r9` -> `01001`
  - rs1 (Source 1): `r2` -> `00010`
  - rs2 (Source 2): `r5` -> `00101`
  - func3: `000`
  - func7: `0000000`
- **32-bit Instruction:** `0000000_00101_00010_000_01001_0110011`


#### Example: XOR r10, r1, r4
- **Operation:** XOR operation between r1 and r4, result in r10.
- **Field Breakdown:**

  - Opcode: `0110011`
  - rd (Destination): `r10` -> `01010`
  - rs1 (Source 1): `r1` -> `00001`
  - rs2 (Source 2): `r4` -> `00100`
  - func3: `100`
  - func7: `0000000`
- **32-bit Instruction:** `0000000_00100_00001_100_01010_0110011`


#### Example: SLT r11, r2, r4
- **Operation:** Sets r11 to 1 if r2 < r4; otherwise, sets r11 to 0.
- **Field Breakdown:**

  - Opcode: `0110011`
  - rd (Destination): `r11` -> `01011`
  - rs1 (Source 1): `r2` -> `00010`
  - rs2 (Source 2): `r4` -> `00100`
  - func3: `010`
  - func7: `0000000`
- **32-bit Instruction:** `0000000_00100_00010_010_01011_0110011`

![r type](https://github.com/user-attachments/assets/33357c39-806e-4d2f-9158-cd204120dcd8)


---

### 2. I-type Instruction
I-type (Immediate-type) instructions use a register and an immediate (constant) value. These are typically used for load and immediate operations.

#### Structure:

| Field Name | Size  | Description                            |
|------------|-------|----------------------------------------|
| Opcode     | 7 bits| Determines the instruction type        |
| rd         | 5 bits| Destination register                  |
| func3      | 3 bits| Specifies the type of operation       |
| rs1        | 5 bits| Source register                       |
| imm[11:0]  | 12 bits| Immediate value                      |

#### Example: ADDI r12, r4, 5
- **Operation:** Adds immediate value 5 to the value in r4 and stores it in r12.
- **Field Breakdown:**
  - Opcode: `0010011`
  - rd (Destination): `r12` -> `01100`
  - rs1 (Source): `r4` -> `00100`
  - imm[11:0] (Immediate): `000000000101`
  - func3: `000`
- **32-bit Instruction:** `000000000101_00100_000_01100_0010011`

![i type](https://github.com/user-attachments/assets/76a06842-0672-46d8-b50e-c538c6f63c99)


---

### 3. S-type Instruction
S-type (Store-type) instructions store register values into memory locations.

#### Structure:

| Field Name | Size  | Description                            |
|------------|-------|----------------------------------------|
| Opcode     | 7 bits| Determines the instruction type        |
| rs1        | 5 bits| Base address register                 |
| rs2        | 5 bits| Source register                       |
| imm[11:5]  | 7 bits| Upper immediate value                  |
| imm[4:0]   | 5 bits| Lower immediate value                  |
| func3      | 3 bits| Specifies the type of operation       |

#### Example: SW r3, 2(r1)
- **Operation:** Stores the value in r3 into the memory at the address `r1 + 2`.
- **Field Breakdown:**
  - Opcode: `0100011`
  - rs1 (Base Address): `r1` -> `00001`
  - rs2 (Source): `r3` -> `00011`
  - imm[11:5] (Upper Immediate): `0000000`
  - imm[4:0] (Lower Immediate): `00010`
  - func3: `010`
- **32-bit Instruction:** `0000000_00011_00001_010_00010_0100011`

![s type](https://github.com/user-attachments/assets/a6210bc8-77c1-424d-a6e0-ada39b5189da)


---

### 4. B-type Instruction
B-type (Branch-type) instructions handle branching based on conditions.

#### Structure:

| Field Name | Size  | Description                            |
|------------|-------|----------------------------------------|
| Opcode     | 7 bits| Determines the instruction type        |
| rs1        | 5 bits| Source register 1                      |
| rs2        | 5 bits| Source register 2                      |
| imm[12|10:5|4:1|11] | 13 bits| Branch offset                      |
| func3      | 3 bits| Specifies the condition for branching |

#### Example: BNE r0, r1, 20
- **Operation:** Branches to the address `PC + 20` if r0 is not equal to r1.
- **Field Breakdown:**
  - Opcode: `1100011`
  - rs1: `r0` -> `00000`
  - rs2: `r1` -> `00001`
  - imm[12|10:5|4:1|11]: `0000010100`
  - func3: `001`
- **32-bit Instruction:** `0000000_00001_00000_001_10100_1100011`

#### Example: BEQ r0, r0, 15
- **Operation:** Branches to the address `PC + 15` if r0 equals r0 (always true).
- **Field Breakdown:**
  - Opcode: `1100011`
  - rs1: `r0` -> `00000`
  - rs2: `r0` -> `00000`
  - imm[12|10:5|4:1|11]: `000001111`
  - func3: `000`
- **32-bit Instruction:** `0000000_00000_00000_000_01111_1100011`

![b type](https://github.com/user-attachments/assets/31c67705-07f0-4d1d-86e0-2c0d8e3e2e78)

---

### 5. U-type Instruction
U-type (Upper Immediate) instructions load immediate data into the destination register.

#### Structure:

| Field Name | Size  | Description                            |
|------------|-------|----------------------------------------|
| Opcode     | 7 bits| Determines the instruction type        |
| rd         | 5 bits| Destination register                  |
| imm[31:12] | 20 bits| Upper immediate value                  |

![u type](https://github.com/user-attachments/assets/d5223eda-40fd-4418-8860-39f350330311)


---

### 6. J-type Instruction
J-type (Jump-type) instructions implement jump operations, often used for loops.

#### Structure:

| Field Name | Size  | Description                            |
|------------|-------|----------------------------------------|
| Opcode     | 7 bits| Determines the instruction type        |
| rd         | 5 bits| Destination register                  |
| imm[20|10:1|11|19:12] | 20 bits| Jump offset                        |

![j type](https://github.com/user-attachments/assets/f9841148-7b72-42c1-adea-3a9e2068d621)


---
# RISC-V Instruction Breakdown

## 1. Instruction: `lui a0, 0x21`
- **Opcode**: `0110111` (7 bits)
- **Immediate (upper 20 bits of 0x21 shifted left by 12)**: `00000000000000000010` (20 bits)
- **Destination Register (rd)**: `a0 (x10)`: `01010` (5 bits)

| imm[31:12]         | rd   | opcode  |
|--------------------|------|---------|
| 00000000000000000010 | 01010 | 0110111 |

## 2. Instruction: `addi sp, sp, -16`
- **Opcode**: `0010011` (7 bits)
- **Immediate**: `1111111111110000` (12 bits)
- **Source Register (rs1)**: `sp (x2)`: `00010` (5 bits)
- **Destination Register (rd)**: `sp (x2)`: `00010` (5 bits)
- **Function (funct3)**: `000` (3 bits)

| imm[11:0]  | rs1   | funct3 | rd   | opcode  |
|------------|-------|--------|------|---------|
| 111111111111 | 00010 | 000    | 00010 | 0010011 |

## 3. Instruction: `li a1, 20`
- **Opcode**: `0010011` (7 bits)
- **Immediate**: `00000000010100` (12 bits)
- **Source Register (rs1)**: `zero (x0)`: `00000` (5 bits)
- **Destination Register (rd)**: `a1 (x11)`: `01011` (5 bits)
- **Function (funct3)**: `000` (3 bits)

| imm[11:0]     | rs1   | funct3 | rd   | opcode  |
|---------------|-------|--------|------|---------|
| 00000000010100 | 00000 | 000    | 01011 | 0010011 |

## 4. Instruction: `jal ra, 10404 <printf>`
- **Opcode**: `1101111` (7 bits)
- **Immediate**: `10404 (0x28B4)` (21 bits)
- **Destination Register (rd)**: `ra (x1)`: `00001` (5 bits)

| imm[20] | imm[10:1] | imm[11] | imm[19:12]  | rd   | opcode |
|---------|-----------|---------|-------------|------|--------|
| 0       | 0101101010 | 1       | 00000000    | 00001 | 1101111 |

## 5. Instruction: `sd ra, 8(sp)`
- **Opcode**: `0100011` (7 bits)
- **Immediate**: `0000000001000` (12 bits, split into two parts)
- **Source Register (rs2)**: `ra (x1)`: `00001` (5 bits)
- **Base Register (rs1)**: `sp (x2)`: `00010` (5 bits)
- **Function (funct3)**: `011` (3 bits)

| imm[11:5] | rs2   | rs1   | funct3 | imm[4:0] | opcode |
|-----------|-------|-------|--------|----------|--------|
| 0000000   | 00001 | 00010 | 011    | 01000    | 0100011 |

## 6. Instruction: `ld ra, 8(sp)`
- **Opcode**: `0000011` (7 bits)
- **Immediate**: `0000000001000` (12 bits)
- **Source Register (rs1)**: `sp (x2)`: `00010` (5 bits)
- **Destination Register (rd)**: `ra (x1)`: `00001` (5 bits)
- **Function (funct3)**: `011` (3 bits)

| imm[11:0]   | rs1   | funct3 | rd   | opcode  |
|-------------|-------|--------|------|---------|
| 0000000001000 | 00010 | 011    | 00001 | 0000011 |

## 7. Instruction: `jalr zero, ra, 0 (ret)`
- **Opcode**: `1100111` (7 bits)
- **Immediate**: `000000000000` (12 bits)
- **Source Register (rs1)**: `ra (x1)`: `00001` (5 bits)
- **Destination Register (rd)**: `zero (x0)`: `00000` (5 bits)
- **Function (funct3)**: `000` (3 bits)

| imm[11:0]   | rs1   | funct3 | rd   | opcode  |
|-------------|-------|--------|------|---------|
| 000000000000 | 00001 | 000    | 00000 | 1100111 |

## 8. Instruction: `auipc a5, 0xffff0`
- **Opcode**: `0010111` (7 bits)
- **Immediate**: `0xffff0` (20 bits)
- **Destination Register (rd)**: `a5 (x15)`: `01111` (5 bits)

| imm[31:12]  | rd   | opcode |
|-------------|------|--------|
| 0xffff0     | 01111 | 0010111 |

## 9. Instruction: `addi a5, a5, -216`
- **Opcode**: `0010011` (7 bits)
- **Immediate**: `11111100101000` (12 bits in 2's complement for -216)
- **Source Register 1 (rs1)**: `a5 (x15)`: `01111` (5 bits)
- **Destination Register (rd)**: `a5 (x15)`: `01111` (5 bits)
- **Function (funct3)**: `000` (3 bits)

| imm[11:0]    | rs1   | funct3 | rd   | opcode  |
|--------------|-------|--------|------|---------|
| 111111001010 | 01111 | 000    | 01111 | 0010011 |

## 10. Instruction: `addi sp, sp, 16`
- **Opcode**: `0010011` (7 bits)
- **Immediate**: `000000010000` (12 bits for 16)
- **Source Register (rs1)**: `sp (x2)`: `00010` (5 bits)
- **Destination Register (rd)**: `sp (x2)`: `00010` (5 bits)
- **Function (funct3)**: `000` (3 bits)

| imm[11:0]  | rs1   | funct3 | rd   | opcode  |
|------------|-------|--------|------|---------|
| 000000010000 | 00010 | 000    | 00010 | 0010011 |

## 11. Instruction: `addi a0, a0, 272`
- **Opcode**: `0010011` (7 bits)
- **Immediate**: `000100010000` (12 bits for 272)
- **Source Register (rs1)**: `a0 (x10)`: `01010` (5 bits)
- **Destination Register (rd)**: `a0 (x10)`: `01010` (5 bits)
- **Function (funct3)**: `000` (3 bits)

| imm[11:0]   | rs1   | funct3 | rd   | opcode  |
|-------------|-------|--------|------|---------|
| 000100010000 | 01010 | 000    | 01010 | 0010011 |

## 12. Instruction: `j 101ac <atexit>` (encoded as `jal x0, 101ac`)
- **Opcode**: `1101111` (7 bits)
- **Immediate**: `0x101ac` (21 bits)
- **Destination Register (rd)**: `x0`: `00000` (5 bits)

| imm[20] | imm[10:1] | imm[11] | imm[19:12]  | rd   | opcode  |
|---------|-----------|---------|-------------|------|---------|
| 0       | 0001101011 | 0       | 00000010    | 00001 | 1101111 |

## 13. Instruction: `addi a0, a0, 368`
- **Opcode**: `0010011` (7 bits)
- **Immediate**: `000101110000` (12 bits for 368)
- **Source Register (rs1)**: `a0 (x10)`: `01010` (5 bits)
- **Destination Register (rd)**: `a0 (x10)`: `01010` (5 bits)
- **Function (funct3)**: `000` (3 bits)

| imm[11:0]   | rs1   | funct3 | rd   | opcode  |
|-------------|-------|--------|------|---------|
|000101110000 | 01010 | 000    | 01010 | 0010011 |

## 14. Instruction: `addi a2, a2, 264`
- **Opcode**: `0010011` (7 bits)
- **Immediate**: `000100001000` (12 bits for 264)
- **Source Register (rs1)**: `a2 (x12)` : `01100` (5 bits)
- **Destination Register (rd)**: `a2 (x12)` : `01100` (5 bits)
- **Function (funct3)**: `000` (3 bits)

| imm[11:0]	 | rs1	| funct3 |	rd	   | opcode  |
|------------|------|--------|------|---------|
|000100001000|01100 |	000	   |01100	|0010011  |

## 15. Instruction: `addi a1, sp, 8`
- **Opcode**: `0010011` (7 bits)
- **Immediate**: `0000000001000` (12 bits for 8)
- **Source Register (rs1)**: `sp (x2)` : `00010` (5 bits)
- **Destination Register (rd)**: `a1 (x11)` -> `01011` (5 bits)
- **Function (funct3)**: `000` (3 bits)

| imm[11:0]	  | rs1 	|funct3	|rd	   | opcode  |
|-------------|------|-------|------|---------|
|0000000001000	|00010	|  000	|01011 |0010011  |

This repository contains a list of 15 unique RISC-V instructions extracted from the assembly code along with their corresponding 32-bit instruction codes. These instructions cover different instruction formats, such as **U-type**, **I-type**, **J-type**, **B-type**, and **R-type**.


