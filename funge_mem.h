/****************************************************************************
 * funge_mem.h
 *
 * Header file for BrainFunge memory manager
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
#ifndef _FUNGE_MEM_H
#define _FUNGE_MEM_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * Number of directions a vector can move. This is set to be up to 4:
 * +x, -x, +y, -y
 */
#define DIRECTIONS  4
#define DIR_POS_X   0
#define DIR_NEG_X   1
#define DIR_POS_Y   2
#define DIR_NEG_Y   4

/*
 * Define the number of cells in X & Y direction per supercell
 */
#define X_SZ        128
#define Y_SZ        128

struct funge_mem_s {
    struct funge_mem_s *next[DIRECTIONS];
    int32_t start_x;
    int32_t start_y;
    int32_t flags;
    int32_t pad;
    int32_t cell[X_SZ][Y_SZ];
};

typedef struct funge_mem_s funge_mem_t;

/*
 * There's always at least one funge_mem_t structure. This is statically
 * allocated to mem_root and corresponds to the first block of cells
 * from (0, 0) to (127, 127)
 */
extern funge_mem_t mem_root;

/* Public API functions */
/* Initialize the funge memory manager */
extern int32_t init_funge_mem(void);
/* Get a value from funge memory */
extern int32_t get_funge_mem(int32_t x, int32_t y, int32_t *val);
/* Store a value into funge memory */
extern int32_t put_funge_mem(int32_t x, int32_t y, int32_t *val);

#endif /* !defined _FUNGE_MEM_H */
