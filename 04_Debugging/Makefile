RUN_GDB=run_gdb_
OUT_GDB=out_gdb_


range: range.c
		gcc -g -o0 range.c -w -o range

test: range
		gdb --args range 1 12 < $(RUN_GDB)1 | grep @@@ | cmp gdb_1_correct
		@ echo "                    ========= TEST #1 IS SUCCED ============"


		gdb --args range -100 100 3 < $(RUN_GDB)2 | grep @@@ | cmp gdb_2_correct
		@ echo "                    ========= TEST #2 IS SUCCED ============"

clean:
		rm -f *.o range a.out