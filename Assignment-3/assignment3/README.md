# COMP 2404 — Assignment 3

## Assignment overview

This project simulates a **lab ecosystem** in C++. **Entity** subtypes such as **LabTech** and **Patient** interact with **Lab**, **LabWork**, and a **LabWorkList**. A **Control** class orchestrates the simulation with a **View** for user interaction. A separate test program (**`a3test`**, built from `test.cc` with **TestControl** and **Tester**) exercises the model alongside the main interactive app (**`a3`**). Design documentation lives under **`design/`** as a draw.io UML file.

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

All paths below are relative to the `assignment3` folder (where the `Makefile` lives).

```
assignment3/
├── Control.cc
├── Control.h
├── design/
│   └── uml.drawio
├── Entity.cc
├── Entity.h
├── Lab.cc
├── Lab.h
├── LabTech.cc
├── LabTech.h
├── LabWork.cc
├── LabWork.h
├── LabWorkList.cc
├── LabWorkList.h
├── main.cc
├── Makefile
├── Patient.cc
├── Patient.h
├── README.md
├── test.cc
├── TestControl.cc
├── TestControl.h
├── Tester.cc
├── Tester.h
├── View.cc
├── View.h
└── .vscode/
    └── c_cpp_properties.json
```

## How to build and run

You need **g++** and **make** (for example on Linux, macOS, or **WSL** on Windows).

### Build

1. Open a terminal and change into the project directory:

   ```bash
   cd path/to/assignment3
   ```

2. Build both the main program and the test executable:

   ```bash
   make
   ```

   This produces:

   - **`a3`** — main interactive application  
   - **`a3test`** — test menu / automated checks  

   To build only the main program you can run `make a3`; for only tests, `make a3test`.

### Run the main program

```bash
./a3
```

Follow the on-screen menu to run the lab simulation.

### Run the test harness

```bash
./a3test
```

Choose options from the menu to run individual tests or the full suite.

### Clean build artifacts

```bash
make clean
```

Removes `a3`, `a3test`, and `*.o` in the current directory.
