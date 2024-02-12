#!/usr/bin/make -f

#SUBDIRS :=

all:
	# Desktop file
	(cd lubuntu/po/ && make)
	(cd ubuntustudio/po/ && make)
	(cd kubuntu/po/ && make)
	# Slideshow
	(cd lubuntu/branding/lubuntu/lang/ && make)
	(cd ubuntustudio/branding/ubuntustudio/lang && make)
	# Kubuntu OEM setup stuff
	(cd kubuntu && mkdir oemconfig && cd oemconfig && mkdir -p usr/bin && mkdir -p etc/calamares && mkdir -p usr/share/xsessions && mkdir -p usr/libexec && mkdir -p etc && mkdir -p usr/share/applications)
	(cp kubuntu/calamares-logs-helper kubuntu/oemconfig/usr/bin/)
	(cp kubuntu/oem/sddm.conf kubuntu/oemconfig/etc/)
	(cp kubuntu/oem/sudoers.oem kubuntu/oemconfig/etc/ && chmod 400 kubuntu/oemconfig/etc/sudoers.oem)
	(cp kubuntu/oem/calamares-oemfinish.sh kubuntu/oemconfig/usr/libexec/)
	(cp kubuntu/oem/calamares-finish-oem kubuntu/oemconfig/usr/bin/)
	(cp kubuntu/oem/calamares-finish-oem.desktop kubuntu/oemconfig/usr/share/applications/)
	(cp -r kubuntu/branding kubuntu/oemconfig/etc/calamares/)
	(cp -r kubuntu/oem/modules/ kubuntu/oemconfig/etc/calamares/)
	(cp kubuntu/oem/settings.conf kubuntu/oemconfig/etc/calamares/)
	(cp kubuntu/oem/kubuntu-oem-env/kubuntu-oem-environment.desktop kubuntu/oemconfig/usr/share/xsessions/)
	(cp kubuntu/oem/kubuntu-oem-env/start-kubuntu-oem-env kubuntu/oemconfig/usr/libexec/)
	(fakeroot bash -c "chown -R root:root kubuntu/oemconfig && tar cvzf kubuntu/oemconfig.tar.gz kubuntu/oemconfig")
	# Get rid of the unnecessary files
	find lubuntu/ -type f -iname "*.in" | xargs rm -f
	find lubuntu/ -type f -iname "Makefile" | xargs rm -f
	find ubuntustudio/ -type f -iname "*.in" | xargs rm -f
	find ubuntustudio/ -type f -iname "Makefile" | xargs rm -f
	find kubuntu/ -type f -iname "*.in" | xargs rm -f
	find kubuntu/ -type f -iname "Makefile" | xargs rm -f
	rm -rf kubuntu/oemconfig
# vim:ts=4
