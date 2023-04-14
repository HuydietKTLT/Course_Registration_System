#define _CRT_SECURE_NO_WARNINGS
#define BACKSLASH '\\'

#ifndef _LIB_H_
#define _LIB_H_


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <direct.h>
#include <conio.h>
#include <stdlib.h>


typedef long long ll;
typedef long int li;

using namespace std;

//Set the max length of the password
const int max_value = 20;

//Set default password
const string default_password = "1234";

struct Score {
	float total_mark = 0;
	float final_mark = 0;
	float mid_mark = 0;
	float other_mark = 0;
};

struct passInfo
{
	passInfo* next;
	string login;
	string password;
	char type;
};

struct Student
{
	string student_ID = "x";
	string first_name = "x";
	string last_name = "x";
	string gender = "x";
	string date_of_birth = "x";
	string social_ID = "x";

	Score score;
	Student* pNext;
};

struct Course
{
	string id = "x";
	string course_name = "x";
	string class_name = "x";
	string number_credits = "x";
	string number_students = "x";
	string teacher_name = "x";
	string day_of_week = "x";
	string sessions = "x";

	float final = 0.5;
	float midterm = 0.4;
	float other = 0.1;

	Student* student;
	Course* pNext;
};


struct Semester
{
	string semester_name = "x";
	Course* course;
	Semester* pNext;
};

struct scoreClass
{
	string course_ID = "x";
	string course_name = "x";
	float total_mark = 0;
	scoreClass *next;
};

struct studentClass
{
	string student_ID = "x";
	scoreClass* scoreClass;
	studentClass* pNext;
};

struct Class
{
	string class_name = "x";
	studentClass* student;
	Class* pNext;
};

struct SchoolYear
{
	string year_name = "x";
	Semester* semester;
	SchoolYear* pNext;
};

bool isFileEmpty(string filename);

//About loading data Wat
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

void Print_All_Student_In_A_Course_With_score(Student* pCur);

void export_list_of_student_ToCSVFile(Student* pCur, string year_name, string semester_name, string course_name);

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

void add_Student_To_Class_By_File(Student*& pHead, passInfo*& headPass);

void add_Student_to_Course_By_Console(Student*& pHead);

void remove_Student_from_Course(Student*& pHead);

///////////////////////////////////////////////////////////
////////void add_Student_To_Class_By_File(Student*& pHead);
///////////////////////////////////////////////////////////

void add_Student_to_Course_By_File(Student*& pHead);

//staff's menu

void menuStaff(SchoolYear* pHead_schoolYear, Class* pHead_class, passInfo* &headPass);

void createNewClass(Class*& pHead);

void createNewSchoolYear(SchoolYear*& pHead_schoolYear);

string revString(string a);

SchoolYear* currentSchoolYear(SchoolYear* pHead);

void addSemesterMenu(SchoolYear* pHead_schoolYear);

void addSemester(Semester* &pHead);

bool check_semester(Semester* pHead, string semester);

void add_semester(Semester*& pHead, string semester);

Semester* currentSemester(Semester* pHead);

//student's menu
void menuStudent(SchoolYear* pHead_schoolYear, string student_ID, passInfo*& headPass);

void view_list_all_courses(SchoolYear* pHead_schoolYear, string student_ID);

void view_list_all_scoreboard(SchoolYear* pHead_schoolYear, string student_ID);

//password

bool LoginCheck(string login, string password, char& type, string& ID, passInfo* readfile);

void login(char& type, string& ID, passInfo* readfile);

void edit(passInfo*& readfile);

bool doTheEdit(string password, string ID, passInfo*& head);

string pass();

void clear(passInfo*& readfile);

void ReadPassword(passInfo*& readfile);

void dialocatePass(passInfo* readfile);

//Menu Scoreboard

void view_scoreboard_toCourse(SchoolYear* list_year);

void import_score_of_course(Course* z);

void Menu_Score_Board(SchoolYear* list_year);

//Utility functions

float float_one_point_round(float value);

void clrscr();

float stf(string str);

void stop();

#endif
