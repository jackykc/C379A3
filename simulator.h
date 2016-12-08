/*REMEMBER TO FREE ALL MEMORY AT THE END*/

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// number of linked lists the hash table can hold
#define SIZE 100

typedef struct linked_list llist;

struct linked_list {
	int key; double data; struct linked_list *next, *previous;
};

// create a new node for the linked list
llist* ll_new(int key, double data);

// insert into list
llist* ll_insert(llist* head, llist* new);

// search for node given a key
llist* ll_search(llist* head, int key);

// delete a node from the linked list
llist* ll_delete(llist* head, llist* item);

// insert an item into the hash table
void ht_insert(llist** table, int size, llist* item);

// delete an item from the hash table
void ht_delete(llist** table, int size, llist* item);

// search for an item in the hash table give a key
llist* ht_search(llist** table, int size, int key);

// prints out a linked list
void print_list(llist* head);

// initializes simulator
void init (int psize, int winsize);

// store a value in memory at indicated address
void put (unsigned int address, int value);

// get contents at indicated address
int get (unsigned int address);

// free memory and print results
void done();

// hash table
llist** table;
// number of memory references
int reference_count;
// linked list of memory references
llist* memory_references;
// page and window size
int page_size, window_size;


#endif