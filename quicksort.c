#include <stdio.h>
#include <string.h>
#include <math.h>
// Quicksort function.

int midPoint(int left, int right) {
	return (left+right)/2;
}

int sizeofArray(array[]) {
	return sizeof(array)/sizeof(int);
}

// void quickSort(int array[], int left, int right) {
// 	int tempLeft = left;
// 	int tempRight = right;
// 	int temp;
// 	int pivot = round(midPoint(left, right));
// 	while (tempLeft <= tempRight) {
// 		while (array[tempLeft] < array[pivot]) {
// 			tempLeft++;
// 		}
// 		while (array[tempRight] > array[pivot]) {
// 			tempRight--;
// 		}
// 		if (tempLeft <= tempRight) {
// 			temp = array[tempLeft];
// 			array[tempLeft] = array[tempRight];
// 			array[tempRight] = temp;
// 			tempLeft++;
// 			tempRight--;
// 		}
// 	}
// 	if (left < tempRight) {
// 		quickSort(array, left, tempRight);
// 	}
// 	if (tempLeft < right) {
// 		quickSort(array, tempLeft, right);
// 	}
// }

// void swapValues(int indexA, int indexB) {
// 	int swapTemp = get(indexA);
// 	//get(indexA) = get(indexB);
// 	put(indexA, get(indexB));
// 	put(indexB, swapTemp);
// }

// void swap(int* first, int* second) {
// 	int temp = *first;
// 	*first = *second;
// 	*second = temp
// }

// int partition(array[], int left, int right) {
// 	int pivot = array[left];
// 	while (1) {
// 		tempLeft++;		
// 		while (array[left] > pivot) {
// 			left++;	
// 		}
// 		while (array[right] > pivot) {
// 			right--;
// 		}
// 		if (left <= right) {
// 			temp = array[left];
// 			array[left] = array[right];
// 			array[right] = temp;
// 		} else {
// 			return right;
// 		}
// }

// void inplaceQuicksort(int array[], int start, int end) {
// 	if (start>end) {
// 		return;
// 	}





// 	int left, right, pivot;
// 	if (end < start+1) {
// 		pivot = array[start];
// 		left = start+1;
// 		right = end;
// 		while (left > right) {
// 			if (array[left] < pivot) {
// 				left++
// 			} else {
// 				swap(&array[left], &array[right]); 
// 			}
// 		}

// 	}


// 	int pivot = array[sizeofArray(array)-1];

	// int insertIndex, sortIndex, insertElement;
	// for (insertIndex=2; insertIndex<sizeofArray(array);insertIndex++) {
	// 	insertElement = array[insertElement];
	// 	sortIndex = insertIndex-1;

	// 	while (insertElement < array[sortIndex] && sortIndex > 0) {
	// 		array[sortIndex+1] = array[sortIndex];
	// 		sortIndex--;
	// 	}

	// 	array[sortIndex+1] = insertElement;
	// }
// }

void quickInPlaceSort(int array[]) {
	int i, j, temp, left, right, mid, item;
	for (i = 0; i<sizeofArray(array)-1; i++) {
		for (j = i+1; j< sizeofArray(array); j++) {
			if (array[i]>array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	for (i=0;i<sizeofArray(array);i++) {
		printf("%i\n", array[i]);
	}

	// left = 0;
	// right = sizeofArray(array)-1;
	// mid = (int) (left + right)/2;
	// while ()

}

int main(int argc, char *argv[]) {

	printf("This is quicksort\n");
	int i;
	int myArray[] = {3,4,9,6,2,5,7};
	for (i = 0; i<(sizeof(myArray)/sizeof(int));i++) {
		printf("%i ", myArray[i]);
	}
	printf("\n");
	quickInPlaceSort(myArray);

	// while (pivot != sizeof(myArray)/sizeof(int)) {}
	for (i = 0; i<(sizeof(myArray)/sizeof(int));i++) {
		printf("%i ", myArray[i]);
	}
	printf("\n");
	return 0;
}





 // void main()
 // {
 
 // for(i=0;i<=9;i++)
 // {
 //  printf("\n%d",arr[i]);
 // }
 // printf("Enter the number to find:");
 // scanf("%d",&item);
 // beg=0;
 // end=9;
 // mid=(int)(end+beg)/2;
 // while(item!=arr[mid] && beg<=end)
 // {
 //  if(item>arr[mid])
 //  {
 //   beg=mid+1;
 //  }
 //  else
 //  {
 //   end=mid-1;
 //  }
 //  mid=(int)(end+beg)/2;
 // }
 // if(beg<=end)
 // {
 //  printf("\nPosition is %d",mid+1);
 // }
 // else
 //  printf("\nPosition may be become %d",mid+1);
 // getch();
 // }