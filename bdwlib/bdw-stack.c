/* bdw-stack.c
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
#include "bdw-stack.h"
#include "bdw-error.h"

BdwStack *
bdw_stack_new (sizetype size)
{
  BdwStack * self = bdw_new (BdwStack);
  self->size = size;
  self->top = 0;

  self->data = bdw_alloc (pointer, self->size);
  return self;
}

void
bdw_stack_destroy (BdwStack * self)
{
  bdw_free (self->data);
  bdw_free (self);
}

void
bdw_stack_reset (BdwStack * self)
{
  sizetype size = self->size;
  bdw_stack_destroy (self);
  self = bdw_stack_new (size);
}

void
bdw_stack_push (BdwStack * self, pointer data)
{
  if (bdw_stack_is_full (self)) {
    bdw_error_report ("ERROR: Stack is full.");
    return;
  }

  self->data[self->top++] = data;
}

pointer
bdw_stack_pop (BdwStack * self)
{
  if (bdw_stack_is_empty (self)) {
    bdw_error_report ("ERROR: Stack is empty.");
    return NULL;
  }

  pointer data = self->data[self->top--];
  return data;
}

pointer
bdw_stack_get_data_at_top (const BdwStack * self)
{
  if (bdw_stack_is_empty (self)) {
    bdw_error_report ("ERROR: Stack is empty.");
    return NULL;
  }

  return self->data[self->top - 1];
}

bool
bdw_stack_is_empty (const BdwStack * self)
{
  if ((self->data == NULL) || (self->top == 0))
    return TRUE;
  return FALSE;
}

bool
bdw_stack_is_full (const BdwStack * self)
{
  if (self->top == (self->size - 1))
    return TRUE;
  return FALSE;
}
