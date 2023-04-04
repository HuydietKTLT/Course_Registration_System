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
		cout << "1. New school year.\n2. New classess for current school year\n";
		cout << "3. Add new 1st year students to 1st-year classes\n4. New semester.\n5. Admin scores for the current school year.\n0. Exit\nEnter options: ";
		cin >> i;
		switch (i)
		{
		case 0:
			return;
		case 1:
			createNewSchoolYear(pHead_schoolYear);
			break;
		case 2:
			createNewClass();
			break;
		case 3:
		{
			Class* find_class = Find_Class(pHead_class);
			if (find_class != nullptr)
				add_Student_To_Class_By_File(find_class->student);
			break;
		}
		case 4:
			if (current_schoolyear != nullptr)
				addCourseMenu(current_schoolyear);
			break;
		case 5:
			if (current_schoolyear != nullptr)
				Menu_Score_Board(current_schoolyear);
			else

				break;
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
	string currentshoolyear;
	while (pHead->pNext != nullptr)
		pHead = pHead->pNext;
	currentshoolyear = pHead->year_name;
	cout << "Current school year: " << currentshoolyear << '\n';
	return pHead;
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
			pHead = new SchoolYear;
			pCur = pHead;
		}
		else
			pCur = pHead;
		while (pCur != nullptr && pCur->pNext != nullptr)
			pCur = pCur->pNext;
		if (pHead->pNext != nullptr)
		{
			pCur->pNext = new SchoolYear;
			pCur = pCur->pNext;
		}
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
void createNewClass()
{
	string type, year;
	int numberOfClasses;
	ifstream fi;
	fi.open("currrentclass.txt");
	fi >> year;
	fi.close();
	int i;
	while (true)
	{
		cout << "-------------------------------------------\n";
		cout << "1. New classes\n0. Exit\nEnter options: ";
		cin >> i;
		if (i != 0)
		{
			cout << "Type of education: ";
			cin >> type;
			cout << "Number of classes: ";
			cin >> numberOfClasses;
			createClasses(year, type, numberOfClasses);
		}
		else
			break;
	}
}

//create new class
void createClasses(string year, string type, int numberOfClasses)
{
	ofstream file;
	string ID;
	for (int i = 1; i <= numberOfClasses; ++i)
	{
		if (i < 10)
			ID = "0" + to_string(i);
		else
			ID = to_string(i);
		file.open(year + type + ID + ".txt");
		file.close();
	}
}

//add new course menu
void addCourseMenu(SchoolYear* pHead_schoolYear)
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
			/*case 1:
				cout << "Pick a school year:\n";
				cin >> a;
				struct stat metaData;
				if ((a.c_str(), &metaData) != 0)
					cout << "The school year doesn't exists.\nPlease create the school year or choose a different school year.\n";
				else
				{
					ofstream fo;
					fo.open("currentschoolyear.txt");
					fo << a;
					a = a.substr(0, a.find('-'));
					a = revString(a);
					fo.open("currrentclass.txt");
					fo << a[1] << a[0] << '\n';
					fo.close();
				}
				break;*/
		case 1:
			addSemester(pHead_schoolYear->semester);
			break;
		default:
			continue;
		}
	}
}

//add new semester
void addSemester(Semester*& pHead)
{
	int option;
	while (true)
	{
		cin >> option;
		cout << "-------------------------------------------\n";
		cout << "1. Semester 1\n2. Semester 2\n3. Semester 3\n0. Exit\nEnter options: ";
		switch (option)
		{
		case 1:
			if (!check_semester(pHead, "Semester1"))
				cout << "Failed to create new semester. Semester has been created!";
			else
				add_semester(pHead, "Semester1");
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
		pHead = pHead->pNext;
	if (pHead == nullptr)
		return false;
	return true;
}

void add_semester(Semester*& pHead, string semester)
{
	Semester* pTail = pHead;
	while (pTail != nullptr && pTail->pNext != nullptr)
		pTail = pTail->pNext;

	pTail->pNext = new Semester;
	pTail = pTail->pNext;
	pTail->course = nullptr;
	pTail->semester_name = semester;
	pTail->pNext = nullptr;
}



