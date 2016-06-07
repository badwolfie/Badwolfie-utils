/* bdw-utility.c
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
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "bdw-utility.h"


/* String utilities. */

string
bdw_strconcat (conststring arg, ...)
{
  string output, aux;
  uint len, current_len;

  va_list arglist;
  va_start (arglist, arg);

  output = (string) malloc (1);
  memset (output, 0x00, 1);
  current_len = 0;

  while (arg != NULL)
  {
    len = strlen (arg);
    current_len = strlen (output);

    aux = output;
    output = (string) malloc (current_len + len + 1);

    strcpy (output, aux);
    strcat (output, arg);

    arg = va_arg (arglist, conststring);
    free (aux);
  }

  return output;
}

string
bdw_strcopy (conststring arg)
{
  unsigned int len = strlen (arg);
  string output = (string) malloc (len + 1);
  strcpy (output, arg);
  return output;
}

bool
bdw_strequals (conststring arg1, conststring arg2)
{
  if (strcmp (arg1, arg2) == 0)
    return TRUE;
  return FALSE;
}

void
bdw_strtrim (string str, conststring delim)
{
  char * newline = NULL;

  newline = strstr (str, delim);
  if (newline != NULL)
  {
    *newline = (char) 0;
  }
}

void
bdw_strappendchr (string dest, char c)
{
  ushort len = strlen (dest);
  dest = realloc (dest, len + 2);
  dest[len + 1] = (char) 0;
  dest[len] = c;
}

string *
bdw_strsplit (conststring str, conststring delim)
{
  short array_len = 1, i = 0;

  string * str_array = (string *) malloc (sizeof (string));
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


/* Array utilities. */

ulong
bdw_arraylen (pointer array)
{
  ulong len = 0;
  if (array)
  {
    while (((pointer *) array)[len])
    {
      len++;
    }
  }

  return len;
}

