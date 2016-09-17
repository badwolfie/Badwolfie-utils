/* bdw-inet-server.h
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
#ifndef BDW_INET_SERVER__H
#define BDW_INET_SERVER__H

#if !defined(__BDWLIB_INSIDE__) && !defined(BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#include "bdw-inet.h"

BDW_BEGIN_DECLS
// clang-format off

/**
 * BdwInetServer:
 * @socket_id: .
 * @connection_num: .
 * @host: .
 * @socket_type: .
 *
 * .
 **/
typedef struct _BdwInetServer BdwInetServer;
struct _BdwInetServer
{
  socketid           socket_id;
  uint16             connection_num;
  struct sockaddr_in host;
  BdwSocketType      socket_type;
};

/**
 * bdw_inet_server_new:
 * @port: .
 * @max_connections: .
 * @type: .
 *
 * .
 *
 * Returns: .
 **/
BdwInetServer   *bdw_inet_server_new                   (uint16               port,
                                                        uint16               max_connections,
                                                        BdwSocketType        type);

/**
 * bdw_inet_server_destroy:
 * @self: .
 *
 * .
 **/
void             bdw_inet_server_destroy               (BdwInetServer       *self);

/**
 * bdw_inet_server_set_max_connections:
 * @self: .
 * @max_connections: .
 *
 * .
 **/
void             bdw_inet_server_set_max_connections   (BdwInetServer       *self,
                                                        uint16               max_connections);

/**
 * bdw_inet_server_deploy:
 * @self: .
 *
 * .
 **/
void             bdw_inet_server_deploy                (const BdwInetServer *self);

/**
 * bdw_inet_server_wait:
 * @self: .
 * @client: .
 *
 * .
 *
 * Returns: .
 **/
int              bdw_inet_server_wait                  (const BdwInetServer *self,
                                                        struct sockaddr_in  *client);

/**
 * bdw_inet_server_shutdown:
 * @self: .
 *
 * .
 **/
void             bdw_inet_server_shutdown              (BdwInetServer       *self);

// clang-format on
BDW_END_DECLS

#endif /* BDW_INET_SERVER__H */

