/*
Name: Sehan Madusha
Student ID: 106223861
Name of the C file: 106223861_A_Qn2.cpp

Asiignment 2 question 2
Text-based Music Album Application
This program is a Text-based music album application made using C++.
It allows the user to manage and play music albums by reading album and track information from an external text file.
The program uses structures, enumerations, array, file handling, and functions. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//enum for genre
enum Genre { POP, ROCK, HIPHOP, CLASSICAL };

//structure for the track
struct Track {
    string title;
    string path;
};

struct Album {
    string title;
    string artist;
    Genre genre;
    int trackCount;
    Track tracks[20]; //total number of arrays for  the track
};

//global data
Album albums[20]; //array that can store 20 albums
int albumCount = 0; //storing how many albums are currently loaded

//converting enum values to readable text for display
string genreToString(Genre g) {
    if (g == POP) 
    return "Pop";

    if (g == ROCK)
     return "Rock";

    if (g == HIPHOP)
     return "HipHop";
    
     if (g == CLASSICAL)
     return "Classical";

    return "Unknown";
}

//menu option 1
//read album data from text file
void readAlbums() {
    string filename;
    cout << "Enter a file path to an Album: ";
    cin >> filename;

    ifstream inFile;
    inFile.open(filename.c_str()); //open file entered by the user

    //checking file opening
    if (inFile.fail()) {
        cout << "File could not be opened.\n";
        return;
    }

    //read number of albums
    inFile >> albumCount;
    inFile.ignore(); //ignore newline

    //read each album
    for (int i = 0; i < albumCount; i++) {
        getline(inFile, albums[i].artist);
        getline(inFile, albums[i].title);

        int g;
        inFile >> g; //reading genre number
        albums[i].genre = static_cast<Genre>(g);  //conerting it to enum type

        inFile >> albums[i].trackCount;//read number of tracks
        inFile.ignore();

        //reading every track title and file path in text file
        for (int j = 0; j < albums[i].trackCount; j++) {
            getline(inFile, albums[i].tracks[j].title);
            getline(inFile, albums[i].tracks[j].path);
        }
    }

    inFile.close();
    cout << "Albums loaded successfully.\n";
}

//main menu option 2(display album)
void displayAlbumMenu() {
    int choice;
    do {
        cout << "\nDisplay Album Menu\n";
        cout << "1. Display all album\n";
        cout << "2. Display album by genre\n";
        cout << "3. Back to main menu\n";
        cout << "Please enter your choice: ";
        cin >> choice;

        //if user enter 1 displaying album title, artist, genre
        if (choice == 1) {
            for (int i = 0; i < albumCount; i++) {
                cout << i + 1 << ". Title : " <<albums[i].title << ", Artist : "
                     << albums[i].artist << ", genre : "
                     << genreToString(albums[i].genre) << endl;
            }
        }
        //if user enter 2 displaying genre and asking the the user to select genre
        else if (choice == 2) {
            int g;
            cout << "0. Pop  1. Rock  2. HipHop  3. Classical\n";
            cout << "Pick a genre\n";
            cin >> g;

            for (int i = 0; i < albumCount; i++) {
                if (albums[i].genre == g) {
                    cout << "Title: "<< albums[i].title << "; Artist Name: "
                         << albums[i].artist << "; Genre: "
                         << genreToString(albums[i].genre) << endl;
                }
            }
        }

    } while (choice != 3);
}

//option 3 (selecting an album to play)
void playAlbum() {

    //showing albums
    for (int i = 0; i < albumCount; i++) {
        cout << i + 1 << ". Title: "
             << albums[i].title << "; Artist Name: "
             << albums[i].artist << "; Album Genre: "
             << genreToString(albums[i].genre) << endl;
    }

    int a;
    cout << "Select an album to play: ";
    cin >> a;
    a--;

    //display tracks
    for (int i = 0; i < albums[a].trackCount; i++) {
        cout << i + 1 << ". Track name: " << albums[a].tracks[i].title << endl;
    }

    int t;
    cout << "Select a track to play: ";
    cin >> t;
    t--;

    cout << "Playing track of "
         << albums[a].artist
         << " from album "
         << albums[a].title << endl;

    //opening the music file using windows default media player
    system(("start " + albums[a].tracks[t].path).c_str());
}

//option 4 (update an existing album)
void updateAlbum() {

    //show all the albums
    for (int i = 0; i < albumCount; i++) {
        cout << i + 1 << ". Title: "
             << albums[i].title << "; Artist: "
             << albums[i].artist << "; Genre: "
             << genreToString(albums[i].genre) << endl;
    }

    int a;
    cout << "Enter the album to edit: ";
    cin >> a;
    a--;

    //letting the user choose what to edit title or genre
    int edit;
    cout << "1. Title\n2. Genre\n";
    cout << "Enter the selection: ";
    cin >> edit;
    cin.ignore();

    //editing album title
    if (edit == 1) {
        cout << "Title: ";
        getline(cin, albums[a].title);
    }

    //editing album genre
    else if (edit == 2) {
        int g;
        cout << "0.Pop 1.Rock 2.HipHop 3.Classical\n";
        cout << "Enter number of genre: ";
        cin >> g;
        albums[a].genre = static_cast<Genre>(g); // update genre using enum value
    }
}

int main() {
    int choice;

    //repeats until user choose exit
    do {
        cout << "\nMain Menu\n";
        cout << "1. Read in Albums\n";
        cout << "2. Display Album\n";
        cout << "3. Select an Album to play\n";
        cout << "4. Update an existing album\n";
        cout << "5. Exit the application\n";
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: readAlbums(); break;
        case 2: displayAlbumMenu(); break;
        case 3: playAlbum(); break;
        case 4: updateAlbum(); break;
        }
    } while (choice != 5);

    return 0;
}
