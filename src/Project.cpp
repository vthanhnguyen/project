/*
 * Project.cpp
 *
 *  Created on: Apr 26, 2020
 *
 */

#include "Project.h"
#include <iostream>

Assignment::Assignment()
{
	type = "";
	name = "";
	score = 0;
}

Assignment::Assignment(string s1, string s2, double n)
{
	type = s1;
	name = s2;
	score = n;
}

Grade::Grade()
{
	HW = NULL;
	Exams = NULL;
	Quizzes = NULL;
	Final = NULL;
	GradePercent = 0;
}

double Grade::calcExamPerc() {
	node *temp = Exams;

	if (temp == nullptr)
		return 0;
	else {
		double scoresum = 0; // Sum of all percentage of exams
		int count = 0; // How many exams there are
		bool dropLowest = false;
		double lowest = temp->data.score;
		int lowestIndex;
		int choice;
		cout << "Drop lowest Exam? (Enter 1 for Yes/ 0 for No): " << endl;
		cin >> choice;

		while (choice != 1 && choice != 0) {
			cout << "Invalid Choice, please enter Y or N: ";
			cin >> choice;
		}

		if (choice == 1)
			dropLowest = true;

		while (temp != nullptr) { // Gets the index for the lowest grade
			if (lowest > temp->data.score) {
				lowest = temp->data.score;
				lowestIndex = count;
			}

			temp = temp->next;
			count++;
		}

		count = 0;
		temp = Exams;
		if (dropLowest) {
			while (temp != nullptr) {
				if (count != lowestIndex) {
					scoresum += temp->data.score;
				}
				temp = temp->next;
				count++;
			}
			count--;
		} else {
			while (temp != nullptr) {
				scoresum += temp->data.score;
				temp = temp->next;
				count++;
			}
		}
		return (scoresum / static_cast<double>(count));
	}
}

double Grade::calcHWPerc() {
	node *temp = HW;

	if (temp == nullptr)
		return 0;
	else {
		double scoresum = 0; // Sum of all percentage of exams
		int count = 0; // How many exams there are
		bool dropLowest = false;
		double lowest = temp->data.score;
		int lowestIndex;
		int choice;
		cout << "Drop lowest HW? (Enter 1 for Yes/ 0 for No): " << endl;
		cin >> choice;

		while (choice != 1 && choice != 0) {
			cout << "Invalid Choice, please enter Y or N: ";
			cin >> choice;
		}

		if (choice == 1)
			dropLowest = true;

		while (temp != nullptr) { // Gets the index for the lowest grade
			if (lowest > temp->data.score) {
				lowest = temp->data.score;
				lowestIndex = count;
			}

			temp = temp->next;
			count++;
		}

		count = 0;
		temp = HW;
		if (dropLowest) {
			while (temp != nullptr) {
				if (count != lowestIndex) {
					scoresum += temp->data.score;
				}
				temp = temp->next;
				count++;
			}
			count--;
		} else {
			while (temp != nullptr) {
				scoresum += temp->data.score;
				temp = temp->next;
				count++;
			}
		}
		return (scoresum / static_cast<double>(count));
	}
}

double Grade::calcQuizzesPerc() {
	node *temp = Quizzes;

	if (temp == nullptr)
		return 0;
	else {
		double scoresum = 0; // Sum of all percentage of exams
		int count = 0; // How many exams there are
		bool dropLowest = false;
		double lowest = temp->data.score;
		int lowestIndex;
		int choice;
		cout << "Drop lowest Quiz? (Enter 1 for Yes/ 0 for No): " << endl;
		cin >> choice;

		while (choice != 1 && choice != 0) {
			cout << "Invalid Choice, please enter Y or N: ";
			cin >> choice;
		}

		if (choice == 1)
			dropLowest = true;

		while (temp != nullptr) { // Gets the index for the lowest grade
			if (lowest > temp->data.score) {
				lowest = temp->data.score;
				lowestIndex = count;
			}

			temp = temp->next;
			count++;
		}

		count = 0;
		temp = Quizzes;
		if (dropLowest) {
			while (temp != nullptr) {
				if (count != lowestIndex) {
					scoresum += temp->data.score;
				}
				temp = temp->next;
				count++;
			}
			count--;
		} else {
			while (temp != nullptr) {
				scoresum += temp->data.score;
				temp = temp->next;
				count++;
			}
		}
		return (scoresum / static_cast<double>(count));
	}
}

