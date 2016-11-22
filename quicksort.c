#include <stdio.h>
#include <string.h>
#include <math.h>
// Quicksort function.

int midPoint(int left, int right) {
	return (left+right)/2;
}

int quickSort(int array[], int left, int right) {
	
}

int main(int argc, char *argv[]) {
	int i, temp;
	int myArray[7] = {3,4,9,6,2,5,7};
	for (i = 0; i<(sizeof(myArray)/sizeof(int));i++) {
		printf("%i ", myArray[i]);
	}
	printf("\n");
	int left = 0;
	int right = sizeof(myArray)/sizeof(int)-1;
	int pivot = round(midPoint(0, sizeof(myArray)/sizeof(int)));
	while (left <= right) {
		while (myArray[left] < myArray[pivot]) {
			left++;
		}
		while (myArray[right] > pivot) {
			right--;
		}
		if (left <= right) {
			temp = myArray[left];
			myArray[left] = myArray[right];
			myArray[right] = temp;
			left++;
			right--;
		}
	}

	// while (pivot != sizeof(myArray)/sizeof(int)) {}
	for (i = 0; i<(sizeof(myArray)/sizeof(int));i++) {
		printf("%i ", myArray[i]);
	}
	printf("\n");
	return 0;
}

