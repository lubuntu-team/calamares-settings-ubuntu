#!/usr/bin/make -f

#SUBDIRS :=

all:
	# Desktop file
	(cd lubuntu/po/ && make)
	(cd kubuntu/po/ && make)
	# Slideshow
	(cd lubuntu/branding/lubuntu/lang/ && make)
	# basicwallpaper
	(cd common/basicwallpaper && mkdir build && cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && make)
	# Lubuntu OEM setup stuff
	(cd lubuntu && mkdir oemconfig && cd oemconfig && mkdir -p usr/bin && mkdir -p etc/calamares && mkdir -p usr/share/xsessions && mkdir -p usr/libexec && mkdir -p etc && mkdir -p usr/share/applications)
	(cp lubuntu/calamares-logs-helper lubuntu/oemconfig/usr/bin/)
	(cp lubuntu/oem/sddm.conf lubuntu/oemconfig/etc/)
	(cp lubuntu/oem/sudoers.oem lubuntu/oemconfig/etc/ && chmod 400 lubuntu/oemconfig/etc/sudoers.oem)
	(cp lubuntu/oem/calamares-oemfinish.sh lubuntu/oemconfig/usr/libexec/)
	(cp lubuntu/oem/calamares-finish-oem lubuntu/oemconfig/usr/bin/)
	(cp lubuntu/oem/calamares-finish-oem.desktop lubuntu/oemconfig/usr/share/applications/)
	(cp -r lubuntu/branding lubuntu/oemconfig/etc/calamares/)
	(cp -r lubuntu/oem/modules/ lubuntu/oemconfig/etc/calamares/)
	(cp lubuntu/oem/settings.conf lubuntu/oemconfig/etc/calamares/)
	(cp lubuntu/oem/lubuntu-oem-env/lubuntu-oem-environment.desktop lubuntu/oemconfig/usr/share/xsessions/)
	(cp lubuntu/oem/lubuntu-oem-env/start-lubuntu-oem-env lubuntu/oemconfig/usr/libexec/)
	(cp common/basicwallpaper/build/basicwallpaper lubuntu/oemconfig/usr/bin/)
	(fakeroot bash -c "chown -R root:root lubuntu/oemconfig && tar cvzf lubuntu/oemconfig.tar.gz lubuntu/oemconfig")
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
	(cp common/basicwallpaper/build/basicwallpaper kubuntu/oemconfig/usr/bin/)
	(fakeroot bash -c "chown -R root:root kubuntu/oemconfig && tar cvzf kubuntu/oemconfig.tar.gz kubuntu/oemconfig")
	# Get rid of the unnecessary files
	find lubuntu/ -type f -iname "*.in" | xargs rm -f
	find lubuntu/ -type f -iname "Makefile" | xargs rm -f
	find kubuntu/ -type f -iname "*.in" | xargs rm -f
	find kubuntu/ -type f -iname "Makefile" | xargs rm -f
	rm -rf kubuntu/oemconfig
	rm -rf lubuntu/oemconfig
	rm -rf common/basicwallpaper/build
# vim:ts=4
