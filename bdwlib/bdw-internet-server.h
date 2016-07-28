/* bdw-internet-server.h
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
#ifndef BDW_INTERNET_SERVER__H
#define BDW_INTERNET_SERVER__H

#if !defined(__BDWLIB_INSIDE__) && !defined(BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#include "bdw-internet.h"

typedef struct _BdwInternetServer BdwInternetServer;
struct _BdwInternetServer
{
  socketid socket_id;
  uint16 connection_num;
  struct sockaddr_in host;
  BdwSocketType socket_type;
};

BdwInternetServer * bdw_internet_server_new (uint16 port,
                                             uint16 max_connections,
                                             BdwSocketType type);

void bdw_internet_server_destroy (BdwInternetServer * self);

void bdw_internet_server_set_max_connections (BdwInternetServer * self,
                                              uint16 max_connections);

void bdw_internet_server_deploy (const BdwInternetServer * self);

int bdw_internet_server_wait (const BdwInternetServer * self);

void bdw_internet_server_shutdown (BdwInternetServer * self);

#endif /* BDW_INTERNET_SERVER__H */
