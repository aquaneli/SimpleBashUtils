FLAG = -std=c11 -Wall -Werror -Wextra
all: grep

grep: Makefile grep.c
	gcc ${FLAG} grep.c -o grep -lpcre
# `pcre-config --libs`

rebuild:
	make clean
	make all

clean:
	rm -f grep

style:
	cp ../../materials/linters/.clang-format ../../src/grep/.clang-format
	clang-format -style=Google -n *.c *.h
	rm .clang-format

test:
	sh test_grep.sh