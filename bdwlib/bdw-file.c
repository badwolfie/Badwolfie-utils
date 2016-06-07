/* bdw-file.c
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
#include <stdio.h>

#include "bdw-file.h"
#include "bdw-utility.h"

struct _BdwFile
{
  FILE * file;
  conststring location;
  BdwFileMode mode;
  BdwFileType type;
};

BdwFile *
bdw_file_new (conststring location)
{
  BdwFile * self = (BdwFile *) malloc (sizeof (BdwFile));
  self->location = bdw_strcopy (location);
  self->file = NULL;
}

void
bdw_file_destroy (BdwFile * self)
{
  if (self == NULL)
    return ;

  if (self->file != NULL)
    fclose (self->file);

  if (self->location != NULL)
    free (self->location);

  free (self);
}

bool
bdw_file_open (BdwFile * self, BdwFileType type, BdwFileMode mode)
{
}

string
bdw_file_getline (BdwFile * self)
{
  string str_line = NULL;
  size_t size = 0;

  int status = getline (&str_line, &size, self->file);
  if (status == -1)
  {
    return NULL;
  }

  bdw_strtrim (str_line, "\n");
  return str_line;
}