void Grade::calcGrade(){
	int HW_Weight, Exam_Weight, Quiz_Weight, Final_Weight;
	int choice = 1;
	while (choice !=0) {
	cout << "Please enter the weight (in percent) of each assignment type for your class: " << endl;
	cout << "HW Weight: " << endl; 		cin >> HW_Weight;
	cout << "Quiz Weight: " << endl; 	cin >> Quiz_Weight;
	cout << "Exam Weight: " << endl; 	cin >> Exam_Weight;
	cout << "Final Weight: " << endl; 	cin >> Final_Weight;

		if (HW_Weight + Quiz_Weight + Exam_Weight + Final_Weight != 100) {
			cout << "The sum of all your assignment's weight does not add up to 100%, please enter 1 if this was a mistake to retype your weight, or 0 if this was intentional:" << endl;
			cin >> choice;
		}
		else
			choice = 0;
	}

	GradePercent = (calcExamPerc() * (Exam_Weight * 0.01)) + (calcHWPerc() * (HW_Weight * 0.01)) + (calcQuizzesPerc() * (Quiz_Weight * 0.01)) + (Final->data.score * (Final_Weight * 0.01));
	cout << "Your current grade percentage is: " << GradePercent << "%" << endl;
	system("pause");
}

// Inserting Functions for Each List
void Grade::insertHW(node* newp)
{
	node* traverse = HW;
	if (HW == NULL) {
			HW = newp;
			newp->next = NULL;
		}
		else {
			while(traverse->next != NULL)
				traverse = traverse->next; //now we have traversed to the node before NULL
			traverse->next = newp; //assign the NULLED node to be the new Node
			traverse->next->next = NULL; // assign the node after the new node to be NULL
		}
}

void Grade::insertQ(node* newp)
{
	node* traverse = Quizzes;
	if (Quizzes == NULL) {
			Quizzes = newp;
			newp->next = NULL;
		}
		else {
			while(traverse->next != NULL)
				traverse = traverse->next; //now we have traversed to the node before NULL
			traverse->next = newp; //assign the NULLED node to be the new Node
			traverse->next->next = NULL; // assign the node after the new node to be NULL
		}
}

void Grade::insertE(node* newp)
{
	node* traverse = Exams;
	if (Exams == NULL) {
			Exams = newp;
			newp->next = NULL;
		}
		else {
			while(traverse->next != NULL)
				traverse = traverse->next; //now we have traversed to the node before NULL
			traverse->next = newp; //assign the NULLED node to be the new Node
			traverse->next->next = NULL; // assign the node after the new node to be NULL
		}
}

void Grade::insertF(node* newp)
{
	node* traverse = Final;
	if (Final == NULL) {
			Final = newp;
			newp->next = NULL;
		}
		else {
			while(traverse->next != NULL)
				traverse = traverse->next; //now we have traversed to the node before NULL
			traverse->next = newp; //assign the NULLED node to be the new Node
			traverse->next->next = NULL; // assign the node after the new node to be NULL
		}
}

// Adds the data to the correct spot and appends it to the file
// Function will request what type of assignment, the name you want to give it, and the score.
// Score format: Either in percentages (Ex: 69%) or Score/Total (Ex: 15/20)
void Grade::addData()
{
	bool validInput = false;
	string type, temp;
	string name = "";
	double score;
	int in;

		do
		{
				//get user inputs
			cout << "Which Type of Assignment Are Inputting?" << endl
				<< "---------------------------------------" << endl
				<< "1. Homework\n"
				<< "2. Quiz\n"
				<< "3. Exam\n"
				<< "4. Final\n"
				<< "\nUser Input: ";

				cin >> in;

				if(in == 1)
				{
					type = "HW";
					validInput = true;
				}
				else if(in == 2)
				{
					type = "QUIZ";
					validInput = true;
				}
				else if(in == 3)
				{
					type = "EXAM";
					validInput = true;
				}
				else if(in == 4)
				{
					type = "FINAL";
					validInput = true;
				}
				else
				{
					cout << "Invalid input..Enter again\n";
					system("pause");
					system("cls");
				}

		}while(validInput == false);


		cout << "\n\nEnter the name of the assignment: ";
		cin.ignore();
		getline(cin, temp);

		// Upper case all letters
		for (unsigned int i = 0; i < temp.length(); i++)
		{
			if (isAlpha(temp[i]))
				name += toupper(temp[i]);
			else
				name += temp[i];
		}

		cout << "Enter the percent of the assignment: ";
		cin >> score;

		//create new node and assign data
		node* n = new node; //create a new node and populate
		n->data.type = type;
		n->data.name = name;
		n->data.score = score;


		if(type == "HW")
		{
			insertHW(n);
		}
		else if(type == "QUIZ")
		{
			insertQ(n);
		}
		else if(type == "EXAM")
		{
			insertE(n);
		}
		else//final
		{
			insertF(n);
		}

}

