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

#ifndef FALSE
#define FALSE 0x00
#endif

#ifndef TRUE
#define TRUE 0x01
#endif


/*    Custom data-types    */

/** Definition of the generic pointer data-type. */
typedef void * pointer;

/** Definition of the generic constant pointer data-type. */
typedef const void * constpointer;

/** Definition of the character string data-type. */
typedef char * string;

/** Definition of the constant character string data-type. */
typedef const char * conststring;


/*    Custom function-types    */


/*    Convenience aliases for existing data-types    */

/** Convenience alias for unsigned char data-type. */
typedef unsigned char uchar;

/** Convenience alias for unsigned short integer data-type. */
typedef unsigned short ushort;

/** Convenience alias for unsigned integer data-type. */
typedef unsigned int uint;

/** Convenience alias for unsigned long integer data-type. */
typedef unsigned long ulong;

/** Convenience alias for unsigned 8 bit integer data-type. */
typedef unsigned char uint8;

/** Convenience alias for unsigned 16 bit integer data-type. */
typedef unsigned short uint16;

/** Convenience alias for unsigned 32 bit integer data-type. */
typedef unsigned int uint32;

/** Convenience alias for unsigned 64 bit integer data-type. */
typedef unsigned long uint64;

/** Convenience alias for unsigned 8 bit integer data-type. */
typedef signed char int8;

/** Convenience alias for unsigned 16 bit integer data-type. */
typedef signed short int16;

/** Convenience alias for unsigned 32 bit integer data-type. */
typedef signed int int32;

/** Convenience alias for unsigned 64 bit integer data-type. */
typedef signed long int64;

/** Convenience alias for an unsigned byte (8 bit) data-type. */
typedef unsigned char byte;

/** Convenience alias for a boolean data-type. */
typedef unsigned char bool;

#endif /* BDW_TYPES__H */

