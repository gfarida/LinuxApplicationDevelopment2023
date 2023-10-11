RUN_GDB=run_gdb_
OUT_GDB=out_gdb_
DEV_NULL = /dev/null


range: range.c
		gcc -g -o0 range.c -o range

test: range
		gdb --args 1 12 < $(RUN_GDB)1 1> $(OUT_GDB)1
		gdb --args -100 100 3 < $(RUN_GDB)2 1> $(OUT_GDB)2

		cat $(OUT_GDB)1 | grep "@@@" | cmp $(OUT_GDB)1 gdb_1_correct
		@ echo "                    ========= TEST #1 IS SUCCED ============"

		cat $(OUT_GDB)2 | grep "@@@" | cmp $(OUT_GDB)2 gdb_2_correct
		@ echo "                    ========= TEST #2 IS SUCCED ============"

clean:
		rm -f *.o range a.out