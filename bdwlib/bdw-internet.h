/* bdw-internet.h
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
#ifndef BDW_INTERNET__H
#define BDW_INTERNET__H

#if !defined(__BDWLIB_INSIDE__) && !defined(BDWLIB_COMPILATION)
#error "Only <bdwlib.h> can be included directly."
#endif

#include <arpa/inet.h>
#include <netinet/in.h>

#include "bdw-error.h"
#include "bdw-types.h"

#ifdef USING_IPv6
#define BDW_INTERNET_DOMAIN AF_INET6
#else
#define BDW_INTERNET_DOMAIN AF_INET
#endif

#ifndef BDW_INTERNET_MAX_CONNECTION_TRIES
#define BDW_INTERNET_MAX_CONNECTION_TRIES 3
#endif

typedef enum {
  BDW_SOCKET_TYPE_UNKOWN,
  BDW_SOCKET_TYPE_UDP = SOCK_DGRAM,
  BDW_SOCKET_TYPE_TCP = SOCK_STREAM,
  BDW_SOCKET_TYPE_RAW = SOCK_RAW
} BdwSocketType;

typedef enum {
  BDW_INTERNET_ERROR_KO = -1,
  BDW_INTERNET_ERROR_OK = 0,
  BDW_INTERNET_ERROR_ALREADY_CONNECTED,
  BDW_INTERNET_ERROR_INVALID_SOCKET,
  BDW_INTERNET_ERROR_NOT_A_SOCKET,
  BDW_INTERNET_ERROR_ADDRESS_NOT_AVAILABLE,
  BDW_INTERNET_ERROR_CONNECTION_REFUSED,
  BDW_INTERNET_ERROR_NETWORK_UNREACHABLE,
  BDW_INTERNET_ERROR_NOT_SUPPORTED,
  BDW_INTERNET_ERROR_TIMEOUT,
  BDW_INTERNET_ERROR_INVALID_ARGUMENT,
  BDW_INTERNET_ERROR_SOCKET_NOT_CONNECTED,
  BDW_INTERNET_ERROR_FAULTY_BUFFER,
  BDW_INTERNET_ERROR_CONNECTION_RESET,
  BDW_INTERNET_ERROR_NO_MEMORY,
  BDW_INTERNET_ERROR_UNDEFINED
} BdwInternetError;

bool bdw_internet_str_is_ip (conststring str, BdwError ** error);

conststring bdw_internet_get_hostname_ip (conststring hostname,
                                          BdwError ** error);

#endif /* BDW_INTERNET__H */
