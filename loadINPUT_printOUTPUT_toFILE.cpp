#include "lib.h"

void load_student_InCourse(Student*& pHead, string schoolYear_name, string semester_name, string course_id)
{
	ifstream file;
	file.open(schoolYear_name + "\\" + semester_name + "\\" + course_id + ".txt");

	if (!file.is_open())
	{
		cout << "Khong mo duoc file .txt cua course";
		return;
	}
	Student* pCur = pHead;
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
		getline(file, pCur->social_ID, '\n');

		pCur->pNext = nullptr;
	}
	file.close();
}

void load_course(Course*& pHead, string schoolYear_name, string semester_name)
{
	ifstream file;
	file.open(schoolYear_name + "\\" + semester_name + "\\courseList.txt");
	if (!file.is_open())
	{
		cout << "Khong mo duoc file courseList.txt" << endl;
		return;
	}

	Course* pCur = pHead;

	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new Course;
			pCur = pHead;
		}
		else
		{
			pCur->pNext = new Course;
			pCur = pCur->pNext;
		}

		getline(file, pCur->id, ',');
		getline(file, pCur->course_name, ',');
		getline(file, pCur->class_name, ',');
		getline(file, pCur->teacher_name, ',');
		getline(file, pCur->number_credits, ',');
		getline(file, pCur->number_students, ',');
		getline(file, pCur->day_of_week, ',');
		getline(file, pCur->sessions, '\n');

		pCur->pNext = nullptr;
	}
	file.close();
}

void load_semester(Semester*& pHead, string schoolYear_name)
{
	ifstream file;
	file.open(schoolYear_name + "\\semesterList.txt");

	Semester* pCur = pHead;
	if (!file.is_open())
	{
		cout << "Khong mo duoc file semesterList.txt";
		return;
	}
	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new Semester;
			pCur = pHead;
		}
		else
		{
			pCur->pNext = new Semester;
			pCur = pCur->pNext;
		}
		getline(file, pCur->semester_name, '\n');
		pCur->pNext = nullptr;
	}
	file.close();
}

void load_schoolYear(SchoolYear*& pHead)
{
	ifstream file;
	file.open("schoolYearList.txt");
	if (!file.is_open())
	{
		cout << "Khong mo duoc file schoolYearList.txt";
		return;
	};
	SchoolYear* pCur = pHead;
	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new SchoolYear;
			pCur = pHead;
		}
		else
		{
			pCur->pNext = new SchoolYear;
			pCur = pCur->pNext;
		}
		file >> pCur->year_name;
		pCur->pNext = nullptr;
	}
	file.close();
}

void load_input(SchoolYear*& pHead_schoolYear)
{
	// The function is used to load the data of schoolyears, semesters in each schoolyear, courses in each semester, students in each courses.
	//The format of the folder is:
	// 
	//The big folder will contain the file .txt which named schoolYearList.txt, which in each line of the file contains the name of the schoolyear (This schoolyear has been created before)
	//For each year which has been included in the file schoolYearList.txt, it means that the folder of that year has been created before.
	// 
	//In each folder of each year, it will contain the file .txt which named semesterList.txt, which included the list of semester that has been created before and folder of its semester
	//In each folder of each semester, it will contain the file .txt which named courseList.txt, which included the data of all the courses which have been created before.
	//The data of each course includes course id, course name, class name,........

	load_schoolYear(pHead_schoolYear);

	SchoolYear* pCur_schoolYear = pHead_schoolYear;

	//The pCur_schoolYear is used for traversing the list of nodes.
	while (pCur_schoolYear != nullptr)
	{
		cout << pCur_schoolYear->year_name << " ";
		Semester* pCur_Semester = nullptr;
		load_semester(pCur_Semester, pCur_schoolYear->year_name);
		pCur_schoolYear->semester = pCur_Semester;
		while (pCur_Semester != nullptr)
		{
			cout << pCur_Semester->semester_name << " ";
			Course* pCur_Course = nullptr;
			load_course(pCur_Course, pCur_schoolYear->year_name, pCur_Semester->semester_name);
			pCur_schoolYear->semester->course = pCur_Course;
			cout << endl;
			while (pCur_Course != nullptr)
			{
				cout << pCur_Course->course_name << " " << pCur_Course->class_name << " " << pCur_Course->sessions << " ";
				cout << endl;
				//Student* pHead_Student = nullptr;
				Student* pCur_Student = nullptr;
				cout << pCur_schoolYear->year_name << " " << pCur_Semester->semester_name << " " << pCur_Course->id;
				cout << endl;
				load_student_InCourse(pCur_Student, pCur_schoolYear->year_name, pCur_Semester->semester_name, pCur_Course->id);
				pCur_schoolYear->semester->course->student = pCur_Student;
				cout << endl;
				while (pCur_Student != nullptr)
				{
					cout << pCur_Student->student_ID << " "
						<< pCur_Student->first_name << " "
						<< pCur_Student->last_name << " "
						<< pCur_Student->gender << " "
						<< pCur_Student->date_of_birth << " "
						<< pCur_Student->social_ID << endl;
					cout << endl;
					pCur_Student = pCur_Student->pNext;
				}
				pCur_Course = pCur_Course->pNext;
			}
			pCur_Semester = pCur_Semester->pNext;
		}
		pCur_schoolYear = pCur_schoolYear->pNext;
		cout << endl;
	}
}

