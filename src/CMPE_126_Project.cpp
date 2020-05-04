// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include "Project.h"

using namespace std;

int main() {
	
	bool validInput = false;
	int userInput;
	Grade user;

	// Menus 1 --> Ask user if they want to import their existing data. If not, go to menu 2 directly
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
			validInput = true;
			break;
		case 2: 
			user.loadInfo();
			validInput = true;
			break;
		case 3: exit(1); break;

		default:
			cout << "Invalid Input. Please Try Again." << endl;
			system("pause");
		}
		system("cls");

	} while (validInput == false);

	cout << "Note: All assignments will calculate into your final grade unless you set flags to drop them in the options menu." << endl << endl;

	// Menu 2 --> User can add, delete, or display all the current assignments they have on file.
	// They can Export the info and calculate their weighted grades
	// Program will end if they select 
	do {
		cout << "Phase 2" << endl
			<< "-------------------" << endl
			<< "1. Add Assignments" << endl
			<< "2. Delete Assignments" << endl
			<< "3. Display All Assignments" << endl
			<< "4. Calculate Grades" << endl
			<< "5. Manage Options" << endl
			<< "6. Exit" << endl
			<< "\nUser Input: ";

		cin >> userInput;

		switch (userInput)
		{
		case 1:
			user.addData();
			break;
		case 2:
			user.deleteAssignment();
			break;
		case 3:
			user.output();
			break;
		case 4:
			user.calcGrade();
			break;
		case 5:
			user.options();
			break;
		case 6:
			user.exportInfo();
			user.dailyReport(); // Doesn't run unless calcGrade was ran.
			exit(1); break;

		default:
			cout << "Invalid Input. Please Try Again." << endl;
			system("pause");
		}

	} while (true);

	
}
