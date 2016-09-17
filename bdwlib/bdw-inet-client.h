/* bdw-inet-client.h
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
#ifndef BDW_INET_CLIENT__H
#define BDW_INET_CLIENT__H

#if !defined(__BDWLIB_INSIDE__) && !defined(BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#include "bdw-inet.h"

BDW_BEGIN_DECLS
// clang-format off

/**
 * BdwInetClient:
 * @socket_id: .
 * @host: .
 * @socket_type: .
 *
 * .
 **/
typedef struct _BdwInetClient BdwInetClient;
struct _BdwInetClient
{
  socketid           socket_id;
  struct sockaddr_in host;
  BdwSocketType      socket_type;
};

/**
 * bdw_inet_client_new:
 * @host: .
 * @port: .
 * @type: .
 *
 * .
 *
 * Returns: .
 **/
BdwInetClient   *bdw_inet_client_new        (conststring          host,
                                             uint16               port,
                                             BdwSocketType        type);

/**
 * bdw_inet_client_destroy:
 * @self: .
 *
 * .
 **/
void             bdw_inet_client_destroy    (BdwInetClient       *self);

/**
 * bdw_inet_client_set_host:
 * @self: .
 * @host: .
 *
 * .
 **/
void             bdw_inet_client_set_host   (BdwInetClient       *self,
                                             conststring          host);

/**
 * bdw_inet_client_connect:
 * @self: .
 * @tries: .
 *
 * .
 *
 * Returns: .
 **/
BdwInetError     bdw_inet_client_connect    (const BdwInetClient *self,
                                             uint8                tries);

/**
 * bdw_inet_client_shutdown:
 * @self: .
 *
 * .
 *
 * Returns: .
 **/
void             bdw_inet_client_shutdown   (BdwInetClient       *self);

// clang-format on
BDW_END_DECLS

#endif /* BDW_INET_CLIENT__H */

