CC=gcc
CFLAGS=-g -Wall -std=c99

all: prog

prog: bst.o bstMain.o
	$(CC) $^ -o $@

clean:
	-rm *.o

cleanall: clean
	-rm prog

