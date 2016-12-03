#include <stdio.h>
#include <string.h>
#include <math.h>
// Quicksort function.
// followed the code here: http://alienryderflex.com/quicksort/

void quicksort(int arr[], int lenArr) {

	int piv, begin[100], end[100], i, j, left, right;
	begin[0] = 0;
	
	end[0] = lenArr;

	while (i >= 0) {
		printf("%i\n", i);
		left = begin[i];
		right = end[i]-1;
		if (left < right) {
			piv = arr[left];
			while (left < right) {
				while (arr[right]>=piv && left < right) {
					right--;
				}
				if (left < right) {
					arr[left++] = arr[right];
				}
				while (arr[left] <= piv && left < right) {
					left++;
				}
				if (left < right) {
					arr[right--] = arr[left];
				}
			}
			arr[left] = piv;
			begin[i+1] = left + 1;
			end[i+1] = end[i];
			end[i++] = left;
		} else {
			i--;
		}
	}
}

int main(int argc, char *argv[]) {

	printf("This is quicksort\n");
	int i;
	int myArray[] = {3,4,13,0,9,3,4,6,2,5,11,7,1,20,14};
	for (i = 0; i<(sizeof(myArray)/sizeof(int));i++) {
		printf("%i ", myArray[i]);
	}
	printf("\n");
	quicksort(myArray, (sizeof(myArray)/sizeof(int)));

	// while (pivot != sizeof(myArray)/sizeof(int)) {}
	for (i = 0; i<(sizeof(myArray)/sizeof(int));i++) {
		printf("%i ", myArray[i]);
	}
	printf("\n");
	return 0;
}