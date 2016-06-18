/* bdw-string.c
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
#include <string.h>
#include <stdarg.h>

#include "bdw-string.h"

string
bdw_strconcat (conststring arg, ...)
{
  string output;
  sizetype len, current_len;

  va_list arglist;
  va_start (arglist, arg);

  output = bdw_alloc (char, 1);
  memset (output, 0x00, 1);
  current_len = 0;

  while (arg != NULL) {
    len = strlen (arg);
    current_len = strlen (output);

    output = (string) realloc (output, current_len + len + 1);
    strcat (output, arg);

    arg = va_arg (arglist, conststring);
  }

  return output;
}

string
bdw_strdup (conststring original)
{
  if (original == NULL)
    return NULL;

  sizetype len = strlen (original);
  string output = bdw_alloc (char, len + 1);
  strcpy (output, original);
  return output;
}

bool
bdw_strequals (conststring arg1, conststring arg2)
{
  if (strcmp (arg1, arg2) == 0)
    return TRUE;
  return FALSE;
}

bool
bdw_str_case_equals (conststring arg1, conststring arg2)
{
  if (strcasecmp (arg1, arg2) == 0)
    return TRUE;
  return FALSE;
}

void
bdw_strtrim (string str, conststring delim)
{
  char * newline = NULL;

  newline = strstr (str, delim);
  if (newline != NULL) {
    *newline = (char) 0;
  }
}

void
bdw_str_append_char (string dest, char c)
{
  sizetype len = strlen (dest);
  dest = (string) realloc (dest, len + 2);
  dest[len + 1] = (char) 0;
  dest[len] = c;
}

string *
bdw_strsplit (conststring str, conststring delim)
{
  sizetype array_len = 1;
  short i = 0;

  string * str_array = bdw_new (string);
  string token = strtok ((string) str, delim);

  while (token != NULL) {
    str_array[i++] = token;
    array_len++;

    str_array = (string *) realloc (str_array, array_len * sizeof (string));
    token = strtok (NULL, delim);
  }

  str_array[i] = NULL;
  return str_array;
}

string
bdw_strjoin (conststring separator, conststring arg, ...)
{
  string tmp = NULL;
  string output = bdw_alloc (char, 1);
  memset (output, 0x00, 1);

  va_list arglist;
  va_start (arglist, arg);

  while (arg != NULL) {
    tmp = output;
    output = bdw_strconcat (tmp, arg, NULL);
    bdw_free (tmp);

    arg = va_arg (arglist, conststring);
  }

  return output;
}

bool
bdw_str_has_prefix (conststring str, conststring prefix)
{
  sizetype i, prefix_len = strlen (prefix);

  for (i = 0; i < prefix_len; i++) {
    if (str[i] != prefix[i])
      return FALSE;
  }

  return TRUE;
}

bool bdw_str_has_suffix (conststring str, conststring suffix)
{
  sizetype i, str_len = strlen (str), suffix_len = strlen (suffix);

  for (i = 1; i <= suffix_len; i++) {
    if (str[str_len - i] != suffix[suffix_len - i])
      return FALSE;
  }

  return TRUE;
}

string
bdw_strstrip (string str)
{
  return bdw_strstrip_leading (bdw_strstrip_trailing (str));
}

string
bdw_strstrip_leading (string str)
{
  if (str == NULL)
    return NULL;

  char * stripped = str;
  while ((*stripped != (char) 0) && (*stripped != ' ') && (*stripped != '\t'))
    stripped++;

  memmove (str, stripped, strlen (stripped) + 1);
  return str;
}

string
bdw_strstrip_trailing (string str)
{
  if (str == NULL)
    return NULL;

  long len = strlen (str) - 1;
  while ((len >= 0) && ((str[len] == ' ') || (str[len] == '\t')))
      str[len--] = (char) 0;
  return str;
}

string
bdw_strerror (int64 error_code)
{
  return strerror (error_code);
}

