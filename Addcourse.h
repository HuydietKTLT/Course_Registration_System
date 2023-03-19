#define _CRT_SECURE_NO_WARNINGS
#define BACKSLASH '\\'

#ifndef _ADDCOURSE_H_
#define _ADDCOURSE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdio>



typedef long long ll;
typedef long int li;

using namespace std;

struct Class
{
	string class_name;
	Student student;
	Class* pNext;
};

struct SchoolYear
{
	string year_name;
	Semester semester;
	SchoolYear* pNext;
};

struct Semester
{
	string semester_name;
	Course course;
	Semester* pNext;
};

struct Course
{
	int id;
	string course_name;
	string class_name;
	int number_credits;
	int number_students;
	string teacher_name;
	string day_of_week;
	string sessions;

	Student student;

	Course* pNext;
};

struct Student
{
	int student_ID;
	string first_name;
	string last_name;
	string gender;
	string date_of_birth;
	int social_ID;
	Student* pNext;
};



//The path which is formated: CURRENTSCHOOLYEAR//CURRENTSEMESTER//  in C++ string.
string currentSchoolYear_Semester_Cpp_string();

////The path which is formated: CURRENTSCHOOLYEAR//CURRENTSEMESTER//  in C string.
char* currentShoolYear_Semester_C_String(int getID);

//Get the data of the Course from File.txt
void getCourseDataFromFile(Course*& pHead);

//Print the data of Course from the system to file.txt
void printCourseToFile(Course* pHead);

//Print the data of course on the screen.
void printCourseToConsole(Course* pHead);

//Use for adding a course.
void addCourse(Course*& pHead);

//Use for deleting a course.
void deleteCourse(Course*& pHead);

void update_course_ID(Course*& cur);
void update_course_name(Course*& cur);
void update_class_name(Course*& cur);
void update_number_credits(Course*& cur);
void update_number_students(Course*& cur);
void update_day_week(Course*& cur);
void update_session(Course*& cur);

void update(Course*& cur);

void updateCourse(Course*& pHead);

//Add student one by one from the console.
void addStudentCourseWithConsole(Course* pHead);

void getStudentInfoFromFile(Student*& pHead);

void removeStudentFromCourse(Student*& pHead);


void deAllocateCourse(Course*& pHead);

#endif
