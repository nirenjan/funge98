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
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "funge_fwd.h"
#include "funge_const.h"
#include "funge_vector.h"
#include "funge_stack.h"
#include "funge_thread.h"

/*
 * Every time a thread is switched in, set a global
 * pointer to point to the current (active) thread.
 */
funge_thread_t *funge_thread_self;

/* Local variables */
/*
 * Thread ID register
 * Maintains an incrementing counter to be placed into thead_id
 * field in the thread structure.
 */
static int32_t thread_id_register;

/*
 * Tick counter
 * Initialized at reset to 0. Increments by 1 every time the active
 * thread list is processed.
 */
static int32_t tick_counter;

/* Pointer to active thread list */
static funge_thread_t *thread_active;

static int32_t funge_thread_create(funge_thread_t **child,
                                   funge_thread_t *parent)
{
    funge_thread_t *thread;

    /* Allocate a thread */
    thread = malloc(sizeof(funge_thread_t));

    if (!thread) {
        return RC_OUT_OF_MEMORY;
    }

    thread->create_epoch = time(NULL);
    thread->create_time = tick_counter;
    thread->uptime = 0;

    thread->thread_id = thread_id_register;
    thread_id_register++;

    thread->flags = THREAD_FLAG_ALIVE;

    if (parent) {
        thread->ip = parent->ip;
        thread->storage_offset = parent->storage_offset;

        thread->delta.x = -(parent->delta.x);
        thread->delta.y = -(parent->delta.y);

        thread->parent_id = parent->thread_id;

        thread->next = parent;
        thread->prev = parent->prev;
        if (!thread->prev) {
            thread_active = thread;
        }
    } else {
        thread->ip.x = 0;
        thread->ip.y = 0;
        thread->delta.x = 1;
        thread->delta.y = 0;
        thread->storage_offset.x = 0;
        thread->storage_offset.y = 0;

        thread->parent_id = 0;

        thread_active = thread;
        thread->next = NULL;
        thread->prev = NULL;
    }
    *child = thread;

    return RC_OK;
}

/* Public APIs */
/* Initialize program with a single thread */
int32_t funge_thread_init(void)
{
    int32_t rc;
    funge_thread_t *thread;

    /*
     * Set the thread ID register to 1.
     * The first thread will have an ID of 1.
     * This will be incremented by the create routine
     * after each thread is created.
     */
    thread_id_register = 1;

    /* Initialize the tick counter to 0 */
    tick_counter = 0;

    /* Initialize the thread list */
    thread_active = NULL;

    rc = funge_thread_create(&thread, NULL);

    return rc;
}
