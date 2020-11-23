#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "degree.h"

using namespace std;

class Roster {
private:
	int lastIdx;
	int maxStudents;
	Student ** classRosterArray;  // Requirement E1


public:
	Roster();				// default constructor
	Roster(int capacity);	// A constructor that sets max size to capacity

	Student* getStudentAt(int idx);
	void parseThenAdd(string studentData);
	void add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int days1, int days2, int days3, Degree degreeType);
	void print_All();
	bool remove(string studentID);
	void printAverageDays(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);

	~Roster(); //destructor
};
