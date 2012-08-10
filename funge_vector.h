/****************************************************************************
 * funge_vector.h
 *
 * Header file for Funge98 vector library
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
#ifndef _FUNGE_VECTOR_H
#define _FUNGE_VECTOR_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct funge_vector_s {
    int32_t x;
    int32_t y;
};

typedef struct funge_vector_s funge_vector_t;

#endif /* !defined _FUNGE_VECTOR_H */
