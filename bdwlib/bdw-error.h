/* bdw-error.h
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
#ifndef BDW_ERROR__H
#define BDW_ERROR__H

#if !defined (__BDWLIB_INSIDE__) && !defined (BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#include <errno.h>
#include "bdw-types.h"

/**
 * BdwError:
 * @code: Error code, defined by the developer.
 * @message: Informative readable message about the error.
 *
 * #BdwError struct that stores information about an occurred error.
 **/
typedef struct _BdwError BdwError;
struct _BdwError
{
  int64 code;
  conststring message;
};

/*    Function prototypes    */
#ifdef __cplusplus /*    C++ support    */
extern "C" {
#endif

/**
 * bdw_error_new:
 * @code: Error code.
 * @format: A printf()-like format for the error message.
 * @...: Parameters for the message format.
 *
 * Creates a new #BdwError with the given @code and a message formatted with
 * @format.
 *
 * Returns: A newly allocated #BdwError.
 **/
BdwError * bdw_error_new (int64 code, conststring format, ...);

/**
 * bdw_error_new_no_format:
 * @code: Error code.
 * @message: Error message.
 *
 * Same as bdw_error_new() but without message format.
 *
 * Returns: A newly allocated #BdwError.
 **/
BdwError * bdw_error_new_no_format (int64 code, conststring format);

/**
 * bdw_error_destroy:
 * @self: #BdwError to be destroyed.
 *
 * Frees a #BdwError and its internal resources.
 **/
void bdw_error_destroy (BdwError * self);

/**
 * bdw_error_report:
 * @format: A printf()-like format for the error message.
 * @...: Parameters for the message format.
 *
 * Printfs information about the error. A printf()-like format for the error
 * message.
 *
 * It's treated as a fatal error and the application closes.
 **/
void bdw_error_report (conststring format, ...);

/**
 * bdw_error_on_code:
 * @return_value: Return value of the function we're checking for errors.
 * @expected_error_code: Expected error code.
 * @message: Message to be displayed along with the error description.
 *
 * Printfs information about the error if the @return_value is equal to the
 * @expected_error_code.
 * It's treated as a fatal error and the application closes.
 **/
void bdw_error_on_code (int64 return_value,
                        int64 expected_error_code,
                        conststring message);

/**
 * bdw_error_on_null:
 * @return_value: Return value of the function we're checking for errors.
 * @message: Message to be displayed along with the error description.
 *
 * Printfs information about the error if the @return_value is equal to %NULL.
 * It's treated as a fatal error and the application closes.
 **/
void bdw_error_on_null (pointer return_value, conststring message);

#ifdef __cplusplus
}
#endif

#endif /* BDW_ERROR__H */
