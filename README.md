# LEGv8 Heapsort Implementation

This project implements the **Heapsort algorithm** in LEGv8 assembly language for use with the custom LEGv8 emulator provided by Iowa State University.

This assignment was completed as part of **CS 321: Computer Architecture and Machine-Level Programming**.

---

## Overview

The program sorts an array of integers using the Heapsort algorithm. Due to the low-level nature of LEGv8 assembly, the implementation is broken into multiple modular procedures to manage complexity and maintain adherence to **ARMv8 calling conventions**.

This project is a **manual translation of a C-based Heapsort implementation** into **LEGv8 assembly language**, simulating the work of a **compiler backend engineer**. It faithfully reproduces the behavior of the original C source code, procedure-by-procedure, while adhering to the **ARMv8 calling conventions** and using a custom **LEGv8 emulator**.

> This project demonstrates how high-level logic (loops, function calls, pointer arithmetic, and recursion-like behavior) is realized at the machine level.

---

## Project Goal

To implement and test a fully functioning version of **Heapsort** in LEGv8 assembly, equivalent in logic and behavior to the following C codebase:

```c
void fill(uint64_t *a, uint64_t s);
void swap(uint64_t *a, uint64_t *b);
void percolate_down(uint64_t *a, uint64_t s, uint64_t i);
void heapify(uint64_t *a, uint64_t s);
void heapsort(uint64_t *a, uint64_t s);
```

## File Structure

- `legv8emul`: The custom LEGv8 emulator provided by course staff. Executes LEGv8 assembly programs on Linux systems, no compilation required.
- `heapsort.c`: The original C implementation of the Heapsort algorithm. Served as the high-level source code that was manually translated into LEGv8.
- `heapsort.legv8asm`: The hand-written LEGv8 assembly implementation of `heapsort.c`, simulating what a compiler would generate at the assembly level.

## How to Run

You can execute the assembly program using the LEGv8 emulator provided. The emulator is a statically-linked binary and works on any Linux-compatible environment, including WSL (Windows Subsystem for Linux).

Open a terminal and run the following command:

```bash
./legv8emul heapsort.legv8asm
```
## Sample Memory Dump Output

Below is an example of what the **LEGv8 emulator's memory dump** looks like after executing the program with an array size of `10`.

Output of `DUMP` After a call to `fill`:

- `fill` initializes the array and fills it with even numbers descending to `0` then odd numbers increasing

```
Main Memory:
00000000  00 00 00 00 00 00 00 08  00 00 00 00 00 00 00 06  |................|
00000010  00 00 00 00 00 00 00 04  00 00 00 00 00 00 00 02  |................|
00000020  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 01  |................|
00000030  00 00 00 00 00 00 00 03  00 00 00 00 00 00 00 05  |................|
00000040  00 00 00 00 00 00 00 07  00 00 00 00 00 00 00 09  |................|
```
Output of `DUMP` After a call to `heapsort`:

- `heapsort` then sorts the array in an equivalent algorithm to the provided c code

```
Main Memory:
00000000  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 01  |................|
00000010  00 00 00 00 00 00 00 02  00 00 00 00 00 00 00 03  |................|
00000020  00 00 00 00 00 00 00 04  00 00 00 00 00 00 00 05  |................|
00000030  00 00 00 00 00 00 00 06  00 00 00 00 00 00 00 07  |................|
00000040  00 00 00 00 00 00 00 08  00 00 00 00 00 00 00 09  |................|
```








