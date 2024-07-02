XPROTO_VERSION := 7.0.29

XPROTO_URL := $(XORG)/proto/xproto-$(XPROTO_VERSION).tar.bz2

$(TARBALLS)/xproto-$(XPROTO_VERSION).tar.bz2:
	$(call download_pkg,$(XPROTO_URL),xcb)

ifeq ($(call need_pkg,"xproto"),)
PKGS_FOUND += xproto
endif

.sum-xproto: xproto-$(XPROTO_VERSION).tar.bz2

xproto: xproto-$(XPROTO_VERSION).tar.bz2 .sum-xproto
	$(UNPACK)
	$(call update_autoconfig,.)
	$(MOVE)

DEPS_xproto = xorg-macros $(DEPS_xorg-macros)

XPROTO_CONF := --enable-xthreads

.xproto: xproto
	$(MAKEBUILDDIR)
	$(MAKECONFIGURE) $(XPROTO_CONF)
	+$(MAKEBUILD)
	+$(MAKEBUILD) install
	touch $@
