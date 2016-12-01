
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
	}

}

int get_exponent(int number) {
	if(number == 64) {
		return 6;
	} else if (number == 128) {
		return 7;
	} else if (number == 256) {
		return 8;
	} else if (number == 512) {
		return 9;
	}
}

void process () {

}

void init (int psize, int winsize) {

}

void put (unsigned int address, int value) {

}

// where address is address of our linked list
int get (unsigned int address) {

}

void done() {

}

int main(int argc, char *argv[]) {


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
	llist** table;
	int size = 100; // temp
	table = malloc(size*sizeof(llist*));
	ht_insert(table, size, new0);
	ht_insert(table, size, new1);
	ht_insert(table, size, new);
	

	llist* item = ht_search(table, size, 6);
	

	//printf("Item with key %d and data %f\n", item->key, item->data);
	

	// this is a 32bit interger right?
	int a = 0x82bc1dc7;
	printf("%x --- %x\n", FIRST(a, 4), LAST(a,3*4));


	return 0;
}
