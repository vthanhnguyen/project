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

	// Menu 2 --> User can add, delete, or display all the currnet assignments they have on file.
	// They can Export the info and calculate their weighted grades
	// Program will end if they select 
	do {
		cout << "Phase 2" << endl
			<< "-------------------" << endl
			<< "1. Add Assignments" << endl
			<< "2. Delete Assignments" << endl
			<< "3. Display All Assignments" << endl
			<< "4. Calculate Grades" << endl
			<< "5. Export Info" << endl
			<< "6. Exit" << endl
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
			user.deleteAssignment();
			break;
		case 3:
			system("cls");
			user.output();
			break;
		case 4:
			system("cls");
			user.calcGrade();
			break;
		case 5:
			system("cls");
			user.exportInfo();
			break;
		case 6: exit(1); break;

		default:
			system("cls");
			cout << "Invalid Input. Please Try Again." << endl;
			system("pause");
		}

		system("cls");
	} while (true);

	
}
