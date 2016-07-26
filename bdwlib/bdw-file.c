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
#include "bdw-file.h"
#include "bdw-string.h"

static conststring bdw_file_get_file_args (BdwFileMode mode, BdwFileType type);

BdwFile *
bdw_file_new (conststring location)
{
  BdwFile * self = bdw_new (BdwFile);
  self->location = bdw_strdup (location);
  self->file = NULL;
  return self;
}

void
bdw_file_destroy (BdwFile * self)
{
  if (self == NULL)
    return;

  if (self->file != NULL)
    fclose (self->file);

  bdw_free (self->location);
  bdw_free (self);
}

BdwFileError
bdw_file_open (BdwFile * self, BdwFileType type, BdwFileMode mode)
{
  if (self == NULL)
    return BDW_FILE_ERROR_NOT_INITIALIZED;

  if (self->location == NULL)
    return BDW_FILE_ERROR_INVALID_LOCATION;

  if (self->file != NULL)
    return BDW_FILE_ERROR_ALREADY_OPENED;

  conststring file_args = bdw_file_get_file_args (mode, type);
  if (file_args == NULL)
    return BDW_FILE_ERROR_BAD_ARGUMENTS;

  self->file = fopen (self->location, file_args);
  if (self->file == NULL)
    return BDW_FILE_ERROR_FATAL;
  return BDW_FILE_ERROR_OK;
}

string
bdw_file_getline (BdwFile * self)
{
  string str_line = NULL;
  sizetype size = 0;

  int status = getline (&str_line, &size, self->file);
  if (status == -1)
    return NULL;

  bdw_strtrim (str_line, "\n");
  return str_line;
}

static conststring
bdw_file_get_file_args (BdwFileMode mode, BdwFileType type)
{
  string file_args, aux;

  switch (mode) {
    default:
    case BDW_FILE_MODE_NONE:
      return NULL;
    case BDW_FILE_MODE_READ:
      file_args = bdw_strdup ("r");
      break;
    case BDW_FILE_MODE_READ_PLUS:
      file_args = bdw_strdup ("r+");
      break;
    case BDW_FILE_MODE_WRITE:
      file_args = bdw_strdup ("w");
      break;
    case BDW_FILE_MODE_WRITE_PLUS:
      file_args = bdw_strdup ("w+");
      break;
    case BDW_FILE_MODE_APPEND:
      file_args = bdw_strdup ("a");
      break;
    case BDW_FILE_MODE_APPEND_PLUS:
      file_args = bdw_strdup ("a+");
      break;
  }

  aux = file_args;

  switch (type) {
    default:
    case BDW_FILE_TYPE_NONE:
      break;
    case BDW_FILE_TYPE_BINARY:
      file_args = bdw_strconcat (aux, "b");
    case BDW_FILE_TYPE_TEXT:
      file_args = bdw_strconcat (aux, "t");
  }

  bdw_free (aux);
  return file_args;
}
