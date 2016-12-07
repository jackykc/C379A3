#include <stdio.h>
#include <string.h>
#include <math.h>
#include "simulator.h"
// Quicksort function.
// followed the code here: http://alienryderflex.com/quicksort/

void quicksort(int lenArr) {
	// declare pivot, begin array, end array, i indecies, and left and right indecies.
	int begin[1000], end[1000], left, right;
	int i = 0;
	// start begin index at 0
	begin[0] = 0;
	// start end index at array length
	end[0] = lenArr;


	while (i >= 0) {
		// grab left and right indecies.
		left = begin[i];
		right = end[i]-1;
		if (left < right) {
			// store pivot
			put(SIZE, get(left));
			while (left < right) {
				// compare value on the right to pivot and decrement right
				while (get(right) >= get(SIZE) && left < right) {
					right--;
				}
				if (left < right) {
					// store right value in index-left and increment
					put(left, get(right));
					left++;
				}
				// compare value at left with pivot, while left is smaller than pivot, increment
				while (get(left) <= get(SIZE) && left < right) {
					left++;
				}
				if (left < right) {
					// store left value in index-right
					put(right, get(left));
					right--;
				}
			}
			// store pivot in index-left
			put(left, get(SIZE));
			// increment index arrays
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
	
	for (i = 0; i<10000; i++) {
		put(i, lrand48()/10000000);
	}

	
	quicksort(10000);

	
	for (i = 0; i<SIZE; i++) {
	//	printf("%i ", get(i));
	}
	/////////////////////////////
	done();
	/////////////////////////////
	

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