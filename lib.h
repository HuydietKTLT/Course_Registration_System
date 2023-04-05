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
#include <direct.h>
#include <conio.h>


typedef long long ll;
typedef long int li;

using namespace std;

struct Score {
	float total_mark = 0;
	float final_mark = 0;
	float mid_mark = 0;
	float other_mark = 0;
};


struct Student
{
	string student_ID;
	string first_name;
	string last_name;
	string gender;
	string date_of_birth;
	string social_ID;

	Score score;
	Student* pNext;
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


struct Semester
{
	string semester_name;
	Course* course;
	Semester* pNext;
};

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

struct passInfo
{
	passInfo* next;
	string login;
	string password;
	char type;
	string ID;
};
bool isFileEmpty(string filename);

//About loading data
void load_student_InCourse(Student*& pHead, string schoolYear_name, string semester_name, string course_name);

void load_student_InClass(Student*& pHead, string class_name);

void load_course(Course*& pHead, string schoolYear_name, string semester_name);

void load_semester(Semester*& pHead, string schoolYear_name);

void load_schoolYear(SchoolYear*& pHead);

void load_class(Class*& pHead);

void load_input(SchoolYear*& pHead_schoolYear, Class*& pHead_class);

void print_student_InCourse(Student* pHead, string schoolYear_name, string Semester_name, string Course_name);

void print_student_InClass(Student* pHead, string class_name);

void print_course(Course* pHead, string schoolYear_name, string Semester_name);

void print_Semester(Semester* pHead_Semester, string Schoolyear_name);

void print_output(SchoolYear* pHead_SchoolYear, Class* pHead_class);


void deallocated(SchoolYear*& pHead_schoolYear, Class*& pHead_class);

//Working with courses.
void print_All_CourseToConsole(SchoolYear* pHead_schoolYear);

void print_All_ClassToConsole(Class* pHead_class);

void print_All_Student_In_A_class(Student* pCur);

void Print_All_Student_In_A_Course(Student* pCur);

void addCourse(Course*& pHead);

void deleteCourse(Course*& pHead, Course*& pDelete, string year_name, string semester_name);

void update_course_ID(Course*& pCur);

void update_course_name(Course*& pCur);

void update_class_name(Course*& pCur);

void update_teacher_name(Course*& pCur);

void update_number_credits(Course*& pCur);

void update_number_students(Course*& pCur);

void update_day_week(Course*& pCur);

void update_session(Course*& pCur);

void update_Course(Course*& pCur);


//Find any semester with specififc schoolyear;
Semester* Find_Semester(SchoolYear* pHead);

//Find any course with specific schoolyear, semester and courseID.
Course* Find_Course(SchoolYear* pHead);

Class* Find_Class(Class* pHead);

void add_Student_to_Course_By_File(Student*& pHead);

void add_Student_to_Course_By_Console(Student*& pHead);

void remove_Student_from_Course(Student*& pHead);

void add_Student_To_Class_By_File(Student*& pHead);

#endif
