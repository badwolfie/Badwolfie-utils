/* bdw-inet-server.c
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
#include "bdw-inet-server.h"
#include "bdw-memory.h"
#include "bdw-utils.h"

#include <unistd.h>

#define BDW_INET_SERVER_MAX_CONNECTIONS 100

BdwInetServer *
bdw_inet_server_new (uint16 port, uint16 max_connections, BdwSocketType type)
{
  BdwInetServer *self = bdw_new (BdwInetServer);
  bdw_utils_clear_buffer (&self->host, sizeof (self->host));
  self->socket_type = type;

  self->host.sin_family = BDW_INET_DOMAIN;
  self->host.sin_addr.s_addr = htonl (INADDR_ANY);
  self->host.sin_port = htons (port);

  bdw_inet_server_set_max_connections (self, max_connections);

  self->socket_id = socket (BDW_INET_DOMAIN, self->socket_type, 0);
  bdw_error_on_code (self->socket_id, BDW_INET_ERROR_KO, "socket()");

  return self;
}

void
bdw_inet_server_destroy (BdwInetServer *self)
{
  bdw_free (self);
}

void
bdw_inet_server_set_max_connections (BdwInetServer *self,
                                     uint16         max_connections)
{
  self->connection_num = TRUNCATE (max_connections,
                                   BDW_INET_SERVER_MAX_CONNECTIONS);
}

void
bdw_inet_server_deploy (const BdwInetServer *self)
{
  int status = BDW_INET_ERROR_OK;

  status = bind (self->socket_id, (struct sockaddr *) &self->host,
                 sizeof (self->host));
  bdw_error_on_code (status, BDW_INET_ERROR_KO, "bind()");

  if (self->socket_type == BDW_SOCKET_TYPE_UDP)
    return;

  status = listen (self->socket_id, self->connection_num);
  bdw_error_on_code (status, BDW_INET_ERROR_KO, "listen()");
}

int
bdw_inet_server_wait (const BdwInetServer *self, struct sockaddr_in *client)
{
  int       channel;
  socklen_t client_len = sizeof (*client);

  if (self->socket_type == BDW_SOCKET_TYPE_UDP)
  {
    bdw_error_report ("UDP Servers don't need to wait for connections, proceed "
                      "to receive messages.");
    return self->socket_id;
  }

  channel = accept (self->socket_id, (struct sockaddr *) client, &client_len);
  bdw_error_on_code (channel, BDW_INET_ERROR_KO, "accept()");
  return channel;
}

void
bdw_inet_server_shutdown (BdwInetServer *self)
{
  bdw_utils_clear_buffer (&self->host, sizeof (self->host));
  close (self->socket_id);
}