void print_student_InCourse(Student* pHead, string schoolYear_name, string Semester_name, string Course_name)
{
	ofstream file;
	file.open(schoolYear_name + "\\" + Semester_name + "\\" + Course_name + ".txt");
	while (pHead != nullptr)
	{
		file << pHead->student_ID << ","
			<< pHead->first_name << ","
			<< pHead->last_name << ","
			<< pHead->gender << ","
			<< pHead->date_of_birth << ","
			<< pHead->social_ID << "\n";
		pHead = pHead->pNext;
	}
	file.close();
}

void print_course(Course* pHead, string schoolYear_name, string Semester_name)
{
	ofstream file;
	file.open(schoolYear_name + "\\" + Semester_name + "\\" + "courseList.txt");
	while (pHead != nullptr)
	{
		file
			<< pHead->id << ","
			<< pHead->course_name << ","
			<< pHead->class_name << ","
			<< pHead->teacher_name << ","
			<< pHead->number_credits << ","
			<< pHead->number_students << ","
			<< pHead->day_of_week << ","
			<< pHead->sessions << "\n";

		pHead = pHead->pNext;
	}
	file.close();
}

void print_Semester(Semester* pHead_Semester, string Schoolyear_name)
{
	ofstream file;
	file.open(Schoolyear_name + "\\" + "semesterList.txt");
	while (pHead_Semester != nullptr)
	{
		file << pHead_Semester->semester_name << endl;
		pHead_Semester = pHead_Semester->pNext;
	}
	file.close();
}

void print_output(SchoolYear* pHead_SchoolYear)
{
	ofstream file;
	file.open("schoolYearlist.txt");
	while (pHead_SchoolYear != nullptr)
	{
		file << pHead_SchoolYear->year_name << endl;
		pHead_SchoolYear = pHead_SchoolYear->pNext;
	}
	file.close();

	while (pHead_SchoolYear != nullptr)
	{
		Semester* pCur_Semester = pHead_SchoolYear->semester;
		print_Semester(pCur_Semester, pHead_SchoolYear->year_name);
		while (pCur_Semester != nullptr)
		{
			Course* pCur_course = pHead_SchoolYear->semester->course;
			print_course(pCur_course, pHead_SchoolYear->year_name, pCur_course->course_name);

			while (pCur_course != nullptr)
			{
				Student* pCur_student = pHead_SchoolYear->semester->course->student;
				print_student_InCourse(pCur_student, pHead_SchoolYear->year_name, pCur_Semester->semester_name, pCur_course->course_name);
				pCur_course = pCur_course->pNext;
			}
			pCur_Semester = pCur_Semester->pNext;
		}
		pHead_SchoolYear = pHead_SchoolYear->pNext;
	}
}

//Today
void printCourseToConsole(Course* pHead)
{
	//print to Console the Courses which have the format:
	//Course_ID---Course_name---Class_name---Teacher_name---Number_of_Credits---Number_of_maximum_students---Day_of_week---Sessions
	cout
		<< setw(15)
		<< "Course ID"
		<< setw(20)
		<< "Course Name"
		<< setw(20)
		<< "Class Name"
		<< setw(20)
		<< "Teacher Name"
		<< setw(10)
		<< "Number of credits"
		<< setw(10)
		<< "Number of maximum students"
		<< setw(10)
		<< "Day of the week"
		<< setw(15)
		<< "Session";
	while (pHead != nullptr)
	{
		cout
			<< setw(15)
			<< pHead->id
			<< setw(20)
			<< pHead->course_name
			<< setw(20)
			<< pHead->class_name
			<< setw(20)
			<< pHead->teacher_name
			<< setw(20)
			<< pHead->number_credits
			<< setw(10)
			<< pHead->number_credits
			<< setw(10)
			<< pHead->day_of_week
			<< setw(15)
			<< pHead->sessions;
		pHead = pHead->pNext;
	}
}

