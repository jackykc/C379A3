
#include "simulator.h"

// makes a new node
llist* ll_new(int key, double data) {
	llist* new = malloc(sizeof(llist));
	new->key = key;
	new->data=data;
	new->next=NULL;
	new->previous=NULL; 
	return new;
}

// Insert at the beginning
llist* ll_insert(llist* head, llist* new) {
	new->next=head;
	if(head != NULL)
		head->previous=new; 
	
	head=new;
	return head;
}

// deletes item from list
llist *ll_delete(llist* head, llist* item) {
	if(item->previous != NULL)
		item->previous->next=item->next;
	if(item->next != NULL)
		item->next->previous=item->previous;
	if(item == head)
		head=item->next;

	free(item);
	return head;
}

// Search for an item, using the key
llist* ll_search(llist* head, int key) {
	for(;head!=NULL; head=head->next){
		if(head->key==key)
		return head;	
	}
	return NULL;
}

// free the linked list
void ll_free(llist* head) {
	llist* current = head;
	llist* last = current;
	while (current != NULL) {
		free(current->previous);
		last = current;
		current = current->next;
	}
	free(last);
}

// insert into hash table (given a linked list node)
void ht_insert(llist** table, int size, llist* item) {
	int key = item->key; 
	table[key % size] = ll_insert(table[key%size], item);
}

// delete an item in the hash table (given a linked list node)
void ht_delete(llist** table, int size, llist* item) {
	int key = item->key;
	table[key % size] = ll_delete(table[key%size], item);	
}

// given a key, check if the item exists in the linked list
llist* ht_search(llist** table, int size, int key){
	return ll_search(table[key%size],key);
}

// print out the linked list, used for checking
void print_list(llist* head) {
	llist* current = head;
	int count = 0;
	while (current != NULL) {
		printf("This is node %d, with key %d and value %f\n", count, current->key, current->data);
		current = current->next;
		++count;
	}

}

// initialize the simulator
void init (int psize, int winsize) {

	table = malloc(SIZE*sizeof(llist*));
	// set table to all zeros
	memset(table, 0, SIZE*sizeof(llist*));

	// global variables
	reference_count = 0;
	memory_references = NULL;
	key_count = 0;
}


void put (unsigned int address, int value) {
	
	++reference_count;

	llist* node = ll_new(address, value);
	
	ht_insert(table, SIZE, node);

	// list of memory references made
	llist* mem_node = ll_new(node->key, node->data);
	memory_references = ll_insert(memory_references, mem_node);

}

// where address is address of our linked list
int get (unsigned int address) {

	++reference_count;

	llist* node = ht_search(table, SIZE, address);

	llist* mem_node = ll_new(node->key, node->data);
	memory_references = ll_insert(memory_references, mem_node);

	return node->data;

}

// print the output
void done() {

	llist* current = memory_references;
	// count of the current memory reference we are on
	int count = 0; 
	// used to check if we went to a new window
	int previous_window = 0;
	int current_window = 0;
	
	// check if we have visited a page before
	llist* pageSet = NULL;

	// what page are we currently on?
	int page = 0;
	// total working set size of the program
	int working_set_size = 0;
	 // working set size of a window
	 int current_count = 0;
	
	// for our current window
	int window_count = reference_count / window_size;
	if(reference_count % window_size != 0) {
		++window_count;
	}


	// run until we reached the end of our memory references
	while (current != NULL) {
		current_window = count/window_size;
		// we are at a new window
		if(current_window != previous_window) {

			printf("Working set size of winodw %d is %d\n", previous_window, current_count);
			
			previous_window = current_window;
			// reset pageSet 
			ll_free(pageSet);
			pageSet = NULL;
			
			// reset working_set_size of current window
			current_count = 0;
			
		}

		// get current page
		page = current->key / page_size;
		
		// check if we have already access the page in this current window
		llist* nodeExist = ll_search(pageSet, current->key / page_size);
		
		// it already exist
		if(nodeExist != NULL) {
		} else { 
			llist* pageNode = ll_new(page, 0);
			pageSet = ll_insert(pageSet, pageNode);
		
			// increase our working set size count
			++current_count;
			++working_set_size;

		}

		// get next memory reference
		current = current->next;
		// increment count of memory reference
		++count;


	}

	
	// print out last window
	printf("Working set size of winodw %d is %d\n", current_window, current_count);
	
	// printf("Count of memory references: %d\n", reference_count);
	// printf("Window count %d\n", window_count);
	// printf("Working set size %d\n", working_set_size);
	
	float average = (float)working_set_size / (float)window_count;
	printf("Average working set size %f\n", average);
	
	//printf("%f, %d : %d\n", average, page_size, window_size);

	// free all memory references
	ll_free(memory_references);
	
	// free the linked list used to check duplicate page accesses
	ll_free(pageSet);
	pageSet = NULL;
	
	// free the hash table
	int i = 0;
	for(i = 0; i < SIZE; ++i) {
		if(table[i]) {
			ll_free(table[i]);
		}
	}

	free(table);

}

