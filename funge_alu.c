/****************************************************************************
 * funge_alu.c
 *
 * Source file for BrainFunge ALU
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

#include "funge_fwd.h"
#include "funge_const.h"
#include "funge_stack.h"
#include "funge_thread.h"

static inline funge_stack_t *funge_thread_stack(void)
{
    return &(funge_thread_self->stack);
}

int32_t funge_logical_not(int32_t funge_char UNUSED)
{
    int32_t val;
    int32_t rc;

    rc = funge_stack_pop(funge_thread_stack(), &val);

    val = !val;

    rc = funge_stack_push(funge_thread_stack(), &val);

    return rc;
}

int32_t funge_discard_tos(int32_t funge_char UNUSED)
{
    int32_t val;
    int32_t rc;

    rc = funge_stack_pop(funge_thread_stack(), &val);
    
    return RC_OK;
}

int32_t funge_remainder(int32_t funge_char UNUSED)
{
    int32_t vala;
    int32_t valb;
    int32_t rc;

    rc = funge_stack_pop(funge_thread_stack(), &valb);
    rc = funge_stack_pop(funge_thread_stack(), &vala);

    vala =  valb ? vala % valb : 0;

    rc = funge_stack_push(funge_thread_stack(), &vala);

    return rc;
}

int32_t funge_multiply(int32_t funge_char UNUSED)
{
    int32_t vala;
    int32_t valb;
    int32_t rc;

    rc = funge_stack_pop(funge_thread_stack(), &valb);
    rc = funge_stack_pop(funge_thread_stack(), &vala);

    vala =  vala * valb;

    rc = funge_stack_push(funge_thread_stack(), &vala);

    return rc;
}

int32_t funge_add(int32_t funge_char UNUSED)
{
    int32_t vala;
    int32_t valb;
    int32_t rc;

    rc = funge_stack_pop(funge_thread_stack(), &valb);
    rc = funge_stack_pop(funge_thread_stack(), &vala);

    vala =  vala + valb;

    rc = funge_stack_push(funge_thread_stack(), &vala);

    return rc;
}

int32_t funge_subtract(int32_t funge_char UNUSED)
{
    int32_t vala;
    int32_t valb;
    int32_t rc;

    rc = funge_stack_pop(funge_thread_stack(), &valb);
    rc = funge_stack_pop(funge_thread_stack(), &vala);

    vala =  vala - valb;

    rc = funge_stack_push(funge_thread_stack(), &vala);

    return rc;
}

int32_t funge_divide(int32_t funge_char UNUSED)
{
    int32_t vala;
    int32_t valb;
    int32_t rc;

    rc = funge_stack_pop(funge_thread_stack(), &valb);
    rc = funge_stack_pop(funge_thread_stack(), &vala);

    vala =  valb ? vala / valb : 0;

    rc = funge_stack_push(funge_thread_stack(), &vala);

    return rc;
}

int32_t funge_stack_push_digit(int32_t funge_char)
{
    int32_t val;
    int32_t rc;

    if (funge_char >= 0x30 && funge_char <= 0x39) {
        val = funge_char - 0x30; // 0..9
    } else if (funge_char >= 0x61 && funge_char <= 0x66) {
        val = funge_char - 0x61 + 0xa; // a..f
    } else {
        return RC_INVALID_PARAMS;
    }

    rc = funge_stack_push(funge_thread_stack(), &val);

    return rc;
}

int32_t funge_stack_duplicate(int32_t funge_char UNUSED)
{
    int32_t val;
    int32_t rc;

    rc = funge_stack_pop(funge_thread_stack(), &val);
    rc = funge_stack_push(funge_thread_stack(), &val);
    rc = funge_stack_push(funge_thread_stack(), &val);

    return RC_OK;
}

int32_t funge_stack_swap(int32_t funge_char UNUSED)
{
    int32_t vala;
    int32_t valb;
    int32_t rc;

    rc = funge_stack_pop(funge_thread_stack(), &valb);
    rc = funge_stack_pop(funge_thread_stack(), &vala);

    rc = funge_stack_push(funge_thread_stack(), &valb);
    rc = funge_stack_push(funge_thread_stack(), &vala);

    return rc;
}

int32_t funge_stack_greater_than(int32_t funge_char UNUSED)
{
    int32_t vala;
    int32_t valb;
    int32_t rc;

    rc = funge_stack_pop(funge_thread_stack(), &valb);
    rc = funge_stack_pop(funge_thread_stack(), &vala);

    vala = vala > valb ? 1 : 0;

    rc = funge_stack_push(funge_thread_stack(), &vala);

    return rc;
}

