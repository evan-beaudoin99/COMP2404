# COMP 2404 Assignment 3

`Author: Evan Beaudoin`

`Student Id: 101340118`

## Directory Structure
```
assinment3/
|   Control.cc
|   Control.h
|   Entity.cc
|   Entity.h
|   Lab.cc
|   Lab.h
|   LabTech.cc
|   LabTech.h
|   LabWork.cc
|   LabWork.h
|   LabWorkList.cc
|   LabWorkList.h
|   List.cc
|   List.h
|   main.cc
|   Makefile
|   Patient.cc
|   Patient.h
|   README.md
|   test.cc
|   test1.cc
|   TestControl.cc
|   TestControl.h
|   Tester.cc
|   Tester.h
|   View.cc
|   View.h
|
\---design
        uml.drawio
```


# Compilation Instructions

1.
Cleans up all old .o and executable files
```
 make clean
```

2.
Builds a test program to test individual classes

```
make a3test
```

OR

Builds a View layer to the project simulation a Lab ecosystem
```
make a3
```

3.

To run each:
```
./a3test OR ./a3
``` 