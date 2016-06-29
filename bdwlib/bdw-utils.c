/* bdw-utils.c
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
#include <string.h>
#include <stdio.h>

#include "bdw-utils.h"

void
bdw_utils_clear_buffer (pointer buffer, sizetype size)
{
  if (buffer != NULL) {
      memset (buffer, 0x00, size);
  }
}

sizetype
bdw_utills_array_get_length (pointer array)
{
  sizetype len = 0;

  if (array) {
    while (((pointer *) array)[len]) {
      len++;
    }
  }

  return len;
}

void
bdw_utils_flush_stdin (void)
{
  int64 d, i;
	d = stdin->_IO_read_end - stdin->_IO_read_ptr;

	for(i = 0; i < d; i++) {
    getchar();
  }
}

