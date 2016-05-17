/* Copyright (c) 2016 Ian Hernandez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "bdw-utils.h"


/* String utilities. */

string
bdw_util_strconcat (const char * arg, ...)
{
  string output, aux;
  unsigned int len, current_len;

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

    arg = va_arg (arglist, const string);
    free (aux);
  }

  return output;
}

string
bdw_util_strcopy (const string arg)
{
  unsigned int len = strlen (arg);
  string output = (string) malloc (len + 1);
  strcpy (output, arg);
  return output;
}

bool
bdw_util_strequals (const string arg1, const string arg2)
{
  if (strcmp (arg1, arg2) == 0)
    return true;
  return false;
}

void
bdw_utils_strtrim (const string str, char delim)
{
  char * newline = NULL;

  newline = strchr (str, delim);
  if (newline != NULL)
  {
    *newline = (char) 0;
  }
}

void
bdw_utils_strappendchr (string dest, char c)
{
  unsigned short len = strlen (dest);
  dest = realloc (dest, len + 2);
  dest[len + 1] = (char) 0;
  dest[len] = c;
}

string *
bdw_utils_strsplit (const string str, const string delim)
{
  short array_len = 1, i = 0;

  string * str_array = (string *) malloc (sizeof (string));
  string token = strtok (str, delim);

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

int
bdw_utils_nullarraylen (pointer array)
{
  int len = 0;
  if (array)
  {
    while (((pointer *) array)[len])
    {
      len++;
    }
  }

  return len;
}

BdwArray *
bdw_array_new (void)
{
  BdwArray * self = (BdwArray *) malloc (sizeof (BdwArray));
  self->elements = NULL;
  self->len = 0;
  return self;
}

void
bdw_array_destroy (BdwArray * self)
{
  if (self == NULL)
    return ;

  if (self->elements != NULL)
    free (self->elements);
  free (self);
}


/* File utilities. */

string
bdw_utils_filegetline (FILE * file)
{
  size_t size = 0;
  string str_line = NULL;

  int status = getline (&str_line, &size, file);
  if (status == -1)
  {
    return NULL;
  }

  bdw_utils_strtrim (str_line, '\n');
  return str_line;
}
