# COMP 2404 — Assignment 4

## Assignment overview

This project implements a small **SummitStream**-style conference application in C++. Users can browse conferences and talks, load talk data from a media file, search talks by speaker and/or keyword, build a playlist, and play talks through audio-only or audio-plus-video players. The design separates concerns using a **Controller** (application flow), **View** (menus and I/O), and model types such as **Conference**, **Talk**, **SummitStream**, and **Search** (with concrete search strategies). A separate test harness (`a4test`) exercises conferences, talks, search, and playback for grading-style checks.

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

All paths below are relative to the `assignment4` folder (where the `Makefile` lives).

```
assignment4/
├── Controller.cc
├── Controller.h
├── Conference.cc
├── Conference.h
├── defs.h
├── List.h
├── main.cc
├── Makefile
├── media/
│   └── media2.txt
├── Player.cc
├── Player.h
├── README.md
├── Search.cc
├── Search.h
├── SearchFactory.h
├── SummitStream.cc
├── SummitStream.h
├── Talk.cc
├── Talk.h
├── test.cc
├── test1.cc
├── TestControl.cc
├── TestControl.h
├── Tester.cc
├── Tester.h
├── View.cc
├── View.h
├── videos/
│   ├── band.txt
│   ├── batman.txt
│   ├── darth.txt
│   ├── genie.txt
│   ├── khan.txt
│   ├── minotaur.txt
│   ├── montypython.txt
│   ├── scoobie.txt
│   ├── simpsons.txt
│   ├── starwars1.txt
│   ├── starwars2.txt
│   └── valkyrie.txt
└── .vscode/
    └── c_cpp_properties.json
```

## How to build and run

You need **g++** and **make** (for example on Linux, macOS, or **WSL** on Windows).

### Build

1. Open a terminal and change into the project directory:

   ```bash
   cd path/to/assignment4
   ```

2. Build both the main program and the test executable:

   ```bash
   make
   ```

   This produces:

   - **`a4`** — main interactive application  
   - **`a4test`** — test menu / automated checks  

   To build only the main program you can run `make a4`; for only tests, `make a4test`.

### Run the main program

Run from **`assignment4`** so relative paths to `media/media2.txt` and `videos/` resolve correctly:

```bash
./a4
```

Follow the on-screen menu to explore conferences, search talks, print or play the playlist, and toggle video mode.

### Run the test harness

```bash
./a4test
```

Choose options from the menu to run individual tests or the full suite. Again, run this from **`assignment4`** so data files are found.

### Clean build artifacts

```bash
make clean
```

Removes `a4`, `a4test`, and `*.o` in the current directory.
