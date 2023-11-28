SUBDIRS = src tests

gcov:	check
	$(MAKE) $(MAKEFLAGS) -C src gcov

clean:
	git clean -df
	rm -rf tests/*.o