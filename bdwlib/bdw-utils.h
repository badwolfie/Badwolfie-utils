/* bdw-utils.h
 *
 * Copyright (C) 2016 Ian Hernandez <ihernandezs@openmailbox.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef BDW_UTILS__H
#define BDW_UTILS__H

#if !defined(__BDWLIB_INSIDE__) && !defined(BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

/*    Function prototypes    */
#ifdef __cplusplus /*    C++ support    */
extern "C" {
#endif

#include "bdw-types.h"

/**
 * bdw_utils_truncate:
 * @num:
 * @max:
 *
 * .
 **/
#define bdw_utils_truncate (num, max) (num > max ? max : num)

/**
 * bdw_utils_clear_buffer:
 * @buffer: Character string to be cleared.
 *
 * Sets every byte on @buffer to zero, clearing all its data.
 **/
void bdw_utils_clear_buffer (pointer buffer, sizetype size);

/**
 * bdw_utills_array_get_length:
 * @array: Pointer to the %NULL-terminated array to be processed.
 *
 * Obtains the length of a %NULL-terminated array of elements.
 *
 * Returns: The length of the given array.
 **/
sizetype bdw_utils_array_get_length (pointer array);

/**
 * bdw_utils_flush_stdin:
 *
 * Flushes the stdin buffer so you don't have problems while reading from it.
 **/
void bdw_utils_flush_stdin (void);

#ifdef __cplusplus
}
#endif

#endif /* BDW_UTILS__H */
