/**
 * 
 * This will be the linked list header file that will be used to define all of the different functions
 * that will be needed for the generic linked list 
 * 
 * Project 5: CS333
 * linkedList.h
 * 
 * Bret Miller 
 * 10/8/19
 * 
 */
#ifndef linkedList_h
#define linkedList_h

#include  <stdio.h>
#include<stdlib.h>

//This is where the Linked List will be defined and have head pointer
typedef struct {
    void* head; //This hold the top of the linked list
}LinkedList;

//Node struct that will actually contain the data that is inside them 
typedef struct{
    void* dataptr; //This will be the pointer to the data that is being stored in the LL
    void* nextptr; //This will contain the next node in the linked list
    void* prevptr; //This will be the prev pointer
}Node;



//This will be all the functions for the linked list to be defined by 

//This will create a new linked list
LinkedList *ll_create();

//This will push new data onto the list making it the head
void ll_push(LinkedList *l, void *data);

//This will pop the head of the list off and create a new head 
void *ll_pop(LinkedList *l);

//This will append the data to the end of the list, making it in a way the tail of the list 
void ll_append(LinkedList *l, void *data);

//This will remove a desired piece of data from the target linked list 
//will search through all the different nodes in the linked list 
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *));

//this will return the size of the list 
int ll_size(LinkedList *l);

//this will clear the entire data associated with the linked list, as well as clears the list 
void ll_clear(LinkedList *l, void (*freefunc)(void *));

//This will take in a function that will manipulate the data that is in the nodes and print it out
void ll_map(LinkedList *l, void (*mapfunc)(void *));

//this will be an extension function that will be able to delete from any number node in the linked list, if it exists
void *ll_delete(LinkedList *l, int position);

//this will be a insert function that will be able to insert a node at a desired index in the linkedlist 
void ll_insert(LinkedList *l, void *data, int index);

#endif /*end of linkedList.h */