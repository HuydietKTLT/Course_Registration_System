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

void load_student_InClass(Student*& pHead, string class_name)
{
	ifstream file;
	file.open(class_name + ".txt");
	if (!file.is_open())
	{
		cout << "Khong mo duoc file class_name.txt";
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
		file >> pCur->semester_name;
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

void load_class(Class*& pHead)
{
	ifstream file;
	file.open("classList.txt");

	if (!file.is_open())
	{
		cout << "Khong mo duoc classList.txt";
		return;
	}

	Class* pCur = pHead;
	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new Class;
			pCur = pHead;
		}
		else
		{
			pCur->pNext = new Class;
			pCur = pCur->pNext;
		}
		file >> pCur->class_name;
		pCur->pNext = nullptr;
	}
	file.close();
}

void load_input(SchoolYear*& pHead_schoolYear, Class*& pHead_class)
{
	// The function is used to load the data of schoolyears, semesters in each schoolyear, courses in each semester, students in each courses.
	//The format of the folder is:
	// 
	//The big folder will contain the file .txt which named schoolYearList.txt, which in each line of the file contains the name of the schoolyear (This schoolyear has been created before)
	//For each year which has been included in the file schoolYearList.txt, it means that the folder of that year has been created before.
	// 
	//In each folder of each year, it will contain the file .txt which named semesterList.txt, which included the list of semester that has been created before and folder of its semester
	//In each folder of each semester, it will contain the file .txt which named courseList.txt, which included the data of all the courses which have been created before.
	//The data of each course includes course id, course name, class name

	/*The pCur_schoolYear is used for traversing the list of nodes*/

	load_schoolYear(pHead_schoolYear);
	SchoolYear* pCur_schoolYear = pHead_schoolYear;
	while (pCur_schoolYear != nullptr)
	{
		Semester* pCur_Semester = nullptr;
		load_semester(pCur_Semester, pCur_schoolYear->year_name);
		pCur_schoolYear->semester = pCur_Semester;
		while (pCur_Semester != nullptr)
		{
			Course* pCur_Course = nullptr;
			load_course(pCur_Course, pCur_schoolYear->year_name, pCur_Semester->semester_name);
			pCur_Semester->course = pCur_Course;
			while (pCur_Course != nullptr)
			{
				Student* pCur_Student = nullptr;
				load_student_InCourse(pCur_Student, pCur_schoolYear->year_name, pCur_Semester->semester_name, pCur_Course->id);
				pCur_Course->student = pCur_Student;
				pCur_Course = pCur_Course->pNext;
			}
			pCur_Semester = pCur_Semester->pNext;
		}
		pCur_schoolYear = pCur_schoolYear->pNext;
	}

	//Load class
	load_class(pHead_class);
	Class* pCur_class = pHead_class;
	while (pCur_class != nullptr)
	{
		Student* pCur_1 = nullptr;
		load_student_InClass(pCur_1, pCur_class->class_name);
		pCur_class->student = pCur_1;
		pCur_class = pCur_class->pNext;
	}

	//PRINT SOMETHING
	/*SchoolYear* pTemp1 = pHead_schoolYear;
	while (pHead_schoolYear != nullptr)
	{
		cout << endl;
		cout << pHead_schoolYear->year_name << endl;
		while (pHead_schoolYear->semester != nullptr)
		{
			cout << endl;
			cout << pHead_schoolYear->semester->semester_name << endl;
			while (pHead_schoolYear->semester->course != nullptr)
			{
				cout << endl;
				cout << pHead_schoolYear->semester->course->id << " " << pHead_schoolYear->semester->course->course_name << " "
					<< pHead_schoolYear->semester->course->class_name << " " << pHead_schoolYear->semester->course->teacher_name << " "
					<< pHead_schoolYear->semester->course->number_credits << " " << pHead_schoolYear->semester->course->number_students << " "
					<< pHead_schoolYear->semester->course->day_of_week << " " << pHead_schoolYear->semester->course->sessions << endl;

				while (pHead_schoolYear->semester->course->student != nullptr)
				{
					cout << endl;
					cout << pHead_schoolYear->semester->course->student->student_ID << " " << pHead_schoolYear->semester->course->student->first_name << " "
						<< pHead_schoolYear->semester->course->student->last_name << " " << pHead_schoolYear->semester->course->student->gender << " "
						<< pHead_schoolYear->semester->course->student->date_of_birth << " " << pHead_schoolYear->semester->course->student->social_ID << endl;
					cout << endl;

					pHead_schoolYear->semester->course->student = pHead_schoolYear->semester->course->student->pNext;
				}
				pHead_schoolYear->semester->course = pHead_schoolYear->semester->course->pNext;
			}
			pHead_schoolYear->semester = pHead_schoolYear->semester->pNext;
		}
		pHead_schoolYear = pHead_schoolYear->pNext;
	}
	pHead_schoolYear = pTemp1;

	Class* pTemp2 = pHead_class;
	while (pHead_class != nullptr)
	{
		cout << endl;
		cout << pHead_class->class_name << " ";
		while (pHead_class->student != nullptr)
		{
			cout << endl;
			cout << pHead_class->student->student_ID << " " << pHead_class->student->first_name << " "
				<< pHead_class->student->last_name << " " << pHead_class->student->gender << " "
				<< pHead_class->student->date_of_birth << " " << pHead_class->student->social_ID << endl;
			cout << endl;
			pHead_class->student = pHead_class->student->pNext;
		}
		cout << endl;
		pHead_class = pHead_class->pNext;
	}*/
}

