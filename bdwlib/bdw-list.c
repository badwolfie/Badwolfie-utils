/* bdw-list.c
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
#include "bdw-list.h"
#include "bdw-memory.h"
#include "bdw-string.h"

BdwList *
bdw_list_new (void)
{
  return NULL;
}

BdwList *
bdw_list_node_alloc (void)
{
  BdwList *self = bdw_new (BdwList);
  self->data = NULL;
  self->prev = NULL;
  self->next = NULL;
  return self;
}

void
bdw_list_destroy (BdwList *self)
{
  if (self == NULL)
    return;

  bdw_list_destroy (self->next);
  bdw_free (self);
}

void
bdw_list_full_destroy (BdwList *self, DestroyFunction free_func)
{
  bdw_list_foreach (self, (ForeachFunction) free_func, NULL);
  bdw_list_destroy (self);
}

BdwList *
bdw_list_append (BdwList *self, pointer node_data)
{
  BdwList *new_node;
  BdwList *last_node;

  new_node = bdw_list_node_alloc ();
  new_node->data = node_data;

  if (self != NULL)
  {
    last_node = bdw_list_get_last (self);
    last_node->next = new_node;
    new_node->prev = last_node;
    return self;
  }

  return new_node;
}

BdwList *
bdw_list_prepend (BdwList *self, pointer node_data)
{
  BdwList *new_node;

  new_node = bdw_list_node_alloc ();
  new_node->data = node_data;
  new_node->next = self;

  if (self != NULL)
  {
    self->prev = new_node;
  }

  return new_node;
}

BdwList *
bdw_list_insert (BdwList *self, pointer node_data, int position)
{
  BdwList *new_node;
  BdwList *aux_node;

  if (position < 0)
    return bdw_list_append (self, node_data);

  if (position == 0)
    return bdw_list_prepend (self, node_data);

  aux_node = bdw_list_get_node_at (self, position);
  if (aux_node == NULL)
    return bdw_list_append (self, node_data);

  new_node = bdw_list_node_alloc ();
  new_node->data = node_data;
  new_node->prev = aux_node->prev;
  new_node->next = aux_node;

  aux_node->prev->next = new_node;
  aux_node->prev = new_node;
  return self;
}

BdwList *
bdw_list_insert_before (BdwList *self, BdwList *node, pointer node_data)
{
  BdwList *new_node;

  if (self == NULL)
  {
    self = bdw_list_node_alloc ();
    self->data = node_data;
    return self;
  }

  if (node == NULL)
  {
    return bdw_list_append (self, node_data);
  }

  new_node = bdw_list_node_alloc ();
  new_node->data = node_data;
  new_node->prev = node->prev;
  new_node->next = node;

  node->prev = new_node;
  if (node->prev != NULL)
  {
    node->prev->next = new_node;
    return self;
  }

  return new_node;
}

BdwList *
bdw_list_insert_after (BdwList *self, BdwList *node, pointer node_data)
{
  BdwList *new_node;

  if (self == NULL)
  {
    self = bdw_list_node_alloc ();
    self->data = node_data;
    return self;
  }

  if (node == NULL)
  {
    return bdw_list_prepend (self, node_data);
  }

  new_node = bdw_list_node_alloc ();
  new_node->data = node_data;
  new_node->prev = node;
  new_node->next = node->next;

  node->next = node;
  if (node->next != NULL)
  {
    node->next->prev = new_node;
  }

  return self;
}

BdwList *
bdw_list_remove (BdwList *self, constpointer node_data)
{
  BdwList *tmp = bdw_list_find (self, node_data);
  if (tmp != NULL)
  {
    self = bdw_list_remove_link (self, tmp);
    bdw_list_destroy (tmp);
  }

  return self;
}

BdwList *
bdw_list_remove_all (BdwList *self, constpointer node_data)
{
  BdwList *tmp;
  tmp = bdw_list_find (self, node_data);

  while (tmp != NULL)
  {
    self = bdw_list_remove_link (self, tmp);
    bdw_list_destroy (tmp);

    tmp = bdw_list_find (self, node_data);
  }

  return self;
}

BdwList *
bdw_list_remove_link (BdwList *self, BdwList *link)
{
  if (self == NULL)
    return NULL;

  if (link->prev != NULL)
    link->prev->next = link->next;

  if (link->next != NULL)
    link->next->prev = link->prev;

  if (link == self)
    self = self->next;

  link->prev = NULL;
  link->next = NULL;

  return self;
}

BdwList *
bdw_list_get_first (const BdwList *self)
{
  BdwList *iterator;

  if (self == NULL)
    return NULL;

  iterator = (BdwList *) self;
  while (iterator->prev != NULL)
    iterator = iterator->prev;
  return iterator;
}

BdwList *
bdw_list_get_last (const BdwList *self)
{
  BdwList *iterator;

  if (self == NULL)
    return NULL;

  iterator = (BdwList *) self;
  while (iterator->next != NULL)
    iterator = iterator->next;
  return iterator;
}

BdwList *
bdw_list_get_node_at (const BdwList *self, uint n)
{
  BdwList *iterator = (BdwList *) self;

  while (((n--) > 0) && (iterator != NULL))
  {
    iterator = iterator->next;
  }

  return iterator;
}

BdwList *
bdw_list_find (const BdwList *self, constpointer node_data)
{
  BdwList *iterator = (BdwList *) self;
  while (iterator != NULL)
  {
    if (iterator->data == node_data)
      break;
    iterator = iterator->next;
  }

  return iterator;
}

BdwList *
bdw_list_find_custom (const BdwList * self,
                      constpointer    node_data,
                      CompareFunction func)
{
  BdwList *iterator;
  int      comparison;

  if (func == NULL)
    return (BdwList *) self;

  iterator = (BdwList *) self;

  while (iterator != NULL)
  {
    comparison = func (iterator->data, node_data, NULL);
    if (comparison == 0)
      break;
    iterator = iterator->next;
  }

  return iterator;
}

BdwList *
bdw_list_copy (BdwList *self)
{
  return bdw_list_full_copy (self, NULL, NULL);
}

BdwList *
bdw_list_full_copy (BdwList *self, CopyFunction func, pointer param_data)
{
  BdwList *iterator = self;
  BdwList *copy = NULL;
  BdwList *new_node;

  while (iterator != NULL)
  {
    new_node = bdw_list_node_alloc ();

    if (func != NULL)
      new_node->data = func (iterator->data, param_data);
    else
      new_node->data = iterator->data;
    copy = bdw_list_append (copy, new_node);

    iterator = iterator->next;
  }

  return copy;
}

BdwList *
bdw_list_concat (BdwList *list1, BdwList *list2)
{
  BdwList *last;

  if (list2 == NULL)
  {
    last = bdw_list_get_last (list1);

    if (last != NULL)
      last->next = list2;
    else
      list1 = list2;
    list2->prev = last;
  }

  return list1;
}

void
bdw_list_foreach (const BdwList *self, ForeachFunction func, pointer param_data)
{
  BdwList *iterator = (BdwList *) self;

  while (iterator != NULL)
  {
    func (iterator->data, param_data);
    iterator = iterator->next;
  }
}

int
bdw_list_get_index (const BdwList *self, constpointer data)
{
  uint     count = 0;
  BdwList *iterator = (BdwList *) self;

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
bdw_list_get_length (const BdwList *self)
{
  uint     count = 0;
  BdwList *iterator = (BdwList *) self;

  while (iterator != NULL)
  {
    iterator = iterator->next;
    count += 1;
  }

  return count;
}

bool
bdw_list_is_empty (const BdwList *self)
{
  return (self == NULL);
}

bool
bdw_list_is_first (const BdwList *self)
{
  return (self->prev == NULL);
}

bool
bdw_list_is_last (const BdwList *self)
{
  return (self->next == NULL);
}

string
bdw_list_to_concat_string (const BdwList   *list,
                           conststring      delim,
                           ToStringFunction func,
                           pointer          param_data)
{
  BdwList *iterator = (BdwList *) list;
  string   data_string;
  string   aux;

  data_string = bdw_strdup ("");

  while (iterator != NULL)
  {
    aux = data_string;
    data_string = bdw_strconcat (aux,
                                 func (iterator->data, param_data),
                                 delim,
                                 NULL);
    bdw_free (aux);

    iterator = bdw_list_get_next (iterator);
  }

  return data_string;
}

BdwList *
bdw_list_from_concat_string (conststring        src,
                             conststring        delim,
                             FromStringFunction func,
                             pointer            param_data)
{
  int      counter = 0;
  BdwList *self = bdw_list_new ();

  string  *data = bdw_strsplit (src, delim);
  pointer  node_data = NULL;

  if (data == NULL)
    return NULL;

  while (data[counter] != NULL)
  {
    node_data = func (data[counter], param_data);
    if (node_data == NULL)
    {
      bdw_free (data);
      return NULL;
    }

    self = bdw_list_append (self, node_data);
    counter++;
  }

  return self;
}

