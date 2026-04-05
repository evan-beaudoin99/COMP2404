# COMP 2404 — Assignment 1

## Assignment overview

This project implements a **home-share / short-term rental** model in C++. Core types include **Date**, **Category**, **Reservation**, **Rental**, and **HomeShare**, which manages collections of rentals and reservations. The program is driven from **`main.cc`**, which presents a menu of unit and integration tests (via **Tester** and local test helpers) that exercise printing, add/remove behaviour, and aggregation through **HomeShare**.

## Author and course information

| Field | Value |
|--------|--------|
| **Author** | Evan Beaudoin |
| **Student number** | 101340118 |
| **Date** | April 5, 2026 |
| **Course** | COMP 2404 — Introduction to Software Engineering |
| **Institution** | Carleton University |
| **Instructor** | Darryl Hill |

## Project directory

All paths below are relative to the `assignment1` folder (where the `Makefile` lives).

```
assignment1/
├── Category.cc
├── Category.h
├── Date.cc
├── Date.h
├── defs.h
├── HomeShare.cc
├── HomeShare.h
├── main.cc
├── Makefile
├── README.md
├── Rental.cc
├── Rental.h
├── Reservation.cc
├── Reservation.h
├── Tester.cc
└── Tester.h
```

## How to build and run

You need **g++** and **make** (for example on Linux, macOS, or **WSL** on Windows).

### Build

1. Open a terminal and change into the project directory:

   ```bash
   cd path/to/assignment1
   ```

2. Build the program:

   ```bash
   make
   ```

   This produces **`a1`**, which includes the interactive test menu (there is no separate test executable target in the `Makefile`).

### Run

```bash
./a1
```

Choose menu options to run individual tests or the full suite.

### Clean build artifacts

```bash
make clean
```

Removes `a1` and `*.o` in the current directory.

## Notes

**`<stdexcept>`:** Out-of-bounds cases in **Rental** and **Reservation** constructors are reported using the standard library’s `<stdexcept>`. This was discussed with the instructor and approved; the autograder does not focus on those edge cases.
