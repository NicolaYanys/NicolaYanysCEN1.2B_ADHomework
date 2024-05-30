CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

all: main

main: main.o book_division.o
	$(CC) $(CFLAGS) -o main main.o book_division.o

main.o: main.c book_division.h
	$(CC) $(CFLAGS) -c main.c

book_division.o: book_division.c book_division.h
	$(CC) $(CFLAGS) -c book_division.c

clean:
	rm -f *.o main
