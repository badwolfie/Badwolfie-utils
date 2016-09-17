/* bdw-simple-list.c
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
#include "bdw-simple-list.h"
#include "bdw-memory.h"

BdwSimpleList *
bdw_simple_list_new (void)
{
  return NULL;
}

BdwSimpleList *
bdw_simple_list_node_alloc (void)
{
  BdwSimpleList *self = bdw_new (BdwSimpleList);
  self->data = NULL;
  self->next = NULL;
  return self;
}

void
bdw_simple_list_destroy (BdwSimpleList *self)
{
  if (self == NULL)
    return;

  bdw_simple_list_destroy (self->next);
  bdw_free (self);
}

void
bdw_simple_list_full_destroy (BdwSimpleList *self, DestroyFunction free_func)
{
  bdw_simple_list_foreach (self, (ForeachFunction) free_func, NULL);
  bdw_simple_list_destroy (self);
}

BdwSimpleList *
bdw_simple_list_append (BdwSimpleList *self, pointer node_data)
{
  BdwSimpleList *new_node;
  BdwSimpleList *last_node;

  new_node = bdw_simple_list_node_alloc ();
  new_node->data = node_data;

  if (self != NULL)
  {
    last_node = bdw_simple_list_get_last (self);
    last_node->next = new_node;
    return self;
  }

  return new_node;
}

BdwSimpleList *
bdw_simple_list_prepend (BdwSimpleList *self, pointer node_data)
{
  BdwSimpleList *new_node;

  new_node = bdw_simple_list_node_alloc ();
  new_node->data = node_data;
  new_node->next = self;
  return new_node;
}

BdwSimpleList *
bdw_simple_list_insert (BdwSimpleList *self, pointer node_data, int position)
{
  BdwSimpleList *new_node;
  BdwSimpleList *aux_node;

  if (position < 0)
    return bdw_simple_list_append (self, node_data);

  if (position == 0)
    return bdw_simple_list_prepend (self, node_data);

  aux_node = bdw_simple_list_get_node_at (self, position);
  if (aux_node == NULL)
    return bdw_simple_list_append (self, node_data);

  new_node = bdw_simple_list_node_alloc ();
  new_node->data = node_data;
  new_node->next = aux_node;

  return self;
}

BdwSimpleList *
bdw_simple_list_insert_before (BdwSimpleList *self,
                               BdwSimpleList *node,
                               pointer        node_data)
{
  BdwSimpleList *new_node = self;
  BdwSimpleList *last = NULL;

  if (self == NULL)
  {
    self = bdw_simple_list_node_alloc ();
    self->data = node_data;
    return self;
  }

  if (node == NULL)
  {
    return bdw_simple_list_append (self, node_data);
  }

  while ((new_node != NULL) && (new_node != node))
  {
    last = new_node;
    new_node = new_node->next;
  }

  new_node = bdw_simple_list_node_alloc ();
  new_node->data = node_data;

  if (last != NULL)
  {
    new_node->next = last->next;
    last->next = new_node;

    return self;
  }

  new_node->next = self;
  return new_node;
}

BdwSimpleList *
bdw_simple_list_insert_after (BdwSimpleList *self,
                              BdwSimpleList *node,
                              pointer        node_data)
{
  BdwSimpleList *new_node;

  if (self == NULL)
  {
    self = bdw_simple_list_node_alloc ();
    self->data = node_data;
    return self;
  }

  if (node == NULL)
  {
    return bdw_simple_list_prepend (self, node_data);
  }

  new_node = bdw_simple_list_node_alloc ();

  new_node->data = node_data;
  new_node->next = node->next;
  node->next = node;

  return self;
}

BdwSimpleList *
bdw_simple_list_remove (BdwSimpleList *self, constpointer node_data)
{
  BdwSimpleList *tmp = bdw_simple_list_find (self, node_data);
  if (tmp != NULL)
  {
    self = bdw_simple_list_remove_link (self, tmp);
    bdw_simple_list_destroy (tmp);
  }

  return self;
}

BdwSimpleList *
bdw_simple_list_remove_all (BdwSimpleList *self, constpointer node_data)
{
  BdwSimpleList *tmp;
  tmp = bdw_simple_list_find (self, node_data);

  while (tmp != NULL)
  {
    self = bdw_simple_list_remove_link (self, tmp);
    bdw_simple_list_destroy (tmp);

    tmp = bdw_simple_list_find (self, node_data);
  }

  return self;
}

BdwSimpleList *
bdw_simple_list_remove_link (BdwSimpleList *self, BdwSimpleList *link)
{
  BdwSimpleList *node = self;
  BdwSimpleList *last = NULL;

  if (self == NULL)
    return NULL;

  while (node != NULL)
  {
    if (node != link)
    {
      if (last != NULL)
        last->next = node->next;
      if (node == self)
        self = self->next;

      node->next = NULL;
      break;
    }

    last = node;
    node = node->next;
  }

  return self;
}

BdwSimpleList *
bdw_simple_list_get_last (const BdwSimpleList *self)
{
  BdwSimpleList *iterator;

  if (self == NULL)
    return NULL;

  iterator = (BdwSimpleList *) self;
  while (iterator->next != NULL)
    iterator = iterator->next;
  return iterator;
}

BdwSimpleList *
bdw_simple_list_get_node_at (const BdwSimpleList *self, uint n)
{
  BdwSimpleList *iterator = (BdwSimpleList *) self;

  while (((n--) > 0) && (iterator != NULL))
  {
    iterator = iterator->next;
  }

  return iterator;
}

BdwSimpleList *
bdw_simple_list_find (const BdwSimpleList *self, constpointer node_data)
{
  BdwSimpleList *iterator = (BdwSimpleList *) self;
  while (iterator != NULL)
  {
    if (iterator->data == node_data)
      break;
    iterator = iterator->next;
  }

  return iterator;
}

BdwSimpleList *
bdw_simple_list_find_custom (const BdwSimpleList *self,
                             constpointer         node_data,
                             CompareFunction      func)
{
  BdwSimpleList *iterator = (BdwSimpleList *) self;
  int            comparison;

  if (func == NULL)
    return (BdwSimpleList *) self;


  while (iterator != NULL)
  {
    comparison = func (iterator->data, node_data, NULL);
    if (comparison == 0)
      break;
    iterator = iterator->next;
  }

  return iterator;
}

BdwSimpleList *
bdw_simple_list_copy (BdwSimpleList *self)
{
  return bdw_simple_list_full_copy (self, NULL, NULL);
}

BdwSimpleList *
bdw_simple_list_full_copy (BdwSimpleList *self,
                           CopyFunction   func,
                           pointer        param_data)
{
  BdwSimpleList *iterator = self;
  BdwSimpleList *copy = NULL;
  BdwSimpleList *new_node;

  while (iterator != NULL)
  {
    new_node = bdw_simple_list_node_alloc ();

    if (func != NULL)
      new_node->data = func (iterator->data, param_data);
    else
      new_node->data = iterator->data;
    copy = bdw_simple_list_append (copy, new_node);

    iterator = iterator->next;
  }

  return copy;
}

BdwSimpleList *
bdw_simple_list_concat (BdwSimpleList *list1, BdwSimpleList *list2)
{
  BdwSimpleList *last;

  if (list2 == NULL)
  {
    last = bdw_simple_list_get_last (list1);

    if (last != NULL)
      last->next = list2;
    else
      list1 = list2;
  }

  return list1;
}

void
bdw_simple_list_foreach (const BdwSimpleList *self,
                         ForeachFunction      func,
                         pointer              param_data)
{
  BdwSimpleList *iterator = (BdwSimpleList *) self;

  while (iterator != NULL)
  {
    func (iterator->data, param_data);
    iterator = iterator->next;
  }
}

int
bdw_simple_list_get_index (const BdwSimpleList *self, constpointer data)
{
  uint           count = 0;
  BdwSimpleList *iterator = (BdwSimpleList *) self;

  while (iterator != NULL)
  {
    if (iterator->data == data)
      return count;

    iterator = iterator->next;
    count += 1;
  }

  return -1;
}

uint
bdw_simple_list_get_length (const BdwSimpleList *self)
{
  uint           count = 0;
  BdwSimpleList *iterator = (BdwSimpleList *) self;

  while (iterator != NULL)
  {
    iterator = iterator->next;
    count += 1;
  }

  return count;
}

bool
bdw_simple_list_is_empty (const BdwSimpleList *self)
{
  return (self == NULL);
}

bool
bdw_simple_list_is_last (const BdwSimpleList *self)
{
  return (self->next == NULL);
}

conststring
bdw_simple_list_node_to_string (const BdwSimpleList *self,
                                ToStringFunction     func,
                                pointer              param_data)
{
  if (self == NULL)
    return NULL;

  return func (self->data, param_data);
}