void addCourse(Course*& pHead)
{
	Course* pCur;
	pCur = pHead;

	while (pCur->pNext != nullptr)
	{
		pCur = pCur->pNext;
	}
	pCur->pNext = new Course;
	pCur = pCur->pNext;

	cout << "Enter Course ID";
	cin >> pCur->id;
	cout << endl;

	cout << "Enter Course Name";
	cin >> pCur->course_name;
	cout << endl;

	cout << "Enter Class Name";
	cin >> pCur->class_name;
	cout << endl;

	cout << "Enter Teacher Name";
	cin >> pCur->teacher_name;
	cout << endl;

	cout << "Enter Number of credits: ";
	cin >> pCur->number_credits;
	cout << endl;

	cout << "Enter Number of students: ";
	cin >> pCur->number_students;
	cout << endl;

	cout << "    Enter day of week" << endl;
	cout << "MON / TUE / WED / THU / FRI / SAT ";
	cin >> pCur->day_of_week;
	cout << endl;


	cout << "    Enter session" << endl;
	cout << "S1(07:30) -- S2 (09:30) -- S3(13:30) -- S4(15:30)";
	cin >> pCur->sessions;
	pCur->pNext = nullptr;
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

//Make sure that at the end of the code, we will find the Course with specific Schoolyear, semester and course. If not found, the console will show it out.
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
	{
		pCur_Semester = pCur_Semester->pNext;
	}
	if (pCur_Semester == nullptr)
	{
		cout << "There is no semester matching with your typing !!!" << endl;
		return NULL;
	}
	Course* pCur_Course = pCur_Semester->course;
	cout << "Enter Course ID: ";
	string get_course_ID;
	cin >> get_course_ID;

	while (pCur_Course != nullptr && pCur_Course->course_name == get_course_ID)
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

void add_Student_to_Course_By_File(Course*& pCur)
{
	Student* pHead_Student = pCur->student;

	ifstream file;
	//The file addStudentToCourse.txt is an input file, which contain the first line is the Course to be addedd
	//The following next lines are the students information.
	file.open("addStudentToCourse.txt");
	if (!file.is_open())
	{
		cout << "Khong mo duoc file addStudentToCourse.txt" << endl;
		return;
	}

	Student* pTail = pHead_Student;
	while (pTail->pNext != nullptr)
		pTail = pTail->pNext;
	while (!file.eof())
	{
		pTail->pNext = new Student;

		pTail = pTail->pNext;

		getline(file, pTail->student_ID, ',');
		getline(file, pTail->first_name, ',');
		getline(file, pTail->last_name, ',');
		getline(file, pTail->gender, ',');
		getline(file, pTail->date_of_birth, ',');
		getline(file, pTail->social_ID, '\n');

		pTail->pNext = nullptr;
	}
	file.close();

}

void add_Student_to_Course_By_Console(Course*& pCur)
{
	Student* pHead_Student = pCur->student;

	while (pHead_Student->pNext != nullptr)
		pHead_Student = pHead_Student->pNext;

	pHead_Student->pNext = new Student;
	pHead_Student = pHead_Student->pNext;

	cout << "Enter new student ID: ";
	cin >> pHead_Student->student_ID;

	cout << "Enter new student first name: ";
	cin >> pHead_Student->first_name;

	cout << "Enter new student last name: ";
	cin >> pHead_Student->last_name;

	cout << "Enter new student gender: ";
	cin >> pHead_Student->gender;

	cout << "Enter new student date of birth: ";
	cin >> pHead_Student->date_of_birth;

	cout << "Enter new student social ID: ";
	cin >> pHead_Student->social_ID;

	pHead_Student->pNext = nullptr;
}

void remove_Student_from_Course(Course*& pCur)
{
	Student* pHead_Student = pCur->student;
	Student* pPrevCur_Student = pCur->student;
	string get_student_ID;
	cout << "Enter student ID: ";
	cin >> get_student_ID;
	while (pHead_Student != nullptr && pHead_Student->student_ID != get_student_ID)
	{
		pPrevCur_Student = pHead_Student;
		pHead_Student = pHead_Student->pNext;
	}

	if (pHead_Student != nullptr)
	{
		pPrevCur_Student->pNext = pHead_Student->pNext;
		delete pHead_Student;
		cout << "Delete Student from Course successfully!!!" << endl;
		pHead_Student = nullptr;
		pPrevCur_Student = nullptr;
		return;
	}
	cout << "There is no student ID matching with your typing !!!" << endl;
}

void deallocated(SchoolYear*& pHead_schoolYear)
{
	SchoolYear* pCur_schoolYear = pHead_schoolYear;
	while (pHead_schoolYear != nullptr)
	{
		Semester* pHead_semester = pCur_schoolYear->semester;
		Semester* pCur_semester = pHead_semester;
		if (pCur_semester == nullptr) break;
		while (pHead_semester != nullptr)
		{
			Course* pHead_course = pHead_semester->course;
			Course* pCur_course = pHead_course;
			if (pCur_course == nullptr) break;
			while (pHead_course != nullptr)
			{
				Student* pHead_student = pHead_course->student;
				Student* pCur_student = pHead_student;
				if (pCur_student == nullptr) break;
				while (pHead_student != nullptr)
				{
					pHead_student = pHead_student->pNext;
					delete pCur_student;
					pCur_student = pHead_student;
				}
				pHead_course = pHead_course->pNext;
				delete pCur_course;
				pCur_course = pHead_course;
			}
			pHead_semester = pHead_semester->pNext;
			delete pCur_semester;
			pCur_semester = pHead_semester;
		}
		pHead_schoolYear = pHead_schoolYear->pNext;
		delete pCur_schoolYear;
		pCur_schoolYear = pHead_schoolYear;
	}
}