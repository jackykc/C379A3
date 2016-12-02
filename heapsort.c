
#include <stdio.h>
#include <string.h>

#include "simulator.h"
//https://en.wikipedia.org/wiki/Heapsort
void swap(int indexA, int indexB);
void heapSort(int count);
void heapify(int count);
void siftDown(int start, int end);

void swapValues(int indexA, int indexB) {
	
	// temporary variable
	put(SIZE, get(indexA));

	put(indexA, get(indexB));
	put(indexB, get(SIZE));
}

void heapSort(int count) {

	// build heap here
	heapify(count);

	int end = count - 1;

	while(end > 0) {
		// impelement swap

		swapValues(0, end);
		--end;
		siftDown(0, end);
		// restore heap property 
	}


}

void heapify(int count) {
	// get the parent
	int start = (count-1) / 2;

	while (start >= 0) {
		siftDown(start, count -1);
	
		--start;
	}

}

void siftDown(int start, int end) {
	
	int child;
	int swap;
	int root = start;
	int leftChild = 2*root+1;
	

	while (leftChild <= end) {
		child = leftChild;
		swap = root;

		if( get(swap) < get(child) ) {
			swap = child; 
		}

		if ( (child + 1 <= end) && (get(swap) < get(child+1)) ) {
			swap = child + 1;
		}

		if (swap == root) {
			return;
		}
		else {

			swapValues(root, swap);
			root = swap;	

		}
		// update leftchild
		leftChild = 2*root+1;

	}


}

int main(int argc, char *argv[]) {

	int page_size, window_size;
	if(argc > 2) {
		page_size = atoi(argv[1]);
		window_size = atoi(argv[2]);
	} else {
		page_size = 64;
		window_size = 128;	
	}
	if(argc == 4) {
		char* process = argv[3];
	}

	
	
	/*---------------------------------------------------------------------------------*/
	
	/*
	int j = 0;

	for(j = 0; j < SIZE; ++j) {
		put(j, lrand48());			
	}

	*/
	init(page_size, window_size);

	put(0, 9);
	put(1, 8);
	put(2, 6);
	put(3, 7);
	put(4, 5);
	put(5, 4);
	put(6, 2);
	put(7, 3);
	put(8, 1);
	put(9, 1);

	printf("True\n");
	heapSort(10);
		
	printf("Here %d %d %d %d %d %d %d %d %d %d\n",
	 get(0), get(1), get(2), get(3), get(4),
	  get(5), get(6), get(7), get(8), get(9));



	printf("Count : %d\n", reference_count);
	


	done();	

	return 0;
}
