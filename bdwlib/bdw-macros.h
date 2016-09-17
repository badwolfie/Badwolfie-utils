/* bdw-macros.h
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
#ifndef BDW_MACROS__H
#define BDW_MACROS__H

// clang-format off

#ifdef __cplusplus
#  define BDW_BEGIN_DECLS  extern "C" {
#  define BDW_END_DECLS    }
#else
#  define BDW_BEGIN_DECLS
#  define BDW_END_DECLS
#endif /* __cplusplus */

#ifndef NULL
#  ifdef __cplusplus
#    define NULL  (0L)
#  else
#    define NULL  ((void *) 0)
#  endif /* __cplusplus */
#endif /* NULL */

/**
 * FALSE:
 *
 * Specifies the "false" value for a boolean type.
 **/
#ifndef FALSE
#  define FALSE (0x00)
#endif /* FALSE */

/**
 * TRUE:
 *
 * Specifies the "true" value for a boolean type.
 **/
#ifndef TRUE
#  define TRUE  (!FALSE)
#endif /* TRUE */

#ifndef MAX_OF
#  define MAX_OF(a, b)  ((a) > (b) ? (a) : (b))
#endif /* MAX_OF */

#ifndef MIN_OF
#  define MIN_OF(a, b)  ((a) < (b) ? (a) : (b))
#endif /* MIN_OF */

#ifndef TRUNCATE
#  define TRUNCATE(x, max)  (MIN_OF (x, max))
#endif /* TRUNCATE */

#ifndef ABS
#  define ABS(x)  ((x) < 0 ? -(x) : (x))
#endif /* ABS */

// clang-format on

#endif /* BDW_MACROS__H */

