#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Made by Hyunwook Jung
// 31 Oct 2019
// Lab:Hash tables
/*
Pseudo Code is referenced from:zyBooks, Ch15.2 Chaining, and HackerEarth
https://learn.zybooks.com/zybook/DVCCOMSC210KolenFall2019/chapter/15/section/2
https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/
*/

/*Specifications:

This week you worked with hash tablesand a variety of ways to handle collisions.
For this lab, please implement a hash table that uses a linked list 
to handle chaining for collision avoidance.
You can be creative with your implementation, 
what I will grade on this lab is your effective hash table implementation
(linked list and chaining).
*/

class Node {
public:
	int data;
	Node* next;

	Node() { // Node Constructor
		data = -1;
		next = nullptr;
	}
	~Node() {
	}
};

void HashInsert(Node HashTable[], int item) {
	// Make a new node
	Node* newNode = new Node;
	newNode->data = item;

	// Make a index out of item data
	int index = item % 10;

	// Push it inside the linked list
	// 1. IF THE TABLE IN THAT INDEX IS EMPTY
	if (HashTable[index].next == nullptr)
	{
		HashTable[index].next = newNode;
	}
	// 2. IF NOT EMPTY
	else if (HashTable[index].next != nullptr)
	{
		Node* curIndexNode = nullptr;
		curIndexNode = (HashTable[index]).next;
		while ((*curIndexNode).next != nullptr)
		{
			curIndexNode = (*curIndexNode).next;
		}
		(*curIndexNode).next = newNode;
	}
}
int HashSearch(Node HashTable[], int key)
{
	int index = key % 10; // Get Bucket index
	// 1. IF THE BUCKET IS EMPTY
	if ((HashTable[index]).next == nullptr) { 
		cout << "Value not found in the bucket[" << index << "]" << endl;
		return -1;
	}
	// 2. NOT EMPTY, START SEARCHING
	else {
		Node* curIndexNode = nullptr; // Bucket index pointer
		curIndexNode = (HashTable[index]).next; // Set index to the head
		while (curIndexNode != nullptr)
		{
			if ((*curIndexNode).data == key) { // If the same value is found
				cout << "Value found in the bucket[" << index << "]" << endl;
				return 1;
			}
			else {// value Not found in the current Index
				// Move index one block next
				curIndexNode = (*curIndexNode).next;
			}
		}
		// If while loop ends without any return value, no key value in the bucket
		cout << "Value not found in the bucket[" << index << "]" << endl;
		return 0;
	}
	/*	return -1 if that bucket is empty
		return 1 if found
		return 0 if bucket is not empty but not found in the bucket
	*/
}
int main()
{
	Node HashTable[10];// HashTable with only 10 heads of class Node, representing the buckets
	cout << "This is a Hashtable with 10 buckets in total." << endl;
	int menuCommand = -999; // switch commanding int
	while(menuCommand != 3){
		do
		{
			cout << "Choose a command." << endl;
			cout << "1. Add ID" << endl;
			cout << "2. Search ID" << endl;
			cout << "3. Quit" << endl;
			cin >> menuCommand;

		} while (menuCommand < 1 || 3 < menuCommand);
		switch (menuCommand)
		{
		case 1:
		{
			int id;
			cout << "Enter the ID number you want:";
			cin >> id;
			HashInsert(HashTable, id); }
			break;
		case 2:
		{
			int id;
			cout << "Enter the ID number you want:";
			cin >> id;
			HashSearch(HashTable, id); }
			break;
		default:
			cout << "switch finished" << endl;
			break;
		}
	} 
	return 0;
}