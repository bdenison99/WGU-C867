#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "student.h"

using namespace std;


// The default constructor
Roster::Roster()
{
	this->classRosterArray = nullptr;
	this->maxStudents = 0;
	this->lastIdx = -1;		// a -1 means no students

}

// Another constructor to set the max student size
Roster::Roster(int studentCount)
{
	this->maxStudents = studentCount; 
	this->lastIdx = -1;	// a -1 means no students yet
	this->classRosterArray = new Student*[studentCount];
}

Student* Roster::getStudentAt(int idx)
{
	return classRosterArray[idx];
}

//adding students to classRosterArray
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
{
	int classDays[Student::COURSE_SAMPLE_SIZE];
	classDays[0] = daysInCourse1;
	classDays[1] = daysInCourse2;
	classDays[2] = daysInCourse3;

	switch (degreeProgram)
	{
	case SOFTWARE:
		classRosterArray[lastIdx] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, studentAge, classDays, degreeProgram);
		break;
	case SECURITY:
		classRosterArray[lastIdx] = new SecurityStudent(studentID, firstName, lastName, emailAddress, studentAge, classDays, degreeProgram);
		break;
	case NETWORK:
		classRosterArray[lastIdx] = new NetworkStudent(studentID, firstName, lastName, emailAddress, studentAge, classDays, degreeProgram);
		break;
	}
}

void Roster::parseThenAdd(string dataRow)
{
	// Sample data row:
	// A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY
	// Format:
	// StudentID, firstName, lastName, emailAddress, studentAge, daysinclass1, daysinclass2, daysinclass3, degreeProgram

	if (lastIdx < maxStudents)
	{
		// Marker notes:
		// The right-hand marker is the index of the next comma in the data row
		// The left-hand marker is the index of the character after the previous comma, or 0 for the student ID since it's the first field

		lastIdx++;

		// Get Student ID from data row
		int rightMarker = dataRow.find(",");
		string studentID = dataRow.substr(0, rightMarker);

		// Get first name from data row
		int leftMarker = rightMarker + 1;
		rightMarker = dataRow.find(",", leftMarker);
		string firstName = dataRow.substr(leftMarker, (rightMarker - leftMarker));

		// Get last name from data row
		leftMarker = rightMarker + 1;
		rightMarker = dataRow.find(",", leftMarker);
		string lastName = dataRow.substr(leftMarker, (rightMarker - leftMarker));

		// Get email from data row
		leftMarker = rightMarker + 1;
		rightMarker = dataRow.find(",", leftMarker);
		string emailAddress = dataRow.substr(leftMarker, (rightMarker - leftMarker));

		// Get age from data row
		leftMarker = rightMarker + 1;
		rightMarker = dataRow.find(",", leftMarker);
		int studentAge = stoi(dataRow.substr(leftMarker, (rightMarker - leftMarker)));

		// Get days in classes from data row
		leftMarker = rightMarker + 1;
		rightMarker = dataRow.find(",", leftMarker);
		int daysInClass1 = stoi(dataRow.substr(leftMarker, (rightMarker - leftMarker)));

		leftMarker = rightMarker + 1;
		rightMarker = dataRow.find(",", leftMarker);
		int daysInClass2 = stoi(dataRow.substr(leftMarker, (rightMarker - leftMarker)));

		leftMarker = rightMarker + 1;
		rightMarker = dataRow.find(",", leftMarker);
		int daysInClass3 = stoi(dataRow.substr(leftMarker, (rightMarker - leftMarker)));

		// Get degree program from data row
		leftMarker = rightMarker + 1;
		rightMarker = dataRow.find(",", leftMarker);
		string degString = dataRow.substr(leftMarker, (rightMarker - leftMarker));

		// This is a hack!  I'm not sure what the right way to do this is
		// The 3rd character in each degree string is the first one that yields a unique value 
		// per degree program:
		// SOFTWARE = F
		// SECURITY = C
		// NETWORK = T
		Degree degree;
		if (degString.substr(2, 1) == "F")
		{
			degree = SOFTWARE;
		}
		else if (degString.substr(2, 1) == "C")
		{
			degree = SECURITY;
		}
		else if (degString.substr(2, 1) == "T")
		{
			degree = NETWORK;
		}
		else
		{
			cout << "INVALID DEGREE PROGRAM IN DATA!" << endl;
			cout << degString << endl;
			exit(-1);
		}

		add(studentID, firstName, lastName, emailAddress, studentAge, daysInClass1, daysInClass2, daysInClass3, degree);
	}
	else
	{
		cout << "ERROR!  TOO MANY STUDENT RECORDS!" << endl;
		exit(-1);
	}
}

