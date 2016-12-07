
#include <stdio.h>
#include <string.h>

#include "simulator.h"

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


void process () {

	// initialize simulator
	init(page_size, window_size);

	// create sorting problem
	int i = 0;
	for(i = 0; i < 10000; ++i) {
		put(i, lrand48());
		++key_count;
	}

	heapSort(10000);
	
	done();

}

int main(int argc, char *argv[]) {


	if(argc > 2) {
		page_size = atoi(argv[1]);
		window_size = atoi(argv[2]);
	} else {
		page_size = 64;
		window_size = 128;	
	}
	
	process();

	return 0;
}
