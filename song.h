//This is the header file for the Song struct and the functions to
//create the song and the returning of the creation of a song 
//and its information

//Bret Miller 
//December 2019

//song.h

#ifndef song_h
#define song_h

#include  <stdio.h>
#include<stdlib.h>

typedef struct{
    //These are all pointers to the data that the song will hold
    char* title; //This will hold the title of the song
    char* artist; //This will hold the arist name
    char* genre; //This will hold the genre of the song 
    int length; //this will hold the duration of the song (Unknown Use yet, but good information)
    int position; //this will hold where it is in the line
    int pop; //this will be a scale of popularity (Possibly out of 100?) This should be of the artist + song
    int plays; //this will be the number of plays that a song has had, can be an indicator of popularity

}Song;

//This will be a function to create a song 
//By passing in the information needed
Song* createSong(char title[], char artist[], char genre[], int length);

//This will deallocate the memory associated with a song struct 
void songOver(Song* out);

//This will be used to print out the info about a song
void songInfo(Song* song);

#endif /*end of linkedList.h */



