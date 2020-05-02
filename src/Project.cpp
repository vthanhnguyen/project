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
	double scoresum = 0; // Sum of all percentage of exams
	double count = 0; // How many exams there are
	while (temp != nullptr) {
		scoresum += temp->data.score;
		temp = temp->next;
		count++;
	}
	return (scoresum / count);
}
double Grade::calcHWPerc() {
	node *temp = HW;
	double scoresum = 0; // Sum of all percentage of HW
	double count = 0; // How many HWs there are
	while (temp != nullptr) {
		scoresum += temp->data.score;
		temp = temp->next;
		count++;
	}
	return (scoresum / count);
}

double Grade::calcQuizzesPerc() {
	node *temp = Quizzes;
	double scoresum = 0; // Sum of all percentage of HW
	double count = 0; // How many HWs there are
	while (temp != nullptr) {
		scoresum += temp->data.score;
		temp = temp->next;
		count++;
	}
	return (scoresum / count);
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
	cout << "Your current grade percentage is: " << GradePercent;
}

void Grade::insert(node* head, node* newp)
{
	if (head == NULL) {
		head = newp;
		newp->next = NULL;
	} else {
		newp->next = head;
		head = newp;
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
	int choice, in;

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

		
		cout << "\n\nEnter the name of the assignment(quiz #1, etc.): ";
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
			insert(HW, n);
		}
		else if(type == "QUIZ")
		{
			insert(Quizzes, n);
		}
		else if(type == "EXAM")
		{
			insert(Exams, n);
		}
		else//final
		{
			insert(Final, n);
		}

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

	input.open(inputName.c_str());

	while (!input.eof())
	{
		node* newNode = new node; // Node that will be inserted within the respected linkedlist
		getline(input, temp);

		stringstream ss(temp);
		
		ss >> newNode->data.type;
		ss >> newNode->data.name;
		ss >> newNode->data.score;

		switch (newNode->data.type[0])
		{
			case 'H': insert(HW, newNode); break;
			case 'Q': insert(Quizzes, newNode); break;
			case 'E': insert(Exams, newNode); break;
			case 'F': insert(Final, newNode); break;
		}
	}
	
	input.close();

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

	outFile.open(name.c_str()); 

	// Format: Homework --> Quiz --> Exams --> Final
	while (temp != NULL)
	{
		outFile << temp->data << endl;
		temp = temp->next;
	}

	temp = Quizzes;

	while (temp != NULL)
	{
		outFile << temp->data << endl;
		temp = temp->next;
	}

	temp = Exams;

	while (temp != NULL)
	{
		outFile << temp->data << endl;
		temp = temp->next;
	}
	
	temp = Final;

	while (temp != NULL)
	{
		outFile << temp->data << endl;
	}

	outFile.close();

}


void Grade::output()
{
	node* temp = HW; // To Allow the program to automatically start exporting all the HW data

	cout << "Your Report: " << endl;

	// Format: Homework --> Quiz --> Exams --> Final
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

bool Grade::isAlpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || ((c >= 'a' && c <= 'z')))
	{
		return true;
	}
	else
		return false;
}
// Overloading << to display Assignment Type + Name + Score
ostream& operator<<(ostream& os, const Assignment& obj)
{ 
	cout << obj.type << " " << obj.name << " " << obj.score <<"%";
	return os;
}
