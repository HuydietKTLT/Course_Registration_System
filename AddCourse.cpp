#include "lib.h"

void print_All_CourseToConsole(SchoolYear *pHead_schoolYear)
{
	// print to Console the Courses which have the format:
	// Course_ID---Course_name---Class_name---Teacher_name---Number_of_Credits---Number_of_maximum_students---Day_of_week---Sessions

	SchoolYear *pHead1 = pHead_schoolYear;
	while (pHead1 != nullptr)
	{
		cout << pHead1->year_name << endl;
		Semester *pHead2 = pHead1->semester;
		while (pHead2 != nullptr)
		{
			cout << pHead2->semester_name << " " << endl;
			cout
				<< left
				<< setw(15)
				<< "Course ID| "
				<< left
				<< setw(15)
				<< "Course Name| "
				<< left
				<< setw(20)
				<< "Class Name|"
				<< left
				<< setw(15)
				<< "Teacher Name| "
				<< left
				<< setw(20)
				<< "Number of credits| "
				<< left
				<< setw(27)
				<< "Number of maximum students| "
				<< left
				<< setw(17)
				<< "Day of the week| "
				<< left
				<< setw(15)
				<< "Session| "
				<< left
				<< setw(3)
				<< "M| "
				<< left
				<< setw(3)
				<< "F| "
				<< left
				<< setw(3)
				<< "O|"
				<< endl;
			Course *pHead3 = pHead2->course;
			while (pHead3 != nullptr)
			{
				cout
					<< left
					<< setw(15)
					<< pHead3->id
					<< left
					<< setw(15)
					<< pHead3->course_name
					<< left
					<< setw(20)
					<< pHead3->class_name
					<< left
					<< setw(15)
					<< pHead3->teacher_name
					<< left
					<< setw(20)
					<< pHead3->number_credits
					<< left
					<< setw(27)
					<< pHead3->number_students
					<< left
					<< setw(17)
					<< pHead3->day_of_week
					<< left
					<< setw(15)
					<< pHead3->sessions
					<< left
					<< setw(3)
					<< pHead3->midterm
					<< left
					<< setw(3)
					<< pHead3->final
					<< left
					<< setw(3)
					<< pHead3->other
					<< endl;
				pHead3 = pHead3->pNext;
			}
			cout << endl;
			pHead2 = pHead2->pNext;
		}
		cout << endl;
		pHead1 = pHead1->pNext;
	}
	string s;
	cout << "Press any key to continue...\n";
	cin >> s;
	clrscr();
}

void print_All_ClassToConsole(Class *pHead_class)
{
	/*if (pHead_class == nullptr)
	{
		cout "There is no class has been created yet" << endl;
		return;
	}*/
	Class *pHead2 = pHead_class;
	while (pHead2 != nullptr)
	{
		cout << pHead2->class_name << endl;
		pHead2 = pHead2->pNext;
	}
	string s;
	cout << "Press any key to continue...\n";
	cin >> s;
	clrscr();
}

void print_All_Student_In_A_class(studentClass *pCur)
{
	if (pCur == nullptr)
	{
		cout << "There is no students have been added yet!" << endl;
		return;
	}
	cout << left
		 << setw(15)
		 << "Student ID| "
		 << left
		 << setw(15)
		 << "First Name| "
		 << left
		 << setw(15)
		 << "Last Name|"
		 << left
		 << setw(15)
		 << "Gender| "
		 << left
		 << setw(17)
		 << "Date of birth| "
		 << left
		 << setw(15)
		 << "Social ID| " << endl;
	while (pCur != nullptr)
	{
		cout << left
			 << setw(15)
			 << pCur->student_ID << " "
			 << left
			 << setw(15)
			 << pCur->first_name << " "
			 << left
			 << setw(15)
			 << pCur->last_name << " "
			 << left
			 << setw(15)
			 << pCur->gender << " "
			 << left
			 << setw(15)
			 << pCur->date_of_birth << " "
			 << left
			 << setw(15)
			 << pCur->social_ID << endl;
		pCur = pCur->pNext;
	}
	string s;
	cout << "Press any key to continue...\n";
	cin >> s;
	clrscr();
}

