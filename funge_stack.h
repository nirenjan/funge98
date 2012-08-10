/****************************************************************************
 * funge_stack.h
 *
 * Header file for BrainFunge stack manager
 *
 * Copyright (C) 2012 Nirenjan Krishnan
 ****************************************************************************
 * This file is part of BrainFunge.
 *
 * BrainFunge is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrainFunge is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public Licese for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BrainFunge. If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/
#ifndef _FUNGE_STACK_H
#define _FUNGE_STACK_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/****************************************************************************
 * A BrainFunge stack is defined like below:
 *
 *         stack hdr    stack cell     stack cell
 *         +-+-+-+-+    +-+-+-+----    +-+-+-+----
 * TOSS -> | | | | | -> | | | | ... -> | | | | ... -> ...
 *         +-+-+-+-+    +-+-+-+----    +-+-+-+----
 *          |
 *          V
 *         +-+-+-+-+    +-+-+-+----    +-+-+-+----
 * SOSS -> | | | | | -> | | | | ... -> | | | | ... -> ...
 *         +-+-+-+-+    +-+-+-+----    +-+-+-+----
 *          |
 *          V
 *          .
 *          .
 *          .
 *         
 ***************************************************************************/

/* Limit each stack cell to 1K entries before allocating a new stack cell */
#define STACK_SZ            1024

/* Index mask */
#define STACK_INDEX_MASK    0x3ff

/* Count shift */
#define STACK_COUNT_SHIFT   10

struct funge_stack_cell_s {
    /* Pointer to the next stack cell in the same stack */
    struct funge_stack_cell_s *next_stack_cell;

    /* These are the actual values in the stack */
    int32_t cell[STACK_SZ];
};

typedef struct funge_stack_cell_s funge_stack_cell_t;

struct funge_stack_s {
    /* Pointer to the next stack cell in the same stack */
    struct funge_stack_cell_s *next_stack_cell;

    /* Pointer to the next stack in the stack stack */
    struct funge_stack_s *next_stack;

    /*
     * Index of the top entry in the current stack.
     * This is NOT the index in the current stack cell.
     * However, it's easy to compute the index by taking
     * the bottom N bits (N = log2 STACK_SZ - 1) of this
     * value. The remaining bits will tell you how many
     * stack cells are used in the current stack.
     * A negative value indicates that the stack is empty.
     */
    int32_t top;

    /* This is the index of the stack in the stack stack, starting from 0 */
    int32_t stack_no;
};

typedef struct funge_stack_s funge_stack_t;

/* Public API functions */
/* Push an element onto the stack */
extern int32_t funge_stack_push(funge_stack_t *stack, int32_t *val);

/* Pop an element from the stack */
extern int32_t funge_stack_pop(funge_stack_t *stack, int32_t *val);

/* Clear the stack of elements (only the TOSS) */
extern int32_t funge_stack_clear(funge_stack_t *stack);

/* Initialize a thread's stack & stack stack */
extern int32_t funge_stack_init(funge_stack_t *stack);

#endif /* !defined _FUNGE_STACK_H */