void Roster::print_All()
{
	for (int i = 0; i <= this->lastIdx; i++) (this->classRosterArray)[i]->print();
}

bool Roster::remove(string studentID)
{
	bool located = false;  // when true indicates student record located on roster
	for (int i = 0; i <= lastIdx; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			// set located flag to true, delete the student record
			// then move the last element of the roster to this location
			// and decrement the last index counter
			located = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIdx];
			lastIdx--;
		}
	}
	if (located == false)
	{
		cout << "Unable to locate and delete a student with ID " << studentID << "!" << endl;
	}
	return located;
}

void Roster::printAverageDays(string studentID)
{

	for (int i = 0; i < lastIdx; i++)
	{
		if (studentID == classRosterArray[i]->getStudentID())
		{

			int* numDaysComplete = classRosterArray[i]->getDaysInCourse();
			cout << "The average days in a course for " << studentID << " is " << (((float)numDaysComplete[0] + (float)numDaysComplete[1] + (float)numDaysComplete[2]) / 3) << endl;

		}
	}
}

//checks validity of email
void Roster::printInvalidEmails()
{
	cout << "The following are invalid email addresses: " << endl;
	for (int i = 0; i < lastIdx; i++)
	{
		string email = classRosterArray[i]->getEmailAddress();

		if ((email.find("@") == string::npos) || (email.find(".") == string::npos) || (email.find(" ") != string::npos))
		{
			cout << "The following email address is invalid:  " << classRosterArray[i]->getEmailAddress() << endl;
		}
	}

}

//print by degree program
void Roster::printByDegreeProgram(int degreeProgram)
{
	cout << "Types of degrees: " << degreeStrings[degreeProgram] << endl;
	for (int i = 0; i <= lastIdx; i++)
	{
		if (this->classRosterArray[i]->getDegreeType() == degreeProgram)  this->classRosterArray[i]->print();

	}
}

Roster::~Roster()
{
	for (int i = 0; i < maxStudents; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}


// This is where the program starts...
int main()
{
	// Acknowledgements:
	// David Bishop's Book repository video examples helped me figure out how to do an array of pointers and access elements correctly
	// https://www.youtube.com/watch?v=YdeJqqQ0M98&list=PLy3px7ccyKLdBTH2gQDomCdwklfpTXYi9
	// Accessed between 2/15/2020 and 3/7/2020

	// The next 4 lines meet requirement F1
	cout << "Course:      Scripting and Programming - Applications – C867" << endl;
	cout << "Language:    C++" << endl;
	cout << "Student ID : #001229869" << endl;
	cout << "Name:        Bart Denison" << endl;

	const int numStudents = 5;
	  
	string studentData[numStudents] =
	{
		"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Bart,Denison,bdenison99@hotmail.com,46,10,10,10,SOFTWARE"  // Requirement A
	};

	Roster * classRoster = new Roster(numStudents);  // Requirement F2

	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parseThenAdd(studentData[i]);
	}

	//displaying all students in roster
	cout << "Student Roster" << endl;
	classRoster->print_All();
	cout << endl;
	
	//printing average days of 3 courses
	cout << "Average number of days for each student in 3 courses: " << endl;
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->printAverageDays(classRoster->getStudentAt(i)->getStudentID());
	}
	cout << endl;

	//printing invalid emails
	classRoster->printInvalidEmails();
	cout << endl;


	// Displaying roster for each program type
	cout << "Printing out Network students: ";
	classRoster->printByDegreeProgram((int)NETWORK);
	cout << endl;


	cout << "Printing out Security students: ";
	classRoster->printByDegreeProgram((int)SECURITY);
	cout << endl;

	cout << "Printing out Software students: ";
	classRoster->printByDegreeProgram((int)SOFTWARE);
	cout << endl;


	//removing student A3, twice
	cout << "Remove Student A3" << endl;
	classRoster->remove("A3");
	classRoster->remove("A3");  // This line should print an error
	cout << endl;

	// Just a pause to help Visual Studio keep the debug console open
	system("pause");
	return 0;

}