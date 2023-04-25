#include "lib.h"

bool checkSchoolYearSemIsFull(SchoolYear *currentSchoolYear)
{
    Semester *pCur = currentSchoolYear->semester;
    int count = 0;
    while (pCur != nullptr)
    {
        count++;
        pCur = pCur->pNext;
    }

    if (count == 3)
        return true;
    else
        return false;
}

void updateScoreForStudent (Course  *course)
{
    Student *s = course->student;
    string temp;
    cout << "Enter student id need to update the result: " ;
    cin >> temp;
    while (s != nullptr) {
        if (s->student_ID == temp) break;
        else s = s->pNext;
    }
    if (s == nullptr) {
        cout << "There are no student got this ID !!!";
        return;
    }
    cout << "Now enter the updated result of the student ID " << temp << " : " << endl;
    cout << "Midterm mark:"; cin >> s->score.mid_mark;
    cout << "Final mark:"; cin >> s->score.final_mark;
    cout << "Other mark:"; cin >> s->score.other_mark;
}

void changeCurrentSchoolYear(SchoolYear *&currentSchoolYear, SchoolYear *pHead)
{
    string s;
    cout << "Enter School Year you need to work with: ";
    cin >> s;
    while (pHead != nullptr && pHead->year_name != s)
    {
        pHead = pHead->pNext;
    }
    if (pHead == nullptr)
    {
        cout << "There are no school year name '" << s << "' !" << endl;
        cout << "Press any key to continue..." << endl;
        cin >> s;
        return;
    }
    currentSchoolYear = pHead;
    cout << "Current school year has been changed !" << endl;
    cout << "Press any key to continue..." << endl;
    cin >> s;
}