void Print_All_Student_In_A_Course_With_score(Student *pCur)
{
	while (pCur != nullptr)
	{
		cout
			<< setw(13)
			<< pCur->student_ID << " "
			<< left
			<< setw(13)
			<< pCur->first_name << " "
			<< left
			<< setw(13)
			<< pCur->last_name << " "
			<< left
			<< setw(13)
			<< pCur->gender << " "
			<< left
			<< setw(13)
			<< pCur->date_of_birth << " "
			<< left
			<< setw(13)
			<< pCur->social_ID << " "
			<< left
			<< setw(9)
			<< pCur->score.total_mark << " "
			<< left
			<< setw(9)
			<< pCur->score.final_mark << " "
			<< left
			<< setw(13)
			<< pCur->score.mid_mark << " "
			<< left
			<< setw(13)
			<< pCur->score.other_mark << endl;

		pCur = pCur->pNext;
	}
	string s;
	cout << "Press any key to continue...\n";
	cin >> s;
	clrscr();
}

void Print_All_Student_In_A_Course(Student *pCur)
{
	cout << left
		 << setw(13)
		 << "Student ID| "
		 << left
		 << setw(13)
		 << "First Name| "
		 << left
		 << setw(13)
		 << "Last Name|"
		 << left
		 << setw(13)
		 << "Gender| "
		 << left
		 << setw(13)
		 << "Date of birth| "
		 << left
		 << setw(13)
		 << "Social ID| " << endl;
	while (pCur != nullptr)
	{
		cout
			<< setw(13)
			<< pCur->student_ID << " "
			<< left
			<< setw(13)
			<< pCur->first_name << " "
			<< left
			<< setw(13)
			<< pCur->last_name << " "
			<< left
			<< setw(13)
			<< pCur->gender << " "
			<< left
			<< setw(13)
			<< pCur->date_of_birth << " "
			<< left
			<< setw(13)
			<< pCur->social_ID << " " << endl;
		pCur = pCur->pNext;
	}
	string s;
	cout << "Press any key to continue...\n";
	cin >> s;
	clrscr();
}

void addCourse(Course *&pHead)
{
	Course *pCur = pHead;
	while (pCur->pNext != nullptr)
		pCur = pCur->pNext;
	pCur->pNext = new Course;
	pCur = pCur->pNext;

	cout << "Enter Course ID: ";
	cin >> pCur->id;

	cout << "Enter Course Name: ";
	cin >> pCur->course_name;

	cout << "Enter Class Name: ";
	cin >> pCur->class_name;

	cout << "Enter Teacher Name: ";
	cin >> pCur->teacher_name;

	cout << "Enter Number of credits: ";
	cin >> pCur->number_credits;

	cout << "Enter Number of students: ";
	cin >> pCur->number_students;

	cout << "Enter day of week: " << endl;
	cout << "MON / TUE / WED / THU / FRI / SAT:  ";
	cin >> pCur->day_of_week;

	cout << "Enter session" << endl;
	cout << "S1(07:30) -- S2 (09:30) -- S3(13:30) -- S4(15:30): ";
	cin >> pCur->sessions;
	pCur->other = -1;
	while (pCur->other < 0)
	{
		cout << "The percentage of point form the midterm exam and final exam:  ";
		cin >> pCur->midterm >> pCur->final;
		pCur->other = 100 - pCur->midterm - pCur->final;
		if (pCur->other < 0)
			cout << "The percentage of point form the other exam is not valid" << endl;
	}

	pCur->pNext = nullptr;
	pCur->student = nullptr;
}

void export_list_of_student_ToCSVFile(Student *pCur, string year_name, string semester_name, string course_id)
{
	ofstream file;
	file.open("student_In_A_Course.txt");
	file << year_name << endl;
	file << semester_name << endl;
	file << course_id << endl;
	while (pCur != nullptr)
	{
		file << pCur->student_ID << ","
			 << pCur->first_name << ","
			 << pCur->last_name << ","
			 << pCur->gender << ","
			 << pCur->date_of_birth << ","
			 << pCur->social_ID;
		if (pCur->pNext != nullptr)
			file << endl;

		pCur = pCur->pNext;
	}
	file.close();
}

