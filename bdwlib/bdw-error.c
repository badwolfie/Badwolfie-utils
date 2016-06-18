/* bdw-error.c
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
#include <stdarg.h>
#include <stdio.h>
#include <errno.h>

#include "bdw-error.h"
#include "bdw-string.h"
#include "bdw-utils.h"

static char aux_buffer[1024];

BdwError *
bdw_error_new (int64 code, conststring format, ...)
{
  BdwError * self = bdw_new (BdwError);
  self->message = NULL;
  self->code = code;

  va_list arglist;
  va_start (arglist, format);

  bdw_utils_clear_buffer (aux_buffer, sizeof (aux_buffer));
  vsprintf (aux_buffer, format, arglist);

  self->message = bdw_strdup (aux_buffer);
  return self;
}

BdwError *
bdw_error_new_no_format (int64 code, conststring format)
{
  BdwError * self = bdw_new (BdwError);
  self->message = bdw_strdup (aux_buffer);
  self->code = code;
  return self;
}

void
bdw_error_destroy (BdwError * self)
{
  if (self == NULL)
    return ;

  bdw_free (self->message);
  bdw_free (self);
}

void
bdw_error_report (conststring format, ...)
{
  va_list arglist;
  va_start (arglist, format);

  bdw_utils_clear_buffer (aux_buffer, sizeof (aux_buffer));
  vsprintf (aux_buffer, format, arglist);

  printf ("%s", aux_buffer);
  exit (1);
}

void
bdw_error_on_code (int64 return_value,
                   int64 expected_error_code,
                   conststring message)
{
  if (return_value == expected_error_code) {
    printf ("%s \nERROR: %s", message, bdw_strerror (errno));
    exit (1);
  }
}

void
bdw_error_on_null (pointer return_value, conststring message)
{
  if (return_value == NULL) {
    printf ("%s \nERROR: %s", message, bdw_strerror (errno));
    exit (1);
  }
}

