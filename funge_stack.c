/****************************************************************************
 * funge_stack.c
 *
 * Source file for Funge98 stack manager
 *
 * Copyright (C) 2012 Nirenjan Krishnan
 ****************************************************************************
 * This file is part of Funge98.
 *
 * Funge98 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Funge98 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public Licese for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Funge98. If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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
    funge_stack_t *temp;

    temp = malloc(sizeof(funge_stack_t));
    if (!temp) {
        /* Out of memory */
        return RC_OUT_OF_MEMORY;
    }

    /* Link the new cell to the stack */
    temp->next_stack_cell = stack;
    if (stack) {
        temp->next_stack = stack->next_stack;
        temp->top = stack->top;
        temp->stack_no = stack->stack_no;
    } else {
        temp->next_stack = NULL;
        temp->top = -1;
        temp->stack_no = 0;
    }
    
    *stack = temp;

    return RC_OK;
}

/* Public API functions */
/* Push an element onto the stack */
int32_t funge_stack_push(funge_stack_t **stack, int32_t *val)
{
    int32_t index;
    int32_t rc;

    if (!stack || !*stack || !val) {
        return RC_BAD_POINTER;
    }

    if (*stack->top >= 0x7FFFFFFF) {
        *val = FUNGE_SPACE;
        return RC_STACK_FULL;
    }

    index = funge_stack_index(*stack);

    if (index == STACK_INDEX_MASK) {
        /* Need to allocate a new stack cell */
        rc = funge_stack_alloc_cell(*stack);
        if (rc) {
            return rc;
        }

        index = funge_stack_index(*stack);
    }
    index++;


    *stack->cell[index] = *val;

    return RC_OK;
}

/* Pop an element from the stack */
int32_t funge_stack_pop(funge_stack_t *stack, int32_t *val)
{
    int32_t index;
    int32_t rc;

    if (!stack || !*stack || !val) {
        return RC_BAD_POINTER;
    }

    if (*stack->top < 0) {
        /* Empty stack */
        *val = FUNGE_SPACE;
        return RC_STACK_EMPTY;
    }

    index = funge_stack_index(*stack);

    if (index == 0) {
        /* Need to free the top stack cell */
        rc = funge_stack_free_cell(*stack);
        if (rc) {
            return rc;
        }

        index = funge_stack_index(*stack);
    }
    index--;

    *stack->cell[index] = *val;

    return RC_OK;
    
}

