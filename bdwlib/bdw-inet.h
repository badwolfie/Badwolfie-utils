/* bdw-inet.h
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
#ifndef BDW_INET__H
#define BDW_INET__H

#if !defined(__BDWLIB_INSIDE__) && !defined(BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#include "bdw-error.h"
#include "bdw-types.h"

#include <arpa/inet.h>
#include <netinet/in.h>

// clang-format off

#ifdef USING_IPv6
#  define BDW_INET_DOMAIN AF_INET6
#else
#  define BDW_INET_DOMAIN AF_INET
#endif

#ifndef BDW_INET_MAX_CONNECTION_TRIES
#  define BDW_INET_MAX_CONNECTION_TRIES 3
#endif

BDW_BEGIN_DECLS

/**
 * socketid:
 *
 * .
 **/
typedef int socketid;

/**
 * BdwSocketType:
 * @BDW_SOCKET_TYPE_UNKOWN: .
 * @BDW_SOCKET_TYPE_UDP: .
 * @BDW_SOCKET_TYPE_TCP: .
 * @BDW_SOCKET_TYPE_RAW: .
 *
 * .
 **/
typedef enum eBdwSocketType BdwSocketType;
enum eBdwSocketType
{
  BDW_SOCKET_TYPE_UNKOWN,
  BDW_SOCKET_TYPE_UDP = SOCK_DGRAM,
  BDW_SOCKET_TYPE_TCP = SOCK_STREAM,
  BDW_SOCKET_TYPE_RAW = SOCK_RAW
};

/**
 * BdwInetError:
 * @BDW_INET_ERROR_KO: .
 * @BDW_INET_ERROR_OK: .
 * @BDW_INET_ERROR_ALREADY_CONNECTED: .
 * @BDW_INET_ERROR_INVALID_SOCKET: .
 * @BDW_INET_ERROR_NOT_A_SOCKET: .
 * @BDW_INET_ERROR_ADDRESS_NOT_AVAILABLE: .
 * @BDW_INET_ERROR_CONNECTION_REFUSED: .
 * @BDW_INET_ERROR_NETWORK_UNREACHABLE: .
 * @BDW_INET_ERROR_NOT_SUPPORTED: .
 * @BDW_INET_ERROR_TIMEOUT: .
 * @BDW_INET_ERROR_INVALID_ARGUMENT: .
 * @BDW_INET_ERROR_SOCKET_NOT_CONNECTED: .
 * @BDW_INET_ERROR_FAULTY_BUFFER: .
 * @BDW_INET_ERROR_CONNECTION_RESET: .
 * @BDW_INET_ERROR_NO_MEMORY: .
 * @BDW_INET_ERROR_UNDEFINED: .
 *
 * .
 **/
typedef enum eBdwInetError BdwInetError;
enum eBdwInetError
{
  BDW_INET_ERROR_KO = -1,
  BDW_INET_ERROR_OK = 0,
  BDW_INET_ERROR_ALREADY_CONNECTED,
  BDW_INET_ERROR_INVALID_SOCKET,
  BDW_INET_ERROR_NOT_A_SOCKET,
  BDW_INET_ERROR_ADDRESS_NOT_AVAILABLE,
  BDW_INET_ERROR_CONNECTION_REFUSED,
  BDW_INET_ERROR_NETWORK_UNREACHABLE,
  BDW_INET_ERROR_NOT_SUPPORTED,
  BDW_INET_ERROR_TIMEOUT,
  BDW_INET_ERROR_INVALID_ARGUMENT,
  BDW_INET_ERROR_SOCKET_NOT_CONNECTED,
  BDW_INET_ERROR_FAULTY_BUFFER,
  BDW_INET_ERROR_CONNECTION_RESET,
  BDW_INET_ERROR_NO_MEMORY,
  BDW_INET_ERROR_UNDEFINED
};

/**
 * bdw_inet_str_is_ip:
 * @str: .
 * @error: .
 *
 * .
 *
 * Returns: .
 **/
bool           bdw_inet_str_is_ip         (conststring               str,
                                           BdwError                **error);

/**
 * bdw_inet_get_hostname_ip:
 * @hostname: .
 * @error: .
 *
 * .
 *
 * Returns: .
 **/
conststring    bdw_inet_get_hostname_ip   (conststring               hostname,
                                           BdwError                **error);

/**
 * bdw_inet_send_msg:
 * @comm_id: .
 * @socket_type: .
 * @host: .
 * @buffer: .
 * @buffer_length: .
 *
 * .
 *
 * Returns: .
 **/
BdwInetError   bdw_inet_send_msg          (const socketid            comm_id,
                                           const BdwSocketType       socket_type,
                                           const struct sockaddr_in *host,
                                           constpointer              buffer,
                                           size                      buffer_length);

/**
 * bdw_inet_receive_msg:
 * @comm_id: .
 * @socket_type: .
 * @host: .
 * @buffer: .
 * @buffer_length: .
 *
 * .
 *
 * Returns: .
 **/
BdwInetError   bdw_inet_receive_msg       (const socketid            comm_id,
                                           const BdwSocketType       socket_type,
                                           struct sockaddr_in       *host,
                                           pointer                   buffer,
                                           size                      buffer_length);

// clang-format on
BDW_END_DECLS

#endif /* BDW_INET__H */

