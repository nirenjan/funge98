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

/****************************************************************************
 * BrainFunge extensions - fingerprint mechanism
 * ---------------------------------------------
 * BrainFunge extensions are stored as follows:
 *
 * [Thread] -> [Funge Extension Map] -> [Extension] -> [Extension] -> ...
 *
 * The Funge Extension Map is an array of 26 pointers to Extension
 * structures mapping the commands 'A' to 'Z'. At init time, the
 * extension map has only NULL pointers, thus indicating to the
 * extension handler that no extensions are loaded.
 *
 * On loading an extension, the extension map pointers are replaced
 * with the current extension's mappings and these mappings point to
 * the old mappings. On unloading an extension, the lists are walked
 * and the mapping with the the correct extension ID is unloaded.
 ***************************************************************************/
struct funge_extn_s {
    struct funge_extn_s *next;
    int32_t fingerprint;
    int32_t thread_id;
    funge_extn_fn_t function;
};

typedef struct funge_extn_s funge_extn_t;

struct funge_extn_map_s {
    funge_extn_t extn_map[26];
}

typedef struct funge_extn_map_s funge_extn_map_t;

/* Public API */
int32_t funge_extn_init(void);

int32_t funge_extn_handler(int32_t funge_char);

int32_t funge_extn_load(int32_t fingerprint);

int32_t funge_extn_unload(int32_t fingerprint);

#endif /* !defined _FUNGE_EXTN_H */
