/* bdw-version.h
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
#ifndef BDW_VERSION__H
#define BDW_VERSION__H

#if !defined(__BDWLIB_INSIDE__) && !defined(BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#define bdwlib_check_version(major, minor, micro)                              \
  ((BDWLIB_MAJOR_VERSION > major) ||                                           \
   ((BDWLIB_MAJOR_VERSION == major) && (BDWLIB_MINOR_VERSION > minor)) ||      \
   ((BDWLIB_MAJOR_VERSION == major) && (BDWLIB_MINOR_VERSION == minor) &&      \
    (BDWLIB_MICRO_VERSION >= micro)))

#endif /* BDW_VERSION__H */