// The pDelete is surely found.
void deleteCourse(Course *&pHead, Course *&pDelete, string year_name, string semester_name)
{
	if (pHead == nullptr)
	{
		cout << "pHead is a nullptr";
		return;
	}

	Course *pCur = pHead;
	if (pHead == pDelete)
	{
		pHead = pHead->pNext;
		while (pCur->student != nullptr)
		{
			Student *pTemp1 = pCur->student;
			pCur->student = pCur->student->pNext;
			delete pTemp1;
		}
		string path;
		path = year_name + BACKSLASH + semester_name + BACKSLASH + pCur->id + ".txt";
		remove(path.c_str());
		delete pCur;
		pCur = nullptr;
		return;
	}

	Course *pPrevCur = pHead;
	while (pCur != nullptr && pCur != pDelete)
	{
		pPrevCur = pCur;
		pCur = pCur->pNext;
	}
	// If found, delete the Node of course in the linked list
	pPrevCur->pNext = pCur->pNext;
	string path;
	path = year_name + BACKSLASH + semester_name + BACKSLASH + pCur->id + ".txt";
	remove(path.c_str());
	// Delete the pointer student of a course
	while (pCur->student != nullptr)
	{
		Student *pTemp1 = pCur->student;
		pCur->student = pCur->student->pNext;
		delete pTemp1;
	}
	delete pCur;
	pPrevCur = nullptr;
	pCur = nullptr;
}

void update_course_ID(Course *&pCur)
{
	cout << "Enter new Course ID: ";
	cin.ignore();
	getline(cin, pCur->id);
	cout << "Update successfully!\nPlease enter any key to continue..." << endl;
}

void update_course_name(Course *&pCur)
{
	cout << "Enter new Course Name: ";
	getline(cin, pCur->course_name);
	cout << "Update successfully!\nPlease enter any key to continue..." << endl;
}

void update_class_name(Course *&pCur)
{
	cout << "Enter new Class Name: ";
	getline(cin, pCur->class_name);
	cout << "Update successfully!\nPlease enter any key to continue..." << endl;
}

void update_teacher_name(Course *&pCur)
{
	cout << "Enter new Teacher Name: ";
	getline(cin, pCur->teacher_name);
	cout << "Update successfully!\nPlease enter any key to continue..." << endl;
}

void update_number_credits(Course *&pCur)
{
	cout << "Enter new Number of Credits: ";
	int get_number_credits;
	cin >> get_number_credits;
	while (get_number_credits <= 0)
	{
		cout << "Invalid input. Try a new positive number of credits: ";
		cin >> get_number_credits;
	}
	pCur->number_credits = to_string(get_number_credits);
	cout << "Update successfully!\nPlease enter any key to continue..." << endl;
}

void update_number_students(Course *&pCur)
{
	cout << "Enter new number of Students: ";
	int get_number_students;
	cin >> get_number_students;
	while (get_number_students <= 0)
	{
		cout << "Invalid input. Please try a new positive number of students!!!";
		cin >> get_number_students;
	}
	pCur->number_students = to_string(get_number_students);
	cout << "Update successfully!\nPlease enter any key to continue..." << endl;
}

void update_day_week(Course *&pCur)
{
	cout << "Enter new Day of week: ";
	cin.ignore();
	cin >> pCur->day_of_week;
	cout << "Update successfully!\nPlease enter any key to continue..." << endl;
}

void update_session(Course *&pCur)
{
	cout << "Enter new session";
	cin.ignore();
	getline(cin, pCur->sessions);
	cout << "Update successfully!\nPlease enter any key to continue..." << endl;
}

void update_percentage(Course *&pCur)
{
	pCur->other = -1;
	while (pCur->other < 0)
	{
		cout << "The percentage of point form the midterm exam and final exam:  ";
		cin >> pCur->midterm >> pCur->final;
		pCur->other = 100 - pCur->midterm - pCur->final;
		if (pCur->other < 0)
			cout << "The percentage of point form the other exam is not valid" << endl;
	}
	cout << "Update successfully!\nPlease enter any key to continue..." << endl;
}