void print_student_InClass(Student* pHead, string class_name)
{
	ofstream file;
	file.open(class_name + ".txt");
	while (pHead != nullptr)
	{
		file
			<< pHead->student_ID << ","
			<< pHead->first_name << ","
			<< pHead->last_name << ","
			<< pHead->gender << ","
			<< pHead->date_of_birth << ","
			<< pHead->social_ID;
		if (pHead->pNext != nullptr)
			file << '\n';

		pHead = pHead->pNext;
	}
	file.close();
}

void print_student_InCourse(Student* pHead, string schoolYear_name, string semester_name, string course_id)
{
	ofstream file;
	file.open(schoolYear_name + "\\" + semester_name + "\\" + course_id + ".txt");
	while (pHead != nullptr)
	{
		file << pHead->student_ID << ","
			<< pHead->first_name << ","
			<< pHead->last_name << ","
			<< pHead->gender << ","
			<< pHead->date_of_birth << ","
			<< pHead->social_ID;
		if (pHead->pNext != nullptr)
			file << '\n';
		pHead = pHead->pNext;
	}
	file.close();
}

void print_course(Course* pHead, string schoolYear_name, string semester_name)
{
	ofstream file;
	file.open(schoolYear_name + "\\" + semester_name + "\\" + "courseList.txt");
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
			<< pHead->sessions;
		if (pHead->pNext != nullptr)
			file << '\n';

		pHead = pHead->pNext;
	}
	file.close();
}

void print_Semester(Semester* pHead_Semester, string schoolYear_name)
{
	ofstream file;
	file.open(schoolYear_name + "\\" + "semesterList.txt");
	while (pHead_Semester != nullptr)
	{
		file << pHead_Semester->semester_name;
		if (pHead_Semester->pNext != nullptr)
			file << endl;
		pHead_Semester = pHead_Semester->pNext;
	}
	file.close();
}

