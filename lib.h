#define _CRT_SECURE_NO_WARNINGS
#define BACKSLASH '\\'

#ifndef _ADDCOURSE_H_
#define _ADDCOURSE_H_

//Thanh niên cái 

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <direct.h>
#include <conio.h>

//////////////////

typedef long long ll;
typedef long int li;

using namespace std;

struct Class
{
	string class_name;
	Student* student;
	Class* pNext;
};

struct SchoolYear
{
	string year_name;
	Semester* semester;
	SchoolYear* pNext;
};

struct Semester
{
	string semester_name;
	Course* course;
	Semester* pNext;
};

struct Course
{
	string id;
	string course_name;
	string class_name;
	string number_credits;
	string number_students;
	string teacher_name;
	string day_of_week;
	string sessions;

	Student* student;

	Course* pNext;
};

struct Student
{
	string student_ID;
	string first_name;
	string last_name;
	string gender;
	string date_of_birth;
	string social_ID;
	Student* pNext;
};

void load_student_InCourse(Student*& pHead, string schoolYear_name, string semester_name, string course_name);

void load_course(Course*& pHead, string schoolYear_name, string semester_name);

void load_semester(Semester*& pHead, string schoolYear_name);

void load_schoolYear(SchoolYear*& pHead);

void load_input(SchoolYear*& pHead_schoolYear);

void print_student_InCourse(Student* pHead, string schoolYear_name, string Semester_name, string Course_name);

void print_course(Course* pHead, string schoolYear_name, string Semester_name);

void print_Semester(Semester* pHead_Semester, string Schoolyear_name);

void print_output(SchoolYear* pHead_SchoolYear);

void deallocated(SchoolYear*& pHead_schoolYear);



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

void removeStudent_Course(Student*& pHead);

#endif