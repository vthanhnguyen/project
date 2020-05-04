/*
 * Project.cpp
 *
 *  Created on: Apr 26, 2020
 *
 */

#include "Project.h"
#include <iostream>

bool gradeCalculated = false;
bool newData = false;
bool dropLowestHW = false;
bool dropLowestExam = false;
bool dropLowestQuiz = false;

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
	HWPercent = 0;
	ExamPercent = 0;
	QuizPercent = 0;
	GradePercent = 0;
}

double Grade::calcExamPerc() {
	node *temp = Exams;

	if (temp == NULL) {
		ExamPercent = -1;
		return 0; }
	else {
		double scoresum = 0; // Sum of all percentage of exams
		int count = 0; // How many exams there are
		double lowest = temp->data.score;
		int lowestIndex;

		while (temp != NULL) { // Gets the index for the lowest grade
			if (lowest > temp->data.score) {
				lowest = temp->data.score;
				lowestIndex = count;
			}

			temp = temp->next;
			count++;
		}

		count = 0;
		temp = Exams;
		if (dropLowestExam) {
			while (temp != NULL) {
				if (count != lowestIndex) {
					scoresum += temp->data.score;
				}
				temp = temp->next;
				count++;
			}
			count--;
		} else {
			while (temp != NULL) {
				scoresum += temp->data.score;
				temp = temp->next;
				count++;
			}
		}
		if (count == 0)
			ExamPercent = -1;
		else
		ExamPercent = (scoresum / static_cast<double>(count));
		return ExamPercent;
	}
}

double Grade::calcHWPerc() {
	node *temp = HW;

	if (temp == NULL) {
		HWPercent = -1;
		return 0; }
	else {
		double scoresum = 0; // Sum of all percentage of exams
		int count = 0; // How many exams there are
		double lowest = temp->data.score;
		int lowestIndex;

		while (temp != NULL) { // Gets the index for the lowest grade
			if (lowest > temp->data.score) {
				lowest = temp->data.score;
				lowestIndex = count;
			}

			temp = temp->next;
			count++;
		}

		count = 0;
		temp = HW;
		if (dropLowestHW) {
			while (temp != NULL) {
				if (count != lowestIndex) {
					scoresum += temp->data.score;
				}
				temp = temp->next;
				count++;
			}
			count--;
		} else {
			while (temp != NULL) {
				scoresum += temp->data.score;
				temp = temp->next;
				count++;
			}
		}
		if (count == 0)
			HWPercent = -1;
		else
		HWPercent = (scoresum / static_cast<double>(count));
		return HWPercent;
	}
}

double Grade::calcQuizzesPerc() {
	node *temp = Quizzes;

	if (temp == NULL) {
		QuizPercent = -1;
		return 0; }
	else {
		double scoresum = 0; // Sum of all percentage of exams
		int count = 0; // How many exams there are
		double lowest = temp->data.score;
		int lowestIndex;

		while (temp != NULL) { // Gets the index for the lowest grade
			if (lowest > temp->data.score) {
				lowest = temp->data.score;
				lowestIndex = count;
			}

			temp = temp->next;
			count++;
		}

		count = 0;
		temp = Quizzes;
		if (dropLowestQuiz) {
			while (temp != NULL) {
				if (count != lowestIndex) {
					scoresum += temp->data.score;
				}
				temp = temp->next;
				count++;
			}
			count--;
		} else {
			while (temp != NULL) {
				scoresum += temp->data.score;
				temp = temp->next;
				count++;
			}
		}

		if (count == 0)
		QuizPercent = -1;
		else
		QuizPercent = (scoresum / static_cast<double>(count));
		return QuizPercent;
	}
}

