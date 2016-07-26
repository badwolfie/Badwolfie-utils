/* bdw-list.h
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
#ifndef BDW_LIST__H
#define BDW_LIST__H

#if !defined(__BDWLIB_INSIDE__) && !defined(BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#include "bdw-types.h"

/**
 * SECTION:bdw-list
 * @title: Doubly-Linked Lists
 * @short_description: Standard doubly-linked list implementation.
 *
 * The #BdwList is a standard doubly-linked list based on the GLib
 * implementation of doubly-linked lists, the
 * [GList](https://developer.gnome.org/glib/stable/glib-Doubly-Linked-Lists.html)
 * structure and its associated functions.
 *
 * Each node in the list has a #pointer to any kind of data and its linked to
 * both the previuos and next nodes in the list, which means you can iterate
 * this lists in both directions.
 **/

/**
 * BdwList:
 * @data: Holds the node's data, which can be a pointer to any kind of data.
 * @prev: Contains the link to the previuos node in the list.
 * @next: Contains the link to the next node in the list.
 *
 * The #BdwList struct used for each node in a doubly-linked list.
 **/
typedef struct _BdwList BdwList;
struct _BdwList
{
  pointer data;
  BdwList * prev;
  BdwList * next;
};

/*    Function prototypes    */
#ifdef __cplusplus /*    C++ support    */
extern "C" {
#endif

/**
 * bdw_list_new:
 *
 * "Creates" a list, calling this is optional since %NULL is considered to be a
 * valid empty list, you could simply set a #BdwList* to %NULL to initialize it.
 *
 * Returns: %NULL
 **/
BdwList * bdw_list_new (void);

/**
 * bdw_list_node_alloc:
 *
 * Allocates space for one #BdwList node.
 *
 * Returns: A pointer to the newly-allocated #BdwList node.
 **/
BdwList * bdw_list_node_alloc (void);

/**
 * bdw_list_destroy:
 * @self: A pointer to a #BdwList.
 *
 * Frees all of the memory used by a #BdwList. If list nodes contain
 * dynamically-allocated memory, you should either use bdw_list_full_destroy()
 * or free them manually first.
 **/
void bdw_list_destroy (BdwList * self);

/**
 * bdw_list_full_destroy:
 * @self: A pointer to a #BdwList.
 * @free_func: The function to be called to free each node's data.
 *
 * Frees all the memory used by a #BdwList, and calls @free_func on every node's
 * data.
 **/
void bdw_list_full_destroy (BdwList * self, DestroyFunction free_func);

/**
 * bdw_list_append:
 * @self: A pointer to a #BdwList.
 * @node_data: The data of the new node.
 *
 * Adds a new node on to the end of the list. Note that the return value is
 * the new start of the list, if list was empty; make sure you store the new
 * value.
 *
 * Returns: Either @self or the new start of the #BdwList if @self was %NULL.
 **/
BdwList * bdw_list_append (BdwList * self, pointer node_data);

/**
 * bdw_list_prepend:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 * @node_data: The data of the new node.
 *
 * Prepends a new node on to the start of the list. Note that the return
 * value is the new start of the list, which will have changed, so make sure you
 * store the new value.
 *
 * Returns: A pointer to the newly prepended node, which is the new start of
 *          the #BdwList.
 **/
BdwList * bdw_list_prepend (BdwList * self, pointer node_data);

/**
 * bdw_list_insert:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 * @node_data: The data of the new node.
 * @position: The position to insert the node. If this is negative, or is larger
 *            than the number of nodes in the list, the new node is added on to
 *            the end of the list.
 *
 * Inserts a new node into the list at the given position.
 *
 * Returns: The (possibly changed) start of the #BdwList.
 **/
BdwList * bdw_list_insert (BdwList * self, pointer node_data, int position);

/**
 * bdw_list_insert_before:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 * @node: The list node before which the new node is inserted or %NULL to insert
 *        at the end of the list.
 * @node_data: The data of the new node.
 *
 * Inserts a new node into the list before the given position.
 *
 * Returns: The (possibly changed) start of the #BdwList.
 **/
BdwList * bdw_list_insert_before (BdwList * self, BdwList * node,
                                  pointer node_data);

/**
 * bdw_list_insert_after:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 * @node: The list node after which the new node is inserted or %NULL to insert
 *        at the start of the list.
 * @node_data: The data of the new node.
 *
 * Inserts a new node into the list after the given position.
 *
 * Returns: The (possibly changed) start of the #BdwList.
 **/
BdwList * bdw_list_insert_after (BdwList * self, BdwList * node,
                                 pointer node_data);

/**
 * bdw_list_remove:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 * @node_data: The data of the node to remove.
 *
 * Removes a node from a #BdwList. If two nodes contain the same data, only
 * the first is removed. If none of the nodes contain the data, the #BdwList is
 * unchanged.
 *
 * Returns: The (possibly changed) start of the #BdwList.
 **/
BdwList * bdw_list_remove (BdwList * self, constpointer node_data);

/**
 * bdw_list_remove_all:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 * @node_data: The data to remove.
 *
 * Removes all list nodes with data equal to @node_data. Returns the new head of
 * the list. Contrast with bdw_list_remove() which removes only the first node
 * matching the given data.
 *
 * Returns: The (possibly changed) start of the #BdwList.
 **/
BdwList * bdw_list_remove_all (BdwList * self, constpointer node_data);

/**
 * bdw_list_remove_link:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 * @link: An element in the #BdwList.
 *
 * Removes a node from a #BdwList, without freeing the node. The removed node's
 * @prev and @next links are set to %NULL, so that it becomes a self-contained
 * list with one node.
 *
 * Returns: The (possibly changed) start of the #BdwList.
 **/
BdwList * bdw_list_remove_link (BdwList * self, BdwList * link);

/**
 * bdw_list_get_first:
 * @self: A pointer to any node in a #BdwList.
 *
 * Gets the first node in a #BdwList.
 *
 * Returns: The first node in the #BdwList, or %NULL if the #BdwList has no
 *          nodes.
 **/
BdwList * bdw_list_get_first (const BdwList * self);

/**
 * bdw_list_get_last:
 * @self: A pointer to any node in a #BdwList.
 *
 * Gets the last node in a #BdwList.
 *
 * Returns: The last node in the #BdwList, or %NULL if the #BdwList has no
 *nodes.
 **/
BdwList * bdw_list_get_last (const BdwList * self);

/**
 * bdw_list_get_previous:
 * @self: A pointer to a #BdwList node.
 *
 * Gets the previous node in a #BdwList.
 *
 * Returns: The previous node, or %NULL if there are no previous nodes.
 **/
BdwList * bdw_list_get_previous (const BdwList * self);

/**
 * bdw_list_get_next:
 * @self: A pointer to a #BdwList node.
 *
 * Gets the next node in a #BdwList.
 *
 * Returns: The next node, or %NULL if there are no more nodes.
 **/
BdwList * bdw_list_get_next (const BdwList * self);

/**
 * bdw_list_get_node_at:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 * @n: The position of the node, counting from zero.
 *
 * Gets the node at the given position in a #BdwList.
 *
 * Returns: The node, or %NULL if the position is off the end of the #BdwList.
 **/
BdwList * bdw_list_get_node_at (const BdwList * self, uint n);

/**
 * bdw_list_find:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 * @node_data: The node data to be found.
 *
 * Finds the node in a #BdwList which contains the given data.
 *
 * Returns: The found #BdwList node, or %NULL if it's not found.
 **/
BdwList * bdw_list_find (const BdwList * self, constpointer node_data);

/**
 * bdw_list_find_custom:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 * @node_data: The node data to be found.
 * @func: The function to call for each node. It should return 0 when the
 *        desired node is found.
 *
 * Finds a node in a #BdwList, using a supplied function to find the desired
 * node. It iterates over the list, calling the given function which should
 * return 0 when the desired node is found. The function takes two arguments,
 * the #BdwList node's data as the first argument and the given user data.
 *
 * Returns: The found #BdwList node, or %NULL if it's not found.
 **/
BdwList * bdw_list_find_custom (const BdwList * self, constpointer node_data,
                                CompareFunction func);

/**
 * bdw_list_copy:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 *
 * Copies a #BdwList.
 * Note that this is a "shallow" copy. If the list nodes consist of pointers to
 * data, the pointers are copied but the actual data is not. See
 * bdw_list_full_copy() if you need to copy the data as well.
 *
 * Returns: The start of the new list that holds the same data as @self.
 **/
BdwList * bdw_list_copy (BdwList * self);

/**
 * bdw_list_full_copy:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 * @func: A copy function used to copy every node in the list.
 * @param_data: Extra data needed by the copy function @func, or %NULL.
 *
 * Makes a full copy of a #BdwList.
 * In contrast with bdw_list_copy(), this function uses @func to make a copy of
 * each list node, in addition to copying the list container itself.
 *
 * @func, as a CopyFunction, takes two arguments: the data to be copied and a
 * @param_data pointer. It's safe to pass %NULL as param_data, if the copy
 * function takes only one argument.
 *
 * Returns: The start of the new list that holds a full copy of @self, you
 *          should use bdw_list_full_destroy() to free it.
 **/
BdwList * bdw_list_full_copy (BdwList * self, CopyFunction func,
                              pointer param_data);

/**
 * bdw_list_concat:
 * @list1: A #BdwList, this must point to the top of the list.
 * @list2: The #BdwList to add to the end of the first #BdwList, this must point
 *         to the top of the list.
 *
 * Adds the second #BdwList onto the end of the first #BdwList. Note that the
 * nodes of the second BdwList are not copied, they are used directly.
 *
 * Returns: The start of the new #BdwList, which equals @list1 if not %NULL.
 **/
BdwList * bdw_list_concat (BdwList * list1, BdwList * list2);

/**
 * bdw_list_foreach:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 * @func: The function to call with each node's data.
 * @param_data: Extra data that the function may need, or %NULL.
 *
 * Calls a function for each element of a #BdwList.
 **/
void bdw_list_foreach (const BdwList * self, ForeachFunction func,
                       pointer param_data);

/**
 * bdw_list_get_index:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 * @data: The data to find.
 *
 * Gets the position of the node containing the given data (starting from zero).
 *
 * Returns: The index of the node containing the data, or -1 if the data is not
 *          found.
 **/
int bdw_list_get_index (const BdwList * self, constpointer data);

/**
 * bdw_list_get_length:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 *
 * Gets the number of nodes in a #BdwList.
 *
 * Returns: The number of nodes in the #BdwList.
 **/
uint bdw_list_get_length (const BdwList * self);

/**
 * bdw_list_get_data:
 * @self: A pointer to a #BdwList node.
 *
 * Gets the data of the given node.
 *
 * Returns: The node's data.
 **/
pointer bdw_list_get_data (const BdwList * self);

/**
 * bdw_list_is_empty:
 * @self: A pointer to a #BdwList, this must point to the top of the list.
 *
 * Checks if @self is an empty list, calling this is optional since you could
 * just compare a #BdwList* to %NULL to see if it's empty.
 *
 * Returns: Whether or not the list is empty.
 **/
bool bdw_list_is_empty (const BdwList * self);

/**
 * bdw_list_is_first:
 * @self: A pointer to a #BdwList node.
 *
 * Checks if @self is the first node in a list.
 *
 * Returns: Whether or not the node is the first in the list.
 **/
bool bdw_list_is_first (const BdwList * self);

/**
 * bdw_list_is_last:
 * @self: A pointer to a #BdwList node.
 *
 * Checks if @self is the last node in a list.
 *
 * Returns: Whether or not the node is the last in the list.
 **/
bool bdw_list_is_last (const BdwList * self);

/**
 * bdw_list_node_to_string:
 * @self: A pointer to a #BdwList node.
 * @func: "To-string" function, it must take the data from the node and create a
 *        string representation for it.
 * @param_data: Additional data needed for string formatting, it can be %NULL if
 *              none needed.
 *
 * Gets the string representation of the node's data, it could be used to print
 * the contents of the list nodes for debugging.
 *
 * Returns: The node's data string representation.
 **/
conststring bdw_list_node_to_string (const BdwList * self,
                                     ToStringFunction func, pointer param_data);

#ifdef __cplusplus
}
#endif

#endif /* BDW_LIST__H */
