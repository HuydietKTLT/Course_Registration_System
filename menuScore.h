#ifndef _MENUSCORE_H_
#define _MENUSCORE_H_
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

struct Score {
	float total_mark;
	float final_mark;
	float mid_mark;
	float other_mark;
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
struct SchoolYear
{
	string year_name;
	Semester* semester;
	SchoolYear* pNext;
};
void view_scoreboard_toCourse(SchoolYear* list_year);
void import_score_of_course (Course *&z);
void Menu_Score_Board(SchoolYear*& list_year);
#endif


