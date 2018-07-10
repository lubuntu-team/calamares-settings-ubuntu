#!/usr/bin/make -f

#SUBDIRS :=

all: install

install:
	make -C lubuntu/po/; \
	find lubuntu/ -type f -iname "*.in" | xargs rm -f
	chmod +x lubuntu/*.desktop

# vim:ts=4
