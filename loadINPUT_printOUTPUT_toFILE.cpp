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