void print_output(SchoolYear* pHead_schoolYear, Class* pHead_class)
{

	////-------------------------------------------PRINTTT TO FILE------------------------------------------
	//Print schoolYear to schoolYearList.txt

	ofstream file;
	file.open("schoolYearlist.txt");
	SchoolYear* pTemp1 = pHead_schoolYear;
	while (pHead_schoolYear != nullptr)
	{
		if (pHead_schoolYear->pNext != nullptr)
			file << pHead_schoolYear->year_name << endl;
		else
			file << pHead_schoolYear->year_name;
		pHead_schoolYear = pHead_schoolYear->pNext;

	}
	file.close();
	/*pHead_schoolYear = pTemp1;
	while (pHead_schoolYear != nullptr)
	{
		Semester* pTemp2 = pHead_schoolYear->semester;
		while (pHead_schoolYear->semester != nullptr)
		{
			print_Semester(pHead_schoolYear->semester, pHead_schoolYear->year_name);
			Course* pTemp3 = pHead_schoolYear->semester->course;
			while (pHead_schoolYear->semester->course != nullptr)
			{
				Student* pTemp4 = pHead_schoolYear->semester->course->student;
				print_course(pHead_schoolYear->semester->course, pHead_schoolYear->year_name, pHead_schoolYear->semester->semester_name);
				while (pHead_schoolYear->semester->course->student != nullptr)
				{
					print_student_InCourse(pHead_schoolYear->semester->course->student, pHead_schoolYear->year_name, pHead_schoolYear->semester->semester_name, pHead_schoolYear->semester->course->id);
					pHead_schoolYear->semester->course->student = pHead_schoolYear->semester->course->student->pNext;
				}
				pHead_schoolYear->semester->course->student = pTemp4;

				pHead_schoolYear->semester->course = pHead_schoolYear->semester->course->pNext;
			}
			pHead_schoolYear->semester->course = pTemp3;


			pHead_schoolYear->semester = pHead_schoolYear->semester->pNext;
		}
		pHead_schoolYear->semester = pTemp2;


		pHead_schoolYear = pHead_schoolYear->pNext;
	}*/

	pHead_schoolYear = pTemp1;
	while (pHead_schoolYear != nullptr)
	{
		Semester* pCur_semester = pHead_schoolYear->semester;
		print_Semester(pCur_semester, pHead_schoolYear->year_name);
		while (pCur_semester != nullptr)
		{
			Course* pCur_course = pCur_semester->course;
			print_course(pCur_course, pHead_schoolYear->year_name, pCur_semester->semester_name);
			while (pCur_course != nullptr)
			{
				Student* pCur_student = pCur_course->student;
				print_student_InCourse(pCur_student, pHead_schoolYear->year_name, pCur_semester->semester_name, pCur_course->id);
				pCur_course = pCur_course->pNext;
			}
			pCur_semester = pCur_semester->pNext;
		}
		pHead_schoolYear = pHead_schoolYear->pNext;
	}
	/////////PRINT CLASS AND STUDENT IN CLASS TO FILE.


	////NO BUG IN THESE LINES OF CODE.
	file.open("classList.txt");
	Class* pTemp9 = pHead_class;
	while (pHead_class != nullptr)
	{
		file << pHead_class->class_name;
		if (pHead_class->pNext != nullptr)
			file << endl;
		pHead_class = pHead_class->pNext;
	}
	file.close();

	pHead_class = pTemp9;
	while (pHead_class != nullptr)
	{
	//	//Print the elements of class.
		print_student_InClass(pHead_class->student, pHead_class->class_name);
		pHead_class = pHead_class->pNext;
	}



	///---------------------------------------------------PRINT TO CONSOLE---------------------------------------------
	/*SchoolYear* pHead1 = pHead_schoolYear;
	while (pHead1 != nullptr)
	{
		cout << pHead1->year_name << " ";
		while (pHead1->semester != nullptr)
		{
			cout << pHead1->semester->semester_name << " ";

			while (pHead1->semester->course != nullptr)
			{
				cout << pHead1->semester->course->course_name << " ";

				while (pHead1->semester->course->student != nullptr)
				{
					cout << endl;
					cout << pHead1->semester->course->student->student_ID << " " << pHead1->semester->course->student->first_name << " "
						<< pHead1->semester->course->student->last_name << " " << pHead1->semester->course->student->gender << " "
						<< pHead1->semester->course->student->date_of_birth << " " << pHead1->semester->course->student->social_ID << " " << endl;
					pHead1->semester->course->student = pHead1->semester->course->student->pNext;
				}
				cout << endl;
				pHead1->semester->course = pHead1->semester->course->pNext;
			}
			cout << endl;
			pHead1->semester = pHead1->semester->pNext;
		}
		cout << endl;
		pHead1 = pHead1->pNext;
	}


	Class* pHead2 = pHead_class;
	while (pHead2 != nullptr)
	{
		cout << endl;
		cout << pHead2->class_name << " ";
		while (pHead2->student != nullptr)
		{
			cout << endl;
			cout << pHead2->student->student_ID << " "
				<< pHead2->student->first_name << " "
				<< pHead2->student->last_name << " "
				<< pHead2->student->gender << " "
				<< pHead2->student->date_of_birth << " "
				<< pHead2->student->social_ID << endl;

			pHead2->student = pHead2->student->pNext;
		}
		cout << endl;
		pHead2 = pHead2->pNext;
		}*/
}

void deallocated(SchoolYear*& pHead_schoolYear, Class*& pHead_class)
{
	//These line is used for deallocating all the students in all courses, and all courses in all semesters, and all semesters in all school years.B
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

	//These line is used for deallocating all the students in the courses, and all the courses.
	Class* pCur_class = pHead_class;
	while (pHead_class != nullptr)
	{
		Student* pTemp = pCur_class->student;
		Student* pPrevTemp = pCur_class->student;
		if (pTemp == nullptr) break;
		while (pTemp != nullptr)
		{
			pTemp = pTemp->pNext;
			delete pPrevTemp;
			pPrevTemp = pTemp;
		}
		pTemp = nullptr;
		pPrevTemp = nullptr;
		pHead_class = pHead_class->pNext;
		delete pCur_class;
		pCur_class = pHead_class;
	}
	pHead_class = nullptr;
	pCur_class = nullptr;
}