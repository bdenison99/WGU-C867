#pragma once
#include<string>
#include "degree.h"

using namespace std;

// The student class
// Represents one student and associated information

class Student
{
protected:
	// these variables are defined in requirement D1.
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int* daysInCourse;
	Degree degreeType;  // To be populated in subclasses only 

public:
	// The course_sample_size is the size of the array of course completion days
	static const int COURSE_SAMPLE_SIZE = 3;

	// The default constructor
	Student();

	// A constructor with all variables filled including degree type (requirement D2C)
	Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysComplete[3], Degree degreeType);


	// Accessor functions per requirement D2A
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getStudentAge();
	int* getDaysInCourse();
	virtual Degree getDegreeType() = 0;  // requirement D2F for virtual function
	

	// Mutator functions per requirement D2B
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int studentAge);
	void setDaysInCourse(int daysComplete[COURSE_SAMPLE_SIZE]);

	
	virtual void setDegreeType(Degree degreeType);
	virtual void print() = 0;  // per requirement D2D

	// The default destructor per requirement D2E
	~Student();

};

