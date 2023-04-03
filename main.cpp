
#include "lib.h"
int main()
{
	SchoolYear* pHead_schoolYear = nullptr;
	Class* pHead_class = nullptr;

	load_input(pHead_schoolYear, pHead_class);

	string s;
	cout << "Enter when done!!: ";
	cin >> s;

	print_output(pHead_schoolYear, pHead_class);

	cout << "Enter when done 2 !!!";
	cin >> s;

	Semester* add_course = Find_Semester(pHead_schoolYear);
	if (add_course == nullptr)
	{
		cout << endl;
		cout << "There is no semester matching with your typing!!!";
		cout << endl;
	}
	else
	{
		cout << "Enter data for course!!";
		cout << endl;
		addCourse(add_course->course);
		cout << "Update successfully!!";
	}
	print_output(pHead_schoolYear, pHead_class);

	/*cout << "Process to add student to course by file!!!";
	cin >> s;
	Course* add_student = Find_Course(pHead_schoolYear);
	if (add_student == nullptr)
	{
		cout << "The course is not existed!!!";
	}
	else
	{
		add_student->student = nullptr;
		add_Student_to_Course_By_File(add_student->student);
		if (add_student->student == nullptr)
			cout << "nullptr has been found";
	}

	print_output(pHead_schoolYear, pHead_class);
	if (add_student->student == nullptr)
		cout << "nullptr has been found";*/


	deallocated(pHead_schoolYear, pHead_class);

	return 0;