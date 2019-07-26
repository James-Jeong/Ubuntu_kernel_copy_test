all: copy

copy: copy.o
	gcc -o copy copy.o

copy.o: copy.c
	gcc -c -o copy.o copy.c

clean:
	rm -f copy.o
	rm -f copy

.PHONY: clean
.PHONY: copy.o


