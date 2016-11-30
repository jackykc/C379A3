#include <stdio.h>
#include <string.h>


//https://en.wikipedia.org/wiki/Heapsort
void swap(int array[], int indexA, int indexB);
void heapSort(int array[], int count);
void heapify(int array[], int count);
void siftDown(int array[], int start, int end);

void swapValues(int array[], int indexA, int indexB) {
	int swapTemp = array[indexA];
	array[indexA] = array[indexB];
	array[indexB] = swapTemp;
}

void heapSort(int array[], int count) {

	
	if (count < 2) {
		return;
	}
	

	// build heap here
	heapify(array, count);

	int end = count - 1;

	while(end > 0) {
		// impelement swap

		swapValues(array, 0, end);
		--end;
		siftDown(array, 0, end);
		// restore heap property 
	}


}

void heapify(int array[], int count) {
	// get the parent
	int start = (count-1) / 2;

	while (start >= 0) {
		siftDown(array, start, count -1);
		//printf("Start %d", start);
		--start;
	}

}

void siftDown(int array[], int start, int end) {
	
	int child;
	int swap;
	int root = start;
	int leftChild = 2*root+1;
	

	while (leftChild <= end) {
		child = leftChild;
		swap = root;

		if(array[swap] < array[child]) {
			swap = child; 
		}

		if ((child + 1 <= end) && (array[swap] < array[child+1])) {
			swap = child + 1;
		}

		if (swap == root) {
			return;
		}
		else {

			swapValues(array, root, swap);
			root = swap;	

		}
		// update leftchild
		leftChild = 2*root+1;

	}


}



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

