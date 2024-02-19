all: pr01

pr01: main.c sc_lib.a
	gcc -Wall -I /home/roma/architecture/include/ -o pr01 main.c sc_lib.a

sc_lib.a: sc*.o print*.o
	ar rcs sc_lib.a sc*.o print*.o

sc*.o: sc*.c print*.c
	gcc -I /home/roma/architecture/include/ -c sc*.c print*.c

.PHONY: clean

clean: sc_lib.a sc*.o print*.o
	rm sc*.o
	rm print*.o
	rm sc_lib.a