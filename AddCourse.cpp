#include "Addcourse.h"

string currentSchoolYear_Semester_Cpp_string()
{
	ifstream current_schoolYear //Use to open file currentSchoolYear.txt, which located in BIG FOLDER
		,current_semester; //Use to open file currentSemester.txt, which located in BIG FOLDER.


	string currentSchoolYear, currentSemester;



	//Open file named currentSchoolYear.txt, which contained a current School Year (The latest school year which users have entered).
	current_schoolYear.open("currentSchoolYear.txt");
	if (!current_schoolYear.is_open())
	{
		cout << "Khong mo duoc file currentSchoolYear.txt";
		return NULL;
	}
	current_schoolYear >> currentSchoolYear;
	current_schoolYear.close();
	


	//Open file named currentSemester.txt, which contained a current semester (The latest semester which user have entered)
	current_semester.open("currentSemester.txt");
	if (!current_semester.is_open())
	{
		cout << "Khong mo duoc file currentSemester.txt";
		return NULL;
	}
	current_semester >> currentSemester;
	current_semester.close();


	//Merge it into a new Path named:   " CURRENTSCHOOLYEAR//CURRENTSEMESTER// "
	currentSchoolYear += "\\" + currentSemester + "\\";

	return currentSchoolYear;

}

char* currentShoolYear_Semester_C_String(int getID)
{
	//-> a is the string with contain the Path which has got the format: " CURRENTSCHOOLYEAR//CURRENTSEMESTER// "
	char a[200];
	int k = 0;

	//The purpose of these below actions is used for getting a path of the Course that will be deleted
	//the remove() function is only used in C string, so I cannot use a C++ string to assign in this function. It will get error.


	//Path update: CURRENTSCHOOLYEAR//CURRENTSEMESTER//
	for (int i = 0; i < currentSchoolYear_Semester_Cpp_string().size(); ++i)
	{
		a[++k] = currentSchoolYear_Semester_Cpp_string()[i];
	}

	//Path update: CURRENTSCHOOLYEAR//CURRENTSEMESTER//course
	string course = "course";
	for (int i = 0; i < course.size(); ++i)
		a[++k] = course[i];

	//Path update: CURRENTSCHOOLYEAR//CURRENTSEMESTER//courseID
	for (int i = 0; i < to_string(getID).size(); ++i)
		a[++k] = to_string(getID)[i];

	//Path update: CURRENTSCHOOLYEAR//CURRENTSEMESTER//courseID.txt
	string txt = ".txt";
	for (int i = 0; i < txt.size(); ++i)
		a[++k] = txt[i];

	//Assign the operator '\n' is to notify this is the end of the string of characters. 
	a[k] = '\n';
	return a;
}

//Get the data of course from file .txt
void getCourseDataFromFile(Course*& pHead)
{
	ifstream file;
	file.open(currentSchoolYear_Semester_Cpp_string() + "listOfCourse.txt");
	if (!file.is_open())
	{
		cout << "Khong mo duoc file";
		return;
	}

	Course* pCur = pHead;

	//Get the data and save to the list of Course until it read to the end of the file
	while (!file.eof())
	{
		//if pHead is nullpointer, create new one
		if (pHead == nullptr)
		{
			pHead = new Course;
			pCur = pHead;
		}

		//if pHead is not nullpointer, means there is data in the list of Nodes, so add one next to the current.
		else
		{
			pCur->pNext = new Course;
			pCur = pCur->pNext;
		}

		string id;
		getline(file, id, ',');
		pCur->id = stoi(id);

		getline(file, pCur->course_name, ',');
		getline(file, pCur->class_name, ',');
		getline(file, pCur->teacher_name, ',');



		string number_credits;
		getline(file, number_credits, ',');
		pCur->number_credits = stoi(number_credits);

		string number_students;
		getline(file, number_students, ',');
		pCur->number_students = stoi(number_students);

		getline(file, pCur->day_of_week, ',');


		getline(file, pCur->sessions, '\n');

		pCur->pNext = nullptr;
	}
}



