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
of 2 upto 1024. The BrainFunge program can control the size of the code
space using the instructions XXX and XXX, which increase and decrease
the usable code space. Increasing code space will create 3 additional
regions as shown in the diagram below.

 +-+    +-+-+
 |0| -> |0|1|
 +-+    +-+-+
        |2|3|
        +-+-+

Decreasing has a more interesting behaviour. Not only will it reduce the
usable code space to 1/4th of the original space, it will also adjust the
code space pointers so that they reside in the new available space. That
is, if the old space is 256x256 and the instruction pointer is at (129,200),
the new IP will be at (129 & 127, 200 & 127) or (1, 72)

---

