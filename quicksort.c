#include <stdio.h>
#include <string.h>
#include <math.h>
#include "simulator.h"
// Quicksort function.
// followed the code here: http://alienryderflex.com/quicksort/

void quicksort(int lenArr) {
	int piv, begin[100], end[100], i, j, left, right;
	
	begin[0] = 0;
	end[0] = lenArr;

	while (i >= 0) {
		left = begin[i];
		right = end[i]-1;
		if (left < right) {
			put(SIZE, get(left)); //piv = arr[left]
			while (left < right) {
				// while (arr[right]>=piv && left < right) {
				while (get(right) >= get(SIZE) && left < right) {
					right--;
				}
				if (left < right) {
					put(left, get(right));
					left++;
					// arr[left++] = arr[right];
				}
				while (get(left) <= get(SIZE) && left < right) {
				// while (arr[left] <= piv && left < right) {
					left++;
				}
				if (left < right) {
					put(right, get(left));
					right--;
					// arr[right--] = arr[left];
				}
			}
			put(left, get(SIZE));
			// arr[left] = piv;
			begin[i+1] = left + 1;
			end[i+1] = end[i];
			end[i++] = left;
		} else {
			i--;
		}
	}
}

void process () {


	/////////////////////////////
	init(page_size, window_size);
	/////////////////////////////
	
	int i;

	printf("This is quicksort\n");
	// put(0, 9);
	// put(1, 8);
	// put(2, 6);
	// put(3, 7);
	// put(4, 5);
	// put(5, 4);
	// put(6, 2);
	// put(7, 3);
	// put(8, 1);
	// put(9, 1);
	
	for (i = 0; i<10000; i++) {
		put(i, lrand48()/10000000);
		printf("%i ", get(i));
	}
	printf("\n");

	quicksort(10000);

	printf("\n");
	
	/////////////////////////////
	done();
	/////////////////////////////
	for (i = 0; i<10000; i++) {
		printf("%i ", get(i));
	}

}

int main(int argc, char *argv[]) {

	//int page_size, window_size;
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