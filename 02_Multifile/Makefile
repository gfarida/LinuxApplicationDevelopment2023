TRASH = *.o *~ o.* prog prog-* *.a *.so output*
CFLAGS = -Wall -fPIC
DEV_NULL = /dev/null
LD_LIBRARY_PATH = `pwd`
OUTPUT = output_
OUTPUT_A = output-a_
OUTPUT_SO = output-so_
ARGS = hello
ARGS_1 = hello, world !

all:	prog prog-a prog-so

test:	all test_0 test_1 test_3

test_0:	prog prog-a prog-so
		./prog > $(OUTPUT)0 2> $(DEV_NULL)
		./prog-a > $(OUTPUT_A)0 2> $(DEV_NULL)
		LD_LIBRARY_PATH=$(LD_LIBRARY_PATH) ./prog-so > $(OUTPUT_SO)0 2> $(DEV_NULL)
		cmp output_0 output-a_0
		cmp output-a_0 output-so_0
		@ echo "                    ========= TEST WITHOUT PARAMETERS IS SUCCED ============"

test_1:	prog prog-a prog-so
		./prog > $(OUTPUT)1 $(ARGS) 2> $(DEV_NULL)
		./prog-a > $(OUTPUT_A)1 $(ARGS) 2> $(DEV_NULL)
		LD_LIBRARY_PATH=$(LD_LIBRARY_PATH) ./prog-so $(ARGS) > $(OUTPUT_SO)1 2> $(DEV_NULL)
		cmp output_1 output-a_1
		cmp output-a_1 output-so_1
		@ echo "                    ========== TEST WITH 1 PARAMETER IS SUCCED ============="

test_3:	prog prog-a prog-so
		./prog > $(OUTPUT)3 $(ARGS_1) 2> $(DEV_NULL)
		./prog-a > $(OUTPUT_A)3 $(ARGS_1) 2> $(DEV_NULL)
		LD_LIBRARY_PATH=$(LD_LIBRARY_PATH) ./prog-so $(ARGS_1) > $(OUTPUT_SO)3 2> $(DEV_NULL)
		cmp output_3 output-a_3
		cmp output-a_3 output-so_3
		@ echo "                    =========== TEST WITH 3 PARAMETERS IS SUCCED ==========="

prog-a:	prog.o liboutput_static.a
		cc -L. $< -loutput_static -o $@

prog-so: prog.o liboutput.so
		cc -L. $< -loutput -o $@

liboutput_static.a:	fun.o const.o
		ar -rcs $@ $^

liboutput.so: fun.o const.o
		cc -shared $^ -o $@

prog: const.o fun.o prog.o

fun.o: outlib.h

clean:
		rm -f $(TRASH)