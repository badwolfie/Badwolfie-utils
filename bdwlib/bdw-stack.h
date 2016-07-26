/* bdw-stack.h
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
#ifndef BDW_STACK__H
#define BDW_STACK__H

#if !defined(__BDWLIB_INSIDE__) && !defined(BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#include "bdw-types.h"

typedef struct _BdwStack BdwStack;
struct _BdwStack
{
  pointer * data;
  sizetype size;
  int top;
};

BdwStack * bdw_stack_new (sizetype size);

void bdw_stack_destroy (BdwStack * self);

void bdw_stack_reset (BdwStack * self);

void bdw_stack_push (BdwStack * self, pointer data);

pointer bdw_stack_pop (BdwStack * self);

pointer bdw_stack_get_data_at_top (const BdwStack * self);

bool bdw_stack_is_empty (const BdwStack * self);

bool bdw_stack_is_full (const BdwStack * self);

#endif /* BDW_STACK__H */
