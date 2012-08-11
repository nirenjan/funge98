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

----

## Data Space

Data space in BrainFunge is stored in a stack which can hold upto 2147483648
elements. Elements can be pushed on to the stack by any of the push digit
commands and are popped off the stack by the arithmetic and logic instructions.

### Stack Stack

BrainFunge maintains a stack stack, that is, a stack of stacks. All stack
operations operate on the top stack of the stack stack or TOSS. BrainFunge
has a set of instructions to manipulate the stack stack.

The stack immediately below the TOSS is the second stack of the stack stack
or the SOSS.

The `{` or Begin Block command pops a count `n` from the TOSS and pushes a new
stack on the stack stack, that is, the old TOSS becomes the SOSS and the
new stack becomes the new TOSS.

If the count `n` is positive, the interpreter moves `n` elements from the SOSS
to the TOSS. If the number of elements `k` on the SOSS is less than `n`, then
`n`-`k` zeroes are pushed on to the TOSS. The order of elements is preserved
between the TOSS & SOSS.

## Instruction Pointer

BrainFunge uses a thread of execution referred to in this document as the
Instruction Pointer or IP. Each IP can move in any direction, and can also
move in a non-cardinal direction.

Each IP has it's own stack.