void update_Course(Course *&pCur)
{
	cout << "Choose option which have to be updated " << endl;
	while (true)
	{
		cout << "1. Course ID" << endl;
		cout << "2. Course Name" << endl;
		cout << "3. Class Name" << endl;
		cout << "4. Teacher Name" << endl;
		cout << "5. Number of credits " << endl;
		cout << "6, Number of students" << endl;
		cout << "7. Day of the week" << endl;
		cout << "8. Sessions" << endl;
		cout << "9. Update the percentage of point form the midterm exam and final exam" << endl;
		cout << "10. All of above " << endl;
		cout << "0. Exit" << endl;
		int option;
		cin >> option;
		clrscr();
		switch (option)
		{
		case 1:
			update_course_ID(pCur);
			break;
		case 2:
			update_course_name(pCur);
			break;
		case 3:
			update_class_name(pCur);
			break;
		case 4:
			update_teacher_name(pCur);
			break;
		case 5:
			update_number_credits(pCur);
			break;
		case 6:
			update_number_students(pCur);
			break;
		case 7:
			update_day_week(pCur);
			break;
		case 8:
			update_session(pCur);
			break;
		case 9:
			update_percentage(pCur);
			break;
		case 10:
		{
			update_course_ID(pCur);
			update_course_name(pCur);
			update_class_name(pCur);
			update_teacher_name(pCur);
			update_number_credits(pCur);
			update_number_students(pCur);
			update_day_week(pCur);
			update_session(pCur);
			update_percentage(pCur);
			break;
		}
		case 0:
		{
			cout << "Finish updating!!!\nPlease enter any key to continue...";
			return;
		}
		default:
			continue;
		}
	}
}

Semester *Find_Semester(SchoolYear *pHead)
{
	string get_schoolyear;
	cout << "Enter shool Year: ";
	cin >> get_schoolyear;
	while (pHead != nullptr && pHead->year_name != get_schoolyear)
	{
		pHead = pHead->pNext;
	}
	if (pHead == nullptr)
	{
		cout << "There is no schoolyear matching with your typing!!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return NULL;
	}

	Semester *pCur_semester = pHead->semester;
	string get_semester;
	cout << "Enter semester: ";
	cin >> get_semester;

	while (pCur_semester != nullptr && pCur_semester->semester_name != get_semester)
	{
		pCur_semester = pCur_semester->pNext;
	}
	if (pCur_semester == nullptr)
	{
		cout << "There is no semester matching with your typing!!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return NULL;
	}
	else
		return pCur_semester;
}

Course *Find_Course(SchoolYear *pHead)
{
	// These code is used for traversing the linked list of Schoolyear, to found the specific Schoolyear.
	string get_schoolyear;
	cout << "Enter School Year: ";
	cin >> get_schoolyear;
	while (pHead != nullptr && pHead->year_name != get_schoolyear)
	{
		pHead = pHead->pNext;
	}
	if (pHead == nullptr)
	{
		cout << "There is no schoolyear matching with your typing!!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return NULL;
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
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return NULL;
	}

	Course *pCur_Course = pCur_Semester->course;
	cout << "Enter Course ID: ";
	string get_course_ID;
	cin >> get_course_ID;
	while (pCur_Course != nullptr && pCur_Course->id != get_course_ID)
		pCur_Course = pCur_Course->pNext;
	if (pCur_Course == nullptr)
	{
		cout << "There is no course ID matching with your typing !!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return NULL;
	}
	// To make sure that the pCur_course is not a null pointer.
	return pCur_Course;
}

