
#include "simulator.h"

// gets the last n bits from b
#define LAST(b,n) ( (b) & ((1 << (n)) -1) )
#define FIRST(b,n) LAST( ((b) >> (32-n)), n)
// gets the first n bits from b
// first right shifts so only first n bits are at the most
// right hand side
// the calls last



// each node of the linked list represents the page
// every hash value has a linked list
// each node has key, address, and next pointer
// say 3 pages hashed to same hash value.
// use key in linked list to determine which specific key is the right one

// every address we get is a combination of a page number and an offset
// we can know what pages we accessed from this
// the working set size is the number of pages we used for a while
// working set size = # of pages we have been referencing
// how do we determine the length of time to determine what we have been working on
// window size

// address  is the beginning of the page number. 
// go into has table, find the key and offset 4(size of int)*wordsize

// so allocate memory for page zero in our has table
// 

// when using put, actually write to the physical address

// each time we put something, the address itself is increased by 1



// makes a new node
llist* ll_new(int key, double data) {
	llist* new = malloc(sizeof(llist));
	new->key = key;
	new->data=data;
	new->next=NULL;
	new->previous=NULL; // do we need doubly linked?
	return new;
}

/*Insert at the beginning*/
llist* ll_insert(llist* head, llist* new) {
	new->next=head;
	if(head != NULL)
		head->previous=new; // for doubly linked only
	
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

/*Search for an item, using the key*/
llist* ll_search(llist* head, int key) {
	for(;head!=NULL; head=head->next){
		if(head->key==key)
		return head;	
	}
	return NULL;
}

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

void ht_insert(llist** table, int size, llist* item) {
	int key = item->key; // key of the item we want to look for
	table[key % size] = ll_insert(table[key%size], item);
}

void ht_delete(llist** table, int size, llist* item) {
	int key = item->key;
	table[key % size] = ll_delete(table[key%size], item);	
}

llist* ht_search(llist** table, int size, int key){
	return ll_search(table[key%size],key);
}

void print_list(llist* head) {
	llist* current = head;
	int count = 0;
	while (current != NULL) {
		printf("This is node %d, with key %d and value %f\n", count, current->key, current->data);
		current = current->next;
		++count;
	}

}

void init (int psize, int winsize) {
	// maybe the table should be a bit bigger?
	table = malloc(SIZE*sizeof(llist*));
	// set table to all zeros
	memset(table, 0, SIZE*sizeof(llist*));

	reference_count = 0;
	memory_references = NULL;
	key_count = 0;
}

void put (unsigned int address, int value) {
	
	++reference_count;

	llist* node = ll_new(address, value);
	
	ht_insert(table, SIZE, node);

	// for our output
	llist* mem_node = ll_new(node->key, node->data);
	memory_references = ll_insert(memory_references, mem_node);

}

// where address is address of our linked list
int get (unsigned int address) {

	++reference_count;

	// SIZE + 1 ??? =
	llist* node = ht_search(table, SIZE, address);

	// for our output
	llist* mem_node = ll_new(node->key, node->data);
	memory_references = ll_insert(memory_references, mem_node);

	// do we still call it a memory reference if we cannot find it?
	
	//DO WE NEED TO DO THE CHECKS?
	//DO WE NEED TO DO THE CHECKS?
	//DO WE NEED TO DO THE CHECKS?
	//if (node != NULL) {

		//memory_references = ll_insert(memory_references, node);
		//return node->data;
	//}
	

	/* else { // cannot find it
		return NULL;
	}
	*/
	return node->data;

}

void done() {

	printf("Count : %d\n", reference_count);
	//print_list(memory_references);

	ll_free(memory_references);
	int i = 0;


	for(i = 0; i < SIZE; ++i) {
		if(table[i]) {
			ll_free(table[i]);
		}
	}

	free(table);

}