void Grade::calcGrade(){
	calcExamPerc();
	calcHWPerc();
	calcQuizzesPerc();
	int HW_Weight, Exam_Weight, Quiz_Weight, Final_Weight;
	int choice = 1;
	while (choice !=0) {
	cout << "Please enter the weight (in percent) of each assignment type for your class: " << endl;
	cout << "HW Weight: " << endl; 		cin >> HW_Weight;
	cout << "Quiz Weight: " << endl; 	cin >> Quiz_Weight;
	cout << "Exam Weight: " << endl; 	cin >> Exam_Weight;
	cout << "Final Weight: " << endl; 	cin >> Final_Weight;

		if (HW_Weight + Quiz_Weight + Exam_Weight + Final_Weight != 100) {
			cout << "The sum of all your assignment's weight does not add up to 100%, please enter 1 if this was a mistake to retype your weight, or 0 if this was intentional, keep in mind this may mess with your grade calculations:" << endl;
			cin >> choice;
		}
		else
			choice = 0;
	}

	double FinalGrade;
	if (Final == NULL) FinalGrade = -1;
	else FinalGrade = Final->data.score;

	double percXWF = 0; // the sum of every type of assignment's percentage times it's weighting factor
	// This part takes care of any empty assignment types and ignores them in the grade calculation
	int totalWeight=0;
	if (HWPercent >= 0) {
		totalWeight += HW_Weight;
		percXWF += (HWPercent * (HW_Weight * 0.01));
	}
	if (ExamPercent >= 0) {
		totalWeight += Exam_Weight;
		percXWF += (ExamPercent * (Exam_Weight * 0.01));
	}
	if (QuizPercent >= 0) {
		totalWeight += Quiz_Weight;
		percXWF += (QuizPercent * (Quiz_Weight * 0.01));
	}
	if (FinalGrade >= 0) {
		totalWeight += Final_Weight;
		percXWF += (FinalGrade * (Final_Weight * 0.01));
	}

	GradePercent = (percXWF / totalWeight) * 100;
	cout << "Your current grade percentage is: " << setprecision(2) << fixed << GradePercent << "%" << endl;

	gradeCalculated = true;
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
// Score format: Percentages (Ex: 69%)
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

		newData = true;

}

void Grade::deleteAssignment()
{
	newData = true;
	cout << "\nWhich type of assignment do you want to delete?" << endl
		<< "1. Homework" << endl
		<< "2. Quiz" << endl
		<< "3. Exam" << endl
		<< "4. Final" << endl
		<< "5. Cancel" << endl
		<< "\nUser Input: ";
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
		node *storeNext = new node;
		node* temp = new node;
		node* temp2 = new node;
		temp = HW;

		if (HW == NULL)
			return;

		cout << "Enter the associated number of the assignment to delete: ";
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
			for(int i = 0; i <userInput-2;i++)//finding the previous node of the node to be deleted
				temp = temp->next; //this node stores the node before the deleted node

			storeNext = temp->next->next; //this stores the next node afer the targeted deleted now
			temp2 = temp->next;
			temp->next = storeNext;

			delete temp2;

		}
		else // Case 3: Delete the tail
		{
			while(temp->next->next != NULL)
				temp = temp->next;
			temp = temp->next;
			temp = NULL;
		}
		cout << "Successfully deleted the assignment"<<endl;

}