void add_Student_to_Course_By_File(Student *&pHead)
{
	Student *pCur = nullptr;
	if (pHead != nullptr)
	{
		pCur = pHead;
		while (pCur->pNext != nullptr)
			pCur = pCur->pNext;
	}

	ifstream file;
	// The file addStudentToCourse.txt is an input file, which contain the first line is the Course to be addedd
	// The following next lines are the students information.
	file.open("addStudentToCourse.txt");
	if (!file.is_open())
	{
		cout << "Can't open addStudentToCourse.txt" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}
	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new Student;
			pCur = pHead;
		}
		else
		{
			pCur->pNext = new Student;
			pCur = pCur->pNext;
		}

		getline(file, pCur->student_ID, ',');
		getline(file, pCur->first_name, ',');
		getline(file, pCur->last_name, ',');
		getline(file, pCur->gender, ',');
		getline(file, pCur->date_of_birth, ',');
		getline(file, pCur->social_ID, ',');

		string temp;
		getline(file, temp, ',');
		pCur->score.total_mark = stof(temp);

		getline(file, temp, ',');
		pCur->score.final_mark = stof(temp);

		getline(file, temp, ',');
		pCur->score.mid_mark = stof(temp);

		getline(file, temp, '\n');
		pCur->score.other_mark = stof(temp);

		pCur->pNext = nullptr;
	}
	file.close();
}

void add_Student_to_Course_By_Console(Student *&pHead)
{
	Student *pCur = nullptr;
	if (pHead != nullptr)
	{
		pCur = pHead;
		while (pCur != nullptr && pCur->pNext != nullptr)
		{
			pCur = pCur->pNext;
		}
		pCur->pNext = new Student;
		pCur = pCur->pNext;
		pCur->pNext = nullptr;
	}

	if (pHead == nullptr)
	{
		pHead = new Student;
		pCur = pHead;
		pHead->pNext = nullptr;
	}

	cout << "Enter new student ID: ";
	cin.ignore();
	cin >> pCur->student_ID;

	cout << "Enter new student first name: ";
	cin.ignore();
	cin >> pCur->first_name;

	cout << "Enter new student last name: ";
	cin.ignore();
	cin >> pCur->last_name;

	cout << "Enter new student gender: ";
	cin.ignore();
	cin >> pCur->gender;

	cout << "Enter new student date of birth: ";
	cin.ignore();
	cin >> pCur->date_of_birth;

	cout << "Enter new student social ID: ";
	cin.ignore();
	cin >> pCur->social_ID;
}

void remove_Student_from_Course(Student *&pHead)
{
	Student *pCur = pHead;
	;
	Student *pPrevCur = pHead;
	string get_student_ID;
	cout << "Enter student ID: ";
	cin >> get_student_ID;
	while (pCur != nullptr && pCur->student_ID != get_student_ID)
	{
		pPrevCur = pCur;
		pCur = pCur->pNext;
	}

	if (pCur != nullptr)
	{
		pPrevCur->pNext = pCur->pNext;
		delete pCur;
		cout << "Delete Student from Course successfully!!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		pCur = nullptr;
		pPrevCur = nullptr;
		return;
	}
	cout << "There is no student ID matching with your typing !!!" << endl;
	cout << "Press any key to continue...\n";
	string s;
	cin >> s;
	clrscr();
}

