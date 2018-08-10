#!/usr/bin/env python3

# Copyright (C) 2018 Simon Quigley <tsimonq2@ubuntu.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.

import json
import subprocess
import libcalamares
from urllib import request

def getcountry():
    # This is hardcoded for now, but should eventually be put into the config
    with request.urlopen("https://ipapi.co/json") as url:
        localedata = json.loads(url.read().decode())
    return localedata["country"]

def getmirror(country):
    with request.urlopen(libcalamares.job.configuration["mirrorList"]) as url:
        mirrors = json.loads(url.read().decode())
    if country in mirrors.keys():
        return mirrors["country"] + "."
    else:
        return ""

def getcodename():
    return libcalamares.check_target_env_output("lsb_release -c -s")

def changesources(prefix):
    root = libcalamares.globalstorage.value("rootMountPoint")

    url = prefix + libcalamares.job.configuration["baseUrl"]
    if not url.startswith("http://") and not url.startswith("https://"):
        url = "http://" + url

    if libcalamares.job.configuration["backend"] == "apt":
        distro = libcalamares.job.configuration["distribution"]
        if "ubuntu" in distro.lower():
            with open("ubuntu.sources.list", "r") as sourcesfile:
                sources = sourcesfile.read()
            sources = sources.replace("DISTRIBUTION", distro)
            sources = sources.replace("CODENAME", getcodename())
            sources = sources.replace("URL", url)

            with open(root + "/etc/apt/sources.list", "r+") as sourcesfile:
                sourcesfile.seek(0)
                sourcesfile.write(sources)
                sourcesfile.truncate()

            if libcalamares.globalstorage.value("hasInternet"):
                libcalamares.check_target_env_call("apt-get update")

def run():
    """Autoselect a mirror from a list."""
    if libcalamares.globalstorage.value("hasInternet"):
        country = getcountry()
        prefix = getmirror(country)
    else:
        prefix = ""

    changesources(prefix)
