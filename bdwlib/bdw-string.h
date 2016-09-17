/* bdw-string-utils.h
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
#ifndef BDW_STRING__H
#define BDW_STRING__H

#if !defined(__BDWLIB_INSIDE__) && !defined(BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#include "bdw-types.h"

BDW_BEGIN_DECLS
// clang-format off

/**
 * SECTION:bdw-string-utils
 * @title: String utilities
 * @short_description: String utility functions.
 *
 * BdwLib strings.
 **/

/*    Function prototypes    */

/**
 * bdw_strconcat:
 * @arg: The first string to be concatenated.
 * @...: A %NULL-terminated series of strings to be concatenated.
 *
 * Concatenates the given strings.
 *
 * Returns: The concatenation of the strings given.
 **/
string    bdw_strconcat           (conststring arg,
                                   ...);

/**
 * bdw_strdup:
 * @original: String to be duplicated.
 *
 * Creates a duplicate of the given string.
 *
 * Returns: A duplicate of the given string.
 **/
string    bdw_strdup              (conststring original);

/**
 * bdw_strequals:
 * @arg1: One of string to be compared.
 * @arg2: The string to be compared with @arg1.
 *
 * Compares two strings.
 *
 * Returns: %TRUE if the strings are the same, %FALSE otherwise.
 **/
bool      bdw_strequals           (conststring arg1,
                                   conststring arg2);

/**
 * bdw_str_case_equals:
 * @arg1: One of string to be compared.
 * @arg2: The string to be compared with @arg1.
 *
 * Same as bdw_strequals() but ignoring case.
 *
 * Returns: %TRUE if the strings are the same, %FALSE otherwise.
 **/
bool      bdw_str_case_equals     (conststring arg1,
                                   conststring arg2);

/**
 * bdw_strtrim:
 * @str: String to be trimmed.
 * @delim: String used as delimiter for the trimming.
 *
 * Trims a string at the first occurrence of a given character.
 **/
void      bdw_strtrim             (string      str,
                                   conststring delim);

/**
 * bdw_str_append_char:
 * @dest: String to be processed.
 * @c: Character to be appended.
 *
 * Appends a character to a given string.
 **/
void      bdw_str_append_char     (string      dest,
                                   char        c);

/**
 * bdw_strsplit:
 * @str: String to be tokenized (split).
 * @delim: String used as a delimiter for the tokenization.
 *
 * Used to tokenize (or split) a given string by a given delimiter.
 * Since this function uses
 *[strtok](http://man7.org/linux/man-pages/man3/strtok.3.html)
 * internally to tokenize @str, it has the same limitations:
 *
 * - This function modify their first argument.
 * - This function cannot be used on constant strings.
 * - The identity of the delimiting byte is lost.
 * - Uses a static buffer while parsing, so it's not thread safe.
 *
 * For more information, see the [man
 *pages](http://man7.org/linux/man-pages/man3/strtok.3.html#BUGS).
 *
 * Returns: The %NULL-terminated array of strings result of the tokenization.
 **/
string   *bdw_strsplit            (conststring str,
                                   conststring delim);

/**
 * bdw_strjoin:
 * @separator: A string to insert between each of the strings, or %NULL.
 * @arg: The first string to be joined.
 * @...: A %NULL-terminated series of strings to be joined.
 *
 * Joins a number of strings together to form one long string with the optional
 * @separator inserted between each of them.
 *
 * Returns: A newly-allocated string containing all of the strings joined
 *          together with @separator between them.
 **/
string    bdw_strjoin             (conststring separator,
                                   conststring arg,
                                   ...);

/**
 * bdw_str_has_prefix:
 * @str: A string.
 * @prefix: The prefix to look for in @str.
 *
 * Checks if @str begins with @prefix.
 *
 * Returns: %TRUE if @str begins with @prefix, %FALSE otherwise.
 **/
bool      bdw_str_has_prefix      (conststring str,
                                   conststring prefix);

/**
 * bdw_str_has_suffix:
 * @str: A string.
 * @suffix: The suffix to look for in @str.
 *
 * Checks if @str ends with @suffix.
 *
 * Returns: %TRUE if @str ends with @suffix, %FALSE otherwise
 **/
bool      bdw_str_has_suffix      (conststring str,
                                   conststring suffix);

/**
 * bdw_strstrip:
 * @str: A string to remove the leading and trailing whitespace from.
 *
 * Removes leading and trailing whitespace from a string.
 *
 * Returns: @str without leading or trailing whitespace.
 **/
#define   bdw_strstrip(str)       (bdw_strstrip_leading (bdw_strstrip_trailing (str)))

/**
 * bdw_strstrip_leading:
 * @str: A string to remove the leading whitespace from.
 *
 * Removes leading whitespace from a string. This function doesn't allocate or
 * reallocate any memory, it modifies @str in place. Therefore, it cannot be
 * used on statically allocated strings.
 *
 * The pointer to @str is returned to allow the nesting of functions.
 *
 * Returns: @str without leading whitespace.
 **/
string    bdw_strstrip_leading    (string      str);

/**
 * bdw_strstrip_trailing:
 * @str: A string to remove the trailing whitespace from.
 *
 * Removes trailing whitespace from a string. This function doesn't allocate or
 * reallocate any memory, it modifies @str in place. Therefore, it cannot be
 * used on statically allocated strings.
 *
 * The pointer to @str is returned to allow the nesting of functions.
 *
 * Returns: @str without trailing whitespace.
 **/
string    bdw_strstrip_trailing   (string      str);

/**
 * bdw_strerror:
 * @error_code: Code for the occurred error.
 *
 * Returns a pointer to a string that describes the error code passed in
 * @error_code by internally calling
 * [strerror](http://man7.org/linux/man-pages/man3/strerror.3.html).
 *
 * Returns: Description of @error_code.
 **/
string    bdw_strerror            (uint64      error_code);

// clang-format on
BDW_END_DECLS

#endif /* BDW_STRING__H */
