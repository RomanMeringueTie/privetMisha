all: console/pr01

console/pr01: mySimpleComputer/main.c mySimpleComputer/sc_lib.a
	gcc -g -Wall -I include/ -o console/pr01 mySimpleComputer/main.c mySimpleComputer/sc_lib.a

mySimpleComputer/sc_lib.a: mySimpleComputer/sc*.o mySimpleComputer/print*.o
	ar rcs mySimpleComputer/sc_lib.a mySimpleComputer/sc*.o mySimpleComputer/print*.o

mySimpleComputer/print*.o: mySimpleComputer/print*.c
	gcc -g -c -I include/ mySimpleComputer/print*.c
	cp *.o mySimpleComputer
	rm *.o

mySimpleComputer/sc*.o: mySimpleComputer/sc*.c
	gcc -g -c -I include/ mySimpleComputer/sc*.c
	cp *.o mySimpleComputer
	rm *.o

.PHONY: clean

clean:
	rm mySimpleComputer/sc*.o
	rm mySimpleComputer/print*.o
	rm mySimpleComputer/sc_lib.a
	rm console/pr01

.PHONY: run

run:
	./console/pr01