void Print_All_Student_In_A_Class_With_score_All(Class *pClass)
{

	Class *pCur_Class = pClass;
	string get_class;
	cout << "Enter Class: ";
	cin >> get_class;

	while (pCur_Class != nullptr && pCur_Class->class_name != get_class)
		pCur_Class = pCur_Class->pNext;

	if (pCur_Class == nullptr)
	{
		cout << "There is no semester matching with your typing !!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}

	studentClass *pCur = pCur_Class->student;

	while (pCur != nullptr)
	{
		cout
			<< setw(13)
			<< pCur->student_ID << " "
			<< left
			<< setw(13)
			<< pCur->first_name << " "
			<< left
			<< setw(13)
			<< pCur->last_name << " "
			<< left
			<< setw(13)
			<< pCur->gender << " "
			<< left
			<< setw(13)
			<< pCur->date_of_birth << " "
			<< left
			<< setw(13)
			<< pCur->social_ID << endl;

		scoreClass *pCurScore = pCur->score;

		if (pCurScore == nullptr)
		{
			cout << "\tNo score for this student" << endl;
			cout << "Press any key to continue...\n";
			string s;
			cin >> s;
			clrscr();
		}

		int n = 0;
		float sum = 0;

		while (pCurScore != nullptr)
		{
			cout
				<< left
				<< setw(30)
				<< pCurScore->course_name << "|"
				<< left
				<< setw(15)
				<< pCurScore->course_ID << "|"
				<< left
				<< setw(5)
				<< pCurScore->score.final_mark << "|"
				<< left
				<< setw(5)
				<< pCurScore->score.final_mark << "|"
				<< left
				<< setw(5)
				<< pCurScore->score.mid_mark << "|"
				<< left
				<< setw(5)
				<< pCurScore->score.other_mark << endl;

			n++;
			sum += pCurScore->score.total_mark;

			pCurScore = pCurScore->next;
		}
		if (n != 0)
			cout << right << setw(50) << "GPA: " << (sum / n) / 10 * 4 << endl;
		pCur = pCur->pNext;
	}
}

bool checkForCourse(Course *pCur, string courseID)
{
	while (pCur != nullptr)
	{
		if (pCur->id == courseID)
		{
			return true;
		}
		pCur = pCur->pNext;
	}
	return false;
}

void Print_All_Student_In_A_Class_With_score_Semester(SchoolYear *pHead, Class *pClass)
{
	SchoolYear *pCurYear = pHead;
	Course *pCurCourse = nullptr;

	string get_schoolyear;
	cout << "Enter School Year: ";
	cin >> get_schoolyear;

	while (pHead != nullptr && pHead->year_name != get_schoolyear)
	{
		pHead = pHead->pNext;
	}
	if (pHead == nullptr)
	{
		cout << "There is no schoolyear matching with your typing!!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}

	Semester *pCur_Semester = pHead->semester;
	string get_semester;
	cout << "Enter Semester: ";
	cin >> get_semester;

	while (pCur_Semester != nullptr && pCur_Semester->semester_name != get_semester)
	{
		pCur_Semester = pCur_Semester->pNext;
	}

	if (pCur_Semester == nullptr)
	{
		cout << "There is no semester matching with your typing !!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}

	pCurCourse = pCur_Semester->course;

	Class *pCur_Class = pClass;
	string get_class;
	cout << "Enter Class: ";
	cin >> get_class;

	while (pCur_Class != nullptr && pCur_Class->class_name != get_class)
		pCur_Class = pCur_Class->pNext;

	if (pCur_Class == nullptr)
	{
		cout << "There is no academic class matching with your typing !!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}

	studentClass *pCur = pCur_Class->student;

	while (pCur != nullptr)
	{
		cout
			<< " "
			<< pCur->student_ID << " "
			<< " "
			<< pCur->first_name << " "
			<< " "
			<< pCur->last_name << " "
			<< " "
			<< pCur->gender << " "
			<< " "
			<< pCur->date_of_birth << " "
			<< " "
			<< pCur->social_ID << endl;

		scoreClass *pCurScore = pCur->score;

		if (pCurScore == nullptr)
		{
			cout << "\tNo score for this student" << endl;
		}

		int n = 0;
		float sum = 0;

		while (pCurScore != nullptr)
		{
			if (pCurScore->score.final_mark == 0)
			{
				pCurScore = pCurScore->next;
				continue;
			}
			if (checkForCourse(pCurCourse, pCurScore->course_ID) == false)
			{
				pCurScore = pCurScore->next;
				continue;
			}

			cout
				<< left
				<< setw(30)
				<< pCurScore->course_name << "|"
				<< left
				<< setw(15)
				<< pCurScore->course_ID << "|"
				<< left
				<< setw(5)
				<< pCurScore->score.final_mark << "|"
				<< left
				<< setw(5)
				<< pCurScore->score.final_mark << "|"
				<< left
				<< setw(5)
				<< pCurScore->score.mid_mark << "|"
				<< left
				<< setw(5)
				<< pCurScore->score.other_mark << endl;
			n++;
			sum += pCurScore->score.final_mark;

			pCurScore = pCurScore->next;
		}
		if (n != 0)
			cout << right << setw(50) << "GPA: " << (sum / n) / 10 * 4 << endl;
		pCur = pCur->pNext;
	}
	cout << "Press any key to continue...\n";
	string s;
	cin >> s;
	clrscr();
}