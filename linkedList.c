/**
 * 
 * This will be a header file that will define all of the different functions needed to create 
 * a linked list and all of the different pieces associated with it so it can be used as a generic 
 *
 * This will also be the linked list implemenation using the header file 
 * 
 * 
 * Project 5: CS333
 * linkedList.c
 * 
 * Bret Miller 
 * 10/8/19
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
//Linked list functions definitions

//This will create and initialize a struct linked list and set the head to null 
LinkedList *ll_create(){
    LinkedList* myList = malloc(sizeof(LinkedList)); //Declares the struct 
    myList->head = NULL;  //this gives the address of the top of the list
    return myList;
}

//This will push the passed in data to a new node and then will push that node to the head
void ll_push(LinkedList *l, void* data ){
    Node* pNode = malloc(sizeof(Node)); //makes the node for the data
    
    //these are the push cases 
    if( l->head == NULL ){ //Empty list case
        pNode->dataptr = data; // gives the dataptr the pointer to the data 
        l->head = pNode;
        pNode->nextptr = NULL; //Sets the next to NULL so the bottom will always be NULL
        pNode->prevptr = NULL; //This sets the prev pointer to NULL too
    }else{ //Not empty list case 
        pNode->dataptr = data; //gives the data to the pointer 
        Node *cap  = l->head; //capture the data in the head right now, to set the next 
        l->head = pNode; //sets the new head
        pNode->nextptr = cap; //sets the old head as the new next 
        cap->prevptr = l->head; //set the prev as the head
    }
}


//this will be the pop to take something off of the front of the list
void *ll_pop(LinkedList *l){
    Node *ret = malloc(sizeof(Node));

    //this will be where the different cases for popping will be defined 
    if(l->head == NULL){ //if the list is empty 
        printf("The List is Empty, nothing can be popped.\n");
        return NULL;
    } else { //list is not empty 
        ret = l->head; //capture the top or pop
        if(ret->nextptr == NULL ){ //means this was the last thing in the list
            l->head = NULL;
        } else { //there is more than one thing left in the linked list 
            Node *newHead = ret->nextptr; //This is the next of the old head
            newHead->prevptr = NULL; //Set the prev to null because it is the head now 
            l->head = newHead; //New head has been added 
        };
    }

    void* retVal = ret->dataptr;
    free(ret);
    return retVal;
}

//This will be the append function that will append the data that is being passed
//to the end of the linked list
void ll_append(LinkedList *l, void *data){
    Node *aNode = malloc(sizeof(Node));
    //Case if the linked list is empty 
    if(l->head == NULL){
        aNode->dataptr = data;
        l->head = aNode;
        aNode->nextptr = NULL;
        aNode->prevptr = NULL;
    }
    //list is not empty, new method of adding to the list
    else{
        aNode->dataptr = data; //this gives the data to the node 
        Node *searchNode  = l->head; //gives it the head to start
        while(searchNode->nextptr != NULL){
            searchNode = searchNode->nextptr;
        }
        //Found the one before the last
        searchNode->nextptr = aNode; //Gives the next pointer as the newNode
        aNode->prevptr = searchNode; //gives the new node the previous of the search
        aNode->nextptr = NULL;
        //need to iterate through to find last node
    }
 
}

//This will be a remove fucntion that will be able to search for a node by using 
// a comparator to search
void* ll_remove(LinkedList *l, void *target, int(*compfunc)(void*, void*)){
    Node *searchNode = malloc(sizeof(Node));
    Node *removed = malloc(sizeof(Node)); //This will take the node and return it
    Node *prev = malloc(sizeof(Node)); //This keeps track of a pointer for the behind
    //Will check to make sure that head of the list is not null
    if(l->head == NULL){
        return removed;
    }
    searchNode = l->head; //searching node is set to the head 
    void *data = searchNode->dataptr;
    prev = NULL;
    int searched = 0;
    void* returnVal;
    while(searched == 0){
        //check to see if the data of the node matches
        if(compfunc(data, target) == 1){
            searched = 1;
            removed = searchNode;
            returnVal = removed->dataptr;

        }
        if(searchNode->nextptr == NULL){
            return NULL;

        }
        prev = searchNode; //This keeps track of the node behind
        searchNode = searchNode->nextptr;
        data = searchNode->dataptr;
    }
    //Time to unlink the node 
    if(searchNode->nextptr == NULL){
        //This will check if the next of the removed was null
        prev->nextptr = NULL;
    } else{
        //This checks if the first node is the one being searched for 
        if(prev == NULL){
            l->head = searchNode->nextptr;
            ((Node*)(l->head))->prevptr = NULL;
        } else{
            prev->nextptr = searchNode->nextptr;
            ((Node*)(prev->nextptr))->prevptr = prev;
        }
        
    }
    printf("the ret val is: %p\n", returnVal);
    return returnVal;

}

//this will return the size of the list 
int ll_size(LinkedList *l){
    int size = 0;
    int end = 0;
    if((l->head) == NULL){
        return size; //returns 0
    }
    Node *searchingNode = malloc(sizeof(Node));
    searchingNode = l->head;
    size++; //increments the size
    while(end == 0){
        if(searchingNode->nextptr == NULL){
            end = 1; //the end has been reached and loop should end 
            
        } else{
            searchingNode = searchingNode->nextptr; //Moves it to the next node 
            size++;
        }
    }
    
    free(searchingNode);
    
    return size;
}

//This will clear and free all of the data and nodes
void ll_clear(LinkedList *l, void (*freefunc)(void *)){
    Node *clearingNode = malloc(sizeof(Node));
    while(l->head != NULL){
        clearingNode = l->head;
        l->head = clearingNode->nextptr;
        freefunc(clearingNode);
    }
}

//This will be a function that will map out the nodes in the linkedlist from
void ll_map(LinkedList *l, void (*mapfunc)(void *)){
    Node *travNode = l->head;
    if( travNode == NULL){
        printf("The Linked List is empty\n");
    } else{
        while(travNode != NULL){
            void *passD = travNode->dataptr;
            mapfunc(passD); //passes the address so that the value can be changed to values later
            travNode = travNode->nextptr; //gives the travnode the next 
        }
    }
}

//This function will be able to an element from the desired index that is inputted
//If the element is too big in the list, then it will return null
void *ll_delete(LinkedList *l, int position){
    Node *searchingNode = l->head; //this gives the searching node the head  
    Node *prev = l->head; //This will keep track of the node before so that it can be linked in 
    int counter = 0; //this will keep track of how many nodes have been traversed, means it is  
    //check if the searching node is null, meaning the list is empty
    if(searchingNode == NULL){
        printf("The list is empty, and nothing can be deleted\n");
        return (searchingNode->dataptr);
    }
    counter =  1; //this means that the head is present and there is at least one node present, so counter is on 1
    //Now to actuall traverse the list 
    while(searchingNode != NULL){ //as long as the end of the list has not been reached
        //check if the counter is equal to the position desired 
        if(counter == position){
            //now will delete the node 
            if(counter == 1){
                //this means that the head is the deleting node 
                void* datahold = searchingNode->dataptr; //holds the data in the node 
                l->head = searchingNode->nextptr; //gives the head the next of the searching 
                ((Node*)(l->head))->prevptr = NULL; //give the prev null
                return datahold;
            } else {
                void* datahold = searchingNode->dataptr; //holds the data in the node 
                prev->nextptr = searchingNode->nextptr; //gives the prev next, the new next.
                ((Node*)(prev->nextptr))->prevptr = prev; //put the prev in
                return datahold;
            }

        }
        counter++; //increments the counter 
        prev = searchingNode; //takes the  prev pointer
        searchingNode = searchingNode->nextptr; //takes the next pointer for the new searching node

    }
    return NULL;
}

//This will be an insert function that will be able to insert a node at any desired index
//these indexes will start at 0, meaning that the index will start as 0 at the first element 
void ll_insert(LinkedList *l, void *data, int index){
    //first will create a node that will be inserted 
    Node *newNode = malloc(sizeof(Node));
    newNode->dataptr = data;
    newNode->nextptr = NULL;
    newNode->prevptr = NULL;
    int counter = 0; //This will track where in the list you are, starts at index 0
    Node *searchingNode = l->head; //will keep track of the node 
    Node *prev = l->head; //will keep track of the behind 

    //check if the list is empty 
    if(l->head == NULL){
        l->head = newNode;//gives the head the new Node
    } else{
        while(counter != index){
            //checks to see if searching node is null, meaning the end of the list 
            if(searchingNode == NULL){
                prev->nextptr = newNode; //links the new one at the end 
                newNode->prevptr = prev; //link prev in 
                break; 
            }
            counter++; //increments the counter 
            prev = searchingNode;
            searchingNode = searchingNode->nextptr; 
        }
        //Now to link in the right place 
        if(counter == index){
            prev->nextptr = newNode;
            newNode->prevptr = prev; //link prev in
            newNode->nextptr = searchingNode;
        }
    }

}
