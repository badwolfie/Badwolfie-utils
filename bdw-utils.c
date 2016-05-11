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

bool
bdw_util_strequals (const char * arg1, const char * arg2)
{
  if (strcmp (arg1, arg2) == 0)
    return TRUE;
  return FALSE;
}

void
bdw_util_strchrappend (char * dest, char c)
{
  unsigned short len = strlen (dest);
  dest = realloc (dest, len + 2);
  dest[len + 1] = (char) 0;
  dest[len] = c;
}
