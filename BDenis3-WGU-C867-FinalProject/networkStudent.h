#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

// networkStudent.h required as part of Requirement B
// Subclass definitions taken from Requirement D3


class NetworkStudent : public Student
{
public:
	// add default constructor
	NetworkStudent();

	// constructor with all values specified
	NetworkStudent(
		string studentId,
		string firstName,
		string lastName,
		string emailAddress,
		int studentAge,
		int daysComplete[COURSE_SAMPLE_SIZE],
		Degree degreeType
	);

	void setDegreeType(Degree degreeType);
	Degree getDegreeType();  // Override defined in requirement D3

	void print();

	//add deconstructor

	~NetworkStudent();

};