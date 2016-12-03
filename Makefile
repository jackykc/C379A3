CC = gcc
CFLAGS = -Wall 
LINKS = -lm

all: quicksort heapsort

quicksort: quicksort.o
	$(CC) $(CFLAGS) simulator.c quicksort.o -o quicksort $(LINKS)

heapsort: heapsort.o
	$(CC) $(CFLAGS) simulator.c heapsort.o -o heapsort

quicksort.o:
	$(CC) -c $(CFLAGS) quicksort.c $(LINKS)	

heapsort.o:
	$(CC) -c  $(CFLAGS) heapsort.c 

clean:
	rm *.o
	rm *sort
