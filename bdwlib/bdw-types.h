/* bdw-types.h
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
#ifndef BDW_TYPES__H
#define BDW_TYPES__H

/**
 * FALSE:
 * Specifies the "false" value for a boolean type.
 **/
#ifndef FALSE
#define FALSE 0x00
#endif

/**
 * TRUE:
 * Specifies the "true" value for a boolean type.
 **/
#ifndef TRUE
#define TRUE 0x01
#endif


/*    Custom data-types    */

/**
 * pointer:
 * Specifies the data-type for a pointer to any kind of data.
 **/
typedef void * pointer;

/**
 * constpointer:
 * Specifies the data-type for a pointer to any kind of constant data.
 **/
typedef const void * constpointer;

/**
 * string:
 * Specifies the data-type for a character string.
 **/
typedef char * string;

/**
 * conststring:
 * Specifies the data-type for a constant character string.
 **/
typedef const char * conststring;


/*    Custom function-types    */

/**
 * CompareFunction:
 * @a: A value.
 * @b: A value to compare @a with.
 * @param_data: Additional data needed for the comparison, can be %NULL if none
 *              is needed.
 *
 * Specifies the type of a comparison function used to compare two values.
 * The function should return a negative integer if the first value comes before
 * the second, 0 if they are equal, or a positive integer if the first value
 * comes after the second.
 *
 * It's used internally by bdw_list_find_custom().
 *
 * Returns: A negative value if @a < @b, zero if @a = @b, positive value if
 *          @a > @b.
 **/
typedef int (*CompareFunction) (constpointer a,
                                constpointer b,
                                pointer param_data);

/**
 * CopyFunction:
 * @original: A pointer to the data to be copied.
 * @param_data: Additional data needed for the copying process.
 *
 * Specifies the type of a copy function used to copy the node data when doing a
 * full-copy of a list.
 *
 * It's used internally by bdw_list_full_copy().
 *
 * Returns: A pointer to the copy.
 **/
typedef pointer (*CopyFunction) (constpointer original, pointer param_data);

/**
 * ForeachFunction:
 * @node_data: The list node data.
 * @param_data: Additional data used by the #ForeachFunction when its called, it
 *              can be %NULL if none is needed.
 *
 * Specifies the type of a function that will be executed once for every node in
 * the list, it can do anything that the user wants.
 *
 * It's used internally by bdw_list_foreach().
 **/
typedef void (*ForeachFunction) (pointer node_data, pointer param_data);

/**
 * ToStringFunction:
 * @node_data: The list node data.
 * @param_data: Additional data needed for string formatting, it can be
 *              %NULL if none is needed.
 *
 * Specifies the type of a function that takes the data from a #BdwList node and
 * creates a printable string from it.
 *
 * It's used internally by bdw_list_node_to_string().
 *
 * Returns: The list node data string representation.
 **/
typedef conststring (*ToStringFunction) (pointer node_data, pointer param_data);

/**
 * DestroyFunction:
 * @node_data: The data element.
 *
 * Specifies the type of function which is called when a node's data is
 * destroyed. It is passed the pointer to the data element and should free any
 * memory and resources allocated for it.
 *
 * It's used internally by bdw_list_full_destroy().
 **/
typedef void (*DestroyFunction) (pointer node_data);


/*    Convenience aliases for existing data-types    */

/**
 * uchar:
 * Specifies a convenience alias for unsigned char data-type.
 **/
typedef unsigned char uchar;

/**
 * ushort:
 * Specifies a convenience alias for unsigned short integer data-type.
 **/
typedef unsigned short ushort;

/**
 * uint:
 * Specifies a convenience alias for unsigned integer data-type.
 **/
typedef unsigned int uint;

/**
 * ulong:
 * Specifies a convenience alias for unsigned long integer data-type.
 **/
typedef unsigned long ulong;

/**
 * uint8:
 * Specifies a convenience alias for unsigned 8 bit integer data-type.
 **/
typedef unsigned char uint8;

/**
 * uint16:
 * Specifies a convenience alias for unsigned 16 bit integer data-type.
 **/
typedef unsigned short uint16;

/**
 * uint32:
 * Specifies a convenience alias for unsigned 32 bit integer data-type.
 **/
typedef unsigned int uint32;

/**
 * uint64:
 * Specifies a convenience alias for unsigned 64 bit integer data-type.
 **/
typedef unsigned long uint64;

/**
 * int8:
 * Specifies a convenience alias for unsigned 8 bit integer data-type.
 **/
typedef signed char int8;

/**
 * int16:
 * Specifies a convenience alias for unsigned 16 bit integer data-type.
 **/
typedef signed short int16;

/**
 * int32:
 * Specifies a convenience alias for unsigned 32 bit integer data-type.
 **/
typedef signed int int32;

/**
 * int64:
 * Specifies a convenience alias for unsigned 64 bit integer data-type.
 **/
typedef signed long int64;

/**
 * sizetype:
 * Specifies a convenience alias for a data-type used for sizes.
 **/
typedef unsigned long sizetype;

/**
 * byte:
 * Specifies a convenience alias for an unsigned byte (8 bit) data-type.
 **/
typedef unsigned char byte;

/**
 * bool:
 * Specifies a convenience alias for a boolean data-type.
 **/
typedef unsigned char bool;

#endif /* BDW_TYPES__H */