void Grade::deleteQuiz()
{
	int userInput;
	int count = printLL(Quizzes);
	node* storeNext = new node;
	node* temp = new node;
	node* temp2 = new node;
	temp = Quizzes;

	if (Quizzes == NULL)
		return;

	cout << "Enter the associated number of the assignment to delete: ";
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
		for(int i = 0; i <userInput-2;i++)//finding the previous node of the node to be deleted
			temp = temp->next; //this node stores the node before the deleted node

		storeNext = temp->next->next; //this stores the next node afer the targeted deleted now
		temp2 = temp->next;
		temp->next = storeNext;

		delete temp2;
	}
	else // Case 3: Delete the tail
	{
		while(temp->next->next != NULL)
			temp = temp->next;
		temp = temp->next;
		temp = NULL;
	}


	cout << "Successfully deleted the assignment: ";

}
void Grade::deleteExam()
{
	int userInput;
	int count = printLL(Exams);
	node* storeNext = new node;
	node* temp = new node;
	node* temp2 = new node;
	temp = Exams;

	if (Exams == NULL)
		return;

	cout << "Enter the associated number of the assignment to delete: ";
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
		for(int i = 0; i <userInput-2;i++)//finding the previous node of the node to be deleted
			temp = temp->next; //this node stores the node before the deleted node

		storeNext = temp->next->next; //this stores the next node afer the targeted deleted now
		temp2 = temp->next;
		temp->next = storeNext;

		delete temp2;
	}
	else // Case 3: Delete the tail
	{
		while(temp->next->next != NULL)
			temp = temp->next;
		temp = temp->next;
		temp = NULL;
	}


	cout << "Successfully deleted the assignment: ";

}
void Grade::deleteFinal()
{
	int userInput;
	int count = printLL(Final);
	node* storeNext = new node;
	node* temp = new node;
	node* temp2 = new node;
	temp = Final;

	if (Final == NULL)
		return;

	cout << "Enter the associated number of the assignment to delete: ";
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
		for(int i = 0; i <userInput-2;i++)//finding the previous node of the node to be deleted
			temp = temp->next; //this node stores the node before the deleted node

		storeNext = temp->next->next; //this stores the next node afer the targeted deleted now
		temp2 = temp->next;
		temp->next = storeNext;

		delete temp2;
	}
	else // Case 3: Delete the tail
	{
		while(temp->next->next != NULL)
			temp = temp->next;
		temp = temp->next;
		temp = NULL;
	}


	cout << "Successfully deleted the assignment: ";
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
		cout << "Could not locate file.";
		exit(1);
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
}

// Exporting Info
// Function: Exporting Student Info w/ Text File of Their ID
void Grade::exportInfo()
{
	if (newData)
	{
	ofstream outFile;
	string name;
	node* temp = HW; // To Allow the program to automatically start exporting all the HW data

	cout << "Please Enter Your Student ID to save your information: ";
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
	else
		cout << "No new data was added so there is nothing to export." << endl;

}

// Displays the user's current data via the command prompt
void Grade::output()
{
	node* temp = HW; // To Allow the program to automatically start exporting all the HW data

	cout << "Your Report: " << endl
		<< "-------------------" << endl;

	cout << setw(10) << left << "Type:" <<
		setw(20) << left << "Assignment Name:" <<
		setw(6) << left << "Grade: " << endl;

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

void Grade::dailyReport()
{
	if (gradeCalculated) {
	cout << "Your Daily Summary: " << endl
		<< "-------------------" << endl;
	if (HWPercent >= 0) cout << "Homework: " << setprecision(2) << fixed << HWPercent << "%" << endl;
	else cout << "Homework: No Assignments" << endl;
	if (QuizPercent >= 0)cout << "Quiz: " << setprecision(2) << fixed << QuizPercent << "%" << endl;
	else cout << "Quiz: No Assignments" << endl;
	if (ExamPercent >= 0)cout << "Exam: " << setprecision(2) << fixed << ExamPercent << "%" << endl;
	else cout << "Exam: No Assignments" << endl;
	cout << "Total Grade: " << setprecision(2) << fixed << GradePercent << "%" << endl;
	}
}

void Grade::options()
{
	cout << "Enter a number to toggle their settings: " << endl;
	int userInput;
	do {
	cout << "1. Drop Lowest HW: ";
	if (dropLowestHW) cout << "True" << endl;
	else cout << "False" << endl;
	cout << "2. Drop Lowest Quiz: ";
	if (dropLowestQuiz) cout << "True" << endl;
	else cout << "False" << endl;
	cout << "3. Drop Lowest Exam: ";
	if (dropLowestExam) cout << "True" << endl;
	else cout << "False" << endl;
	cout << "4. Exit" << endl;
	cin >> userInput;

	switch (userInput) {
	case 1:
		dropLowestHW = !dropLowestHW;
		break;
	case 2:
		dropLowestQuiz = !dropLowestQuiz;
		break;
	case 3:
		dropLowestExam = !dropLowestExam;
		break;
	case 4:
		return;
	default:
		cout << "Invalid Input. Please Try Again." << endl;
		system("pause");
	}
	} while (userInput != 4);
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

	if (temp == NULL)
	{
		cout << "The list is empty!!!\n";
	}
	cout << endl;
	while (temp != NULL)
	{
		cout << count << ". " << temp->data << endl;
		temp = temp->next;
		count++;
	}

	return count;
}
