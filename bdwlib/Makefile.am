lib_LTLIBRARIES = libbdwlib.la

AM_CFLAGS = \
	$(WARN_CFLAGS) \
	-DBDWLIB_MAJOR_VERSION=@BDWLIB_MAJOR_VERSION@ \
	-DBDWLIB_MINOR_VERSION=@BDWLIB_MINOR_VERSION@ \
	-DBDWLIB_MICRO_VERSION=@BDWLIB_MICRO_VERSION@ \
	-DBDWLIB_VERSION=@BDWLIB_VERSION@ \
	-DBDWLIB_COMPILATION

libbdwlib_la_SOURCES = \
	bdw-array.c \
	bdw-bytearray.c \
	bdw-file.c \
	bdw-list.c \
	bdw-queue.c \
	bdw-simple-list.c \
	bdw-stack.c \
	bdw-static-queue.c \
	bdw-static-stack.c \
	bdw-string-utils.c

bdwlibincludedir=$(includedir)/bdwlib-1.0
bdwlibinclude_HEADERS = bdwlib.h

bdwlibsubincludedir=$(includedir)/bdwlib-1.0/bdwlib
bdwlibsubinclude_HEADERS = \
	bdw-array.h \
	bdw-bytearray.h \
	bdw-file.h \
	bdw-list.h \
	bdw-queue.h \
	bdw-simple-list.h \
	bdw-stack.h \
	bdw-static-queue.h \
	bdw-static-stack.h \
	bdw-string-utils.h \
	bdw-types.h \
	bdw-version.h

