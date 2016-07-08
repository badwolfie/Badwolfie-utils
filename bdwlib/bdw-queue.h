/* bdw-queue.h
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
#ifndef BDW_QUEUE__H
#define BDW_QUEUE__H

#if !defined (__BDWLIB_INSIDE__) && !defined (BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#include "bdw-types.h"

typedef struct _BdwQueue BdwQueue;
struct _BdwQueue
{
  pointer * data;
  sizetype size;
  int head;
  int tail;
};

BdwQueue * bdw_queue_new (sizetype size);

void bdw_queue_destroy (BdwQueue * self);

void bdw_queue_reset (BdwQueue * self);

void bdw_queue_push (BdwQueue * self, pointer data);

pointer bdw_queue_pop (BdwQueue * self);

pointer bdw_queue_get_data_at_front (const BdwQueue * self);

bool bdw_queue_is_empty (const BdwQueue * self);

bool bdw_queue_is_full (const BdwQueue * self);

#endif /* BDW_QUEUE__H */

