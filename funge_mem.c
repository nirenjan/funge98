/****************************************************************************
 * funge_mem.c
 *
 * Source file for Funge98 memory manager
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

/*
 * The current implementation limits the usable Funge-space to (0, 0) to
 * X_SZ * Y_SZ. Future implementations will allow access to the entire
 * Funge-space.
 */

#include "funge_mem.h"

/*
 * There's always at least one funge_mem_t structure. This is statically
 * allocated to mem_root and corresponds to the first block of cells
 * from (0, 0) to (127, 127)
 */
funge_mem_t mem_root;

/* Public API functions */
/* Initialize the funge memory manager */
extern int32_t init_funge_mem(void)
{
    /* Reset the memory contents to space */
    memset(&mem_root, 0, sizeof(funge_mem_t) - 
            X_SZ * Y_SZ * sizeof(int32_t));
    memset(&mem_root.cell[0][0], FUNGE_SPACE,
            X_SZ * Y_SZ * sizeof(int32_t));
    return 0;
}

/* Get a value from funge memory */
extern int32_t get_funge_mem(int32_t x, int32_t y, int32_t *val)
{
    if (x < 0 || x >= X_SZ || y < 0 || y >= Y_SZ) {
        *val = FUNGE_SPACE;
        return RC_MEM_INVALID_PARAMS;
    }

    if (!val) {
        *val = FUNGE_SPACE;
        return RC_MEM_BAD_PTR;
    }

    *val = mem_root.cells[x][y];

    return RC_OK;
}

/* Store a value into funge memory */
extern int32_t put_funge_mem(int32_t x, int32_t y, int32_t *val)
{
    if (x < 0 || x >= X_SZ || y < 0 || y >= Y_SZ) {
        return RC_MEM_INVALID_PARAMS;
    }

    if (!val) {
        return RC_MEM_BAD_PTR;
    }

    mem_root.cells[x][y] = *val;

    return RC_OK;
}

