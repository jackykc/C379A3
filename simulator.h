/*REMEMBER TO FREE ALL MEMORY AT THE END*/

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

typedef struct linked_list llist;

void process ();

void init (int psize, int winsize);

void put (unsigned int address, int value);

int get (unsigned int address);

void done();

// get the exponent from 
// 2^^exponent = number
int get_exponent(int number);

struct linked_list {
	int key; double data; struct linked_list *next, *previous;
};

llist* ll_new(int key, double data);

/*Insert at the beginning*/
llist* ll_insert(llist* head, llist* new);

llist* ll_search(llist* head, int key);

llist* ll_delete(llist* head, llist* item);

void ht_insert(llist** table, int size, llist* item);

void ht_delete(llist** table, int size, llist* item);

llist* ht_search(llist** table, int size, int key);

void print_list(llist* head);


llist** table;

#endif