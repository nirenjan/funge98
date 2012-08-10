/****************************************************************************
 * funge_fwd.h
 *
 * Forward declarations header file for BrainFunge
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
#ifndef _FUNGE_FWD_H
#define _FUNGE_FWD_H

/****************************************************************************
 * funge_const.h
 ***************************************************************************/

/****************************************************************************
 * funge_extn.h
 ***************************************************************************/
typedef int32_t (*funge_handler_fn_t)(int32_t funge_char);
struct funge_extn_map_s;
typedef struct funge_extn_map_s funge_extn_map_t;

/****************************************************************************
 * funge_mem.h
 ***************************************************************************/

/****************************************************************************
 * funge_stack.h
 ***************************************************************************/

/****************************************************************************
 * funge_thread.h
 ***************************************************************************/
struct funge_thread_s;
typedef struct funge_thread_s funge_thread_t;

/****************************************************************************
 * funge_vector.h
 ***************************************************************************/

#endif /* !defined _FUNGE_FWD_H */
