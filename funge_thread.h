/****************************************************************************
 * funge_thread.h
 *
 * Header file for BrainFunge thread library
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
#ifndef _FUNGE_THREAD_H
#define _FUNGE_THREAD_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "funge_vector.h"
#include "funge_stack.h"

/* Thread flags */
#define THREAD_FLAG_ALIVE       (1 << 0)
#define THREAD_FLAG_STRINGMODE  (1 << 1)
#define THREAD_FLAG_INF_LOOP    (1 << 2)

struct funge_thread_s {
    struct funge_thread_s *next;
    int32_t thread_id;
    int32_t team_id;
    int32_t flags;

    int32_t create_epoch;
    int32_t create_time;
    int32_t uptime;
    int32_t del_time;

    funge_vector_t ip;
    funge_vector_t delta;

    funge_vector_t storage_offset;

    funge_stack_t *stack;
    funge_extn_map_t *extn;
};

/*
 * Every time a thread is switched in, set a global
 * pointer to point to the current (active) thread.
 */
extern funge_thread_t *funge_thread_self;

#endif /* !defined _FUNGE_THREAD_H */
