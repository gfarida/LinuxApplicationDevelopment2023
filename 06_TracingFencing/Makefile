TEST=test_

move: move.c
		@gcc -g -o0 move.c -o move

# test: esub
# 		@echo abcd | sed 's/\(a*\)/<\1>'/ > $(TEST)1
# 		@./esub '(a*)' '<\1>' 'abcd' | cmp $(TEST)1
# 		@echo "                    ========= TEST #1 IS SUCCED ============"

# 		@echo '12345' | sed 's/\([0-9]\)\([46]\)/<\1>*\2*/' > $(TEST)2
# 		@./esub '([0-9])([46])' '<\1>*\2*' '12345' | cmp $(TEST)2
# 		@echo "                    ========= TEST #2 IS SUCCED ============"

# 		@echo 'abcde' | sed 's/\(a*\)\(b*\)/<\1><\2>/' > $(TEST)3
# 		@./esub '(a*)(b*)' '<\1><\2>' 'abcde' | cmp $(TEST)3
# 		@echo "                    ========= TEST #3 IS SUCCED ============"

noremove.so: noremove.o
		cc -shared $^ -o $@

clean:
		rm -f *.o move