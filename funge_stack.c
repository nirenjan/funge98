/****************************************************************************
 * funge_stack.c
 *
 * Source file for BrainFunge stack manager
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
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "funge_const.h"
#include "funge_stack.h"

/* Private functions */
/* Compute the index in the current stack cell */
static inline int32_t funge_stack_index(funge_stack_t *stack)
{
    return (stack->top & STACK_INDEX_MASK);
}

/* Allocate a new stack cell */
static int32_t funge_stack_alloc_cell(funge_stack_t *stack)
{
    funge_stack_cell_t *temp;

    temp = malloc(sizeof(funge_stack_t));
    if (!temp) {
        /* Out of memory */
        return RC_OUT_OF_MEMORY;
    }

    /* Link the new cell to the stack */
    temp->next_stack_cell = stack->next_stack_cell;
    stack->next_stack_cell = temp;

    return RC_OK;
}

/* Free the top stack cell */
static int32_t funge_stack_free_cell(funge_stack_t *stack)
{
    funge_stack_cell_t *temp;

    temp = stack->next_stack_cell;
    if (!temp) {
        /* Should never get here */
        return RC_BAD_POINTER;
    }

    /* Link the next cell to the stack */
    stack->next_stack_cell = temp->next_stack_cell;
    
    free(temp);

    return RC_OK;
}

/* Public API functions */
/* Push an element onto the stack */
int32_t funge_stack_push(funge_stack_t *stack, int32_t *val)
{
    int32_t index;
    int32_t rc;

    if (!stack || !val) {
        return RC_BAD_POINTER;
    }

    if (stack->top >= 0x7FFFFFFF) {
        *val = FUNGE_SPACE;
        return RC_STACK_FULL;
    }

    stack->top++;

    index = funge_stack_index(stack);

    if (index == 0) {
        /* Need to allocate a new stack cell */
        rc = funge_stack_alloc_cell(stack);
        if (rc) {
            return rc;
        }
    }

    stack->next_stack_cell->cell[index] = *val;

    return RC_OK;
}

/* Pop an element from the stack */
int32_t funge_stack_pop(funge_stack_t *stack, int32_t *val)
{
    int32_t index;
    int32_t rc;

    if (!stack || !val) {
        return RC_BAD_POINTER;
    }

    if (stack->top < 0) {
        /* Empty stack */
        *val = FUNGE_SPACE;
        return RC_STACK_EMPTY;
    }

    index = funge_stack_index(stack);

    if (index == STACK_INDEX_MASK) {
        /* Need to free the top stack cell */
        rc = funge_stack_free_cell(stack);
        if (rc) {
            *val = FUNGE_SPACE;
            return rc;
        }
    }

    *val = stack->next_stack_cell->cell[index];

    stack->top--;

    return RC_OK;
    
}

/* Clear the stack of elements (only the TOSS) */
int32_t funge_stack_clear(funge_stack_t *stack)
{
    funge_stack_cell_t *temp;

    if (!stack) {
        return RC_BAD_POINTER;
    }

    temp = stack->next_stack_cell;
    stack->top = -1;

    /* We want to free all stack cells but the last one */
    while(temp->next_stack_cell) {
        stack->next_stack_cell = temp->next_stack_cell;
        free(temp);

        temp = stack->next_stack_cell;
    }

    return RC_OK;
}

/* Initialize a thread's stack & stack stack */
int32_t funge_stack_init(funge_stack_t *stack)
{
    if (!stack) {
        return RC_BAD_POINTER;
    }

    /* Initialize pointers */
    stack->next_stack_cell = NULL;
    stack->next_stack = NULL;
    stack->top = -1;
    stack->stack_no = 0;

    return funge_stack_alloc_cell(stack);
}
