#!/bin/bash
# Preps the preinstalled system to go straight into
# First user configuration mode, bypassing oem config
# mode

/usr/libexec/calamares-oemprep.sh

sddm_file="$(cat <<EOL
[Autologin]
Session=lubuntu-oem-environment
User=oem
EOL
)"

echo "$sddm_file" > /etc/sddm.conf
