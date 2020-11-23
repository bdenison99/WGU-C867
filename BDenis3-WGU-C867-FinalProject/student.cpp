#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

//constructor default
Student::Student()
{}

// constructor using all values
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysComplete[3], Degree degreeType)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	this->daysInCourse = new int[COURSE_SAMPLE_SIZE];
	for (int i = 0; i < COURSE_SAMPLE_SIZE; i++)
		this->daysInCourse[i] = daysComplete[i];

}

//Assessors & Mutators

string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getStudentAge()
{
	return studentAge;
}

int* Student::getDaysInCourse()
{
	return daysInCourse;
}

Degree Student::getDegreeType()
{
	// Leaving the implementation empty per requirement D2F
	// however, there must be a return for this function, so returning an empty Degree class.
	return Degree();
}

void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int studentAge)
{
	this->studentAge = studentAge;
}

void Student::setDaysInCourse(int daysComplete[COURSE_SAMPLE_SIZE])
{
	for (int i = 0; i < COURSE_SAMPLE_SIZE; i++)
		this->daysInCourse[i] = daysComplete[i];

}

void Student::setDegreeType(Degree degreeType)
{
}

void Student::print()
{
	// using getters per task requirements
	cout << "StudentID: " << getStudentID() << "\t";
	cout << "First Name: " << getFirstName() << "\t";
	cout << "Last Name: " << getLastName() << "\t";
	cout << "Email Address: " << getEmailAddress() << "\t";
	cout << "Age: " << getStudentAge() << "\t";
	cout << "Days in Courses: " << getDaysInCourse()[0] << " " << getDaysInCourse()[1] << " " << getDaysInCourse()[2] << "\t";
}

// Destructor
Student::~Student()
{

}

