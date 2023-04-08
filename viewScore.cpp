// The work below use for task 20-21-22-23


#include "lib.h"


// This function use to import score for ONE COURSE
// This function use parameter as A Linked List Course 
// pls read comment inside function.

void import_score_of_course (Course *&z)
{
    cout << "Course information: " << endl;
    cout << z->id << "  " << z->course_name << endl;
    cout << z->class_name << endl;
    cout << "Now we import score for each students : " << endl << endl;
    Student *s = z->student; // from now just use branch Student of this Course
    while (s != nullptr) {
        cout << "Student id: " << s->student_ID << "\t" << s->last_name << " " << s->first_name << endl;
        cout << "Midterm mark:"; cin >> s->score.mid_mark;
        cout << "Final mark:"; cin >> s->score.final_mark;
        cout << "Other mark:"; cin >> s->score.other_mark;

        // just assume the logic math calculate, staff can fix it
        s->score.total_mark = (s->score.final_mark*2 + s->score.mid_mark) / 3 + s->score.other_mark;
        cout << "Total mark is: " << s->score.total_mark;
        s = s->pNext;
    }
}

void viewScore (Course *course)
{
    cout << "Course information: " << endl;
    cout << course->id << "  " << course->course_name << endl;
    cout << course->class_name << endl;
    cout << "Here is scoreboard of this course: " << endl;
    Student *s = course->student;
    while (s != nullptr) {
        cout << "Student id: " << s->student_ID << "\t" << s->last_name << " " << s->first_name << endl;
        cout << "Midterm mark:" << s->score.mid_mark << endl;
        cout << "Final mark:" << s->score.final_mark << endl;
        cout << "Other mark:" << s->score.other_mark << endl;
        cout << "Total mark is: " << s->score.total_mark << endl;
        cout << endl;
    }
}

void clear(passInfo*& readfile)
{
    ofstream fo;
    fo.open("password.txt");
    passInfo* cur = readfile;
    while (cur->next != nullptr)
    {
        fo << cur->login << ' ' << cur->password << ' ' << cur->type << ' ' << cur->ID << '\n';
        cur = cur->next;
    }
    fo.close();
    passInfo* temp;
    while (readfile != nullptr)
    {
        temp = readfile;
        readfile = readfile->next;
        delete temp;
    }
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

