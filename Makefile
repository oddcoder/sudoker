all: main.o sudoku.o
	gcc main.o sudoku.o -o sudoker
main: main.c
	gcc main.c -c -o main.o
sudoku: sudoku.c
	gcc sudoku.c -c -o sudoku.o
debug:
	gcc -ggdb3 -Wall -Werror -Wno-unused-variable    main.c sudoku.c  -o sudoker
clean:
	rm -f sudoku.o sudoker main.o
