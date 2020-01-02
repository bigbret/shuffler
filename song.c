//Bret Miller 
//Shuffling Main File
//December 2019 

//song.c

#include "song.h"
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>





//This will be a function to build a song
Song* createSong(char title[], char artist[], char genre[], int length){
    //First to create the song 
    Song* newSong = (Song*)malloc(sizeof(Song));
    //Assigning all of the fields and initing some to zero for time
    newSong->title = title;
    newSong->artist = artist;
    newSong->genre = genre;
    newSong->length = length;
    newSong->position = 0;
    newSong->pop = 0;

    

    return newSong;
}

//Need a way to deallocate the memory for the song when its not needed anymore
//Maybe distance from current? 
void songOver(Song* out){
    free(out);
}

//This will be a function to print out the information about a song 
void songInfo(Song* song){
    printf("%s\n", (song->title));
    printf("%s\n", (song->artist));
    printf("%s\n", (song->genre));
    printf("%d\n", (song->length));
}


/*int main(int argc, char *argv[]){
    Song* my = createSong("MySong", "Bret Miller", "R&B", 95);

    songInfo(my);

}*/







//Need to be able to build a linked list with the song structs
//as its data 

//Need to build a comaprator function for the linked list to take in 
//data 

//possibly need to find a way to take in song statistics 
//order and rank them in a way 

