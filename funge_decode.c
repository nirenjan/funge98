/****************************************************************************
 * funge_decode.c
 *
 * Source file for BrainFunge decoder
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

#include "funge_fwd.h"
#include "funge_const.h"

typedef struct funge_decode_s funge_decode_t;

static int32_t funge_nop(int32_t funge_char)
{
    return RC_OK;
}

static int32_t funge_nop_space(int32_t funge_char)
{
    return RC_OK;
}

static const funge_handler_fn_t decode_array[] = {
    [0x20] = &funge_nop_space,          // Space
    [0x21] = &funge_logical_not,        // !
    [0x22] = &funge_thread_stringmode,  // "
    [0x23] = &funge_trampoline,         // #
    [0x24] = &funge_discard_tos,        // $
    [0x25] = &funge_remainder,          // %
    [0x26] = &funge_input_integer,      // &
    [0x27] = &funge_fetch_char,         // '
    [0x28] = &funge_load_fingerprint,   // (
    [0x29] = &funge_unload_fingerprint, // )
    [0x2A] = &funge_multiply,           // *
    [0x2B] = &funge_add,                // +
    [0x2C] = &funge_output_char,        // ,
    [0x2D] = &funge_subtract,           // -
    [0x2E] = &funge_output_integer,     // .
    [0x2F] = &funge_divide,             // /
    [0x30] = &funge_stack_push_digit,   // 0
    [0x31] = &funge_stack_push_digit,   // 1
    [0x32] = &funge_stack_push_digit,   // 2
    [0x33] = &funge_stack_push_digit,   // 3
    [0x34] = &funge_stack_push_digit,   // 4
    [0x35] = &funge_stack_push_digit,   // 5
    [0x36] = &funge_stack_push_digit,   // 6
    [0x37] = &funge_stack_push_digit,   // 7
    [0x38] = &funge_stack_push_digit,   // 8
    [0x39] = &funge_stack_push_digit,   // 9
    [0x3A] = &funge_stack_duplicate,    // :
    [0x3B] = &funge_thread_skip_code,   // ;
    [0x3C] = &funge_thread_direction,   // <
    [0x3D] = &funge_system_execute,     // =
    [0x3E] = &funge_thread_direction,   // >
    [0x3F] = &funge_thread_direction,   // ?
    [0x40] = &funge_thread_stop,        // @
    [0x41] = &funge_extn_handler,       // A
    [0x42] = &funge_extn_handler,       // B
    [0x43] = &funge_extn_handler,       // C
    [0x44] = &funge_extn_handler,       // D
    [0x45] = &funge_extn_handler,       // E
    [0x46] = &funge_extn_handler,       // F
    [0x47] = &funge_extn_handler,       // G
    [0x48] = &funge_extn_handler,       // H
    [0x49] = &funge_extn_handler,       // I
    [0x4A] = &funge_extn_handler,       // J
    [0x4B] = &funge_extn_handler,       // K
    [0x4C] = &funge_extn_handler,       // L
    [0x4D] = &funge_extn_handler,       // M
    [0x4E] = &funge_extn_handler,       // N
    [0x4F] = &funge_extn_handler,       // O
    [0x50] = &funge_extn_handler,       // P
    [0x51] = &funge_extn_handler,       // Q
    [0x52] = &funge_extn_handler,       // R
    [0x53] = &funge_extn_handler,       // S
    [0x54] = &funge_extn_handler,       // T
    [0x55] = &funge_extn_handler,       // U
    [0x56] = &funge_extn_handler,       // V
    [0x57] = &funge_extn_handler,       // W
    [0x58] = &funge_extn_handler,       // X
    [0x59] = &funge_extn_handler,       // Y
    [0x5A] = &funge_extn_handler,       // Z
    [0x5B] = &funge_thread_direction,   // [
    [0x5C] = &funge_stack_swap,         // \ 
    [0x5D] = &funge_thread_direction,   // ]
    [0x5E] = &funge_thread_direction,   // ^
    [0x5F] = &funge_thread_direction,   // _
    [0x60] = &funge_stack_greater_than, // `
    [0x61] = &funge_stack_push_digit,   // a
    [0x62] = &funge_stack_push_digit,   // b
    [0x63] = &funge_stack_push_digit,   // c
    [0x64] = &funge_stack_push_digit,   // d
    [0x65] = &funge_stack_push_digit,   // e
    [0x66] = &funge_stack_push_digit,   // f
    [0x67] = &funge_get_funge_space,    // g
    [0x68] = &funge_thread_direction,   // h
    [0x69] = &funge_system_input_file,  // i
    [0x6A] = &funge_thread_direction,   // j
    [0x6B] = &funge_iterate,            // k
    [0x6C] = &funge_thread_direction,   // l
    [0x6D] = &funge_thread_direction,   // m
    [0x6E] = &funge_stack_clear,        // n
    [0x6F] = &funge_system_output_file, // o
    [0x70] = &funge_put_funge_space,    // p
    [0x71] = &funge_system_quit,        // q
    [0x72] = &funge_thread_reflect,     // r
    [0x73] = &funge_store_char,         // s
    [0x74] = &funge_thread_fork,        // t
    [0x75] = &funge_stack_under_stack,  // u
    [0x76] = &funge_thread_direction,   // v
    [0x77] = &funge_thread_direction,   // w
    [0x78] = &funge_thread_direction,   // x
    [0x79] = &funge_system_information, // y
    [0x7A] = &funge_nop,                // z
    [0x7B] = &funge_stack_begin_block,  // {
    [0x7C] = &funge_thread_direction,   // |
    [0x7D] = &funge_stack_end_block,    // }
    [0x7E] = &funge_input_char,         // ~
};
