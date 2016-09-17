lib_LTLIBRARIES = libbdwlib.la

AM_CFLAGS = 										\
	-DBDWLIB_MAJOR_VERSION=@BDWLIB_MAJOR_VERSION@ 	\
	-DBDWLIB_MINOR_VERSION=@BDWLIB_MINOR_VERSION@ 	\
	-DBDWLIB_MICRO_VERSION=@BDWLIB_MICRO_VERSION@ 	\
	-DBDWLIB_VERSION=@BDWLIB_VERSION@ 				\
	-DBDWLIB_COMPILATION 							\
	-Wall 											\
	-Wcast-align 									\
	-Wdeclaration-after-statement 					\
	-Werror=format-security 						\
	-Werror=format=2 								\
	-Wextra 										\
	-Wformat-nonliteral 							\
	-Wformat-security 								\
	-Wmissing-include-dirs 							\
	-Wnested-externs 								\
	-Wno-missing-field-initializers 				\
	-Wno-sign-compare 								\
	-Wno-strict-aliasing 							\
	-Wno-uninitialized 								\
	-Wno-unused-parameter 							\
	-Wpointer-arith 								\
	-Wredundant-decls 								\
	-Wshadow 										\
	-Wswitch-default 								\
	-Wswitch-enum 									\
	-Wundef 										\
	-Werror

libbdwlib_la_SOURCES = 	\
	bdw-array.c 		\
	bdw-bytearray.c 	\
	bdw-error.c 		\
	bdw-file.c 			\
	bdw-inet.c 			\
	bdw-inet-client.c 	\
	bdw-inet-server.c 	\
	bdw-list.c 			\
	bdw-memory.c 		\
	bdw-queue.c 		\
	bdw-simple-list.c	\
	bdw-stack.c 		\
	bdw-string.c 		\
	bdw-utils.c 		\
	bdw-version.c

bdwlibincludedir=$(includedir)/bdwlib-1.0
bdwlibinclude_HEADERS = bdwlib.h

bdwlibsubincludedir=$(includedir)/bdwlib-1.0/bdwlib
bdwlibsubinclude_HEADERS = 	\
	bdw-array.h 			\
	bdw-bytearray.h 		\
	bdw-error.h 			\
	bdw-file.h 				\
	bdw-inet.h 				\
	bdw-inet-client.h 		\
	bdw-inet-server.h 		\
	bdw-list.h 				\
	bdw-macros.h 			\
	bdw-memory.h 			\
	bdw-queue.h 			\
	bdw-simple-list.h 		\
	bdw-stack.h 			\
	bdw-string.h 			\
	bdw-types.h 			\
	bdw-utils.h 			\
	bdw-version.h

