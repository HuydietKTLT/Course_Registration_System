#ifndef _STAFF_H_
#define _STAFF_H_

#include "lib.h"

void menuStaff(SchoolYear* pHead_schoolYear, Class* pHead_class);

void createNewClass(Class*& pHead);

void createNewSchoolYear(SchoolYear*& pHead_schoolYear);

string revString(string a);

SchoolYear* currentSchoolYear(SchoolYear* pHead);

void addSemesterMenu(SchoolYear* pHead_schoolYear);

void addSemester(Semester* &pHead);

bool check_semester(Semester* pHead, string semester);

void add_semester(Semester*& pHead, string semester);

Semester* currentSemester(Semester* pHead);

#endif