#ifndef _STAFF_H_
#define _STAFF_H_

#include "lib.h"

void menuStaff(SchoolYear* pHead_schoolYear, Class* pHead_class);
void createNewClass();
void createNewSchoolYear(SchoolYear*& pHead_schoolYear);
void createClasses(string year, string type,int numberOfClasses);
string revString(string a);
SchoolYear* currentSchoolYear(SchoolYear* pHead);
void addCourseMenu(SchoolYear* pHead_schoolYear);
void addSemester(Semester* pHead);
Semester* currentSemester(Semester* pHead);

#endif