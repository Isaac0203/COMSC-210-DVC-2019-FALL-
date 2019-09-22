#include <iostream>
#include <string>
#include <stdexcept>
// 20/Sep/2019
// Hyunwook Jung
// Diablo Valley College COMSC 210
// Ch 19 Lab

/*
Lab instruction:

Be creative!  
Design your own lab that does the following:  
Identify and code a solution for a problem that makes use of exceptions to improve program flow.

Make sure you show your implementation of the use of exceptions.  
Specifically, your program must use at least one try/catch clause 
to catch an ios_base::failure exception.  

In output, you must show the user the row that had the problem and indicate what the problem was.*/

/*
Program Summary:

A small life-simulation game. 
3 Files required to operate: Source.cpp, person.h, person.cpp.
Program aborted by two exceptions: only if the money gets lower than zero or input wrong command in the menu.
*/
using namespace std;
#include "person.h"		// user class

int getMenuCommand()
{
	cout << endl;
	cout << "#############################################" << endl;
	int command = -1;
		cout << "What would you do now?" << endl;
		cout << "1. Go to school" << endl;
		cout << "2. Eat something" << endl;
		cout << "3. Play Minecraft" << endl;
		cout << "4. Do part-time job" << endl;
		cin >> command;
		if (command != 1 && command != 2 && command != 3 && command != 4) {
			cout << "You do what?" << endl;
			throw runtime_error("Line 35 inside getMenuCommand function, Invalid user command.");
		}
	
	return command;
}

int main()
{
	person user;	// player created
	try
	{
		while (user.getMoney() >= 0)
		{

			switch (getMenuCommand())
			{
				/*
				"1. Go to school"
				"2. Eat something"
				"3. Play Minecraft"
				"4. Do part-time job" */
			case 1:
				user.goSchool();
				break;
			case 2:
				user.eatSomething();
				break;
			case 3:
				user.playMinecraft();
				break;
			case 4:
				user.doWork();
				break;
			default:
				break;
			}
		}
	}
	catch (runtime_error& excpt)
	{
		cout << "You are overwhelmed by an unexpected urge of escaping this world of material!" << endl << endl;
		cout << excpt.what() << endl;
		cout << "You should enter the command number between 1, 2, 3, or 4." << endl;
	}
	catch (int& score) // exp is the score in parameter
	{
		cout << "Oh no! No more money to survive!" << endl;
		cout << "You died..." << endl;
		cout << "Your score: " << score << endl << endl;
		cout << "Line 54, inside the person.cpp file:setMoney function" << endl;
		cout << "You should keep your money greater than or equal to zero." << endl;
	}
	return 0;
}
