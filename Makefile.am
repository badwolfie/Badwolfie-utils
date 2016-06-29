ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

SUBDIRS = docs bdwlib

EXTRA_DIST = \
  autogen.sh \
  bdwlib-1.0.pc.in \
  bdwlib.doap \
  ChangeLog \
  gtk-doc.make \
  INSTALL \
  NEWS \
  README \
  README.md \
  $(NULL)

BUILT_EXTRA_DIST = \
  ChangeLog \
  INSTALL \
  README \
  $(NULL)

ChangeLog:
	$(AM_V_GEN) if test -d "$(srcdir)/.git"; then \
	  cd $(srcdir) && git log --stat --name-only --date=short --abbrev-commit > $@.tmp \
	  && mv -f $@.tmp $@ \
	  || ($(RM) $@.tmp; \
	      echo Failed to generate ChangeLog, your ChangeLog may be outdated >&2; \
	      (test -f $@ || echo git-log is required to generate this file >> $@)); \
	else \
	  test -f $@ || \
	  (echo A git checkout and git-log is required to generate ChangeLog >&2 && \
	  echo A git checkout and git-log is required to generate this file >> $@); \
	fi

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = bdwlib-1.0.pc
$(pkgconfig_DATA): config.status

# build documentation when doing distcheck
DISTCHECK_CONFIGURE_FLAGS = --enable-debug --enable-gtk-doc --enable-man --disable-maintainer-mode

