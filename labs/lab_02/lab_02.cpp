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
  
  StudentCollection collection;

  StudentProfile new_entry;

  fstream fin;
  
  fin.open("data.txt");
  
  /* test output

     fin >> new_entry.PersonalInfo.SSN;
     
     collection.CS211.push_back(new_entry);

     cout << collection.CS211[0].PersonalInfo.SSN << endl;

  */
  return 0;
}
