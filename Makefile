app: console/test.c
	gcc -Wall -o app console/test.c

.PHONY: run
run:
	./app

.PHONY: clean
clean:
	rm app