#include "lib.h"

void menuManager(SchoolYear* &pHead_schoolYear, Class* &pHead_class, passInfo* &headPass)
{
    int choice;
    while (true)
    {
        clrscr();
        cout << "=======================================\n";
        cout << "1. Edit staff memeber\n";
        cout << "2. Edit password\n";
        cout << "3. Staff menus\n";
        cout << "4. Log out\n";
        cout << "Choose your action: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            addStaff(headPass);
            break;
        }
        case 2:
        {
            editStudent(headPass);
            break;
        }
        case 3:
        {
            menuStaffMan(pHead_schoolYear, pHead_class, headPass);
            break;
        }
        case 4:
        {
            return;
        }
        }
    }
}

void addStaff(passInfo*& headPass)
{
    clrscr();
    cout << "=======================================\n";
    cout << "1. Add new staff member by console\n";
    cout << "2. Add new staff member by file\n";
    cout << "3. Remove staff member\n";
    cout << "4. Back\n";
    cout << "Choose your action: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        addStaffByConsole(headPass);
        break;
    }
    case 2:
    {
        addStaffByFile(headPass);
        break;
    }
    case 3:
    {
        removeStaff(headPass);
        break;
    }
    case 4:
    {
        return;
    }
    }
}

void addStaffByConsole(passInfo* &headPass)
{
    if(headPass == nullptr)
    {
        headPass = new passInfo;
        headPass->next = nullptr;
        cout << "Enter ID: ";
        cin >> headPass->login;
        headPass->password = default_password;
        cout << "Enter type: ";
        cin >> headPass->type;
        return;
    }
    passInfo* cur = headPass;
    while(cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = new passInfo;
    cur = cur->next;
    cur->next = nullptr;
    cout << "Enter ID: ";
    cin >> cur->login;
    cur->password = default_password;
    cout << "Enter type: ";
    cin >> cur->type;
}

void addStaffByFile(passInfo* &headPass)
{
    ifstream fin;
    fin.open("staff.txt");
    if(fin.fail())
    {
        cout << "Error! Can't open file staff.txt!";
        return;
    }
    if(headPass == nullptr)
    {
        headPass = new passInfo;
        headPass->next = nullptr;
        getline(fin, headPass->login, ',');
        string temp;
        getline(fin, temp, '\n');
        headPass->type = temp[0];
        headPass->password = default_password;
    }
    passInfo* cur = headPass;
    while(cur->next != nullptr)
    {
        cur = cur->next;
    }
    while(!fin.eof())
    {
        cur->next = new passInfo;
        cur = cur->next;
        cur->next = nullptr;
        getline(fin, cur->login, ',');
        string temp;
        getline(fin, temp, '\n');
        cur->type = temp[0];
        cur->password = default_password;
    }
    fin.close();
    ofstream fout;
    fout.open("staff.txt");
    fout << "";
    fout.close();
}

void editStudent(passInfo* &headPass)
{
    clrscr();
    cout << "Enter ID: ";
    string id;
    cin >> id;
    passInfo* cur = headPass;
    while(cur != nullptr)
    {
        if(cur->login == id)
        {
            cout << "Enter new password: ";
            cin >> cur->password;
            cout << "New type: ";
            cin >> cur->type;
            return;
        }
        cur = cur->next;
    }
	//
}

void removeStaff(passInfo*& headPass)
{
    clrscr();
    cout << "Enter ID: ";
    string id;
    cin >> id;
    passInfo* cur = headPass;
    if(cur->login == id)
    {
        headPass = headPass->next;
        delete cur;
        return;
    }
    while(cur->next != nullptr)
    {
        if(cur->next->login == id)
        {
            passInfo* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            return;
        }
        cur = cur->next;
    }
    cout << "ID not found!";
    string s;
    cin >> s;
    return;
}


void menuStaffMan(SchoolYear* &pHead_schoolYear, Class* &pHead_class, passInfo* &headPass)
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
				add_Student_to_Course_By_File(course_addStudent_file,course_addStudent_file->student, headPass);
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
				add_Student_to_Course_By_Console(course_addStudent_console, course_addStudent_console->student, headPass);
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
				update_Course(course_update, pHead_schoolYear);
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
				string s;
				cout << "Press any key to continue...";
				cin >> s;
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
				string s;
				cout << "Press any key to continue...";
				cin >> s;
				break;
			}
			export_list_of_student_ToCSVFile(pCur_Course->student, pHead->year_name, pCur_Semester->semester_name, pCur_Course->id);
			break;
		}
		default:
			continue;
		}
	}
}