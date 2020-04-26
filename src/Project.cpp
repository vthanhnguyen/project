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
	HW = nullptr;
	Exams = nullptr;
	Quizzes = nullptr;
	Final = nullptr;
	GradePercent = 0;
}

double Grade::calcExamPerc() {
	node *temp = Exams;
	double scoresum = 0; // Sum of all percentage of exams
	double count = 0; // How many exams there are
	while (temp != nullptr) {
		scoresum += temp->score;
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
		scoresum += temp->score;
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
		scoresum += temp->score;
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
	GradePercent = (calcExamPerc() * (Exam_Weight * 0.01)) + (calcHWPerc() * (HW_Weight * 0.01)) + (calcQuizzesPerc() * (Quiz_Weight * 0.01)) + (Final->score * (Final_Weight * 0.01));
	cout << "Your current grade percentage is: " << GradePercent;
}

void Grade::insert(node *head, node *newp)
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
	string type,name;
	double score;
	int choice, in;
	do
	{
		//get user inputs
		cout << "Enter 1 for assignment type homework\n"
			 << "Enter 2 for assignment type quiz\n"
			 << "Enter 3 for assignment type exam\n"
			 << "Enter 4 for assignment type final\n";
		cin >> in;
		if(in == 1)
		{
			type = "hw";
		}
		if(in == 2)
		{
			type = "quiz";
		}
		if(in == 3)
		{
			type = "exam";
		}
		if(in == 4)
		{
			type = "final";
		}


		cout << "Enter the name of the assignment(quiz #1, etc.): ";
		cin >> name;

		cout << "Enter the percent of the assignment(.67=67%, 3/4c): ";
		cin >> score;

		//create new node and assign data
		node* n = new node; //create a new node and populate
		n->next = NULL;
		n->type = type;
		n->name = name;

		if(type == "hw")
		{

		}
		if(type == "quiz")
		{

		}
		if(type == "exam")
		{

		}



		cout << "Enter a positive number to add another assignment\nEnter a negitive number to stop.\n";
		cin >> choice;
	}while(choice >= 0);


}

//void Grade::loadInfo();

//void Grade::exportInfo();

//void Grade::deleteAssignment();


