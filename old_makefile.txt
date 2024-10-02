CC = g++
CFLAGS = -g -Wall -Wextra

default: sorting

sorting: Sorting.o main.o
	$(CC) $(CFLAGS) -o Sorting Sorting.o main.o

Sorting.o: Sorting.cpp Sorting.h
	$(CC) $(CFLAGS) -c Sorting.cpp

main.o: main.cpp Sorting.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) Sorting *.p *~ *.o