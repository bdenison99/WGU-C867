#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

// securityStudent.h required as part of Requirement B
// Subclass definitions taken from Requirement D3

class SecurityStudent : public Student
{
public:
	//add constructors
	SecurityStudent();

	SecurityStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int studentAge,
		int daysComplete[COURSE_SAMPLE_SIZE],
		Degree degreeType
	);

	void setdegreeType(Degree degreeType);
	Degree getDegreeType();
	void print();

	//add deconstructor

	~SecurityStudent();

};