void Grade::deleteAssignment()
{
	cout << "Which type of assignment do you want to delete? [Enter a number]" << endl
		 << "1. Homework" << endl
		 << "2. Quiz" << endl
		 << "3. Exam" << endl
		 << "4. Final" << endl
		 << "5. Cancel" << endl;
	int userInput;
	cin >> userInput;
	while (userInput > 5 && userInput < 0)
	{
		cout << "That's not a valid choice, please reenter your choice:";
		cin >> userInput;
	}

	switch (userInput) {
	case 1:
		deleteHW();
		break;

	case 2:
		deleteQuiz();
		break;
	case 3:
		deleteExam();
		break;
	case 4:
		deleteFinal();
		break;
	case 5:
		return;

	default:
		cout << "Invalid Input. Please Try Again." << endl;
	}

}

void Grade::deleteHW()
{
	int userInput;
	int count = printLL(HW);
	node *storeNext;
	node* temp;
	temp = HW;
	cout << "Enter the number of the assignment you would like to delete: ";
	cin >> userInput;
	while (userInput > count || userInput <= 0)
	{
		cout << "Invalid Input. Please Try Again: ";
		cin >> userInput;
	}

	if(userInput == 1)// Case 1: Delete Head
	{
		temp = HW->next;
		delete HW;
		HW = temp;
	}
	else if(userInput < count) // Case 2: Delete anywhere in the middle
	{
		for(int i = 0; i <userInput-1;i++)//finding the previous node of the node to be deleted
			temp = temp->next; //this node stores the node before the deleted node

		storeNext = temp->next->next; //this stores the next node afer the targeted deleted now
		temp->next = storeNext;

		delete temp;
		delete storeNext;
	}
	else // Case 3: Delete the tail
	{
		while(temp->next->next != NULL)
			temp = temp->next;
		temp = temp->next;
		temp = NULL;
	}
	cout << "Succesfully deleted the assignment"<<endl;

}

void Grade::deleteQuiz()
{
	int userInput;
	int count = printLL(Quizzes);
	node *storeNext;
	node* temp;
	temp = Quizzes;
	cout << "Enter the number of the assignment you would like to delete: ";
	cin >> userInput;
	while (userInput > count || userInput <= 0)
	{
		cout << "Invalid Input. Please Try Again: ";
		cin >> userInput;
	}

	if(userInput == 1)// Case 1: Delete Head
	{
		temp = Quizzes->next;
		delete Quizzes;
		Quizzes = temp;
	}
	else if(userInput < count) // Case 2: Delete anywhere in the middle
	{
		for(int i = 0; i <userInput-1;i++)//finding the previous node of the node to be deleted
			temp = temp->next; //this node stores the node before the deleted node

		storeNext = temp->next->next; //this stores the next node afer the targeted deleted now
		temp->next = storeNext;

		delete temp;
		delete storeNext;
	}
	else // Case 3: Delete the tail
	{
		while(temp->next->next != NULL)
			temp = temp->next;
		temp = temp->next;
		temp = NULL;
	}


	cout << "Succesfully deleted the assignment: ";

}
void Grade::deleteExam()
{
	int userInput;
	int count = printLL(Exams);
	node *storeNext;
	node* temp;
	temp = Exams;
	cout << "Enter the number of the assignment you would like to delete: ";
	cin >> userInput;
	while (userInput > count || userInput <= 0)
	{
		cout << "Invalid Input. Please Try Again: ";
		cin >> userInput;
	}

	if(userInput == 1)// Case 1: Delete Head
	{
		temp = Exams->next;
		delete Exams;
		Exams = temp;
	}
	else if(userInput < count) // Case 2: Delete anywhere in the middle
	{
		for(int i = 0; i <userInput-1;i++)//finding the previous node of the node to be deleted
			temp = temp->next; //this node stores the node before the deleted node

		storeNext = temp->next->next; //this stores the next node afer the targeted deleted now
		temp->next = storeNext;

		delete temp;
		delete storeNext;
	}
	else // Case 3: Delete the tail
	{
		while(temp->next->next != NULL)
			temp = temp->next;
		temp = temp->next;
		temp = NULL;
	}


	cout << "Succesfully deleted the assignment: ";

}
void Grade::deleteFinal()
{
	int userInput;
	int count = printLL(Final);
	node *storeNext;
	node* temp;
	temp = Final;
	cout << "Enter the number of the assignment you would like to delete: ";
	cin >> userInput;
	while (userInput > count || userInput <= 0)
	{
		cout << "Invalid Input. Please Try Again: ";
		cin >> userInput;
	}

	if(userInput == 1)// Case 1: Delete Head
	{
		temp = Final->next;
		delete Final;
		Final = temp;
	}
	else if(userInput < count) // Case 2: Delete anywhere in the middle
	{
		for(int i = 0; i <userInput-1;i++)//finding the previous node of the node to be deleted
			temp = temp->next; //this node stores the node before the deleted node

		storeNext = temp->next->next; //this stores the next node afer the targeted deleted now
		temp->next = storeNext;

		delete temp;
		delete storeNext;
	}
	else // Case 3: Delete the tail
	{
		while(temp->next->next != NULL)
			temp = temp->next;
		temp = temp->next;
		temp = NULL;
	}


	cout << "Succesfully deleted the assignment: ";

}

