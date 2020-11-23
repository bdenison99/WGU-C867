#include <iostream>
#include <string>
#include "securityStudent.h"
#include "student.h"
#include "degree.h"

using namespace std;

// securityStudent.cpp required as part of Requirement B

SecurityStudent::SecurityStudent()
{
	degreeType = SECURITY; //check on if it should be Degree or Degree type
}

//check on this
SecurityStudent::SecurityStudent(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int studentAge,
	int daysComplete[COURSE_SAMPLE_SIZE],
	Degree degreeType
) : Student(studentID, firstName, lastName, emailAddress, studentAge, daysComplete, degreeType)
{
	degreeType = SECURITY;
}

Degree SecurityStudent::getDegreeType()
{
	return SECURITY;
}

void SecurityStudent::setdegreeType(Degree degreeType)
{
	this->degreeType = SECURITY;
}


void SecurityStudent::print()
{
	this->Student::print();
	cout << "Degree Program: " << degreeStrings[SECURITY] << endl;
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
	delete this;
}