#include<iostream>
#include<string>
#include<vector>
// Hyunwook Jung
// COMSC 210 Diablo Valley College
// 6 October 2019
// Ch.11 Lab::Inheritance
using namespace std;
/*Create a class called Musicians to contain three functions string ( ), wind ( ) and perc ( ).

Each of these functions should initialize a string array to contain the following instruments:
    -  veena, guitar, sitar, sarod and mandolin under string ( )
    -  flute, clarinet saxophone, nadhaswaram and piccolo under wind ( )
    -  tabla, mridangam, bangos, drums and tambour under perc ( )

It should also display the contents of the arrays that are initialized.

Create a derived class called TypeIns to contain a function called get ( ) and show ( ). 
The get ( ) function must display instruments as follows:

  Type of instruments to be displayed
   a.    String instruments
   b.    wind instruments
   c.    Percussion instruments

The show ( ) function should display the relevant detail according to our choice. 
The base class variables must be accessible only to its derived classes.*/
class Musicians {
protected:
	vector<string> insArray;
	vector<string> stringArray;
	vector<string> windArray;
	vector<string> percArray;
public:
	Musicians() {
		cout << "Musician created" << endl;
		String();
		Wind();
		Perc();
	};
	//~Musicians();
	void String();
	void Wind();
	void Perc();
	void PrintArray();
private:
};

void Musicians::String() {
	cout << "Adding string instruments." << endl;
	int stringCommand = 1;
	while (stringCommand != 0) {
		cout << "What would you like to add?" << endl;
		cout << "1.veena, 2.guitar, 3.sitar, 4.sarod and 5.mandolin" << endl;
		cout << "Enter 0 to quit" << endl;
		cin >> stringCommand;
		if (stringCommand <= 5 && stringCommand >= 0)
		{
			switch (stringCommand)
			{
			case 1:
				stringArray.push_back("veena");
				break;
			case 2:
				stringArray.push_back("guitar");
				break;
			case 3:
				stringArray.push_back("sitar");
				break;
			case 4:
				stringArray.push_back("sarod");
				break;
			case 5:
				stringArray.push_back("mandolin");
				break;
			default:
				break;
			}
		}
		
		
		
	}
	PrintArray();
}
void Musicians::Wind() {
	cout << "Adding wind instruments." << endl;
	int stringCommand = 1;
	while (stringCommand != 0) {
		cout << "What would you like to add?" << endl;
		cout << "1.flute, 2.clarunet saxophone, 3.nadhaswaram, 4.piccolo" << endl;
		cout << "Enter 0 to quit" << endl;
		cin >> stringCommand;
		if (stringCommand <= 4 && stringCommand >= 0)
		{
			switch (stringCommand)
			{
			case 1:
				windArray.push_back("flute");
				break;
			case 2:
				windArray.push_back("clarinet saxophone");
				break;
			case 3:
				windArray.push_back("nadhaswaram");
				break;
			case 4:
				windArray.push_back("piccolo");
				break;
			default:
				break;
			}
		}

	PrintArray();
}
	void Musicians::Perc() {
	cout << "Adding perc instruments." << endl;
	int stringCommand = 1;
	while (stringCommand != 0) {
		cout << "What would you like to add?" << endl;
		cout << "1.tabla, 2.mridangam, 3.bangos, 4.drums and 5.tambour" << endl;
		cout << "Enter 0 to quit" << endl;
		cin >> stringCommand;
		if (stringCommand <= 5 && stringCommand >= 0)
		{
			switch (stringCommand)
			{
			case 1:
				percArray.push_back("tabla");
				break;
			case 2:
				percArray.push_back("mridangam");
				break;
			case 3:
				percArray.push_back("bangos");
				break;
			case 4:
				percArray.push_back("drums");
				break;
			case 5:
				percArray.push_back("tambour");
			default:
				break;
			}
		}
	PrintArray();
}
void Musicians::PrintArray() {
	unsigned int i;
	cout << endl << "Printing the string instruments in the array." << endl;
	for (i = 0; i < stringArray.size(); i++)
	{
		cout << i + 1 << ". " << stringArray.at(i) << endl;
	}
	cout << endl << "Printing the wind instruments in the array." << endl;
	for (i = 0; i < windArray.size(); i++)
	{
		cout << i + 1 << ". " << windArray.at(i) << endl;
	}
	cout << endl << "Printing the perc instruments in the array." << endl;
	for (i = 0; i < percArray.size(); i++)
	{
		cout << i + 1 << ". " << percArray.at(i) << endl;
	}
}
class TypeIns : public Musicians {
protected:
public:
	//TypeIns();
	void get();
	void show(char command);
private:
};
void TypeIns::get() {
	cout << "Type of instruments to be displayed" << endl <<
		"a.String instruments" << endl <<
		"b.wind instruments" << endl <<
		"c.Percussion instruments" << endl; 
	char menu;
	do {
		cout << "Enter a command a, b, or c: ";
		cin >> menu;
	} while (menu != 'a' && menu != 'b' && menu != 'c');
	show(menu);
}
void TypeIns::show(char command) {
	unsigned int i;
	switch (command)
	{
	case 'a':
		cout << endl << "Printing the string instruments in the array." << endl;
		for (i = 0; i < stringArray.size(); i++)
		{
			cout << i + 1 << ". " << stringArray.at(i) << endl;
		}
		break;
	case 'b':
		cout << endl << "Printing the wind instruments in the array." << endl;
		for (i = 0; i < windArray.size(); i++)
		{
			cout << i + 1 << ". " << windArray.at(i) << endl;
		}
		break;
	case 'c':
		cout << endl << "Printing the string instruments in the array." << endl;
		for (i = 0; i < percArray.size(); i++)
		{
			cout << i + 1 << ". " << percArray.at(i) << endl;
		}
		break;
	default:
		break;
	}
}
int main() 
{
	TypeIns huhu;
	huhu.get();
	return 0;
}