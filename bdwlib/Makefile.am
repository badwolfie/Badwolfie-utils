lib_LTLIBRARIES = libbdwlib.la

AM_CFLAGS = \
	-Wall -Werror \
	-DBDWLIB_MAJOR_VERSION=@BDWLIB_MAJOR_VERSION@ \
	-DBDWLIB_MINOR_VERSION=@BDWLIB_MINOR_VERSION@ \
	-DBDWLIB_MICRO_VERSION=@BDWLIB_MICRO_VERSION@ \
	-DBDWLIB_VERSION=@BDWLIB_VERSION@ \
	-DBDWLIB_COMPILATION

libbdwlib_la_SOURCES = \
	bdw-array.c \
	bdw-bytearray.c \
	bdw-error.c \
	bdw-file.c \
	bdw-internet.c \
	bdw-internet-client.c \
	bdw-list.c \
	bdw-queue.c \
	bdw-simple-list.c \
	bdw-stack.c \
	bdw-string.c \
	bdw-utils.c

bdwlibincludedir=$(includedir)/bdwlib-1.0
bdwlibinclude_HEADERS = bdwlib.h

bdwlibsubincludedir=$(includedir)/bdwlib-1.0/bdwlib
bdwlibsubinclude_HEADERS = \
	bdw-array.h \
	bdw-bytearray.h \
	bdw-error.h \
	bdw-file.h \
	bdw-internet.h \
	bdw-internet-client.h \
	bdw-list.h \
	bdw-queue.h \
	bdw-simple-list.h \
	bdw-stack.h \
	bdw-string.h \
	bdw-types.h \
	bdw-utils.h \
	bdw-version.h

