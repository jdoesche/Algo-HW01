CC = g++
CFLAGS = -g -Wall -Wextra

default: sorting

sortering: Sorting.o main.o
	$(CC) $(CFLAGS) -o sortering Sorting.o main.o

Sorting.o: Sorting.cpp Sorting.h
	$(CC) $(CFLAGS) -c Sorting.cpp

main.o: main.cpp Sorting.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) sorting *.p *~