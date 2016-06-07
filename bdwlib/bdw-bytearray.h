/* bdw-bytearray.h
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
#ifndef BDW_BYTEARRAY__H
#define BDW_BYTEARRAY__H

#include "bdw-types.h"

/** Struct that stores an array of bytes and the number of elements it holds. */
typedef struct _BdwByteArray BdwByteArray;

/**
 * Creates and initializes a new BdwByteArray struct.
 *
 * @return A pointer to the newly created BdwByteArray struct.
 */
BdwByteArray * bdw_byte_array_new (void);

/**
 * Destroys an existing BdwByteArray struct.
 *
 * @param self Pointer to the BdwByteArray struct to be destroyed.
 */
void bdw_byte_array_destroy (BdwByteArray * self);

#endif /* BDW_BYTEARRAY__H */