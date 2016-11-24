#include <stdio.h>
#include <string.h>
#include <math.h>
// Quicksort function.

int midPoint(int left, int right) {
	return (left+right)/2;
}

void quickSort(int array[], int left, int right) {
	int tempLeft = left;
	int tempRight = right;
	int temp;
	int pivot = round(midPoint(left, right));
	while (tempLeft <= tempRight) {
		while (array[tempLeft] < array[pivot]) {
			tempLeft++;
		}
		while (array[tempRight] > array[pivot]) {
			tempRight--;
		}
		if (tempLeft <= tempRight) {
			temp = array[tempLeft];
			array[tempLeft] = array[tempRight];
			array[tempRight] = temp;
			tempLeft++;
			tempRight--;
		}
	}
	if (left < tempRight) {
		quickSort(array, left, tempRight);
	}
	if (tempLeft < right) {
		quickSort(array, tempLeft, right);
	}
}

int main(int argc, char *argv[]) {

	printf("This is quicksort\n");
	int i;
	int myArray[] = {3,4,9,6,2,5,7};
	for (i = 0; i<(sizeof(myArray)/sizeof(int));i++) {
		printf("%i ", myArray[i]);
	}
	printf("\n");
	quickSort(myArray, 0, 6);

	// while (pivot != sizeof(myArray)/sizeof(int)) {}
	for (i = 0; i<(sizeof(myArray)/sizeof(int));i++) {
		printf("%i ", myArray[i]);
	}
	printf("\n");
	return 0;
}

