#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

// SoftwareStudent definition taken from Requirement D3
class SoftwareStudent : public Student
{
public:
	//add constructors
	SoftwareStudent();

	SoftwareStudent(
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

	~SoftwareStudent();

};
