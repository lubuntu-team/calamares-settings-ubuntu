#!/usr/bin/make -f

SUBDIRS := lubuntu/po/

all: install

install:
	for i in $(SUBDIRS); do \
		make -C $$i; \
		find $$i/../ -type f -iname "*.in" | xargs rm -f
	done

# vim:ts=4
