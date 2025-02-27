# Samsung RISC-V  
This program is based on the RISC-V  architecture and uses open-source tools to teach people about vlsi chip design and RISC-V. The instructor for this internship is Kunal Ghosh Sir.

# Basic Details
Name: PS Chandana

College: Sahyadri College of Engineering and Management

Email ID: chandana250404@gmail.com

LinkedIN Profile: PS Chandana




---

<details>
<summary> <b>Task 1:</b> Understanding C and RISC-V Compilation</summary> 
<br>

This task involves reviewing *C-based* and *RISC-V-based* lab videos to understand the differences in compiling C programs using *GCC* and *RISC-V GCC compilers*.</summary>

## *C Language-Based Lab*  

This section demonstrates how to compile a *C program* on a standard *GCC compiler* and execute it.

### *Steps to Compile and Run a C Program*
1. Open the terminal and navigate to the desired directory.
2. Create and edit a .c file using the following command:

        sh
       leafpad sum1ton.c

4. Compile and execute the program:

        sh
        gcc sum1ton.c
       ./a.out


Compilation and execution are now complete.

![2](Task1/sum1ton_gcc.png
)
![2](Task1/gcc_compile.png
)


RISC-V Based Lab

This section covers compiling a C program for the RISC-V architecture using the RISC-V GCC compiler.

Steps to Compile Using RISC-V GCC Compiler

1. Ensure the RISC-V GCC compiler is installed.


2. Verify the .c file content using:
   
         sh
         cat sum1ton.c


4. Compile the program with the -O1 optimization:

       sh
       riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c


6. Disassemble the object file to view its assembly code:

        sh
         riscv64-unknown-elf-objdump -d sum1ton.o


8. Minimize the assembly output for easier reading:

         sh
         riscv64-unknown-elf-objdump -d sum1ton.o | less


10. Extract the main function’s assembly code using:
  
         sh
         /main


11. Locate the main function in the assembly output.

   ![4](Task1/objdump_O1_mode.png
)


Compiling with -Ofast Optimization

1. Compile the program with aggressive optimization using -Ofast:

          sh
         riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
         

3. Disassemble the object file:

         sh
         riscv64-unknown-elf-objdump -d sum1ton.o
         

5. Minimize the assembly output:

          sh
         riscv64-unknown-elf-objdump -d sum1ton.o | less


7. Extract the main function:
 
         sh
         /main


8. Locate the main function in the assembly output.

 ![4](Task1/objdump_Ofast_mode.png
)


Explanation of Key Commands and Options

This concludes Task 1, demonstrating C and RISC-V compilation workflows.

</details>
---


---
<details>
<summary> <b>Task 2:</b> RISC-V SPIKE Simulation and Compiler Optimization </b>Task Overview</summary> 
<br>

This task involves compiling a **C program** using the **RISC-V GCC compiler**, simulating it in **SPIKE**, and comparing the performance of different optimization levels (`-O1` and `-Ofast`).  

The goal is to understand how **compiler optimizations** affect the **execution and instruction set** in the SPIKE RISC-V simulator.  


Steps to Complete the Task

### **1. Write a Simple C Program**  

The following program calculates the addition of two numbers:  

![Task 2 image]("Task%202/task2_c_program.png")



### **2. Compile Using RISC-V GCC**

#### **Compile with -O1 Optimization**  

Use the following command to compile the program with the **-O1** optimization flag:  
 
      sh
      riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o swift.o swift.c


#### **Disassemble Object Files to View Assembly Code**  

Generate Dump for **-O1** Optimization:  
  
      sh
      riscv64-unknown-elf-objdump -d swift.o

Minimize the assembly output using the following command:
  
      sh
      riscv64-unknown-elf-objdump -d swift.o | less

![O1_objdump](Task%202/task2_O1_objdump.png)


### **3. Run SPIKE Simulation**

Run a compiled **RISC-V program** on the SPIKE simulator in non-debug mode:  
 
      sh
      spike pk swift.o

Invoke the debug mode of the SPIKE RISC-V simulator:
 
      sh
      spike -d pk swift.o

![O1_objdump](Task%202/O1_objdump_optimization.png)


### **4. Compile with -Ofast Optimization**

Use the following command to compile the program with the **-Ofast** optimization flag:  
  
      sh
      riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o swift.o swift.c
      

#### **Disassemble Object Files to View Assembly Code**  

Generate Dump for **-Ofast** Optimization:  
  
      sh
      riscv64-unknown-elf-objdump -d swift.o

Minimize the assembly output using the following command:
   
      sh
      riscv64-unknown-elf-objdump -d swift.o | less

