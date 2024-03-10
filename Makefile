# all: print/pr_lib.a myTerm/mt_lib.a mySimpleComputer/sc_lib.a

# console/pr01: mySimpleComputer/main.c mySimpleComputer/*.c myTerm/*.c print/*.c
# 	gcc -g -Wall -Iinclude/ -o console/pr01 mySimpleComputer/main.c mySimpleComputer/sc*.c myTerm/mt*.c print/pr*.c

console/concole: console/concole.c mySimpleComputer/*.c myTerm/*.c print/*.c
	gcc -g -Wall -Iinclude/ -o console/concole console/concole.c mySimpleComputer/sc*.c myTerm/mt*.c print/pr*.c

# myTerm/mt_lib.a: myTerm/*.o print/*.o 
# 	ar rcs myTerm/mt_lib.a myTerm/*.o print/*.o

# mySimpleComputer/sc_lib.a: mySimpleComputer/sc*.o
# 	ar rcs mySimpleComputer/sc_lib.a mySimpleComputer/sc*.o

# myTerm/*.o: myTerm/*.c
# 	gcc -g -c -Iinclude/ myTerm/*.c
# 	cp *.o myTerm
# 	rm *.o

# print/print*.o: print/print*.c
# 	gcc -g -c -Iinclude/ print/print*.c
# 	cp *.o print
# 	rm *.o

# mySimpleComputer/sc*.o: mySimpleComputer/sc*.c
# 	gcc -g -c -Iinclude/ mySimpleComputer/sc*.c
# 	cp *.o mySimpleComputer
# 	rm *.o

clean:
	rm mySimpleComputer/*.o
	rm mySimpleComputer/*.a
	rm myTerm/*.o
	rm myTerm/*.a
	rm print/*.o
	rm print/*.o

.PHONY: run

run:
	./console/pr01