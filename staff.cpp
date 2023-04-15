#include "lib.h"
#include "menuScoreTemp.h"

//Temp Menu for staff

void menuStaff(SchoolYear* pHead_schoolYear, Class* pHead_class, passInfo*& headPass)
{
	int i;
	SchoolYear* current_schoolyear = currentSchoolYear(pHead_schoolYear);
	while (true)
	{
		cout 	<< "-------------------------------------------\n"
				<< "1. New school year.\n2. New classes\n"
				<< "3. Add new 1st year students to 1st-year classes\n4. New semester.\n5. Add students to course by file.\n6. Add a student to course by console.\n7. View the list of courses."
				<< "\n8. View the list of class: "
				<< "\n9. Update course information."
				<< "\n10. Remove a student from the course."
				<< "\n11. Delete a course "
				<< "\n12. Add scores for the current school year."
				<< "\n13. View a list of students in a class"
				<< "\n14. View a list of students in a course"
				<< "\n15. View GPA of a class in a semester"
				<< "\n16. View total GPA of a class"
				<< "\n17. Export list of students in course to CSV file!"
				<< "\n18. Edit password."
				<< "\n0. Log out"
				<< " \nEnter options :";
		cin >> i;
		switch (i)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			createNewSchoolYear(pHead_schoolYear);
			break;
		}
		case 2:
		{
			createNewClass(pHead_class);
			break;
		}
		case 3:
		{
			Class* find_class = Find_Class(pHead_class);
			if (find_class != nullptr)
			{
				string s;
				cout << "Enter when you finish entering student in file addStudentToClass.txt[Yes] : ";
				cin >> s;
				add_Student_To_Class_By_File(find_class->student, headPass);
			}
			break;
		}
		case 4:
		{
			if (current_schoolyear != nullptr)
				addSemesterMenu(current_schoolyear);
			break;
		}
		case 5:
		{
			Course* course_addStudent_file = Find_Course(pHead_schoolYear);
			if (course_addStudent_file != nullptr)
			{
				string s;
				cout << "Enter when you finish entering student in file addStudentToCourse.txt[Yes] : ";
				cin >> s;
				add_Student_to_Course_By_File(course_addStudent_file->student);
			}
			break;
		}
		case 6:
		{
			Course* course_addStudent_console = Find_Course(pHead_schoolYear);
			if (add_Student_to_Course_By_Console != nullptr)
				add_Student_to_Course_By_Console(course_addStudent_console->student);
			break;
		}
		case 7:
		{
			print_All_CourseToConsole(pHead_schoolYear);
			break;
		}
		case 8:
			print_All_ClassToConsole(pHead_class);
			break;
		case 9:
		{
			Course* course_update = Find_Course(pHead_schoolYear);
			if (course_update != nullptr)
				update_Course(course_update);
			break;
		}
		case 10:
		{
			Course* course_remove_student = Find_Course(pHead_schoolYear);
			if (course_remove_student != nullptr)
				remove_Student_from_Course(course_remove_student->student);
			break;
		}
		case 11:
		{
			string get_schoolyear;
			cout << "Enter School Year: ";
			cin >> get_schoolyear;
			SchoolYear* pHead = pHead_schoolYear;
			while (pHead != nullptr && pHead->year_name != get_schoolyear)
			{
				pHead = pHead->pNext;
			}
			if (pHead == nullptr)
			{
				cout << "There is no schoolyear matching with your typing!!!" << endl;
				break;
			}

			Semester* pCur_Semester = pHead->semester;
			//These code is used for traversing the linked list of Semester, to found the specific Semester.
			string get_semester;
			cout << "Enter Semester: ";
			cin >> get_semester;

			while (pCur_Semester != nullptr && pCur_Semester->semester_name != get_semester)
				pCur_Semester = pCur_Semester->pNext;

			if (pCur_Semester == nullptr)
			{
				cout << "There is no semester matching with your typing !!!" << endl;
				break;
			}

			Course* pCur_Course = pCur_Semester->course;
			cout << "Enter Course ID: ";
			string get_course_ID;
			cin >> get_course_ID;
			while (pCur_Course != nullptr && pCur_Course->id != get_course_ID)
			{
				pCur_Course = pCur_Course->pNext;
			}
			if (pCur_Course == nullptr)
			{
				cout << "There is no course ID matching with your typing !!!" << endl;
				return;
			}

			deleteCourse(pCur_Semester->course, pCur_Course, pHead->year_name, pCur_Semester->semester_name);
			break;
		}
		case 12:
		{
			Menu_Score_Board(pHead_schoolYear);
			break;
		}
		case 13:
		{
			Class* class_print_student = Find_Class(pHead_class);
			if (class_print_student != nullptr)
				print_All_Student_In_A_class(class_print_student->student);
			break;
		}
		case 14:
		{
			Course* course_print_student = Find_Course(pHead_schoolYear);
			if (course_print_student != nullptr)
				Print_All_Student_In_A_Course(course_print_student->student);
			break;
		}
		case 15:
		{	
			Print_All_Student_In_A_Class_With_score_Semester(pHead_schoolYear, pHead_class);
			break;
		}
		case 16:
		{	
			Print_All_Student_In_A_Class_With_score_All(pHead_class);
			break;
		}
		case 17:
		{
			string get_schoolyear;
			cout << "Enter School Year: ";
			cin >> get_schoolyear;
			SchoolYear* pHead = pHead_schoolYear;
			while (pHead != nullptr && pHead->year_name != get_schoolyear)
			{
				pHead = pHead->pNext;
			}
			if (pHead == nullptr)
			{
				cout << "There is no schoolyear matching with your typing!!!" << endl;
				break;
			}

			Semester* pCur_Semester = pHead->semester;
			//These code is used for traversing the linked list of Semester, to found the specific Semester.
			string get_semester;
			cout << "Enter Semester: ";
			cin >> get_semester;

			while (pCur_Semester != nullptr && pCur_Semester->semester_name != get_semester)
				pCur_Semester = pCur_Semester->pNext;

			if (pCur_Semester == nullptr)
			{
				cout << "There is no semester matching with your typing !!!" << endl;
				break;
			}

			Course* pCur_Course = pCur_Semester->course;
			cout << "Enter Course ID: ";
			string get_course_ID;
			cin >> get_course_ID;
			while (pCur_Course != nullptr && pCur_Course->id != get_course_ID)
			{
				pCur_Course = pCur_Course->pNext;
			}
			if (pCur_Course == nullptr)
			{
				cout << "There is no course ID matching with your typing !!!" << endl;
				break;
			}
			export_list_of_student_ToCSVFile(pCur_Course->student, pHead->year_name, pCur_Semester->semester_name, pCur_Course->id);
			break;
		}
		case 18:
		{
			edit(headPass);
			break;
		}
		
		default:
			continue;
		}
	}
}

