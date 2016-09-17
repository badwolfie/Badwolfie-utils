/* bdw-array.h
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
#ifndef BDW_ARRAY__H
#define BDW_ARRAY__H

#if !defined(__BDWLIB_INSIDE__) && !defined(BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#include "bdw-types.h"

BDW_BEGIN_DECLS
// clang-format off

/**
 * BdwArray:
 * @data: Elements of the array.
 * @length: Array's length.
 *
 * The #BdwArray struct that stores an array of elements and the number of
 * elements it holds.
 **/
typedef struct _BdwArray BdwArray;
struct _BdwArray
{
  pointer data;
  uint    length;
};

/*    Function prototypes    */

/**
 * bdw_array_new:
 *
 * Creates and initializes a new #BdwArray struct.
 *
 * Returns: A pointer to the newly created #BdwArray struct.
 **/
BdwArray   *bdw_array_new       (void);

/**
 * bdw_array_destroy:
 * @self: Pointer to the #BdwArray struct to be destroyed.
 *
 * Destroys an existing #BdwArray struct.
 **/
void        bdw_array_destroy   (BdwArray *self);

// clang-format on
BDW_END_DECLS

#endif /* BDW_ARRAY__H */

