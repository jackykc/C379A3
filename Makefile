CC = gcc
CFLAGS = -Wall 
LINKS = -lm

all: simulator quicksort heapsort

simulator: simulator.o
	$(CC) $(CFLAGS) simulator.o -o simulator

quicksort: quicksort.o
	$(CC) $(CFLAGS) quicksort.o -o quicksort $(LINKS)

heapsort: heapsort.o
	$(CC) $(CFLAGS) heapsort.o -o heapsort

simulator.o:  
	$(CC) -c $(CFLAGS) simulator.c

quicksort.o:
	$(CC) -c $(CFLAGS) quicksort.c $(LINKS)	

heapsort.o:
	$(CC) -c  $(CFLAGS) heapsort.c 

cleanSort:
	rm *sort

cleanSim:
	rm simulator

clean:
	rm *.o
	rm *sort
	rm simulator
