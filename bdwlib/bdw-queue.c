/* bdw-queue.c
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
#include "bdw-queue.h"
#include "bdw-error.h"

BdwQueue *
bdw_queue_new (sizetype size)
{
  BdwQueue * self = bdw_new (BdwQueue);
  self->head = self->tail = 0;
  self->size = size;

  self->data = bdw_alloc (pointer, self->size);
  return self;
}

void
bdw_queue_destroy (BdwQueue * self)
{
  bdw_free (self->data);
  bdw_free (self);
}

void
bdw_queue_reset (BdwQueue * self)
{
  sizetype size = self->size;
  bdw_queue_destroy (self);
  self = bdw_queue_new (size);
}

void
bdw_queue_push (BdwQueue * self, pointer data)
{
  if (bdw_queue_is_full (self)) {
    bdw_error_report ("ERROR: Queue is full.");
    return;
  }

  self->tail = (self->tail + 1) % self->size;
  self->data[self->tail] = data;
}

pointer
bdw_queue_pop (BdwQueue * self)
{
  if (bdw_queue_is_empty (self)) {
    bdw_error_report ("ERROR: Queue is empty.");
    return NULL;
  }

  self->head = (self->head + 1) % self->size;
  return self->data[self->head];
}

pointer
bdw_queue_get_data_at_front (const BdwQueue * self)
{
  if (bdw_queue_is_empty (self)) {
    bdw_error_report ("ERROR: Queue is empty.");
    return NULL;
  }

  return self->data[self->head];
}

bool
bdw_queue_is_empty (const BdwQueue * self)
{
  if (self->head == self->tail)
    return TRUE;
  return FALSE;
}

bool
bdw_queue_is_full (const BdwQueue * self)
{
  if (self->head == ((self->tail + 1) % self->size))
    return TRUE;
  return FALSE;
}
