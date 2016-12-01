#include "heapsort.c"

int main(int argc, char *argv[]) {

	int page_size, window_size;
	if(argc > 2) {
		page_size = atoi(argv[1]);
		window_size = atoi(argv[2]);
	} else {
		page_size = 64;
		window_size = 128++++++++++++++++++++++	}

	if(argc == 4) {
		char* process = argv[3];
	}

	llist* head = NULL;
	llist* new = ll_new(5, 10.0);
	llist* new0 = ll_new(6, 11.0);
	llist* new1 = ll_new(7, 12.0);
	// inserts new into head
	/*
	head = ll_insert(head, new);
	head = ll_insert(head, new0);
	head = ll_insert(head, new1);
	llist* item = ll_search(head, 5);

	printf("I am looking for a node with key %d, it has value %f\n", 5, item->data);
	print_list(head);

	ll_delete(head, new0);
	printf("___________________________\n");
	print_list(head);
	*/

	/*---------------------------------------------------------------------------------*/
/*	
	ht_insert(table, size, new0);
	ht_insert(table, size, new1);
	ht_insert(table, size, new);
	

	llist* item = ht_search(table, size, 6);
*/	

	//printf("Item with key %d and data %f\n", item->key, item->data);
	table = malloc(size*sizeof(llist*));

	put(10, 200);
	// this is a 32bit interger right?
	int a = 0x82bc1dc7;
	printf("%x --- %x\n", FIRST(a, 4), LAST(a,3*4));


	/*---------------------------------------------------------------------------------*/
	int j = 0;

	int tempArray[10] = {0};

	for(j = 0; j < size; ++j) {
		//tempArray[j] = j;
		//tempArray[j] = lrand48();
		//put(j, tempArray[j]);
		put(j, lrand48());			
	}



	for(j = 0; j < size; ++j) {
	//	printf("%d\n", get(j));
	}


	/* 

	if(sort == 1) {
		heapsort(table);
	}
	
	*/
	int i = 0;
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
