#!/usr/bin/make -f

#SUBDIRS :=

all:
	# Desktop file
	(cd lubuntu/po/ && make)
	(cd ubuntustudio/po/ && make)
	# Slideshow
	(cd lubuntu/branding/lubuntu/lang/ && make)
	(cd ubuntustudio/branding/ubuntustudio/lang && make)
	# Get rid of the unnecessary files
	find lubuntu/ -type f -iname "*.in" | xargs rm -f
	find lubuntu/ -type f -iname "Makefile" | xargs rm -f
	find ubuntustudio/ -type f -iname "*.in" | xargs rm -f
	find ubuntustudio/ -type f -iname "Makefile" | xargs rm -f
# vim:ts=4
