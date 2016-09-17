/* bdw-memory.c
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
#include "bdw-memory.h"

#include <stdlib.h>

pointer
bdw_memory_malloc (size mem_size)
{
  pointer mem_area;

  if (mem_size > 0)
  {
    mem_area = malloc (mem_size);

    if (mem_area != NULL)
      return mem_area;
  }

  return NULL;
}

pointer
bdw_memory_malloc_n (size mem_blocks,
                     size mem_size)
{
  pointer mem_area;

  if (mem_size > 0)
  {
    mem_area = malloc (mem_blocks * mem_size);

    if (mem_area != NULL)
      return mem_area;
  }

  return NULL;
}

pointer
bdw_memory_calloc (size mem_size)
{
  pointer mem_area;

  if (mem_size > 0)
  {
    mem_area = calloc (1, mem_size);

    if (mem_area != NULL)
      return mem_area;
  }

  return NULL;
}

pointer
bdw_memory_calloc_n (size mem_blocks,
                     size mem_size)
{
  pointer mem_area;

  if (mem_size > 0)
  {
    mem_area = calloc (mem_blocks, mem_size);

    if (mem_area != NULL)
      return mem_area;
  }

  return NULL;
}

pointer
bdw_memory_realloc (pointer mem_area,
                    size    new_mem_size)
{
  pointer new_mem_area;

  if (new_mem_size > 0)
  {
    new_mem_area = realloc (mem_area, new_mem_size);

    if (new_mem_area != NULL)
      return new_mem_area;
  }

  if (mem_area != NULL)
    free (mem_area);

  return NULL;
}

void
bdw_memory_free (pointer mem_area)
{
  if (mem_area != NULL)
    free (mem_area);
}
