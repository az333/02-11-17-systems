all: dir.c
	gcc dir.c

run: all
	./a.out
