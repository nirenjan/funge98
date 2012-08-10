# BrainFunge

BrainFunge is a fungeoid inspired by Befunge-93 and the Funge-98
specification. BrainFunge is a programming language whose programs
are represented in 2 dimensions in Cartesian space.

-----

# The BrainFunge Virtual Machine
## Code and Data

Any given piece of code or data in a BrainFunge program can be
stored in one of two places (called a cell)

* Code-space, a 2-dimensional matrix of size NxN, N being an
  integer power of 2 and at least 128
* Data-space, a stack bound to a maximum of 2147483648 cells

Regardless of the location of the cell, each cell is always 32-bits wide.

----

## Code Space

Unlike Befunge-93 and Funge-98, the code space in BrainFunge is always
square in layout and the size is an integer power of 2. The minimum
size in a compliant interpreter is 128x128 and can go up to any power
of 2. However, 
