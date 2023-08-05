FLAG = -std=c11 -Wall -Werror -Wextra
all: cat

cat: Makefile cat.c
	gcc $(FLAG) cat.c -o cat

rebuild:
	make clean
	make all

clean:
	rm -f cat

style:
	cp ../../materials/linters/.clang-format ../../src/cat/.clang-format
	clang-format -style=Google -n *.c *.h
	rm .clang-format

test:
	sh test_cat.sh