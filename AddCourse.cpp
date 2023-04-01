#include "lib.h"

void print_All_CourseToConsole(SchoolYear* pHead_schoolYear)
{
	//print to Console the Courses which have the format:
	//Course_ID---Course_name---Class_name---Teacher_name---Number_of_Credits---Number_of_maximum_students---Day_of_week---Sessions

	SchoolYear* pHead1 = pHead_schoolYear;
	while (pHead1 != nullptr)
	{
		cout << pHead1->year_name << " ";
		Semester* pHead2 = pHead1->semester;
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
				<< setw(15)
				<< "Session|";
			cout << endl;
			Course* pHead3 = pHead2->course;
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
					<< setw(15)
					<< pHead3->sessions;
				cout << endl;
				pHead3 = pHead3->pNext;
			}
			cout << endl;
			pHead2 = pHead2->pNext;
		}
		cout << endl;
		pHead1 = pHead1->pNext;
	}

}

void addCourse(Course*& pHead)
{
	Course* pCur = pHead;
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
	pCur->pNext = nullptr;

	pCur->student = nullptr;
}

//The pDelete is surely found.
void deleteCourse(Course*& pHead, Course*& pDelete)
{
	if (pHead == nullptr)
	{
		cout << "pHead is a nullptr";
		return;
	}

	Course* pCur = pHead;
	while (pCur->pNext != pDelete)
		pCur = pCur->pNext;
	//If found, delete the Node of course in the linked list
	Course* pTemp = pCur->pNext->pNext;
	delete pCur->pNext;
	pCur->pNext = pTemp;
	pTemp = nullptr;
	pCur = nullptr;
	/*Course* pCur = pHead;
	Course* pPrevCur = pHead;

	while (pCur != nullptr && pCur->id != pX->)
	{
		pPrevCur = pCur;
		pCur = pCur->pNext;
	}
	if (pCur != nullptr)
	{
		if (temp == pHead)
			pHead = temp->pNext;
		else
			temp->pNext = pCur->pNext;
		delete temp;
		temp = nullptr;
		pCur = nullptr;
		return;
	}*/
}

void update_course_ID(Course*& pCur)
{
	cout << "Enter new Course ID: ";
	getline(cin, pCur->id);
	cout << "Update successfully!" << endl;
}

void update_course_name(Course*& pCur)
{
	cout << "Enter new Course Name: ";
	getline(cin, pCur->course_name);
	cout << "Update successfully!" << endl;
}

void update_class_name(Course*& pCur)
{
	cout << "Enter new Class Name: ";
	getline(cin, pCur->class_name);
	cout << "Update successfully!" << endl;
}

void update_teacher_name(Course*& pCur)
{
	cout << "Enter new Teacher Name: ";
	getline(cin, pCur->teacher_name);
	cout << "Update successfully!" << endl;
}

void update_number_credits(Course*& pCur)
{
	cout << "Enter new Number of Credits: ";

	int get_number_credits = 0;
	cin >> get_number_credits;

	while (get_number_credits <= 0)
	{
		cout << "Invalid input. Try a new positive number of credits: ";
		cin >> get_number_credits;
	}
	pCur->number_credits = to_string(get_number_credits);
	cout << "Update successfully!" << endl;
}

void update_number_students(Course*& pCur)
{
	cout << "Enter new number of Students: ";

	int get_number_students = 0;
	cin >> get_number_students;
	while (get_number_students <= 0)
	{
		cout << "Invalid input. Please try a new positive number of students!!!";
		cin >> get_number_students;
	}
	pCur->number_students = to_string(get_number_students);
	cout << "Update successfully!" << endl;
}

void update_day_week(Course*& pCur)
{
	cout << "Enter new Day of week: ";
	cin >> pCur->day_of_week;
	cout << "Update successfully!" << endl;

}

void update_session(Course*& pCur)
{
	cout << "Enter new session";
	getline(cin, pCur->sessions);
	cout << "Update successfully!" << endl;
}

void update_Course(Course*& pCur)
{
	cout << "Choose option which have to be updated ";
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
		cout << "9. All of above " << endl;
		cout << "0. Exit" << endl;
		int option;
		cin >> option;
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

			update_course_ID(pCur);
			update_course_name(pCur);
			update_class_name(pCur);
			update_teacher_name(pCur);
			update_number_credits(pCur);
			update_number_students(pCur);
			update_day_week(pCur);
			update_session(pCur);
			break;
		case 0:
			return;
		default:
			continue;
		}
	}
}

Semester* Find_Semester(SchoolYear* pHead)
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
		return NULL;
	}

	Semester* pCur_semester = pHead->semester;
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
		return NULL;
	}
	else
		return pCur_semester;
}

Course* Find_Course(SchoolYear* pHead)
{
	//These code is used for traversing the linked list of Schoolyear, to found the specific Schoolyear.
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
		return NULL;
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
		return NULL;
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
		return NULL;
	}
	//To make sure that the pCur_course is not a null pointer.
	if (pCur_Course != nullptr)
		return pCur_Course;
}

void add_Student_to_Course_By_File(Student*& pHead)
{
	Student* pCur = nullptr;
	if (pHead != nullptr)
		pCur = pHead;

	ifstream file;
	//The file addStudentToCourse.txt is an input file, which contain the first line is the Course to be addedd
	//The following next lines are the students information.
	file.open("addStudentToCourse.txt");
	if (!file.is_open())
	{
		cout << "Khong mo duoc file addStudentToCourse.txt" << endl;
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

void add_Student_to_Course_By_Console(Student*& pHead)
{
	Student* pCur = pHead;
	while (pCur->pNext != nullptr)
		pCur = pCur->pNext;

	pCur->pNext = new Student;
	pCur = pCur->pNext;

	cout << "Enter new student ID: ";
	cin >> pCur->student_ID;

	cout << "Enter new student first name: ";
	cin >> pCur->first_name;

	cout << "Enter new student last name: ";
	cin >> pCur->last_name;

	cout << "Enter new student gender: ";
	cin >> pCur->gender;

	cout << "Enter new student date of birth: ";
	cin >> pCur->date_of_birth;

	cout << "Enter new student social ID: ";
	cin >> pCur->social_ID;

	cout << "Enter new student total mark";
	cin >> pCur->score.total_mark;

	cout << "Enter new student final mark";
	cin >> pCur->score.final_mark;

	cout << "Enter new student mid mark";
	cin >> pCur->score.mid_mark;

	cout << "Enter new student other mark";
	cin >> pCur->score.other_mark;

	pCur->pNext = nullptr;
}

void remove_Student_from_Course(Student*& pHead)
{
	Student* pCur = pHead;;
	Student* pPrevCur = pHead;
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
		pCur = nullptr;
		pPrevCur = nullptr;
		return;
	}
	cout << "There is no student ID matching with your typing !!!" << endl;
}