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

