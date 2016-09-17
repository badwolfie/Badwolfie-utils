/* bdw-memory.h
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
#ifndef BDW_MEMORY__H
#define BDW_MEMORY__H

#include "bdw-types.h"

BDW_BEGIN_DECLS
// clang-format off

pointer   bdw_memory_malloc     (size    mem_size);

pointer   bdw_memory_malloc_n   (size    mem_blocks,
                                 size    mem_size);

pointer   bdw_memory_calloc     (size    mem_size);

pointer   bdw_memory_calloc_n   (size    mem_blocks,
                                 size    mem_size);

pointer   bdw_memory_realloc    (pointer mem_area,
                                 size    new_mem_size);

void      bdw_memory_free       (pointer mem_area);


#ifndef bdw_new
/**
 * bdw_new:
 * @struct_type: The type of the struct element to allocate.
 *
 * Allocates memory for a single element of type @struct_type.
 *
 * Returns: A pointer to the allocated memory, cast to a pointer to
 * @struct_type.
 **/
#define bdw_new(struct_type)                                                   \
    (struct_type *) bdw_memory_calloc (sizeof (struct_type))
#endif /* bdw_new */


#ifndef bdw_alloc
/**
 * bdw_alloc:
 * @struct_type: The type of the elements to allocate.
 * @n_structs: The number of elements to allocate.
 *
 * Allocates @n_structs elements of type @struct_type, if @n_structs is equal or
 * lesser than 0 it returns %NULL.
 *
 * Returns: A pointer to the allocated memory, cast to a pointer to
 * @struct_type.
 **/
#define bdw_alloc(struct_type, n_structs)                                      \
    (struct_type *) bdw_memory_malloc_n ((n_structs), sizeof (struct_type))
#endif /* bdw_alloc */


#ifndef bdw_realloc
/**
 * bdw_realloc:
 * @struct_type: The type of the elements to allocate.
 * @mem_area: The pointer to the memory area to reallocate.
 * @n_structs: The number of elements to allocate.
 *
 * Reallocates @n_structs elements of type @struct_type to the memory area
 * pointed by @mem_area, if @n_structs is equal or lesser than 0 it returns
 * %NULL.
 *
 * Returns: A pointer to the reallocated memory, cast to a pointer to
 * @struct_type.
 **/
#define bdw_realloc(struct_type, mem_area, n_structs)                          \
    (struct_type) bdw_memory_realloc (mem_area, (n_structs))
#endif /* bdw_realloc */


#ifndef bdw_free
/**
 * bdw_free:
 * @mem: The memory space to free.
 *
 * If @mem is different from %NULL, it frees the memory pointed to by it.
 **/
#define bdw_free(mem)                                                          \
    bdw_memory_free (POINTER (mem))
#endif /* bdw_free */

// clang-format on
BDW_END_DECLS

#endif /* BDW_MEMORY__H */

