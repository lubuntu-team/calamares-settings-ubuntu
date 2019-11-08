#!/usr/bin/make -f

#SUBDIRS :=

all:
	# Desktop file
	(cd lubuntu/po/ && make)
	# Slideshow
	(cd lubuntu/branding/lubuntu/lang/ && make)
	# Get rid of the unnecessary files
	find lubuntu/ -type f -iname "*.in" | xargs rm -f
	find lubuntu/ -type f -iname "Makefile" | xargs rm -f
	(cd cinnamon-remix/po/ && make)
	# Slideshow
	(cd cinnamon-remix/branding/cinnamon-remix/lang/ && make)
	# Get rid of the unnecessary files
	find cinnamon-remix/ -type f -iname "*.in" | xargs rm -f
	find cinnamon-remix/ -type f -iname "Makefile" | xargs rm -f


# vim:ts=4
