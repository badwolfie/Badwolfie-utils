/* bdw-array.c
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
#include <stdlib.h>

#include "bdw-array.h"

struct _BdwArray
{
  /** Elements of the array. */
  pointer data;

  /** Array's length. */
  uint length;
};

BdwArray *
bdw_array_new (void)
{
  BdwArray * self = (BdwArray *) malloc (sizeof (BdwArray));
  self->data = NULL;
  self->length = 0;
  return self;
}

void
bdw_array_destroy (BdwArray * self)
{
  if (self == NULL)
    return ;

  if (self->data != NULL)
    free (self->data);
  free (self);
}

