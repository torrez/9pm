CC=gcc
LDFLAGS=-lncurses

all: a

a: main.o map.o
	$(CC) main.o map.o -o a $(LDFLAGS)

clean:
	rm *o
