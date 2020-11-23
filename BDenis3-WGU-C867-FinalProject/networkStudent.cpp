#include <iostream>
#include <string>
#include "networkStudent.h"
#include "student.h"
#include "degree.h"

using namespace std;


NetworkStudent::NetworkStudent()
{
	degreeType = NETWORK;
}

// This is the Network Student class which 
NetworkStudent::NetworkStudent(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int studentAge,
	int daysComplete[COURSE_SAMPLE_SIZE],
	Degree degreeType
) : Student(studentID, firstName, lastName, emailAddress, studentAge, daysComplete, degreeType)
{
	degreeType = NETWORK;
}

Degree NetworkStudent::getDegreeType()
{
	return NETWORK;
}

void NetworkStudent::setDegreeType(Degree degreeType)
{
	this->degreeType = NETWORK;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "Degree Program: " << degreeStrings[NETWORK] << endl;
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}