// Importing Info
// Function: Importing Student Info w/ Text File of the Student's ID
void Grade::loadInfo()
{
	ifstream input;
	string inputName;

	// Used to Input Data
	string temp;
	string tempName;

	// Requesting User Input for Input File
	cout << "Please Enter Your Student ID: ";
	cin >> inputName;

	inputName += ".txt";

	input.open(inputName.c_str());

	if (input.fail())
	{
//		system("cls");
		cout << "Could not locate file.";
		exit(1);
//		system("pause");
	}
	while (!input.eof())
	{
		node* newNode = new node; // Node that will be inserted within the respective linkedlist
		getline(input, temp);

		stringstream ss(temp);

		ss >> newNode->data.type;
		ss >> newNode->data.name;
		ss >> newNode->data.score;

		newNode->data.name = removeDashes(newNode->data.name);

		switch (newNode->data.type[0])
		{
			case 'H': insertHW(newNode); break;
			case 'Q': insertQ(newNode); break;
			case 'E': insertE(newNode); break;
			case 'F': insertF(newNode); break;
		}
	}

	input.close();
	system("cls");
}

// Exporting Info
// Function: Exporting Student Info w/ Text File of Their ID
void Grade::exportInfo()
{
	ofstream outFile;
	string name;
	node* temp = HW; // To Allow the program to automatically start exporting all the HW data

	cout << "Please Enter Your Student ID: ";
	cin >> name;
	name += ".txt";

	outFile.open(name.c_str());

	// Format: Homework --> Quiz --> Exams --> Final
	while (temp != NULL)
	{

		temp->data.name = insertDashes(temp->data.name);

		outFile << temp->data << endl;
		temp = temp->next;
	}

	temp = Quizzes;

	while (temp != NULL)
	{
		temp->data.name = insertDashes(temp->data.name);

		outFile << temp->data << endl;
		temp = temp->next;
	}

	temp = Exams;

	while (temp != NULL)
	{
		temp->data.name = insertDashes(temp->data.name);

		outFile << temp->data << endl;
		temp = temp->next;
	}

	temp = Final;

	while (temp != NULL)
	{
		temp->data.name = insertDashes(temp->data.name);

		outFile << temp->data << endl;
		temp = temp->next;
	}

	outFile.close();

}

// Displays the user's current data via the command prompt
void Grade::output()
{
	node* temp = HW; // To Allow the program to automatically start exporting all the HW data

	cout << "Your Report: " << endl
		<< "-------------------" << endl;

	// Format Order: Homework --> Quiz --> Exams --> Final
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}

	temp = Quizzes;

	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}

	temp = Exams;

	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}

	temp = Final;

	if (temp != NULL)
	{
		cout << temp->data << endl;
	}

	system("pause");

}

// isAlpha is to make all the letters of the assignment name to make importing and exporting files easier

bool Grade::isAlpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || ((c >= 'a' && c <= 'z')))
	{
		return true;
	}
	else
		return false;
}

// Using stringstream for importing will store each word into a different variable after each space
// Not wanted for Assignment Name if a space is present
// Changes spaces to dashes to keep the integrity of the assignment name
string Grade::insertDashes(string name)
{
	string temp = "";

	for (unsigned int i = 0; i < name.length(); i++)
	{
		if (name[i] == ' ')
		{
			temp += "-";
		}
		else
			temp += name[i];
	}

	return temp;
}

// Removes the dashes upon import to keep the integrity of the assignment name
// Example: chapter-#1-HW --> chapter #1 HW
string Grade::removeDashes(string name)
{
	string temp = "";

	for (unsigned int i = 0; i < name.length(); i++)
	{
		if (name[i] == '-')
		{
			temp += " ";
		}
		else
			temp += name[i];
	}

	return temp;
}

// Overloading << to display Assignment Type + Name + Score
ostream& operator<<(ostream& os, const Assignment& obj)
/*
{
	os << setw(5) << left << obj.type <<
		setw(20) << left << obj.name <<
		setw(5) << left << setprecision(2) << fixed << obj.score <<"%";
*/
{
	os << setw(10) << left << obj.type <<
		setw(20) << left << obj.name <<
		setw(6) << left << setprecision(1) << fixed << obj.score <<"%";

	return os;
}

// Helpful Functions:

int Grade::printLL(node *head)
{
	int count = 1;
	node *temp;
	temp = head;

	if (temp == nullptr)
	{
		cout << "The list is empty!!!\n";
	}
	cout << endl;
	while (temp != nullptr)
	{
		cout << count << ". " << temp->data << endl;
		temp = temp->next;
		count++;
	}

	return count;
}
