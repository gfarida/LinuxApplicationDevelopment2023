TEST=test_

move: move.c
		@gcc -g -o0 move.c -o move

test: test_move test_remove

test_move: move
		@echo hello > in
		@strace -e fault=openat:error=EACCES:when=3 ./move in test_out 2> $(TEST)1 || true
		@cat $(TEST)1 | grep "+++ exited with 13 +++" > /dev/null
		@test -f in
		@echo "TEST #1 IS SUCCED"

		@echo hello > in
		@strace -e fault=openat:error=EACCES:when=4 ./move in test_out 2> $(TEST)2 || true
		@cat $(TEST)2 | grep "+++ exited with 13 +++" > /dev/null
		@test -f in
		@echo "TEST #2 IS SUCCED"

		@echo hello > in
		@strace -e fault=read:error=EACCES:when=1 ./move in test_out 2> $(TEST)3 || true
		@cat $(TEST)3 | grep "+++ exited with 127 +++" > /dev/null
		@test -f in
		@echo "TEST #3 IS SUCCED"

		@echo hello > in
		@strace -e fault=close:error=EACCES:when=2 ./move in test_out 2> $(TEST)4 || true
		@cat $(TEST)4 | grep "+++ exited with 127 +++" > /dev/null
		@test -f in
		@echo "TEST #4 IS SUCCED"

test_remove: move noremove.c
		@cc -shared -o noremove.so noremove.c
		@echo hello, world! > test_PROTECT.txt
		@LD_PRELOAD=`pwd`/noremove.so ./move test_PROTECT.txt test_out.txt
		@test -f test_PROTECT.txt
		@echo "TEST #5 IS SUCCED"

clean:
		rm -f *.o move *.so *.txt $(TEST)* in test_out