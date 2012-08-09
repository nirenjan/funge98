/****************************************************************************
 * sysinfo.c
 *
 * System information file for Funge98
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

#define SYSINFO_FLAGS_CONCURRENT    0x1
#define SYSINFO_FLAGS_IN_FILE       0x2
#define SYSINFO_FLAGS_OUT_FILE      0x4
#define SYSINFO_FLAGS_SYSEXEC       0x8
#define SYSINFO_FLAGS_UNBUFF_IO     0x10

/* Flags field */
#define SYSINFO_FLAGS               0x0

/* Cell size */
#define SYSINFO_CELL_SIZE           0x4

/* Handprint */
// TODO
#define SYSINFO_HANDPRINT           0xa5a5a5a5

/* Version number */
#define SYSINFO_VERSION             1001 /* v1.0a */

/* Operating paradigm */
#define SYSINFO_OPERATING_PARADIGM  0

/* Path separator character */
#define SYSINFO_PATH_SEPARATOR      '/'

/* Number of dimensions */
#define SYSINFO_DIMENSIONS          2

/* Current IP ID */

void get_sysinfo(void)
{
    int32_t param;
    int32_t pushed;

    // TODO: implement stack
    // param = pop();


}
