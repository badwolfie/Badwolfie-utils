/* bdw-utility.h
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
#ifndef UTIL__H
#define UTIL__H

#include "bdw-types.h"

/**
 * Used to concatenate the given strings.
 *
 * @param arg NULL-terminated series of strings.
 * @return The concatenation of the strings given.
 */
string bdw_strconcat (conststring arg, ...);

/**
 * Creates a copy of the given string.
 *
 * @param arg String to be copied.
 * @return An exact copy of the given string.
 */
string bdw_strcopy (conststring arg);

/**
 * Compares two strings.
 *
 * @param arg1 One of string to be compared.
 * @param arg2 The string to be compared with arg1.
 * @return
 *    - @ref true if the strings are the same.
 *    - @ref false otherwise.
 */
bool bdw_strequals (conststring arg1, conststring arg2);

/**
 * Trims a string at the first occurrence of a given character.
 *
 * @param str String to be trimmed.
 * @param delim Character used as delimiter for the trimming.
 */
void bdw_strtrim (conststring str, string delim);

/**
 * Appends a character to a given string.
 *
 * @param dest String to be processed.
 * @param c Character to be appended.
 */
void bdw_strappendchr (string dest, char c);

/**
 * Used to tokenize (or split) a given string by a given delimiter.
 *
 * @param str String to be tokenized (split).
 * @param delim String used as a delimiter for the tokenization.
 * @return The NULL-terminated array of strings result of the tokenization.
 */
string * bdw_strsplit (conststring str, conststring delim);

/**
 * Obtains the length of a NULL-terminated array of elements.
 *
 * @param array Pointer to the NULL-terminated array to be processed.
 * @return The length of the given array.
 */
ulong bdw_arraylen (pointer array);

#endif /* UTIL__H */

