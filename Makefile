CC = gcc
CFLAGS = -Wall

all: simulator quicksort heapsort

simulator:  
	$(CC) $(CFLAGS) simulator.c -o simulator

quicksort:
	$(CC) $(CFLAGS) quicksort.c -o quicksort	

heapsort:
	$(CC) $(CFLAGS) heapsort.c -o heapsort

cleanSort:
	rm *sort

cleanSim:
	rm simulator

clean:
	rm *sort
	rm simulator