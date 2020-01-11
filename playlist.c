//This will be the playlist file
//This will use a linked list to implement a playlist style of songs 
//This will use a doubly linked list to hold the order of the songs and the playlist

//playlist.c 

//Jan 2020

#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include "song.h"
#include "linkedList.h"

//This is a function to be able to create a new playlist 
Playlist* newPlaylist(char* name){
    Playlist* plist = (Playlist*)malloc(sizeof(Playlist));
    plist->name = name; //assigns the name to the playlist
    plist->num = 0;
    //This is the initializiation of the linked list
    LinkedList* ll = ll_create();
    plist->plist = ll;
    return plist;
}

//this will have the ability to add a song to the playlist
void addSong(Playlist* plist, Song* sng){
    //First need to grab the linked list out of the playlist 
    LinkedList* ll = plist->plist;
    ll_push(ll, sng);
}

//here is a mapping function to pass to the linkedlist mapping function
void llPrint(void* data){
    Song* out = (Song*)data; 
    printf("Song #: %d\nTitle: %s\nArist: %s\nGenre: %s\n\n",out->position, out->title, out->artist, out->genre);
}

//This will be a function that will be used to print out the entirety of the playlist 
void playlistPrint(Playlist* pl){
    printf("Playlist: %s\n", pl->name);
    ll_map(pl->plist, llPrint);
}

//This will be a playlist shuffling function 




int main(int argc, char* argv[]){
    char* c = "Bret's";
    Playlist* p = newPlaylist(c);
    printf("The name of the playlist is: %s\n", p->name);
    Song* sng = createSong("Hello", "Adele", "Pop", 125);
    addSong(p, sng);
    //To do, Create another playlist and check the sheet to make sure that you are
    //following along with the functionality needed to make this work
    Song* sng2 = createSong("Hot", "Young Thug", "Rap", 132 );
    Song* sng3 = createSong("Dance Monkey", "Two Tones", "Pop", 180);
    Song* sng4 = createSong("Are You Up", "The Phantoms", "EDM", 165);
    Song* sng5 = createSong("Something About You", "Rudimental", "EDM", 190);
    addSong(p, sng2);
    addSong(p, sng3);
    addSong(p, sng4);
    addSong(p, sng5);
    playlistPrint(p);
    return 0;
}