void printCourseToFile(Course* pHead)
{
	ofstream file;
	file.open(currentSchoolYear_Semester_Cpp_string() + "listOfCourse.txt");

	Course* pCur = pHead;

	//print the data from courses to file .txt.
	while (pCur != nullptr)
	{
		file << pCur->id << ","
			<< pCur->course_name << ","
			<< pCur->class_name << ","
			<< pCur->teacher_name << ","
			<< pCur->number_credits << ","
			<< pCur->number_students << ","
			<< pCur->day_of_week << ","
			<< pCur->sessions << endl;

		pCur = pCur->pNext;
	}

	file.close();

}


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

	string courseID = to_string(pCur->id);

	cout << "Enter Course Name";
	cin >> pCur->course_name;

	cout << "Enter Class Name";
	cin >> pCur->class_name;

	cout << "Enter Teacher Name";
	cin >> pCur->teacher_name;

	cout << "Enter Number of credits: ";
	cin >> pCur->number_credits;

	cout << "Enter Number of students: ";
	cin >> pCur->number_students;

	cout << "    Enter day of week" << endl;
	cout << "MON / TUE / WED / THU / FRI / SAT ";
	cin >> pCur->day_of_week;

	cout << "    Enter session" << endl;
	cout << "S1(07:30) -- S2 (09:30) -- S3(13:30) -- S4(15:30)";
	cin >> pCur->sessions;

	pCur->pNext = nullptr;


	ofstream file;
	file.open(currentSchoolYear_Semester_Cpp_string() + "listOfCourse.txt", ofstream::app);
	file << endl
		<< pCur->id << ","
		<< pCur->course_name << ","
		<< pCur->class_name << ","
		<< pCur->teacher_name << ","
		<< pCur->number_credits << ","
		<< pCur->number_students << ","
		<< pCur->day_of_week << ","
		<< pCur->sessions;

	file.close();



	//Save new list of courses to the file, which contained the list of Courses, and it is stored in folder
	// "CURRENTSCHOOLYEAR//CURRENTSEMESTER//listOfCourse.txt"
	printCourseToFile(pHead);

	//After adding a new course to a new file, and a list of Courses in the system, means that creating a new file, which named courseID.txt
	//It stored the list of students enrolled in the courses.
	ofstream create_file;
	create_file.open(currentSchoolYear_Semester_Cpp_string() + "course" + courseID + ".txt", ofstream::out, ofstream::app);
	create_file.close();
}

void deleteCourse(Course*& pHead)
{
	int getID;
	cout << "Enter the Course ID which you want to delete: ";
	cin >> getID;
	while (getID <= 0)
	{
		cout << "Invalid input. Please try a new course ID: ";
		cin >> getID;
	}
	//the remove Course will be located in Folder:  CURRENTSCHOOLYEAR//CURRENTSEMESTER//courseID.txt

	Course* cur;
	cur = pHead;
	Course* temp = cur;
	while (cur != nullptr && cur->id != getID)
	{
		temp = cur;
		cur = cur->pNext;
	}
	if (cur != nullptr)
	{
		if (temp == pHead)
			pHead = temp->pNext;
		else
			temp->pNext = cur->pNext;
		delete cur;

		//Save new list of courses into the file, which contained the list of Courses, and it is stored in folder
		// "CURRENTSCHOOLYEAR//CURRENTSEMESTER//listOfCourse.txt"
		printCourseToFile(pHead);


		//the remove() functions can delete a file .txt

		remove(currentShoolYear_Semester_C_String(getID));
		return;
	}
	cout << "There is no Course ID matching with your typing: " << endl;
}

void update_course_ID(Course*& cur)
{
	cout << "Enter new Course ID: ";
	cin >> cur->id;
	while (cur->id <= 0)
	{
		cout << "Invalid input. Please try a new Course ID ";
		cin >> cur->id;
	}
	cout << "Update successfully!" << endl;
}

void update_course_name(Course*& cur)
{
	cout << "Enter new Course Name: ";
	getline(cin, cur->course_name);
	cout << "Update successfully!" << endl;
}

void update_class_name(Course*& cur)
{
	cout << "Enter new Class Name: ";
	getline(cin, cur->class_name);
	cout << "Update successfully!" << endl;
}