![Ofast_objdump](Task2/task2_Ofast_objdump.png)

### **5. Run SPIKE Simulation for -Ofast Optimization**

Run the **-Ofast binary** in SPIKE:  
  
      sh
      spike pk swift.o

Invoke the debug mode of the SPIKE RISC-V simulator:
  
      sh
      spike -d pk swift.o

![Ofast_objdump](Task%202/Ofast_objdump_optimization.png)

## **Observing Instructions in SPIKE (`spike -d pk swift.o`)**  

1. After loading, **SPIKE initializes** and displays the **Program Counter (PC)** and **Stack Pointer (SP)**.  

2. Press **Enter** repeatedly to step through the execution.  

3. Each press displays the **next instruction executed** by the program.  

4. The displayed instructions **directly correspond to the C code** of the main program, providing insights into the program's execution flow.


## **Explanation of Key Commands and Options**  

| Command | Description |
|---------|------------|
| `spike` | RISC-V simulator that runs RISC-V programs on a virtual machine. |
| `pk` | Proxy kernel that acts as a minimal runtime environment for RISC-V programs, handling system calls like I/O and memory management. |
| `swift.o` | The compiled RISC-V binary of your program (created using a RISC-V GCC compiler). |
| `-d` (debugging mode) | Debugging mode in SPIKE, allows stepping through the instructions and inspecting the program's behavior. |
| `riscv64-unknown-elf-gcc` | RISC-V GCC compiler used to compile the C program into a RISC-V object file (.o). |
| `-O1` | Basic optimizations for performance. |
| `-Ofast` | Aggressive optimizations for maximum speed. |
| `riscv64-unknown-elf-objdump` | Disassembles RISC-V binaries to examine assembly code. |

These tools together enable compiling, running, and debugging **RISC-V programs** on a simulated environment.
</details>
---


---
<details>
<summary><b>Task 3:</b> The goal is to analyze and categorize each of the provided instructions based on their type, whether it be R-type, I-type, or J-type, and then translate them into their respective 32-bit machine instruction codes. These instruction codes should be represented in the appropriate format, ensuring that each instruction is properly encoded according to the specific structure and opcode requirements of the given architecture. The result should provide a detailed mapping of the instructions to their corresponding binary code representations.</summary>
<br>

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


### 5. U-type Instruction
U-type (Upper Immediate) instructions load immediate data into the destination register.

#### Structure:

| Field Name | Size  | Description                            |
|------------|-------|----------------------------------------|
| Opcode     | 7 bits| Determines the instruction type        |
| rd         | 5 bits| Destination register                  |
| imm[31:12] | 20 bits| Upper immediate value                  |

