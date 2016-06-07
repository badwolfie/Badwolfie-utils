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

#include "bdw-types.h"

/**
 * Struct that stores an array of elements and the number of elements it holds.
 */
typedef struct _BdwArray BdwArray;

/**
 * Creates and initializes a new BdwArray struct.
 *
 * @return A pointer to the newly created BdwArray struct.
 */
BdwArray * bdw_array_new (void);

/**
 * Destroys an existing BdwArray struct.
 *
 * @param self Pointer to the BdwArray struct to be destroyed.
 */
void bdw_array_destroy (BdwArray * self);

#endif /* BDW_ARRAY__H */

