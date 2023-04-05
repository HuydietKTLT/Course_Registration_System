#include "staff.h"
#include "password.h"
#include "lib.h"
#include "menuScore.h"
//Temp Menu for staff
void menuStaff(SchoolYear* pHead_schoolYear, Class* pHead_class)
{
	int i;
	SchoolYear* current_schoolyear = currentSchoolYear(pHead_schoolYear);
	while (true)
	{
		cout << "-------------------------------------------\n";
		cout << "1. New school year.\n2. New classes\n";
		cout << "3. Add new 1st year students to 1st-year classes\n4. New semester.\n5. Add students to course by file.\n6. Add students to course by console.\n7. View the list of courses.";
		cout << "\n8. Update course information\n9. Add scores for the current school year.\n0. Exit\nEnter options:";
		cin >> i;
		switch (i)
		{
		case 0:
			return;
		case 1:
			createNewSchoolYear(pHead_schoolYear);
			break;
		case 2:
			createNewClass(pHead_class);
			break;
		case 3:
		{
			Class* find_class = Find_Class(pHead_class);
			if (find_class != nullptr)
			{
				string s;
				cout << "Enter when you finish entering student in file addStudentToClass.txt";
				cin >> s;
				add_Student_To_Class_By_File(find_class->student);
			}
			break;
		}
		case 4:
			if (current_schoolyear != nullptr)
				addSemesterMenu(current_schoolyear);
			break;
		case 5:
		{
			Course* course_addStudent_file = Find_Course(pHead_schoolYear);
			if (course_addStudent_file != nullptr)
			{
				cout << "Enter when you finish entering student in file addStudentToCourse.txt";
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
		{
			Course* course_update = Find_Course(pHead_schoolYear);
			if (course_update != nullptr)
				update_Course(course_update);
			break;
		}
		case 9:
		{
			if (current_schoolyear != nullptr)
				Menu_Score_Board(pHead_schoolYear);
			else
				cout << "There is no semester for this school year!" << endl;
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
	SchoolYear* currentshoolyear=pHead;
	while (currentshoolyear->pNext != nullptr)
		currentshoolyear = currentshoolyear->pNext;
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
		while (pCur->pNext != nullptr )
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
			break;
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
			return;
		case 1:
			addSemester(pHead_schoolYear->semester);
			break;
		default:
			continue;
		}
	}
}

void add_semester(Semester*& pHead, string semester)
{
	if(pHead==nullptr) {
	pHead=new Semester();
	Semester* pTail = pHead;
	pTail->course = nullptr;
	pTail->semester_name = semester;
	pTail->pNext = nullptr;
	}
	else{
	Semester* pTail = pHead;	
	while (pTail->pNext != nullptr )
	pTail = pTail->pNext;
	pTail->pNext = new Semester();
	pTail=	pTail->pNext;
	pTail->course = nullptr;
	pTail->semester_name = semester;
	pTail->pNext= nullptr;
	}
}
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
			return;
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