void update_teacher_name(Course*& cur)
{
	cout << "Enter new Teacher Name: ";
	getline(cin, cur->class_name);
	cout << "Update successfully!" << endl;
}

void update_number_credits(Course*& cur)
{
	cout << "Enter new Number of Credits: ";
	cin >> cur->number_credits;
	while (cur->number_credits <= 0)
	{
		cout << "Invalid input. Please try a new Number of Credits: ";
		cin >> cur->number_credits;
	}
	cout << "Update successfully!" << endl;
}

void update_number_students(Course*& cur)
{
	cout << "Enter new Number of Credits: ";
	cin >> cur->number_credits;
	while (cur->number_credits <= 0)
	{
		cout << "Invalid input. Please try a new Number of Credits: ";
		cin >> cur->number_credits;
	}
	cout << "Update successfully!" << endl;
}

void update_day_week(Course*& cur)
{
	cout << "Enter new Day of week: ";
	cin >> cur->day_of_week;
	cout << "Update successfully!" << endl;

}

void update_session(Course*& cur)
{
	cout << "Enter new session";
	cin >> cur->sessions;
	cout << "Update successfully!" << endl;

}

void update(Course*& cur)
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
			update_course_ID(cur);
			break;
		case 2:
			update_course_name(cur);
			break;
		case 3:
			update_class_name(cur);
			break;
		case 4:
			update_teacher_name(cur);
			break;
		case 5:
			update_number_credits(cur);
			break;
		case 6:
			update_number_students(cur);
			break;
		case 7:
			update_day_week(cur);
			break;
		case 8:
			update_session(cur);
			break;
		case 9:
		{
			update_course_ID(cur);
			update_course_name(cur);
			update_class_name(cur);
			update_teacher_name(cur);
			update_number_credits(cur);
			update_number_students(cur);
			update_day_week(cur);
			update_session(cur);
		}
		break;
		case 0:
			return;
		default:
			continue;
		}
	}
}

void updateCourse(Course*& pHead)
{
	Course* cur = pHead;
	printCourseToConsole(pHead);
	cout << "Enter the Course ID which have to be updated ";
	int getID;
	cin >> getID;
	while (cur != nullptr)
	{
		if (getID == cur->id)
		{
			update(cur);
			printCourseToFile(pHead);
			cout << "Update successfully!";
			return;
		}
		cur = cur->pNext;
	}
	cout << "Not found Course ID!!!";
	return;
}

void deAllocateCourse(Course*& pHead)
{
	Course* cur = pHead;
	Course* temp = cur->pNext;
	while (cur != nullptr)
	{
		delete cur;
		cur = temp;
		temp = temp->pNext;
	}
}

void addStudentCourseWithFile()
{
	ifstream file;
	//The file addStudentToCourse.txt is an input file, which contain the first line is the Course to be addedd
	//The following next lines are the students information.
	file.open(currentSchoolYear_Semester_Cpp_string() + "addStudentToCourse.txt");
	if (!file.is_open())
	{
		cout << "Khong mo duoc file addStudentToCourse.txt";
		return;
	}
	string courseID_string;

	file >> courseID_string;
	int courseID_int = stoi(courseID_string);

	while (!file.eof())
	{

	}
}


