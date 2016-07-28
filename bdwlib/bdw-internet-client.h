/* bdw-internet-client.h
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
#ifndef BDW_INTERNET_CLIENT__H
#define BDW_INTERNET_CLIENT__H

#if !defined(__BDWLIB_INSIDE__) && !defined(BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#include "bdw-internet.h"

typedef struct _BdwInternetClient BdwInternetClient;
struct _BdwInternetClient
{
  socketid socket_id;
  struct sockaddr_in host;
  BdwSocketType socket_type;
};

BdwInternetClient * bdw_internet_client_new (conststring host, uint16 port,
                                             BdwSocketType type);

void bdw_internet_client_destroy (BdwInternetClient * self);

void bdw_internet_client_set_host (BdwInternetClient * self, conststring host);

BdwInternetError bdw_internet_client_connect (const BdwInternetClient * self,
                                              uint8 tries);

void bdw_internet_client_shutdown (BdwInternetClient * self);

#endif /* BDW_INTERNET_CLIENT__H */
