/* bdw-internet.c
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
#include <netdb.h>

#include "bdw-internet.h"
#include "bdw-string.h"

bool
bdw_internet_str_is_ip (conststring str, BdwError ** error)
{
  if (error != NULL)
    bdw_free (*error);
  *error = NULL;

#ifdef USING_IPv6
  struct in6_addr output;
#else
  struct in_addr output;
#endif

  int result;
  result = inet_pton (BDW_INTERNET_DOMAIN, str, &output);

  switch (result) {
    case -1:
      *error =
          bdw_error_new (errno, "ERROR (inet_pton): %s", bdw_strerror (errno));
    default:
    case 0:
      return FALSE;
    case 1:
      return TRUE;
  }
}

conststring
bdw_internet_get_hostname_ip (conststring hostname, BdwError ** error)
{
  if (error != NULL)
    bdw_free (*error);
  *error = NULL;

  struct hostent * host;
  struct in_addr ** addr_list;

  conststring ip;
  short i;

  host = gethostbyname (hostname);
  if (host == NULL) {
    *error = bdw_error_new (errno, "ERROR (gethostbyname): %s",
                            bdw_strerror (errno));
    return NULL;
  }

  addr_list = (struct in_addr **) host->h_addr_list;
  for (i = 0; addr_list[i] != NULL; i++) {
    ip = bdw_strdup (inet_ntoa (*addr_list[i]));
    return ip;
  }

  *error = bdw_error_new_no_format (BDW_INTERNET_ERROR_KO,
                                    "ERROR: invalid hostname.");
  return NULL;
}
