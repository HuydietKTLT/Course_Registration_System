#include "lib.h"

// Temp Menu for staff

void menuStaff(SchoolYear *pHead_schoolYear, Class *pHead_class, passInfo *&headPass)
{
	int i;
	SchoolYear *current_schoolyear = currentSchoolYear(pHead_schoolYear);
	while (true)
	{
		clrscr();
		cout << "-------------------------------------------\n"
			 << current_schoolyear->year_name << endl;
		cout << "-------------------------------------------\n"
			 << "1. New school year.\n"
			 << "2. New classes.\n"
			 << "3. Change current school year.\n"
			 << "4. Add new 1st year students to 1st-year classes.\n"
			 << "5. New semester for current school year.\n"
			 << "6. Add students to course by file.\n"
			 << "7. Add a student to course by console.\n"
			 << "8. Add a course to this semester. \n"
			 << "9. View the list of courses.\n"
			 << "10. View the list of class.\n"
			 << "11. Update course information.\n"
			 << "12. Remove a student from the course.\n"
			 << "13. Delete a course.\n"
			 << "14. Add scores for the current school year.\n"
			 << "15. View a list of students in a class.\n"
			 << "16. View a list of students in a course.\n"
			 << "17. View GPA of a class in a semester.\n"
			 << "18. View total GPA of a class.\n"
			 << "19. Export list of students in course to CSV file.\n"
			 << "20. Edit password.\n"
			 << "0. Log out.\n"
			 << "Enter options: ";
		cin >> i;
		clrscr();
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
			changeCurrentSchoolYear(current_schoolyear, pHead_schoolYear);
			break;
		}
		case 4:
		{
			Class *find_class = Find_Class(pHead_class);
			if (find_class != nullptr)
			{
				string s;
				cout << "Enter when you finish entering student in file addStudentToClass.txt[Yes] : ";
				cin >> s;
				if (s != "Yes")
				{
					cout << "Cancel the action!" << endl;
					cout << "Press any key to continue..." << endl;
					cin >> s;
					break;
				}
				add_Student_To_Class_By_File(find_class->student, headPass);
				cout << "Updated successfully!" << endl;
				cout << "Press any key to continue..." << endl;
				cin >> s;
			}
			break;
		}
		case 5:
		{
			if (current_schoolyear != nullptr) {
				if (checkSchoolYearSemIsFull(current_schoolyear)) {
					cout << "This school year is full of semester ! (3 semesters) \n";
					break;
				}
				addSemesterMenu(current_schoolyear);
			}
			break;
		}
		case 6:
		{
			Course *course_addStudent_file = Find_Course(pHead_schoolYear);
			if (course_addStudent_file != nullptr)
			{
				string s;
				cout << "Enter when you finish entering student in file addStudentToCourse.txt[Yes] : ";
				cin >> s;
				if (s != "Yes")
				{
					cout << "Cancel the action!" << endl;
					cout << "Press any key to continue..." << endl;
					cin >> s;
					break;
				}
				add_Student_to_Course_By_File(course_addStudent_file->student);
				cout << "Updated successfully!" << endl;
				cout << "Press any key to continue..." << endl;
				cin >> s;
			}
			break;
		}
		case 7:
		{
			Course *course_addStudent_console = Find_Course(pHead_schoolYear);
			if (course_addStudent_console != nullptr)
			{
				add_Student_to_Course_By_Console(course_addStudent_console->student);
				cout << "Updated successfully!" << endl;
				cout << "Press any key to continue..." << endl;
				string s;
				cin >> s;
			}
			break;
		}
		case 8:
		{
			SchoolYear *pHead_schoolYear = current_schoolyear;
			Semester *pCur = pHead_schoolYear->semester;
			while (pCur->pNext != nullptr)
				pCur = pCur->pNext;
			addCourse(pCur->course);
			cout << "Updated succefully!" << endl;
			cout << "Press any key to continue..." << endl;
			string s;
			cin >> s;
			break;
		}
		case 9:
		{
			print_All_CourseToConsole(pHead_schoolYear);
			break;
		}
		case 10:
		{
			print_All_ClassToConsole(pHead_class);
			break;
		}
		case 11:
		{
			Course *course_update = Find_Course(pHead_schoolYear);
			if (course_update != nullptr)
			{
				update_Course(course_update);
				cout << "Updated successfully!" << endl;
				cout << "Press any key to continue..." << endl;
				string s;
				cin >> s;
			}
			break;
		}
		case 12:
		{
			Course *course_remove_student = Find_Course(pHead_schoolYear);
			if (course_remove_student != nullptr)
			{
				remove_Student_from_Course(course_remove_student->student);
				cout << "Updated successfully!" << endl;
				cout << "Press any key to continue..." << endl;
				string s;
				cin >> s;
			}
			break;
		}
		case 13:
		{
			string get_schoolyear;
			cout << "Enter School Year: ";
			cin >> get_schoolyear;
			SchoolYear *pHead = pHead_schoolYear;
			while (pHead != nullptr && pHead->year_name != get_schoolyear)
			{
				pHead = pHead->pNext;
			}
			if (pHead == nullptr)
			{
				cout << "There is no schoolyear matching with your typing!!!" << endl;
				break;
			}

			Semester *pCur_Semester = pHead->semester;
			// These code is used for traversing the linked list of Semester, to found the specific Semester.
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

			Course *pCur_Course = pCur_Semester->course;
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
			cout << "Updated successfully!" << endl;
			cout << "Press any key to continue..." << endl;
			string s;
			cin >> s;
			break;
		}
		case 14:
		{
			
			SchoolYear *current_schoolYear_print_score = currentSchoolYear(pHead_schoolYear);
			if (current_schoolYear_print_score != nullptr)
			Menu_Score_Board(current_schoolYear_print_score);
			break;
		}
		case 15:
		{
			Class *class_print_student = Find_Class(pHead_class);
			if (class_print_student != nullptr)
				print_All_Student_In_A_class(class_print_student->student);
			break;
		}
		case 16:
		{
			Course *course_print_student = Find_Course(pHead_schoolYear);
			if (course_print_student != nullptr)
				Print_All_Student_In_A_Course(course_print_student->student);
			break;
		}
		case 17:
		{
			Print_All_Student_In_A_Class_With_score_Semester(pHead_schoolYear, pHead_class);
			break;
		}
		case 18:
		{
			Print_All_Student_In_A_Class_With_score_All(pHead_class);
			break;
		}
		case 19:
		{
			string get_schoolyear;
			cout << "Enter School Year: ";
			cin >> get_schoolyear;
			SchoolYear *pHead = pHead_schoolYear;
			while (pHead != nullptr && pHead->year_name != get_schoolyear)
			{
				pHead = pHead->pNext;
			}
			if (pHead == nullptr)
			{
				cout << "There is no school year matching with your typing!!!" << endl;
				break;
			}

			Semester *pCur_Semester = pHead->semester;
			// These code is used for traversing the linked list of Semester, to found the specific Semester.
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

			Course *pCur_Course = pCur_Semester->course;
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
		case 20:
		{
			edit(headPass);
			cout << "Updated successfully!" << endl;
			cout << "Press any key to continue..." << endl;
			string s;
			cin >> s;
			break;
		}
		default:
			continue;
		}
	}
}

