#pragma once
#ifndef PERSON_H
#define PERSON_H
using namespace std;

class person {
public:
	person();	// Constructor
	~person();	// Destructor
	int getExp() const;	// exp accessor
	void setExp(int earnedExp);	// exp mutator
	int getMoney() const; // money accessor
	void setMoney(int earnedMoney);	// money mutator
	string getName() const;	// name accessor
	void setName(string userInputName);	// name mutator

	void goSchool();
	void eatSomething();
	void playMinecraft();
	void doWork();
private:
	int exp = 0;
	int money = 10;
	string name = "Name me";
};
#endif // !PERSON
