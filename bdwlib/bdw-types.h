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

#if !defined(__BDWLIB_INSIDE__) && !defined(BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#include "bdw-macros.h"

BDW_BEGIN_DECLS
// clang-format off

/**
 * SECTION:bdw-types
 * @title: BdwLib data-types
 * @short_description: Custom data-types, convenience aliases and functions.
 *
 * BdwLib types and functions.
 **/

/*    Custom data-types    */

#ifndef STRING
#  define STRING(x)       ((string)   (x))
#  define STRING_REF(x)   ((string *) (x))
#  define STRING_DEF(x)  *((string *) (x))

/**
 * string:
 *
 * Specifies the data-type for a character string.
 **/
typedef char* string;
#endif /* STRING */


#ifndef CONSTSTRING
#  define CONSTSTRING(x)       ((conststring)   (x))
#  define CONSTSTRING_REF(x)   ((conststring *) (x))
#  define CONSTSTRING_DEF(x)  *((conststring *) (x))

/**
 * conststring:
 *
 * Specifies the data-type for a constant character string.
 **/
typedef const char* conststring;
#endif /* CONSTSTRING */


#ifndef POINTER
#  define POINTER(x)       ((pointer)   (x))
#  define POINTER_REF(x)   ((pointer *) (x))
#  define POINTER_DEF(x)  *((pointer *) (x))

/**
 * pointer:
 *
 * Specifies the data-type for a pointer to any kind of data.
 **/
typedef void* pointer;
#endif /* POINTER */


#ifndef CONSTPOINTER
#  define CONSTPOINTER(x)       ((constpointer)   (x))
#  define CONSTPOINTER_REF(x)   ((constpointer *) (x))
#  define CONSTPOINTER_DEF(x)  *((constpointer *) (x))

/**
 * constpointer:
 *
 * Specifies the data-type for a pointer to any kind of constant data.
 **/
typedef const void* constpointer;
#endif /* CONSTPOINTER */


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
 * Returns: A negative value if @a < @b, zero if @a = @b, positive value if
 *          @a > @b.
 **/
typedef int           (*CompareFunction)      (constpointer a,
                                               constpointer b,
                                               pointer      param_data);

/**
 * CopyFunction:
 * @original: A pointer to the data to be copied.
 * @param_data: Additional data needed for the copying process.
 *
 * Specifies the type of a copy function used to copy the node data when doing a
 * full-copy of a list.
 *
 * Returns: A pointer to the copy.
 **/
typedef pointer       (*CopyFunction)         (constpointer original,
                                               pointer      param_data);

/**
 * ForeachFunction:
 * @node_data: The list node data.
 * @param_data: Additional data used by the #ForeachFunction when its called, it
 *              can be %NULL if none is needed.
 *
 * Specifies the type of a function that will be executed once for every node in
 * the list, it can do anything that the user wants.
 **/
typedef void          (*ForeachFunction)      (pointer      node_data,
                                               pointer      param_data);

/**
 * ToStringFunction:
 * @node_data: The list node data.
 * @param_data: Additional data needed for string formatting, it can be
 *              %NULL if none is needed.
 *
 * Specifies the type of a function that takes the data from a #BdwList node and
 * creates a printable string from it.
 *
 * Returns: The list node data string representation.
 **/
typedef conststring   (*ToStringFunction)     (pointer      node_data,
                                               pointer      param_data);

/**
 * FromStringFunction:
 * @string_data: The string representation of a list node's data.
 * @param_data: Additional data needed for string formatting, it can be
 *              %NULL if none is needed.
 *
 * Specifies the type of a function that takes the string representation of an
 * #iList node data and creates an #iList node from it.
 *
 * Returns: The list node data that @string_data represents.
 **/
typedef pointer       (*FromStringFunction)   (conststring  string_data,
                                               pointer      param_data);

/**
 * DestroyFunction:
 * @node_data: The data element.
 *
 * Specifies the type of function which is called when a node's data is
 * destroyed. It is passed the pointer to the data element and should free any
 * memory and resources allocated for it.
 **/
typedef void          (*DestroyFunction)      (pointer      node_data);


/*    Convenience aliases for existing data-types    */

#ifndef BOOL_T
#  define BOOL_T(x)     ((bool)   (x))
#  define BOOL_REF(x)   ((bool *) (x))
#  define BOOL_DEF(x)  *((bool *) (x))

/**
 * bool:
 *
 * Specifies a convenience alias for a boolean data-type.
 **/
typedef unsigned char bool;
#endif /* BOOL */


#ifndef UNSIGNED_CHAR_T
#  define UNSIGNED_CHAR_T(x)     ((unsigned char)   (x))
#  define UNSIGNED_CHAR_REF(x)   ((unsigned char *) (x))
#  define UNSIGNED_CHAR_DEF(x)  *((unsigned char *) (x))

