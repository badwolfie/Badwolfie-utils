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

char *
bdw_util_strconcat (const char * arg, ...)
{
  char * output, * aux;
  unsigned int len, current_len;

  va_list arglist;
  va_start (arglist, arg);

  output = (char *) malloc (1);
  memset (output, 0x00, 1);
  current_len = 0;

  while (arg != NULL)
  {
    len = strlen (arg);
    current_len = strlen (output);

    aux = output;
    output = (char *) malloc (current_len + len + 1);

    strcpy (output, aux);
    strcat (output, arg);

    arg = va_arg (arglist, const char *);
    free (aux);
  }

  return output;
}

char *
bdw_util_strcopy (const char * arg)
{
  unsigned int len = strlen (arg);
  char * output = (char *) malloc (len + 1);
  strcpy (output, arg);
  return output;
}

Bool
bdw_util_strequals (const char * arg1, const char * arg2)
{
  if (strcmp (arg1, arg2) == 0)
    return TRUE;
  return FALSE;
}

void
bdw_util_strappendchr (char * dest, char c)
{
  unsigned short len = strlen (dest);
  dest = realloc (dest, len + 2);
  dest[len + 1] = (char) 0;
  dest[len] = c;
}

int 
bdw_util_arraylen (pointer array)
{
  int len = 0;
  if (array) {
    while (((pointer *) array)[len]) {
      len++;
    }
  }

  return len;
}
