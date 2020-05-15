#!/usr/bin/make -f

POTFILES := $(shell cat POTFILES.in)

all: generate-po-files

generate-pot: POTFILES.in
	intltool-update --pot --gettext-package=calamares-settings-lubuntu

generate-po-files:
	for i in $(POTFILES); do \
		f=$$(echo $$i | sed 's/\.in//'); \
		intltool-merge -d . ../$$i ../$$f; \
	done

update-po:
	for i in *.po; do \
		code=$$(echo $$i | sed 's/.po//'); \
		intltool-update --gettext-package=calamares-settings-lubuntu --dist $$code; \
	done

# vim:ts=4
