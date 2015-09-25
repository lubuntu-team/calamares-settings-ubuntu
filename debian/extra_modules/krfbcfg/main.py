#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
# === This file is part of Calamares - <http://github.com/calamares> ===
#
#   Copyright 2015, Teo Mrnjavac <teo@kde.org>
#
#   Calamares is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   Calamares is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with Calamares. If not, see <http://www.gnu.org/licenses/>.

import libcalamares
import os
from pwd import getpwnam

def run():
    """ Setup network configuration """

    obfuscatedPassword = libcalamares.globalstorage.value("password")
    user = libcalamares.globalstorage.value("autologinUser")
    cfgPath = libcalamares.utils.check_target_env_output(["sudo", "-u", user, "kde4-config", "--path", "config"]).split(":")[0]
    os.makedirs(cfgPath, exist_ok=True)

    with open(cfgPath + "krfbrc", 'w') as krfbrc:
        krfbrc.write("[Security]\n" +
                     "allowUnattendedAccess=true\n" +
                     "desktopPassword=" + obfuscatedPassword + "\n" +
                     "noWallet=true" +
                     "unattendedPassword=" + obfuscatedPassword + "\n")

    userEntry = getpwnam(user)
    libcalamares.utils.check_target_env_output(["chown", "-R", "{0}:{1}".format(userEntry.pw_uid, userEntry.pw_gid), userEntry.pw_dir])

    return None
