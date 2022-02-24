CC=gcc
CFLAGS=-g -Wall

all: dir_example

main.o: main.c directory.h
	$(CC) $(CFLAGS) -c main.c

directory.o: directory.c directory.h
	$(CC) $(CFLAGS) -c directory.c

dir_example: main.o directory.o
	$(CC) $(CFLAGS) -o dir_example main.o directory.o

clean:
	rm -f main.o;
	rm -f directory.o;
	rm -f dir_example;

