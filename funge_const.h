/****************************************************************************
 * funge_const.h
 *
 * Constants header file for Funge98
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
#ifndef _FUNGE_CONST_H
#define _FUNGE_CONST_H

#include "version.h"

/****************************************************************************
 * Interpreter constants
 ***************************************************************************/
#define RC_OK                       0
#define RC_MEM_INVALID_PARAMS       1
#define RC_BAD_POINTER              2
#define RC_OUT_OF_MEMORY            3
#define RC_STACK_FULL               4
#define RC_STACK_EMPTY              5

/****************************************************************************
 * Funge98 language constants
 ***************************************************************************/
#define FUNGE_SPACE                 32

/****************************************************************************
 * System information constants
 ***************************************************************************/
#define SYSINFO_FLAGS_CONCURRENT    0x1
#define SYSINFO_FLAGS_IN_FILE       0x2
#define SYSINFO_FLAGS_OUT_FILE      0x4
#define SYSINFO_FLAGS_SYSEXEC       0x8
#define SYSINFO_FLAGS_UNBUFF_IO     0x10

/* Flags field */
#define SYSINFO_FLAGS               0x0

/* Cell size */
#define SYSINFO_CELL_SIZE           0x4

/* Operating paradigm */
#define SYSINFO_OPERATING_PARADIGM  0   // Unavailable

/* Path separator character */
#define SYSINFO_PATH_SEPARATOR      '/'

/* Number of dimensions */
#define SYSINFO_DIMENSIONS          2

#endif /* !defined _FUNGE_CONST_H */
