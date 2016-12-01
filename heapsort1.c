
#include <stdio.h>
#include <string.h>

#include "simulator.h"
//https://en.wikipedia.org/wiki/Heapsort
void swap(int indexA, int indexB);
void heapSort(int count);
void heapify(int count);
void siftDown(int start, int end);

void swapValues(int indexA, int indexB) {
	int swapTemp = get(indexA);
	//get(indexA) = get(indexB);
	put(indexA, get(indexB));
	put(indexB, swapTemp);
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
		//printf("Start %d", start);
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

	table = malloc(SIZE*sizeof(llist*));

	llist* head = NULL;
	llist* new = ll_new(5, 10.0);
	// inserts new into head	

	//printf("Item with key %d and data %f\n", item->key, item->data);
	
	
	/*---------------------------------------------------------------------------------*/
	int j = 0;

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

	heapSort(10);

	printf("Here %d %d %d %d %d %d %d %d %d %d\n",
	 get(0), get(0), get(0), get(0), get(0),
	  get(0), get(0), get(0), get(0), get(0));




	/*
	for (j = 0; j < 10; ++j) {

	}
	*/
	// int i = 0;
	// int myArray[] = {8,7,6,5,4,3,2};
	// //int myArray[] = {1,2,3,4,5,6,7};

	// int arraySize = sizeof(myArray)/sizeof(int); 
	// for (i = 0; i< arraySize;i++) {
	// 	printf("%i ", myArray[i]);
	// }
	// printf("\n");
	// heapSort(myArray, arraySize);

	// // while (pivot != sizeof(myArray)/sizeof(int)) {}
	// for (i = 0; i<(sizeof(myArray)/sizeof(int));i++) {
	// 	printf("%i ", myArray[i]);
	// }
	// printf("\n");



	/*

	for(j = 0; j < SIZE; ++j) {
		put(j, lrand48());			
	}

	*/

	put(10, 100);

	printf("Here %d\n", get(10));


	put(10, 20);
	printf("Here %d\n", get(10));


	return 0;
}

/*
int main(int argc, char *argv[]) {

	printf("This is heapsort\n");

	int i;
	//int myArray[] = {3,4,9,6,2,5,7,1, 5};
	int myArray[] = {8,7,6,5,4,3,2};
	//int myArray[] = {1,2,3,4,5,6,7};

	int arraySize = sizeof(myArray)/sizeof(int); 
	for (i = 0; i< arraySize;i++) {
		printf("%i ", myArray[i]);
	}
	printf("\n");
	heapSort(myArray, arraySize);

	// while (pivot != sizeof(myArray)/sizeof(int)) {}
	for (i = 0; i<(sizeof(myArray)/sizeof(int));i++) {
		printf("%i ", myArray[i]);
	}
	printf("\n");

	return 0;

}

*/