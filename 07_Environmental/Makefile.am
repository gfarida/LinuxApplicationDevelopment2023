AM_CFLAGS = -O0 -g -lreadline

bin_PROGRAMS=rhasher

rhasher_SOURCES=src/rhasher.c

test:
	@sha1sum src/rhasher.c > test1
	@echo 'SHA1 src/rhasher.c' | ./rhasher &> test2
	@sed -n '2p' test2 > test3
	@cat test1 | grep -f test3 > /dev/null
	@echo "                    =========== TEST1 IS SUCCEED ==========="
	@rm test1 test2 test3

	@md5sum src/rhasher.c > test1
	@echo 'MD5 src/rhasher.c' | ./rhasher &> test2
	@sed -n '2p' test2 > test3
	@cat test1 | grep -f test3 > /dev/null
	@echo "                    =========== TEST2 IS SUCCEED ==========="
	@rm test1 test2 test3

clean:
	git clean -df
	rm src/*.o