![u type](https://github.com/user-attachments/assets/d5223eda-40fd-4418-8860-39f350330311)


### 6. J-type Instruction
J-type (Jump-type) instructions implement jump operations, often used for loops.

#### Structure:

| Field Name | Size  | Description                            |
|------------|-------|----------------------------------------|
| Opcode     | 7 bits| Determines the instruction type        |
| rd         | 5 bits| Destination register                  |
| imm[20|10:1|11|19:12] | 20 bits| Jump offset                        |

![j type](https://github.com/user-attachments/assets/f9841148-7b72-42c1-adea-3a9e2068d621)


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

</details>
---

---
<details>
<summary> <b>Task 4:</b>This task involves simulating the RISC-V Core using the provided Verilog netlist and testbench. You will set up a simulation environment using tools like Icarus Verilog and GTKWave, run the simulation to verify the functional correctness of the core, and analyze output signals. Waveform snapshots of the executed instructions must be captured and uploaded to your GitHub repository along with a brief description, demonstrating your understanding of RISC-V functional simulation and verification.</summary> 
<br>

## 2. BLOCK DIAGRAM OF RISC-V RV32I
![image](https://user-images.githubusercontent.com/110079631/181293948-beb8622c-7696-4b06-b6c9-eeab9b8ab9d3.png)

## 3. INSTRUCTION SET OF RISC-V RV32I
![image](https://user-images.githubusercontent.com/110079631/181298133-60269bc2-01da-4b5c-8b42-69057b8dc15c.png)

# RISC-V Core Functional Simulation 
## 4. FUNCTIONAL SIMULATION

### 4.1 About iverilog and gtkwave
- Icarus Verilog is an implementation of the Verilog hardware description language.
- GTKWave is a fully featured GTK+ v1. 2 based wave viewer for Unix and Win32 which reads Ver Structural Verilog Compiler generated AET files as well as standard Verilog VCD/EVCD files and allows their viewing.

### 4.2 Installing iverilog and gtkwave

- **For Ubuntu**

 Open your terminal and type the following to install iverilog and GTKWave
 ```
 $   sudo apt get update
 $   sudo apt get install iverilog gtkwave
 ```
 ![image](Task%204/installation_iverilog.png)
 ![image](Task%204/installation_gtkwave.png)

- **To clone the repository and download the netlist files for simulation , enter the following commands in your terminal.**

 ```
 $ git clone https://github.com/vinayrayapati/iiitb_rv32i
 $ cd iiitb_rv32i
 ```
- **To simulate and run the verilog code , enter the following commands in your terminal.**

```
$ iverilog -o iiitb_rv32i iiitb_rv32i.v iiitb_rv32i_tb.v
$ ./iiitb_rv32i
```
- **To see the output waveform in gtkwave, enter the following commands in your terminal.**

`$ gtkwave iiitb_rv32i.vcd`

### 4.3 The output waveform

 The output waveform showing the instructions performed in a 5-stage pipelined architecture.

## **Analyzing the Output Waveform of Various Instructions**

### **Instruction 1: `ADD R6, R2, R1`**  
![ADD](Task%204/add.png)

### **Instruction 2: `SUB R7, R1, R2`**  
![SUB](Task%204/sub.png)

### **Instruction 3: `AND R8, R1, R3`**  
![AND](Task%204/and.png)

### **Instruction 4: `OR R9, R2, R5`**  
![OR](Task%204/or.png)

### **Instruction 5: `XOR R10, R1, R4`**  
![XOR](Task%204/xor.png)

### **Instruction 6: `SLT R1, R2, R4`**  
![SLT](Task%204/slt.png)

### **Instruction 7: `ADDI R12, R4, 5`**  
![ADDI](Task%204/addi.png)


### **Full `gtkwave` Instruction**  
![Full gtkwave instruction](Task%204/full_gtkwave_instruction.png)  

</details>
---

---
<details>
<summary> <b>Task 5:</b> This task involves implementating a project using VSDsquadron Mini board. LED Fading with PWM. This project demonstrates a smooth LED fading effect using Pulse Width Modulation (PWM) on a VSDsquadron Mini Board.</summary>


## Components Required
| Component               | Quantity | Description                                        |
|-------------------------|----------|----------------------------------------------------|
| VSDsquadron Mini Board  | 1        | The core microcontroller used for LED control     |
| LEDs                    | 4        | Light-emitting diodes for visual output          |
| Resistors (330Ω)        | 4        | Used to limit current through the LEDs           |
| Connecting wires        | As needed| Used for establishing electrical connections      |
| Breadboard              | 1        | Platform for prototyping the circuit             |
| Power supply (3.3V/5V)  | 1        | Provides power to the microcontroller and LEDs   |

## Circuit Connections
| LED  | GPIO Pin | Connection Details |
|------|---------|-------------------|
| LED1 | PC3     | Connected via a 330Ω resistor |
| LED2 | PC4     | Connected via a 330Ω resistor |
| LED3 | PC5     | Connected via a 330Ω resistor |
| LED4 | PC6     | Connected via a 330Ω resistor |
| GND  | Common  | All LED grounds connected to microcontroller GND |


## Circuit Diagram
![image](Task%205/circuit_diagram.jpg)

## Working Mechanism
1. **PWM Control:**
   - The microcontroller modulates the brightness of each LED using **Pulse Width Modulation (PWM)**.
   - Each LED is assigned a varying duty cycle to create a fading effect.
2. **Wave Effect:**
   - The first LED starts at a dim level, with each subsequent LED increasing in brightness until the last one reaches full intensity.
   - The pattern then reverses, smoothly dimming the LEDs back down, creating a **wave-like flow**.
3. **Timing & Delay Adjustments:**
   - Delays are carefully adjusted to ensure a smooth transition without abrupt changes.
   - The fading effect repeats continuously, creating an eye-catching **dynamic lighting effect**.

</details>
---

---
<details>
<summary> <b>Task 6:</b>This project demonstrates a smooth LED fading effect using Pulse Width Modulation (PWM) on a VSDSquadron Mini board. Four LEDs, connected to GPIO pins PC3, PC4, PC5, and PC6, gradually transition in brightness, creating a visually appealing wave-like pattern. The microcontroller precisely controls the brightness using PWM, ensuring a seamless and smooth transition.</summary>

## Steps to Implement
### Hardware Implementation
1. *Microcontroller Setup:*
   - The *VSDSquadron Mini board* is programmed to control LED brightness using PWM.
   - GPIO pins *PC3, PC4, PC5, and PC6* are configured as output pins.
2. *LED Circuit:*
   - Each LED is connected in series with a *330Ω resistor* to limit the current.
   - The circuit is powered using a *3.3V/5V power supply*.
3. *Physical Assembly:*
   - Components are connected on a *breadboard* for easy prototyping.
   - Wires are used to establish electrical connections between the LEDs and microcontroller.

### Software Implementation
1. *PWM Control:*
   - The microcontroller modulates the brightness of each LED using *Pulse Width Modulation (PWM)*.
   - Each LED is assigned a varying duty cycle to create a fading effect.
2. *Wave Effect:*
   - The first LED starts at a dim level, with each subsequent LED increasing in brightness until the last one reaches full intensity.
   - The pattern then reverses, smoothly dimming the LEDs back down, creating a *wave-like flow*.
3. *Timing & Delay Adjustments:*
   - Delays are carefully adjusted to ensure a smooth transition without abrupt changes.
   - The fading effect repeats continuously, creating an eye-catching *dynamic lighting effect*.

## Expected Output
- LEDs will smoothly transition in brightness from dim to bright in a *wave-like* pattern.
- The wave effect will continuously repeat in both *forward and reverse order*.
- The smooth transition of brightness ensures a visually appealing effect without flickering.

## Code Implementation
- The project is implemented using *VS Code with PlatformIO*.
- The code initializes *PWM on GPIO pins PC3, PC4, PC5, and PC6*.
- A loop continuously updates PWM duty cycles to create a fading effect.
- Delay values are set to control the timing of brightness changes.
- The implementation ensures a seamless and efficient LED fading sequence.

      sh
      #include <ch32v00x.h>
      #include <debug.h>
      
      #define LED1_GPIO_PORT GPIOC
      #define LED2_GPIO_PORT GPIOC
      #define LED3_GPIO_PORT GPIOC
      #define LED4_GPIO_PORT GPIOC
      
      #define LED1_GPIO_PIN GPIO_Pin_3
      #define LED2_GPIO_PIN GPIO_Pin_4
      #define LED3_GPIO_PIN GPIO_Pin_5
      #define LED4_GPIO_PIN GPIO_Pin_6
      
      #define BLINKY_CLOCK_ENABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE)
      
      void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
      void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
      void Delay_Init(void);
      void Delay_Ms(uint32_t n);
      
      void Fade_LED(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
      {
          for (int i = 0; i < 10; i++)
          {
              GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_SET);
              Delay_Ms(i * 20);
              GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_RESET);
              Delay_Ms(200 - i * 20);
          }
          for (int i = 10; i > 0; i--)
          {
              GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_SET);
              Delay_Ms(i * 20);
              GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_RESET);
              Delay_Ms(200 - i * 20);
          }
      }
      
      int main(void)
      {
          NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
          SystemCoreClockUpdate();
          Delay_Init();
      
          GPIO_InitTypeDef GPIO_InitStructure = {0};
          BLINKY_CLOCK_ENABLE;
          GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN | LED2_GPIO_PIN | LED3_GPIO_PIN | LED4_GPIO_PIN;
          GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
          GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
          GPIO_Init(GPIOC, &GPIO_InitStructure);
      
          while (1)
          {
              // Forward fading sequence
              Fade_LED(LED1_GPIO_PORT, LED1_GPIO_PIN);
              Fade_LED(LED2_GPIO_PORT, LED2_GPIO_PIN);
              Fade_LED(LED3_GPIO_PORT, LED3_GPIO_PIN);
              Fade_LED(LED4_GPIO_PORT, LED4_GPIO_PIN);
      
              // Reverse fading sequence
              Fade_LED(LED4_GPIO_PORT, LED4_GPIO_PIN);
              Fade_LED(LED3_GPIO_PORT, LED3_GPIO_PIN);
              Fade_LED(LED2_GPIO_PORT, LED2_GPIO_PIN);
              Fade_LED(LED1_GPIO_PORT, LED1_GPIO_PIN);
          }
      }
      
      void NMI_Handler(void) {}
      void HardFault_Handler(void)
      {
          while (1)
          {
          }
      }
      
          

## Applications
- LED lighting effects and animations.
- Visual indicators for embedded systems.
- Smooth transition effects in smart lighting solutions.
- Learning platform for PWM-based brightness control.

## Conclusion
This project effectively demonstrates the *use of PWM for LED brightness control* in embedded systems. The smooth transitions between brightness levels showcase precise *timing and duty cycle adjustments, creating an appealing **wave-like LED animation*. The implementation can be further extended for advanced LED control applications, making it a useful foundation for larger embedded projects.
</details>
---
