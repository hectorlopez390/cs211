#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Course
{
public:
  long CourseNum;
  string CourseName;
};

class Student
{
public:
  long StNo;
  Course Course1;
  Course Course2;
  Course Course3;
};

class Person
{
public:
  long SSN;
  string Fname;
  string Lname;
  int Age;
  char Gender;
};

class StudentProfile
{
public:
  Person PersonalInfo;
  Student StdInfo;
};

class StudentCollection
{
public:
  vector<StudentProfile> CS211;
};

int main()
{
  
  StudentCollection collection; //create student collection object

  StudentProfile new_entry; //create student profile object

  fstream fin;
  
  fin.open("data.txt");
  
  /* test input/output

     fin >> new_entry.PersonalInfo.SSN;
     
     collection.CS211.push_back(new_entry);

     cout << collection.CS211[0].PersonalInfo.SSN << endl;
  */
  
  fin >> new_entry.PersonalInfo.SSN;
  fin >> new_entry.PersonalInfo.Fname;
  fin >> new_entry.PersonalInfo.Lname;
  fin >> new_entry.PersonalInfo.Age;
  fin >> new_entry.PersonalInfo.Gender;
  fin >> new_entry.StdInfo.StNo;
  fin >> new_entry.StdInfo.Course1.CourseNum;
  fin >> new_entry.StdInfo.Course1.CourseName;
  fin >> new_entry.StdInfo.Course2.CourseNum;
  fin >> new_entry.StdInfo.Course2.CourseName;
  fin >> new_entry.StdInfo.Course3.CourseNum;
  fin >> new_entry.StdInfo.Course3.CourseName;
  
  while(!fin.eof())
    {
      collection.CS211.push_back(new_entry); //add new_entry to CS211 vector
      
      fin >> new_entry.PersonalInfo.SSN;
      fin >> new_entry.PersonalInfo.Fname;
      fin >> new_entry.PersonalInfo.Lname;
      fin >> new_entry.PersonalInfo.Age;
      fin >> new_entry.PersonalInfo.Gender;
      fin >> new_entry.StdInfo.StNo;
      fin >> new_entry.StdInfo.Course1.CourseNum;
      fin >> new_entry.StdInfo.Course1.CourseName;
      fin >> new_entry.StdInfo.Course2.CourseNum;
      fin >> new_entry.StdInfo.Course2.CourseName;
      fin >> new_entry.StdInfo.Course3.CourseNum;
      fin >> new_entry.StdInfo.Course3.CourseName;
      
      cout << "New student added successfully." << endl;
    }

  cout << "Printing student collection..." << endl << endl;
  
  for(int i = 0; i < collection.CS211.size(); i++)
    {
      cout << "SSN: " << collection.CS211[i].PersonalInfo.SSN << endl;
      cout << "First Name: " << collection.CS211[i].PersonalInfo.Fname << endl;
      cout << "Last Name: " << collection.CS211[i].PersonalInfo.Lname << endl;
      cout << "Age: " << collection.CS211[i].PersonalInfo.Age << endl;
      cout << "Gender: " << collection.CS211[i].PersonalInfo.Gender << endl;
      cout << "Student Number: " << collection.CS211[i].StdInfo.StNo << endl;
      cout << "Course 1 Number: " << collection.CS211[i].StdInfo.Course1.CourseNum << endl;
      cout << "Course 1 Name: " << collection.CS211[i].StdInfo.Course1.CourseName << endl;
      cout << "Course 2 Number: " << collection.CS211[i].StdInfo.Course2.CourseNum << endl;
      cout << "Course 2 Name: " << collection.CS211[i].StdInfo.Course2.CourseName << endl;
      cout << "Course 3 Number: " << collection.CS211[i].StdInfo.Course3.CourseNum << endl;
      cout << "Course 3 Name: " << collection.CS211[i].StdInfo.Course3.CourseName << endl;

      cout << endl;
    }
  cout << "Student collection successfully printed." << endl << endl;
  
  return 0;
}
