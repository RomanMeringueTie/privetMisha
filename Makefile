# all: /home/roman/architecture/console/pr01

# /home/roman/architecture/console/pr01: /home/roman/architecture/mySimpleComputer/main.c /home/roman/architecture/mySimpleComputer/sc_lib.a
# 	gcc -g -Wall -I /home/roman/architecture/include/ -o /home/roman/architecture/console/pr01 /home/roman/architecture/mySimpleComputer/main.c /home/roman/architecture/mySimpleComputer/sc_lib.a

# /home/roman/architecture/mySimpleComputer/sc_lib.a: /home/roman/architecture/mySimpleComputer/sc*.o /home/roman/architecture/mySimpleComputer/print*.o
# 	ar rcs /home/roman/architecture/mySimpleComputer/sc_lib.a /home/roman/architecture/mySimpleComputer/sc*.o /home/roman/architecture/mySimpleComputer/print*.o

# /home/roman/architecture/mySimpleComputer/print*.o: /home/roman/architecture/mySimpleComputer/print*.c
# 	gcc -g -c -I /home/roman/architecture/include/ /home/roman/architecture/mySimpleComputer/print*.c
# 	cp *.o /home/roman/architecture/mySimpleComputer
# 	rm *.o

# /home/roman/architecture/mySimpleComputer/sc*.o: /home/roman/architecture/mySimpleComputer/sc*.c
# 	gcc -g -c -I /home/roman/architecture/include/ /home/roman/architecture/mySimpleComputer/sc*.c
# 	cp *.o /home/roman/architecture/mySimpleComputer
# 	rm *.o

all: build.sh
	sh build.sh

	.PHONY: clean

clean:
	rm /home/roman/architecture/mySimpleComputer/sc*.o
	rm /home/roman/architecture/mySimpleComputer/print*.o
	rm /home/roman/architecture/mySimpleComputer/sc_lib.a
	rm /home/roman/architecture/console/pr01

.PHONY: run

run:
	./console/pr01