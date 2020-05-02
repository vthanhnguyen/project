// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Project.h"

using namespace std;

int main() {
	
	bool validInput = false;
	int userInput;
	Grade user;

	// User Input for Importing Data
	do {
		cout << "Phase 1" << endl
			<< "-------------" << endl
			<< "1. New User" << endl
			<< "2. Load Info" << endl
			<< "3. Exit" << endl
			<< "\nUser Input: ";

		cin >> userInput;

		switch (userInput)
		{
		case 1:
			system("cls");
			validInput = true;
			break;
		case 2: 
			system("cls");
			user.loadInfo();
			validInput = true;
			break;
		case 3: exit(1); break;

		default:
			system("cls");
			cout << "Invalid Input. Please Try Again." << endl;
			system("pause");
		}
	} while (validInput == false);

	do {
		cout << "Phase 2" << endl
			<< "-------------" << endl
			<< "1. Add Assignments" << endl
			<< "2. Display All Assignments" << endl
			<< "3. Export Info" << endl
			<< "4. Exit" << endl
			<< "\nUser Input: ";

		cin >> userInput;

		switch (userInput)
		{
		case 1:
			system("cls");
			user.addData();
			break;
		case 2:
			system("cls");
			user.output();
			break;
		case 3:
			system("cls");
			user.exportInfo();
			break;
		case 4: exit(1); break;

		default:
			system("cls");
			cout << "Invalid Input. Please Try Again." << endl;
			system("pause");
		}

		system("cls");
	} while (true);

	
}