// check if current school year exists
SchoolYear* currentSchoolYear(SchoolYear* pHead)
{
	if (pHead == nullptr) return NULL;
	cout << "-------------------------------------------\n";
	SchoolYear* currentshoolyear = pHead;
	while (currentshoolyear->pNext != nullptr)
		currentshoolyear = currentshoolyear->pNext;
	cout << currentshoolyear->year_name << endl;
	return currentshoolyear;
}

//print current semester to screen
Semester* currentSemester(Semester* pHead)
{
	if (pHead == nullptr)
	{
		cout << "Chua tao ky nao!" << endl;
		return NULL;
	}
	cout << "-------------------------------------------\n";
	string currentSemester;
	while (pHead->pNext != nullptr)
		pHead = pHead->pNext;
	currentSemester = pHead->semester_name;
	cout << "Current semester: " << currentSemester << '\n';
	return pHead;
}

//Revese string
string revString(string a)
{
	string b = "";
	int n = a.length();
	for (int i = 0; i < n; i++)
		b += a[n - i - 1];
	return b;
}

//create new school year
void createNewSchoolYear(SchoolYear*& pHead)
{
	string year;
	cout << "-------------------------------------------\n";
	cout << "Enter new school year: ";
	cin >> year;
	if (_mkdir(year.c_str()) == 0) {
		SchoolYear* pCur = nullptr;
		if (pHead == nullptr)
		{
			pHead = new SchoolYear();
			pCur = pHead;
		}
		else
			pCur = pHead;
		while (pCur->pNext != nullptr)
			pCur = pCur->pNext;
		pCur->pNext = new SchoolYear();
		pCur = pCur->pNext;
		pCur->year_name = year;
		pCur->semester = nullptr;
		pCur->pNext = nullptr;
		cout << "New school year created successfully.\n";
	}
	else {
		cout << "Failed to create new school year.\n";
	}
	cout << "Press any key to continue...\n";
}

