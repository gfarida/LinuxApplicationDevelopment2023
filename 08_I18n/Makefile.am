bin_PROGRAMS=program
program_SOURCES=src/program.c

rus:
	xgettext -c -k_ src/program.c -o po/ru.pot
	msgmerge -U po/ru.po po/ru.pot

	mkdir -p ru_RU.UTF-8/LC_MESSAGES

	msgfmt po/ru.po -o ru_RU.UTF-8/LC_MESSAGES/ru.mo


clean:
	git clean -df
	rm src/*.o