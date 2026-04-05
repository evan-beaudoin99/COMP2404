# COMP 2404 — Assignment 2

## Assignment overview

This project implements a **project and asset management** application in C++. **ProjectManager** coordinates **Project** and **Asset** objects stored in array-backed collections (**ProjectArray**, **AssetArray**) and an **AssetStore**. A **Control** class drives the interactive flow with a **View** for menus and I/O. A separate test harness (**`a2test`**, built from `testmain.cc` with **TestControl** and **Tester**) supports automated or menu-driven checks alongside the main app (**`a2`**).

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

All paths below are relative to the `assignment2` folder (where the `Makefile` lives).

```
assignment2/
├── Asset.cc
├── Asset.h
├── AssetArray.cc
├── AssetArray.h
├── AssetStore.cc
├── AssetStore.h
├── Control.cc
├── Control.h
├── defs.h
├── main.cc
├── Makefile
├── Project.cc
├── Project.h
├── ProjectArray.cc
├── ProjectArray.h
├── ProjectManager.cc
├── ProjectManager.h
├── README.md
├── TestControl.cc
├── TestControl.h
├── Tester.cc
├── Tester.h
├── testmain.cc
├── View.cc
└── View.h
```

## How to build and run

You need **g++** and **make** (for example on Linux, macOS, or **WSL** on Windows).

### Build

1. Open a terminal and change into the project directory:

   ```bash
   cd path/to/assignment2
   ```

2. Build both the main program and the test executable:

   ```bash
   make
   ```

   This produces:

   - **`a2`** — main interactive application  
   - **`a2test`** — test menu / automated checks  

   To build only the main program you can run `make a2`; for only tests, `make a2test`.

### Run the main program

```bash
./a2
```

Follow the on-screen menu to work with projects and assets.

### Run the test harness

```bash
./a2test
```

Choose options from the menu to run individual tests or the full suite.

### Clean build artifacts

```bash
make clean
```

Removes `a2`, `a2test`, and `*.o` in the current directory.
