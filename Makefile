#!/usr/bin/make -f

#SUBDIRS :=

all:
	# Desktop file
	(cd lubuntu/po/ && make)
	chmod +x lubuntu/*.desktop
	# Slideshow
	(cd lubuntu/branding/lubuntu/lang/ && make)
	# Get rid of the unnecessary files
	find lubuntu/ -type f -iname "*.in" | xargs rm -f
	find lubuntu/ -type f -iname "Makefile" | xargs rm -f

# vim:ts=4
