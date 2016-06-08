# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.62])

m4_define(bdwlib_configure_ac)

m4_define([bdwlib_major_version], [1])
m4_define([bdwlib_minor_version], [0])
m4_define([bdwlib_micro_version], [0])
m4_define([bdwlib_version],
          [bdwlib_major_version.bdwlib_minor_version.bdwlib_micro_version])

AC_INIT (bdwlib, [bdwlib_version], [https://github.com/badwolfie/bdwlib/issues])

# AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([bdwlib/bdwlib.h])
AC_CONFIG_MACRO_DIR([m4])
# AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([1.11 -Wno-portability no-define no-dist-gzip dist-xz tar-ustar])
AM_MAINTAINER_MODE([enable])

AM_SILENT_RULES([yes])

BDWLIB_MAJOR_VERSION=bdwlib_major_version
BDWLIB_MINOR_VERSION=bdwlib_minor_version
BDWLIB_MICRO_VERSION=bdwlib_micro_version
BDWLIB_VERSION=bdwlib_version

AC_SUBST(BDWLIB_MAJOR_VERSION)
AC_SUBST(BDWLIB_MINOR_VERSION)
AC_SUBST(BDWLIB_MICRO_VERSION)
AC_SUBST(BDWLIB_VERSION)

AC_DEFINE(BDWLIB_MAJOR_VERSION, [bdwlib_major_version], 
          [Define to the BdwLib major version])
AC_DEFINE(BDWLIB_MINOR_VERSION, [bdwlib_minor_version], 
          [Define to the BdwLib minor version])
AC_DEFINE(BDWLIB_MICRO_VERSION, [bdwlib_micro_version], 
          [Define to the BdwLib micro version])

AC_PROG_CC

m4_ifdef([GTK_DOC_CHECK], [
GTK_DOC_CHECK([1.20], [--flavour no-tmpl])
],[
AM_CONDITIONAL([ENABLE_GTK_DOC],[false])
])

bdwlib_INCLUDES='-I(top_srcdir)/bdwlib -I$(top_srcdir)'
AC_SUBST(bdwlib_INCLUDES)

AC_CONFIG_FILES([
  Makefile
  bdwlib/Makefile
  docs/Makefile
  docs/reference/Makefile
  docs/reference/bdwlib/Makefile
  docs/reference/bdwlib/version.xml
])

AC_OUTPUT
