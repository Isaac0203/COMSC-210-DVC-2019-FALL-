#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// Hyunwook Jung
// Diablo Valley College COMSC
// 08/Sep/2019
// Lab 1

/*Make sure you show your implementation of the use of vectors in this lab-- 
alternatively, you can use pointers and build your own linked list---the choice is yours.  

You MUST modularize your code 
( meaning, there must be functions written for each piece of functionality that you write... 
at the very least:  
add(), 
delete(), 
print() 
and main() functions should be obvious.*/

string addSong();
void removeSong(vector<string> &songList);
void printSong(vector<string>);
void printMenu();

int main()
{
	vector<string> songsArtists;
	/*
	1. Add song/artist pair
	2. remove song/artist pair
	3. print the list
	4. quit
	*/

	int command = -1;	// Command switch (1~4)

	cout << "Hello, this is your playlist." << endl;
	while (command != 4) {
		cout << "Please select the command(integer 1, 2, 3, or 4)." << endl;
		printMenu();
		cin >> command;
		while (command < 1 || command > 4)
		{
			cout << "Please enter an integer between 1, 2, 3, or 4." << endl;
			printMenu();
			cin >> command;
		}
		switch (command)
		{
		case 1:
			songsArtists.push_back(addSong());
			break;
		case 2:
			removeSong(songsArtists);
			break;
		case 3:
			printSong(songsArtists);
			break;
		case 4:
			break;
		default:
			break;
		}
	}
	return 0;
}


void printMenu()
{
	cout << "1. Add song / artist pair" << endl
		<< "2. Remove song / artist pair" << endl
		<< "3. Print the list" << endl
		<< "4. Quit" << endl;
}
string addSong()
{
	cout << endl;
	cout << "Adding a song / artist" << endl;
	char tmpSong[20];
	char tmpArtist[20];
	cout << "Enter the name of the song(<20): ";
	cin >> tmpSong;
	cout << "Enter the name of the artist(<20): ";
	cin >> tmpArtist;
	char songArtist[40];
	strcpy(songArtist, tmpSong);
	strcat(songArtist, " / ");
	strcat(songArtist, tmpArtist);
	cout << songArtist << endl << endl;
	return songArtist;
}
void removeSong(vector<string> &songList)
{
	printSong(songList);
	cout << "Remove which song / artist? Enter the number in the list.";
	int indexPlusOne;
	cin >> indexPlusOne;
	if (indexPlusOne >= 0 && indexPlusOne < songList.size())
	{
		songList.erase(songList.begin() + indexPlusOne);
		cout << "A song / artist Removed." << endl << endl;
	}
}
void printSong(vector<string> songList)
{
	cout << endl;
	cout << "Printing the song / artist list" << endl;
	cout << "Song \t\t / \t\t Artist" << endl;
	for (unsigned int i = 0; i < songList.size(); i++)
	{
		cout << i << ". " << songList.at(i) << endl;
	}
	cout << endl;
}