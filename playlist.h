//This will be the playlist file
//This will use a linked list to implement a playlist style of songs 
//This will use a doubly linked list to hold the order of the songs and the playlist

//Bret Miller 
//December 2019

//playlist.h
#ifndef playlist_h
#define playlist_h


#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "song.h"

typedef struct{
    char* name; //this will hold the name of the playlist
    int num; //will hold the number of songs in the playlist
    LinkedList* plist; //this will hold the linked list that will hold all of the songs
    Song* currSong; //this will hold the data of the current node which holds the song
    Song* prevSong; //this will hold the data of the previous song 
    Song* nxtSong; //this will hold the data of the next song

}Playlist;

//This is a create playlist function 
Playlist* newPlaylist(char* name);

//This will be a method to add a song to the playlist
void addSong(Playlist* plist, Song* sng);

//This is a playlist mapping function
void llPrint(void* data);

//This is a function to print out the playlist
void playlistPrint(Playlist* pl);

//this will be a playlist shuffling function 


#endif /*end of playlist.h */