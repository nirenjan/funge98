/****************************************************************************
 * funge_mem.h
 *
 * Header file for Funge98 memory manager
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
#ifndef _FUNGE_MEM_H
#define _FUNGE_MEM_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * Number of directions a vector can move. This is set to be up to 6:
 * +x, -x, +y, -y, +z, -z
 */
#define DIRECTIONS 6

struct funge_mem_s {
    struct funge_mem_s *next[DIRECTIONS];
    int32_t cell[X_SZ][Y_SZ][Z_SZ];
}

#endif /* !defined FUNGE_MEM_H */