/**
 * uchar:
 *
 * Specifies a convenience alias for unsigned char data-type.
 **/
typedef unsigned char uchar;

/**
 * uint8:
 *
 * Specifies a convenience alias for unsigned 8 bit integer data-type.
 **/
typedef unsigned char uint8;

/**
 * byte:
 *
 * Specifies a convenience alias for an unsigned byte (8 bit) data-type.
 **/
typedef unsigned char byte;
#endif /* UNSIGNED_CHAR */


#ifndef CHAR_T
#  define CHAR_T(x)     ((char)   (x))
#  define CHAR_REF(x)   ((char *) (x))
#  define CHAR_DEF(x)  *((char *) (x))

/**
 * int8:
 *
 * Specifies a convenience alias for unsigned 8 bit integer data-type.
 **/
typedef signed char int8;
#endif /* CHAR */


#ifndef UNSIGNED_SHORT_T
#  define UNSIGNED_SHORT_T(x)     ((unsigned short)   (x))
#  define UNSIGNED_SHORT_REF(x)   ((unsigned short *) (x))
#  define UNSIGNED_SHORT_DEF(x)  *((unsigned short *) (x))

/**
 * ushort:
 *
 * Specifies a convenience alias for unsigned short integer data-type.
 **/
typedef unsigned short ushort;

/**
 * uint16:
 *
 * Specifies a convenience alias for unsigned 16 bit integer data-type.
 **/
typedef unsigned short uint16;
#endif /* UNSIGNED_SHORT */


#ifndef SHORT_T
#  define SHORT_T(x)     ((short)   (x))
#  define SHORT_REF(x)   ((short *) (x))
#  define SHORT_DEF(x)  *((short *) (x))

/**
 * int16:
 *
 * Specifies a convenience alias for unsigned 16 bit integer data-type.
 **/
typedef signed short int16;
#endif /* SHORT */


#ifndef UNSIGNED_INT_T
#  define UNSIGNED_INT_T(x)     ((unsigned int)   (x))
#  define UNSIGNED_INT_REF(x)   ((unsigned int *) (x))
#  define UNSIGNED_INT_DEF(x)  *((unsigned int *) (x))

/**
 * uint:
 *
 * Specifies a convenience alias for unsigned integer data-type.
 **/
typedef unsigned int uint;

/**
 * uint32:
 *
 * Specifies a convenience alias for unsigned 32 bit integer data-type.
 **/
typedef unsigned int uint32;
#endif /* UNSIGNED_INT */


#ifndef INT_T
#  define INT_T(x)     ((int)   (x))
#  define INT_REF(x)   ((int *) (x))
#  define INT_DEF(x)  *((int *) (x))

/**
 * int32:
 *
 * Specifies a convenience alias for unsigned 32 bit integer data-type.
 **/
typedef signed int int32;
#endif /* INT */


#ifndef UNSIGNED_LONG_T
#  define UNSIGNED_LONG_T(x)     ((unsigned long)   (x))
#  define UNSIGNED_LONG_REF(x)   ((unsigned long *) (x))
#  define UNSIGNED_LONG_DEF(x)  *((unsigned long *) (x))

/**
 * ulong:
 *
 * Specifies a convenience alias for unsigned long integer data-type.
 **/
typedef unsigned long ulong;
/**
 * uint64:
 *
 * Specifies a convenience alias for unsigned 64 bit integer data-type.
 **/
typedef unsigned long uint64;
#endif /* UNSIGNED_LONG */


#ifndef LONG_T
#  define LONG_T(x)     ((long)   (x))
#  define LONG_REF(x)   ((long *) (x))
#  define LONG_DEF(x)  *((long *) (x))

/**
 * int64:
 *
 * Specifies a convenience alias for unsigned 64 bit integer data-type.
 **/
typedef signed long int64;
#endif /* LONG */


#ifndef SIZE
#  define SIZE(x)       ((size)   (x))
#  define SIZE_REF(x)   ((size *) (x))
#  define SIZE_DEF(x)  *((size *) (x))

/**
 * size:
 *
 * Specifies a convenience alias for a data-type used for sizes.
 **/
typedef unsigned long size;
#endif /* SIZE */


#ifndef FLOAT_T
#  define FLOAT_T(x)     ((float)   (x))
#  define FLOAT_REF(x)   ((float *) (x))
#  define FLOAT_DEF(x)  *((float *) (x))
#endif /* FLOAT */


#ifndef DOUBLE_T
#  define DOUBLE_T(x)     ((double)   (x))
#  define DOUBLE_REF(x)   ((double *) (x))
#  define DOUBLE_DEF(x)  *((double *) (x))
#endif /* DOUBLE */

// clang-format on
BDW_END_DECLS

#endif /* BDW_TYPES__H */

