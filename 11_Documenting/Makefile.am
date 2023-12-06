bin_PROGRAMS=program
program_SOURCES=src/program.c

@DX_RULES@

all-local:  doxygen-doc

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)

rus:
	xgettext -c -k_ src/program.c -o po/ru.pot
	msgmerge -U po/ru.po po/ru.pot

	mkdir -p ru_RU.UTF-8/LC_MESSAGES

	msgfmt po/ru.po -o ru_RU.UTF-8/LC_MESSAGES/ru.mo

http:	doxygen-doc
	python3 -m http.server --directory $</html

clean:
	git clean -df
	rm src/*.o