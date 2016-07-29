/* bdw-version.c
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
#include "bdw-version.h"
#include "bdw-string.h"

bool
bdwlib_check_version (uint64 major, uint64 minor, uint64 micro)
{
  if ((BDWLIB_MAJOR_VERSION > major) ||
      ((BDWLIB_MAJOR_VERSION == major) && (BDWLIB_MINOR_VERSION > minor)) ||
      ((BDWLIB_MAJOR_VERSION == major) && (BDWLIB_MINOR_VERSION == minor) &&
       (BDWLIB_MICRO_VERSION >= micro)))
    return TRUE;
  return FALSE;
}

conststring
bdwlib_compilation_date (void)
{
  return bdw_strdup (__DATE__);
}

conststring
bdwlib_compilation_time (void)
{
  return bdw_strdup (__TIME__);
}

conststring
bdwlib_compilation_datetime (void)
{
  return bdw_strconcat (bdwlib_compilation_date (), bdwlib_compilation_time (),
                        NULL);
}
