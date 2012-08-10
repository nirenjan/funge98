/****************************************************************************
 * funge_extn.h
 *
 * Header file for BrainFunge extension library
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
#ifndef _FUNGE_EXTN_H
#define _FUNGE_EXTN_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct funge_extn_s {
    struct funge_extn_s *next;
    int32_t extn_id;
    int32_t thread_id;
    int32_t enabled_mask;

    funge_function_t function[26];      

    int32_t pad[2];
};

typedef struct funge_extn_s funge_extn_t;

#endif /* !defined _FUNGE_EXTN_H */