void addStudentCourseWithConsole(Course* pHead)
{
	//Check the course ID is exist or not.
	int getID;
	string course_ID;
	cout << "Enter the course ID: ";
	cin >> course_ID;

	getID = stoi(course_ID);
	bool isFound = false;

	Course* cur;
	cur = pHead;


	while (cur != nullptr && cur->id != getID)
	{
		cur = cur->pNext;
	}

	if (cur != nullptr)
	{
		isFound = true;
	}

	if (!isFound)
	{
		cout << "There is no course ID matching with your typing ";
		return;
	}


	//If the course ID is exist, then find the folder which contain that course, and then update new student.
	int ID_student;
	cout << "Enter ID: ";
	cin >> ID_student;

	string first_name;
	cout << "Enter first name: ";
	cin >> first_name;

	string last_name;
	cout << "Enter last name: ";
	cin >> last_name;

	string gender;
	cout << "Enter gender: (NAM/NU)";
	cin >> gender;

	string date_of_birth;
	cout << "Enter date of birth: ";
	cin >> date_of_birth;

	int social_ID;
	cout << "Enter social ID: ";
	cin >> social_ID;

	ifstream file1;

	file1.open(currentSchoolYear_Semester_Cpp_string() + "course" + course_ID + ".txt");
	if (!file1.is_open())
	{
		cout << "Khong mo duoc file tuong ung voi Course ID!!";
		return;
	}
	string temp;
	int index = 1;
	//This action is used for finding the number of line, then the next Student which going to be added into the list will get the index respectively.
	while (!file1.eof())
	{
		getline(file1, temp, '\n');
		++index;
	}
	file1.close();


	ofstream file;

	//open the file which located in Folder:  "CURRENTSCHOOLYEAR//CURRENTSEMSTER//courseID.txt"
	file.open(currentSchoolYear_Semester_Cpp_string() + "course" + course_ID + ".txt", ios::app);
	file << endl;

	//Add new student to the end of the file.
	file << index
		<< ID_student << ","
		<< first_name << ","
		<< last_name << ","
		<< gender << ","
		<< date_of_birth << ","
		<< social_ID;
	file.close();
	cout << "Add Student to Course successfully";
}


//Get stundet data from file and pass these datas into the linked list Students.
void getStudentInfoFromFile(Student*& pHead, string get, ifstream &file)
{
	Student* pCur = pHead;

	//Get the data and save to the list of Course until it read to the end of the file
	while (!file.eof())
	{
		//if pHead is nullpointer, create new one
		if (pHead == nullptr)
		{
			pHead = new Student;
			pCur = pHead;
		}

		//if pHead is not nullpointer, means there is data in the list of Nodes, so add one next to the current.
		else
		{
			pCur->pNext = new Student;
			pCur = pCur->pNext;
		}

		string student_ID;
		getline(file, student_ID, ',');
		pCur->student_ID = stoi(student_ID);


		getline(file, pCur->first_name, ',');

		getline(file, pCur->last_name, ',');

		getline(file, pCur->gender, ',');

		getline(file, pCur->date_of_birth, ',');

		string social_ID;
		getline(file, social_ID, '\n');

		pCur->social_ID = stoi(social_ID);

		pCur->pNext = nullptr;
	}
}

void print1StudentDataToFile(Student* pHead, string get)
{
	ofstream file;
	file.open(currentSchoolYear_Semester_Cpp_string() + "course" + get +".txt", ofstream::app);

	Student* pCur = pHead;

	//print the new data of students to the end of file .txt.
	while (pCur != nullptr)
	{
		file << pCur->student_ID << ","
			<< pCur->first_name << ","
			<< pCur->last_name << ","
			<< pCur->gender << ","
			<< pCur->date_of_birth << ","
			<< pCur->social_ID << "\n";
		pCur = pCur->pNext;
	}
	file.close();
}


void removeStudentFromCourse(Student *&pHead)
{
	int getID;
	cout << "Enter the course ID: ";
	cin >> getID;
	string get = to_string(getID);


	//The file open the file: CURRENTSCHOOYEAL//CURRENTSEMESTER//courseID.txt
	ifstream file;

	file.open(currentSchoolYear_Semester_Cpp_string() + "course" + get + ".txt");

	//Find the Course ID base on the existence of file courseID.txt
	while (!file.is_open())
	{
		cout << "The course does not exist";
		file.close();
		return;
	}
	//Open file for getting student information and save to the linked list 
	getStudentInfoFromFile(pHead, get, file);	
	file.close();


	if (pHead == nullptr)
	{
		cout << "There is no data of student in file course!!!";
		return;
	}

	int student_ID;
	cout << "Enter student ID: ";
	cin >> student_ID;

	Student* pCur = pHead;
	Student* pPrevCur = nullptr;
	while (pCur->pNext != nullptr && pCur->student_ID != student_ID)
	{
		pPrevCur = pCur;
		pCur = pCur->pNext;
	}

	if (pCur->pNext != nullptr)
	{
		pPrevCur->pNext = pCur->pNext;
		delete pCur;
		pCur = nullptr;
		pPrevCur = nullptr;
		return;
	}

	cout << "There is no student ID matching with your typing!!!";
	return;



}