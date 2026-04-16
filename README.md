# CS211 Projects

This repository contains coursework and lab work for CS211.  
Each folder corresponds to a different assignment or lab.

## Repository Structure

### `Bomblab/`
Bomb Lab reverse-engineering work.

- `bomb222/README` - identifies the assigned bomb instance and owner.
- `bomb222/bomb.c` - bomb driver source showing argument handling and phase execution flow.
- `bomb222/mysolution.txt` - solved inputs for phases in this bomb.

### `Homework0/`
Starter/testing material for early file and I/O practice.

- `testarino/examples.txt` - expected character/word/line counts for edge-case input examples.
- `testarino/sicboi.c` - helper utility that writes test text to a file (used to generate quick test files).
- `testarino/EG0` ... `testarino/EG8` - example input files used for testing.

### `Homework1/`
Logic-gate and adder implementation in C.

- `nandAdder.c` - implements `nand`, `not`, `and`, `or`, `xor`, a half-adder, and a full-adder.
  - Includes:
    - Diagnostic mode: `./nandAdder -d A B`
    - Compute mode: `./nandAdder A B Cin`

### `Homework2/`
Word-count style assignment using low-level file I/O.

- `wordcount.c` - reads a file and reports line, word, and character counts.
- `test.txt` - sample test input (currently empty).
- `stuff.txt` - sample multi-line input for testing.

## Build and Run (Quick Reference)

From the repository root:

```bash
gcc Homework1/nandAdder.c -o Homework1/nandAdder
gcc Homework2/wordcount.c -o Homework2/wordcount
```

Run examples:

```bash
./Homework1/nandAdder 1 0 1
./Homework1/nandAdder -d 1 0
./Homework2/wordcount Homework2/stuff.txt
```

## Notes

- Most assignments are written in C and tested from the terminal.
- Some folders may also include generated binaries or temporary test artifacts.
- This was the last class the professor taught before leaving so some assignments are not in this repository as the course has been deleted on Canvas.
