/*
 * Project.h
 *
 *      Author: Anh Huynh | Kevin La | Thanh Nguyen
 *
 */


#ifndef PROJECT_H_
#define PROJECT_H_

#include <iostream>
#include <string>

using namespace std;

class Assignment
{
public:
	Assignment();
	Assignment(string, string, double);
	friend class Grade;

	string type; // Types: HW, Quizzes, Exams
	string name; // Name of assignment
	double score; // Percent of the assignment

};

class node : public Assignment
{
public:
	node* next;

};

class Grade
{

public:
	Grade(); // Constructor

	double calcExamPerc(); // Calculates the total percentage of exams | There will be an option to set a flag for dropping the lowest score
	double calcHWPerc(); // Calculates the total percentage of Homework
	double calcQuizzesPerc(); // Calculates the total percentage of Quizzes | There will be an option to set a flag for dropping the lowest score
	// All calculated by taking the sum of the percentages of the assignments and dividing by the number of that assignment.

	void calcGrade();
	// Calculates the percentage grade and puts it in GradePercent
	// Calculated by multiplying the average percentage of the assignment type by it's weight, and summed by all assignment types.

	void addData();
	// Adds the data to the correct spot and appends it to the file
	// Function will request what type of assignment, the name you want to give it, and the score.
	// Score format: Either in percentages (Ex: 69%) or Score/Total (Ex: 15/20)

	void loadInfo();
	// When program runs, the program will attempt to load pre existing information so you can add on to it or just review it.

	void exportInfo();
	// Exports all assignments of all types into a nice format so the program can load the file on run time.
	// Info will be exported in this format: <Assignment Type> <Assignment Name> <Score>

	void deleteAssignment();
	// Functionality: Select assignment type, which will display all assignment in that type
	// Enter the name of the assignment to delete it from the list

	void insert(node *head, node *newp); // Used for inserting nodes into the linked list

private: // Each of these nodes are the head pointer of their respective assignment types
	node *HW;
	node *Exams;
	node *Quizzes;
	node *Final; // There should only be 1 score in here
	double GradePercent;

};




#endif /* PROJECT_H_ */