// check if current school year exists
SchoolYear *currentSchoolYear(SchoolYear *pHead)
{
	if (pHead == nullptr)
		return NULL;
	// cout << "-------------------------------------------\n";
	SchoolYear *currentshoolyear = pHead;
	while (currentshoolyear->pNext != nullptr)
		currentshoolyear = currentshoolyear->pNext;
	// cout << currentshoolyear->year_name << endl;
	return currentshoolyear;
}

// print current semester to screen
Semester *currentSemester(Semester *pHead)
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

// Revese string
string revString(string a)
{
	string b = "";
	int n = a.length();
	for (int i = 0; i < n; i++)
		b += a[n - i - 1];
	return b;
}

// create new school year
void createNewSchoolYear(SchoolYear *&pHead)
{
	cout << "-------------------------------------------\n";
	cout << "Enter new school year: ";
	string year;
	cin >> year;
	string year1 = year.substr(0, 4);
	string year2 = year.substr(5, year.size() - 1);

	while (year.size() != 9 || year[4] != '-' || stoi(year2) - stoi(year1) != 1)
	{
		clrscr();
		cout << "Wrong syntax to create new school year.\n";
		if (year.size() != 9 || year[4] != '-')
		{
			cout << "The syntax must be xxxx-xxxx." << endl;
		}
		if (stoi(year2) - stoi(year1) > 1)
			cout << "The distance of the academic year is 1 year." << endl;
		if (stoi(year2) - stoi(year1) < 1)
			cout << "The more later year must be bigger than the sooner year " << endl;
		cout << "Please try again..." << endl;
		cout << "Enter new school year (press '0' to exit): ";
		cin >> year;
		if (year == "0")
			return;
		year1 = year.substr(0, 4);
		year2 = year.substr(5, year.size() - 1);
		clrscr();
	}

	SchoolYear *pCur = nullptr;
	if (pHead != nullptr)
		pCur = pHead;
	bool is_created = true;
	while (pCur != nullptr && pCur->year_name != year)
	{
		pCur = pCur->pNext;
	}
	if (pCur == nullptr)
		is_created = false;
	if (is_created == false)
	{
		pCur = nullptr;
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
	else
	{
		cout << "Failed to create new school year. The school year has been created!\n";
	}
	cout << "Press any key to continue...\n";
	string s;
	cin >> s;
}

// create new class menu
void createNewClass(Class *&pHead)
{
	int i;
	while (true)
	{
		clrscr();
		cout << "-------------------------------------------\n";
		cout << "1. New classes\n0. Exit\nEnter options: ";
		cin >> i;
		if (i == 1)
		{
			string get_class;
			cout << "Enter class (from 1-99): ";
			cin >> get_class;
			while (stoi(get_class) <= 0 || stoi(get_class) >= 100)
			{
				cout << "Wrong syntax of class, enter the academic class which begin from 1-99 " << endl;
				cin >> get_class;
			}
			cout << "Enter type of the class: ";
			string type_class;
			cin >> type_class;

			while (type_class != "CLC" && type_class != "VP" && type_class != "APCS")
			{
				cout << "Wrong syntax of class, enter the type of class among CLC, VP or APCS: ";
				cin >> type_class;
			}

			cout << "Enter the ordered of the class (1-99): ";
			int ordered_class;
			cin >> ordered_class;
			while (ordered_class < 1 || ordered_class > 99)
			{
				cout << "Invalid input. The ordereded of the class must in range 1-99: ";
				cin >> ordered_class;
			}
			if (ordered_class < 10)
				get_class = get_class + type_class + "0" + to_string(ordered_class);
			else
				get_class = get_class = get_class + type_class + to_string(ordered_class);

			Class *pCur = nullptr, *pPrevCur = nullptr;
			if (pHead == nullptr)
			{
				pHead = new Class;
				pCur = pHead;
				pPrevCur = pHead;
			}
			else
			{
				pCur = pHead;
				while (pCur != nullptr && pCur->class_name != get_class)
				{
					pPrevCur = pCur;
					pCur = pCur->pNext;
				}
				if (pCur != nullptr)
				{
					cout << "The class has been already created !!" << endl;
					cout << "Press any key to continue...\n";
					string s;
					cin >> s;
					continue;
				}
				else
				{
					pPrevCur->pNext = new Class;
					pPrevCur = pPrevCur->pNext;
				}
			}

			pPrevCur->class_name = get_class;
			pPrevCur->student = nullptr;
			pPrevCur->pNext = nullptr;
			cout << "Create the class successfully!" << endl;
			cout << "Press any key to continue...\n";
			string s;
			cin >> s;
			continue;
		}
		else if (i == 0)
			break;
		else
		{
			cout << "Invalid option!" << endl;
			cout << "Press any key to continue...\n";
			string s;
			cin >> s;
			continue;
		}
	}
}

// add new course menu
void addSemesterMenu(SchoolYear *pHead_schoolYear)
{
	clrscr();
	while (true)
	{
		cout << "-------------------------------------------\n";
		cout << "1. Choose a semester\n0. Exit\nEnter options: ";
		int i;
		cin >> i;
		switch (i)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			addSemester(pHead_schoolYear->semester);
			break;
		}
		default:
			continue;
		}
	}
}

// void add_semester(Semester*& pHead, string semester)
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
// }
// add new semester

void addSemester(Semester *&pHead)
{
	while (true)
	{
		cout << "-------------------------------------------\n";
		cout << "1. Semester 1\n2. Semester 2\n3. Semester 3\n0. Exit\nEnter options: ";
		int option;
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

bool check_semester(Semester *pHead, string semester)
{
	if (pHead == nullptr)
		return false;
	while (pHead != nullptr && pHead->semester_name != semester)
	{
		pHead = pHead->pNext;
	}
	if (pHead != nullptr)
		return false;
	return true;
}

void add_semester(Semester *&pHead, string semester)
{
	Semester *pTail = nullptr;
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
