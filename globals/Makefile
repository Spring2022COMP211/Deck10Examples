CC=gcc
CFLAGS=-g -Wall

all: globals 

foo.o: foo.c
	$(CC) $(CFLAGS) -c foo.c

bar.o: bar.c
	$(CC) $(CFLAGS) -c bar.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

globals: foo.o bar.o main.o
	$(CC) $(CFLAGS) -o globals foo.o bar.o main.o

clean:
	rm -f main.o;
	rm -f foo.o;
	rm -f bar.o;
	rm -f globals;