//create new class menu
void createNewClass(Class*& pHead)
{
	string get_class;
	int i;
	Class* pCur = nullptr;
	if (pHead == nullptr)
	{
		pHead = new Class;
		pCur = pHead;
	}
	else
	{
		pCur = pHead;
		while (pCur != nullptr && pCur->pNext != nullptr)
			pCur = pCur->pNext;
		if (pHead != nullptr)
		{
			pCur->pNext = new Class;
			pCur = pCur->pNext;
		}
	}
	while (true)
	{
		cout << "-------------------------------------------\n";
		cout << "1. New classes\n0. Exit\nEnter options: ";
		cin >> i;
		if (i != 0)
		{
			cout << "Enter class: ";
			cin >> get_class;
			pCur->class_name = get_class;

			pCur->student = nullptr;
			pCur->pNext = nullptr;
		}
		else
		{
			break;
		}
	}
}

//add new course menu
void addSemesterMenu(SchoolYear* pHead_schoolYear)
{
	int i;
	while (true)
	{
		cout << "-------------------------------------------\n";
		cout << "1. Choose a semester\n0. Exit\nEnter options: ";
		cin >> i;
		string a;
		switch (i)
		{
		case 0:
		{
			return;
		}
		case 1:
			addSemester(pHead_schoolYear->semester);
			break;
		default:
			continue;
		}
	}
}

//void add_semester(Semester*& pHead, string semester)
//{
//	if (pHead == nullptr) {
//		pHead = new Semester();
//		Semester* pTail = pHead;
//		pTail->course = nullptr;
//		pTail->semester_name = semester;
//		pTail->pNext = nullptr;
//	}
//	else {
//		Semester* pTail = pHead;
//		while (pTail->pNext != nullptr)
//			pTail = pTail->pNext;
//		pTail->pNext = new Semester();
//		pTail = pTail->pNext;
//		pTail->course = nullptr;
//		pTail->semester_name = semester;
//		pTail->pNext = nullptr;
//	}
//}
//add new semester

void addSemester(Semester*& pHead)
{
	int option;
	while (true)
	{
		cout << "-------------------------------------------\n";
		cout << "1. Semester 1\n2. Semester 2\n3. Semester 3\n0. Exit\nEnter options: ";
		cin >> option;
		switch (option)
		{
		case 1:
			if (pHead == nullptr)
				add_semester(pHead, "Semester1");
			else
				cout << "Failed to create new semester. Semester has been created!";
			break;
		case 2:
			if (!check_semester(pHead, "Semester2"))
				cout << "Failed to create new semester. Semester has been created!";
			else
				add_semester(pHead, "Semester2");
			break;
		case 3:
			if (!check_semester(pHead, "Semester3"))
				cout << "Failed to create new semester. Semester has been created!";
			else
				add_semester(pHead, "Semester3");
			break;
		case 0:
		{
			return;
		}
		default:
			continue;
		}
	}

}

bool check_semester(Semester* pHead, string semester)
{
	if (pHead == nullptr) return false;
	while (pHead != nullptr && pHead->semester_name != semester)
	{
		pHead = pHead->pNext;
	}
	if (pHead != nullptr)
		return false;
	return true;
}

void add_semester(Semester*& pHead, string semester)
{
	Semester* pTail = nullptr;
	if (pHead == nullptr)
	{
		pHead = new Semester;
		pTail = pHead;
	}

	else
	{
		pTail = pHead;
		while (pTail != nullptr && pTail->pNext != nullptr)
			pTail = pTail->pNext;
		pTail->pNext = new Semester;
		pTail = pTail->pNext;
	}
	pTail->semester_name = semester;
	pTail->course = nullptr;
	pTail->pNext = nullptr;
}