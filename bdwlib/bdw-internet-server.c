/* bdw-internet-server.c
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
#include "bdw-internet-server.h"
#include "bdw-utils.h"
#include <unistd.h>

#ifndef BDW_INTERNET_SERVER_MAX_CONNECTIONS
#define BDW_INTERNET_SERVER_MAX_CONNECTIONS 100
#endif

BdwInternetServer *
bdw_internet_server_new (uint16 port, uint16 max_connections,
                         BdwSocketType type)
{
  BdwInternetServer * self = bdw_new (BdwInternetServer);
  bdw_utils_clear_buffer (&self->host, sizeof (self->host));
  self->socket_type = type;

  self->host.sin_family = BDW_INTERNET_DOMAIN;
  self->host.sin_addr.s_addr = htonl (INADDR_ANY);
  self->host.sin_port = htons (port);

  bdw_internet_server_set_max_connections (self, max_connections);

  self->socket_id = socket (BDW_INTERNET_DOMAIN, self->socket_type, 0);
  bdw_error_on_code (self->socket_id, BDW_INTERNET_ERROR_KO, "socket()");

  return self;
}

void
bdw_internet_server_destroy (BdwInternetServer * self)
{
  bdw_free (self);
}

void
bdw_internet_server_set_max_connections (BdwInternetServer * self,
                                         uint16 max_connections)
{
  self->connection_num =
      bdw_utils_truncate (max_connections, BDW_INTERNET_SERVER_MAX_CONNECTIONS);
}

void
bdw_internet_server_deploy (const BdwInternetServer * self)
{
  int status = BDW_INTERNET_ERROR_OK;

  status = bind (self->socket_id, (struct sockaddr *) &self->host,
                 sizeof (self->host));
  bdw_error_on_code (status, BDW_INTERNET_ERROR_KO, "bind()");

  if (self->socket_type == BDW_SOCKET_TYPE_UDP)
    return;

  status = listen (self->socket_id, self->connection_num);
  bdw_error_on_code (status, BDW_INTERNET_ERROR_KO, "listen()");
}

int
bdw_internet_server_wait (const BdwInternetServer * self,
                          struct sockaddr_in * client)
{
  if (self->socket_type == BDW_SOCKET_TYPE_UDP) {
    bdw_error_report ("UDP Servers don't need to wait for connections, proceed "
                      "to receive messages.");
    return self->socket_id;
  }

  socklen_t client_len = sizeof (*client);
  int channel;

  channel = accept (self->socket_id, (struct sockaddr *) client, &client_len);
  bdw_error_on_code (channel, BDW_INTERNET_ERROR_KO, "accept()");
  return channel;
}

void
bdw_internet_server_shutdown (BdwInternetServer * self)
{
  bdw_utils_clear_buffer (&self->host, sizeof (self->host));
  close (self->socket_id);
}
