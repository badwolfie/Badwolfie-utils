ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

SUBDIRS = . bdwlib docs

EXTRA_DIST += \
  autogen.sh \
  bdwlib.doap \
  ChangeLog \
  INSTALL \
  NEWS \
  README \
  README.md \
  $(NULL)

BUILT_EXTRA_DIST += \
  ChangeLog \
  INSTALL \
  README \
  $(NULL)
 
ChangeLog:
	$(AM_V_GEN) if test -d "$(srcdir)/.git"; then \
	  (GIT_DIR=$(top_srcdir)/.git ./missing --run git log GLIB_2_20_0^^.. --stat) | fmt --split-only > $@.tmp \
	  && mv -f $@.tmp $@ \
	  || ($(RM) $@.tmp; \
	      echo Failed to generate ChangeLog, your ChangeLog may be outdated >&2; \
	      (test -f $@ || echo git-log is required to generate this file >> $@)); \
	else \
	  test -f $@ || \
	  (echo A git checkout and git-log is required to generate ChangeLog >&2 && \
	  echo A git checkout and git-log is required to generate this file >> $@); \
	fi

# build documentation when doing distcheck
DISTCHECK_CONFIGURE_FLAGS = --enable-debug --enable-gtk-doc --enable-man --disable-maintainer-mode

