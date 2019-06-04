#include<iostream>
#include<string>
using namespace std;
const int arraysize = 100;
string student[arraysize][2] = {};
//[Arraysize] = Num Of Stu & [2]-> 0 = Name, 1 = Grade 
int menu()
{
	int choice;
	do
	{
		cout << endl;
		cout << " 1. Add a student" << endl;
		cout << " 2. Change a grade" << endl;
		cout << " 3. Search by ID" << endl;
		cout << " 4. Remove a student" << endl;
		cout << " 5. Print class roster" << endl;
		cout << " 6. Exit" << endl;
		cout << "Please enter your choice ===>" << endl; // choice number
		cin >> choice;
		cout << endl;
	} while (choice < 1 || choice>6);
	return choice;

}
int findID()
{
	int studentID;
	cout << endl;
	cout << "Please Enter Student ID" << endl;
	cin >> studentID;
	while (studentID<1 || studentID>arraysize)
	{
		cout << "studentID not found" << endl;
		cout << "Please Enter Student ID" << endl;
		cin >> studentID;
	}
	return studentID--;
}
bool displaystudent(int studentID)
{
	if (student[studentID][0].empty() && student[studentID][1].empty())
		//If the first and second string is empty then return false
		//Else cout all the informations student id & student name & student grade
	{
		cout << "Student with this studentID: " << studentID << " does not exist" << endl;
		return false;
	}
	else
	{
		cout << "Student Id: " << studentID +1 << endl;//This will cout the student ID
		cout << "Student Name: " << student[studentID][0] << endl;//This will cout the student name
		cout << "Student Grade: " << student[studentID][1] << endl;//This will cout the student grade
	}
}
void addastudent()
{
	int studentID;
	string grade;
	string name;
	studentID = findID();
	if (student[studentID][0].empty() && student[studentID][1].empty())
	{
		cout << "Please Enter Student Name" << endl;
		cin >> name;
		cout << "Please Enter Student Grade" << endl;
		cin >> grade;
		cout << "Student name  " << name << "  Student grade  " << grade << endl;
		cout << "Is Sucessfully Added" << endl;
		student[studentID][0] = name;
		student[studentID][1] = grade;
	}
	else
		cout << "------Duplicate ID--------------" << endl;
	//set the student[studentID][0] =name, to assign name to the first string

}
void removeastudent()
{
	int studentID;
	studentID = findID();
	if (student[studentID][0].empty() && student[studentID][1].empty())
	{
		cout << "Student is not on the list" << endl;
	}
	else
	{
		cout << "Student is on the list" << endl;
		(student[studentID][0].clear());
		(student[studentID][1].clear());
		cout << " |Student Is Removed| " << endl;
	}
	/*Using string member function .clear
	to remove the first&second string of that student Id*/
}
void changeagrade()
{
	int studentID;
	string change;
	cout << "You Want To Change A Student Grade " << endl;
	studentID = findID();
	if (student[studentID][0].empty() && student[studentID][1].empty())
	{
		cout << "Student is not on the list" << endl;
	}
	else
	{
		cout << "Student is on the list" << endl;
		cout << "Student Current grade is" << endl;
		cout << student[studentID][1] << endl;
		cout << "Change Student Grade To" << endl;
		cin >> change;
		student[studentID][1] = change;
		//set sutdent[studentID][1]=change, original student grade will automatically be clear/erase
		cout << "Student Grade Is Successfully Change to: " << student[studentID][1] << endl;
		/*Cout the brand new grade*/
	}
}
void searchbyid()
{
	int studentID;
	studentID = findID();
	/*Using the findId() function to cin the studen id
	and cout the 2 strings of that student id*/
	if (student[studentID][0].empty() && student[studentID][1].empty())
	{
		cout << "Student is not on the list" << endl;
	}
	else 
	{
		cout << "Student is on the list" << endl;
		cout << "Student Name: " << student[studentID][0] << endl;
		cout << "Student Grade: " << student[studentID][1] << endl;
	}
}
void printclassroster()
{
	
	cout << "Class Roster" << endl;
	for (int i = 0; i<arraysize; i++)
	{
		displaystudent(i);
		//i here is call and i basically means the studentID
	}
}

int main()
{
	while (true)
	{
		switch (menu())
		{
		case 1: cout << "1. Add a student" << endl;
			addastudent();
			break;
		case 2: cout << "2. Change a grade" << endl;
			changeagrade();
			break;
		case 3: cout << "3. Search by ID" << endl;
			searchbyid();
			break;
		case 4: cout << "4. Remove a student" << endl;
			removeastudent();
			break;
		case 5: cout << "5. Print class roster" << endl;
			printclassroster();
			break;
		default:
			exit(6);
		}
	}
	system("pause");
	return 0;
}