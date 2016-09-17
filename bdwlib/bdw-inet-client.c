/* bdw-inet-client.c
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
#include "bdw-inet-client.h"
#include "bdw-memory.h"
#include "bdw-utils.h"

#include <stdlib.h>
#include <unistd.h>

BdwInetClient *
bdw_inet_client_new (conststring host, uint16 port, BdwSocketType type)
{
  BdwInetClient *self = bdw_new (BdwInetClient);
  bdw_utils_clear_buffer (&self->host, sizeof (self->host));
  self->socket_type = type;

  self->host.sin_family = BDW_INET_DOMAIN;
  self->host.sin_port = htons (port);

  bdw_inet_client_set_host (self, host);

  self->socket_id = socket (BDW_INET_DOMAIN, self->socket_type, 0);
  bdw_error_on_code (self->socket_id, BDW_INET_ERROR_KO, "socket()");

  return self;
}

void
bdw_inet_client_destroy (BdwInetClient *self)
{
  bdw_free (self);
}

void
bdw_inet_client_set_host (BdwInetClient *self, conststring host)
{
  conststring real_host;
  BdwError *  inner_error = NULL;
  bool        host_is_ip = bdw_inet_str_is_ip (host, &inner_error);
  if (inner_error != NULL)
  {
    bdw_error_report ("%s\n", inner_error->message);
    bdw_error_destroy (inner_error);
    exit (1);
  }

  if (!host_is_ip)
  {
    real_host = bdw_inet_get_hostname_ip (host, &inner_error);
    if (inner_error != NULL)
    {
      bdw_error_report ("%s\n", inner_error->message);
      bdw_error_destroy (inner_error);
      exit (1);
    }
  }
  else
  {
    real_host = host;
  }

#ifdef USING_IPv6
#error "IPv6 not fully supported yet."
#else
  self->host.sin_addr.s_addr = inet_addr (real_host);
#endif
}

BdwInetError
bdw_inet_client_connect (const BdwInetClient *self, uint8 tries)
{
  int8  try_number = 0;
  int64 status = BDW_INET_ERROR_OK;

  if (self->socket_type == BDW_SOCKET_TYPE_UDP)
    return BDW_INET_ERROR_OK;

  while (try_number < TRUNCATE (tries, BDW_INET_MAX_CONNECTION_TRIES))
  {
    status = connect (self->socket_id,
                      (struct sockaddr *) &self->host,
                      sizeof (self->host));
    try_number++;
  }

  if (status == BDW_INET_ERROR_KO)
  {
    switch (errno)
    {
    case EISCONN:
      return BDW_INET_ERROR_ALREADY_CONNECTED;

    case EBADF:
      return BDW_INET_ERROR_INVALID_SOCKET;

    case ENOTSOCK:
      return BDW_INET_ERROR_NOT_A_SOCKET;

    case EADDRNOTAVAIL:
      return BDW_INET_ERROR_ADDRESS_NOT_AVAILABLE;

    case ECONNREFUSED:
      return BDW_INET_ERROR_CONNECTION_REFUSED;

    case ENETUNREACH:
      return BDW_INET_ERROR_NETWORK_UNREACHABLE;

    case EPROTOTYPE:
      return BDW_INET_ERROR_NOT_SUPPORTED;

    case ETIMEDOUT:
      return BDW_INET_ERROR_TIMEOUT;

    default:
      return BDW_INET_ERROR_UNDEFINED;
    }
  }

  return BDW_INET_ERROR_OK;
}

void
bdw_inet_client_shutdown (BdwInetClient *self)
{
  bdw_utils_clear_buffer (&self->host, sizeof (self->host));
  close (self->socket_id);
}
