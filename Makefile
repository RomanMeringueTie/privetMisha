all: myTerm/mt_lib.a mySimpleComputer/sc_lib.a console/concole

console/concole: console/concole.c mySimpleComputer/*.c myTerm/*.c console/print*.c
	gcc -g -Iinclude/ -o console/concole console/concole.c mySimpleComputer/sc*.c myTerm/mt*.c console/print*.c

console/cons_lib.a: console/print*.o
	ar rcs console/cons_lib.a console/print*.o

console/print*.o: console/print*.c mySimpleComputer/sc_lib.a myTerm/mt_lib.a
	gcc -g -c -Iinclude/ console/print*.c mySimpleComputer/sc_lib.a myTerm/mt_lib.a
	cp *.o console
	rm *.o

myTerm/mt_lib.a: myTerm/*.o
	ar rcs myTerm/mt_lib.a myTerm/*.o

mySimpleComputer/sc_lib.a: mySimpleComputer/sc*.o
	ar rcs mySimpleComputer/sc_lib.a mySimpleComputer/sc*.o

myTerm/*.o: myTerm/*.c
	gcc -g -c -Iinclude/ myTerm/*.c
	cp *.o myTerm
	rm *.o

mySimpleComputer/sc*.o: mySimpleComputer/sc*.c
	gcc -g -c -Iinclude/ mySimpleComputer/sc*.c
	cp *.o mySimpleComputer
	rm *.o

clean:
	rm mySimpleComputer/*.o
	rm mySimpleComputer/*.a
	rm myTerm/*.o
	rm myTerm/*.a
	# rm console/*.o
	rm console/concole

.PHONY: run

run:
	./console/concole