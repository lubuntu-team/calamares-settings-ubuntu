#!/bin/bash
#
# Remove OEM files from the system.

rm -rf /etc/calamares /usr/bin/basicwallpaper /usr/bin/calamares-finish-oem /usr/share/applications/calamares-finish-oem.desktop /etc/sddm.conf /usr/share/xsessions/kubuntu-oem-environment.desktop /usr/libexec/start-kubuntu-oem-env /etc/sudoers

mv /etc/sudoers.orig /etc/sudoers
