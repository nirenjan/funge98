/****************************************************************************
 * funge_extn.c
 *
 * Source file for BrainFunge extension library
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
#include <string.h>

#include "funge_extn.h"
#include "funge_thread.h"
#include "funge_const.h"

extern int32_t funge_reflect(int32_t);
/* Public API */
/* Initialize extensions for current thread */
int32_t funge_extn_init(funge_thread_t *thread)
{
    if (!thread) {
        return RC_BAD_POINTER;
    }

    if (thread->extn) {
        /* We already have an extension */
        return RC_EXTENSION_EXISTS;
    }

    thread->extn = malloc(sizeof(funge_extn_map_t));
    if (!thread->extn) {
        return RC_OUT_OF_MEMORY;
    }

    memset(thread->extn, 0, sizeof(funge_extn_map_t));

    return RC_OK;
}

int32_t funge_extn_handler(int32_t funge_char)
{
    funge_handler_fn_t handler = &funge_reflect;
    int32_t index;

    if (!funge_thread_self) {
        return RC_BAD_POINTER;
    }

    if (funge_char < 'A' || funge_char > 'Z') {
        /* Unsupported funge command for extensions */
        return RC_OUT_OF_RANGE;
    }

    /* Map [A-Z] to [0..25] */
    index = funge_char - 'A';

    if (funge_thread_self->extn && 
        funge_thread_self->extn->extn_map[index].function) {
        handler = funge_thread_self->extn->extn_map[index].function;
    }

    return handler(funge_char);
}

int32_t funge_extn_load(int32_t fingerprint)
{
    return RC_OK;
}

int32_t funge_extn_unload(int32_t fingerprint)
{
    return RC_OK;
}

