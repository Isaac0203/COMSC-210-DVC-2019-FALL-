#include <iostream>
#include <string>
#include "person.h"

person::person()
{
	cout << "How do you want to be called?" << endl;
	string tempName;
	getline(cin, tempName);
	name = tempName;
	cout << "You are now " << name << "." << endl;
}
person::~person()
{
}

int person::getExp() const {
	return exp;
}	// exp accessor

void person::setExp(int earnedExp) {
	exp += earnedExp;
	if (earnedExp >= 0)
	{
		cout << "You earned " << earnedExp << " exp." << endl;
		cout << "Now you have " << exp << " exp." << endl;
	}
	else
	{
		cout << "You lost " << earnedExp << " exp." << endl;
		cout << "Now you have " << exp << " exp." << endl;
	}
}	// exp mutator

int person::getMoney() const {
	return money;
} // money accessor

void person::setMoney(int earnedMoney) {
	money += earnedMoney;
	if (earnedMoney >= 0)
	{
		cout << "You earned " << earnedMoney << " dollars." << endl;
		cout << "Now you have " << money << " dollars." << endl;
	}
	else
	{
		cout << "You lost " << earnedMoney << " dollars." << endl;
		cout << "Now you have " << money << " dollars." << endl;
	}
	if (money < 0) {
		throw exp;
	}
}	// money mutator

string person::getName() const {
	return name;
}	// name accessor

void person::setName(string userInputName) {
	name = userInputName;
}	// name mutator

void person::goSchool() {
	cout << "You went to school" << endl;
	setExp(+2);
	setMoney(-2);
}
void person::eatSomething() {
	cout << "You ate vodka jelly" << endl;
	setMoney(-1);
}
void person::playMinecraft() {
	cout << "You played Minecraft" << endl;
	setExp(-1);
}
void person::doWork() {
	cout << "You went to work" << endl;
	setMoney(+2);
}

