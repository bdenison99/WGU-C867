#include <iostream>
#include <string>
#include "softwareStudent.h"
#include "student.h"
#include "degree.h"

using namespace std;

// softwareStudent.cpp required as part of Requirement B

SoftwareStudent::SoftwareStudent()
{
	degreeType = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int studentAge,
	int daysComplete[COURSE_SAMPLE_SIZE],
	Degree degreeType
) : Student(studentID, firstName, lastName, emailAddress, studentAge, daysComplete, degreeType)
{
	degreeType = SOFTWARE;
}

Degree SoftwareStudent::getDegreeType()
{
	return SOFTWARE;
}

void SoftwareStudent::setdegreeType(Degree degreeType)
{
	this->degreeType = SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "Degree Program: " << degreeStrings[SOFTWARE] << endl;
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
	delete this;
}