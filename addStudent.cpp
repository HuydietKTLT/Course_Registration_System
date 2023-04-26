#include "lib.h"

Class *Find_Class(Class *pHead)
{
	if (pHead == nullptr)
	{
		cout << "There is no class has been created yet!!" << endl;
		return NULL;
	}
	string get_class;
	cout << "Enter class: ";
	cin >> get_class;

	while (pHead != nullptr && pHead->class_name != get_class)
		pHead = pHead->pNext;

	if (pHead == nullptr)
	{
		cout << "There is no class matching with your typing !!" << endl;
		return NULL;
	}
	return pHead;
}

void add_Student_To_Class_By_File(studentClass *&pHead, passInfo *&headPass)
{
	ifstream file;
	// The file addStudentToCourse.txt is an input file, which contain the first line is the Course to be added
	// The following next lines are the students information.
	file.open("addStudentToClass.txt");
	if (!file.is_open())
	{
		cout << "Can't open addStudentToClass.txt" << endl;
		file.close();
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}
	string student_ID;
	string first_name;
	string last_name;
	string gender;
	string date_of_birth;
	string social_ID;

	passInfo *pCurPass = nullptr;
	if (headPass != nullptr)
	{
		pCurPass = headPass;
		while (pCurPass != nullptr && pCurPass->next != nullptr)
		{
			pCurPass = pCurPass->next;
		}
	}

	while (!file.eof())
	{
		getline(file, student_ID, ',');
		getline(file, first_name, ',');
		getline(file, last_name, ',');
		getline(file, gender, ',');
		getline(file, date_of_birth, ',');
		getline(file, social_ID);
		// Create a new account for the student
		// If the student who is going to added, got the existed ID, then the passInfo won't update.
		if (is_Exist_account(headPass, student_ID) == false)
		{
			if (headPass == nullptr)
			{
				headPass = new passInfo;
				pCurPass = headPass;
			}
			else
			{
				pCurPass->next = new passInfo;
				pCurPass = pCurPass->next;
			}
			pCurPass->login = student_ID;
			pCurPass->password = default_password;
			pCurPass->type = 's';
			pCurPass->next = nullptr;
		}
		studentClass *pOverWrite = pHead;
		studentClass *pPrevOverWrite = nullptr;
		while (pOverWrite != nullptr && pOverWrite->student_ID != student_ID)
		{
			pPrevOverWrite = pOverWrite;
			pOverWrite = pOverWrite->pNext;
		}
		if (pOverWrite != nullptr)
		{
			continue;
		}
		else
		{
			pPrevOverWrite->pNext = new studentClass;
			pPrevOverWrite = pPrevOverWrite->pNext;
			pPrevOverWrite->student_ID = student_ID;
			pPrevOverWrite->first_name = first_name;
			pPrevOverWrite->last_name = last_name;
			pPrevOverWrite->gender = gender;
			pPrevOverWrite->date_of_birth = date_of_birth;
			pPrevOverWrite->social_ID = social_ID;
			pPrevOverWrite->pNext = nullptr;
		}
	}
	file.close();
}

bool is_Exist_studentClass(studentClass *pHead_student, string student_ID)
{
	while (pHead_student != nullptr)
	{
		if (pHead_student->student_ID == student_ID)
			return true;
		pHead_student = pHead_student->pNext;
	}
	return false;
}

bool is_Exist_studentCourse(Student *pHead_student, string student_ID)
{
	while (pHead_student != nullptr)
	{
		if (pHead_student->student_ID == student_ID)
			return true;
		pHead_student = pHead_student->pNext;
	}
	return false;
}

void add_Student_to_Course_By_File(Course *pCur, Student *&pHead, passInfo *&headPass)
{
	ifstream file;
	// The file addStudentToCourse.txt is an input file, which contain the first line is the Course to be addedd
	// The following next lines are the students information.
	file.open("addStudentToCourse.txt");
	if (!file.is_open())
	{
		cout << "Can't open addStudentToCourse.txt" << endl;
		file.close();
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}
	string student_ID;
	string first_name;
	string last_name;
	string gender;
	string date_of_birth;
	string social_ID;
	string total_mark;
	string final_mark;
	string mid_mark;
	string other_mark;
	passInfo *pCurPass = nullptr;
	if (headPass != nullptr)
	{
		pCurPass = headPass;
		while (pCurPass != nullptr && pCurPass->next != nullptr)
			pCurPass = pCurPass->next;
	}

	while (!file.eof())
	{
		getline(file, student_ID, ',');
		getline(file, first_name, ',');
		getline(file, last_name, ',');
		getline(file, gender, ',');
		getline(file, date_of_birth, ',');
		getline(file, social_ID, ',');
		getline(file, total_mark, ',');
		getline(file, final_mark, ',');
		getline(file, mid_mark, ',');
		getline(file, other_mark, '\n');

		if (is_Exist_account(headPass, student_ID) == false)
		{
			if (headPass == nullptr)
			{
				headPass = new passInfo;
				pCurPass = headPass;
			}
			else
			{
				pCurPass->next = new passInfo;
				pCurPass = pCurPass->next;
			}

			pCurPass->login = student_ID;
			pCurPass->password = default_password;
			pCurPass->type = 's';
			pCurPass->next = nullptr;
		}
		Student *pOverWrite = pHead;
		Student *pPrevOverWrite = nullptr;
		while (pOverWrite != nullptr && pOverWrite->student_ID != student_ID)
		{
			pPrevOverWrite = pOverWrite;
			pOverWrite = pOverWrite->pNext;
		}
		if (pOverWrite != nullptr)
		{
			continue;
		}
		else
		{
			// cout << "Hello World " << endl;
			pPrevOverWrite->pNext = new Student;
			pPrevOverWrite = pPrevOverWrite->pNext;

			pPrevOverWrite->student_ID = student_ID;
			pPrevOverWrite->first_name = first_name;
			pPrevOverWrite->last_name = last_name;
			pPrevOverWrite->gender = gender;
			pPrevOverWrite->date_of_birth = date_of_birth;
			pPrevOverWrite->social_ID = social_ID;
			pPrevOverWrite->score.total_mark = float_one_point_round(stof(total_mark));
			pPrevOverWrite->score.final_mark = float_one_point_round(stof(final_mark));
			pPrevOverWrite->score.mid_mark = float_one_point_round(stof(mid_mark));
			pPrevOverWrite->score.other_mark = float_one_point_round(stof(other_mark));

			pPrevOverWrite->score.total_mark = pPrevOverWrite->score.final_mark * pCur->final / 100 + pPrevOverWrite->score.mid_mark * pCur->midterm / 100 + pPrevOverWrite->score.other_mark * pCur->other / 100;
			pPrevOverWrite->score.total_mark = float_one_point_round(pPrevOverWrite->score.total_mark);
			pPrevOverWrite->pNext = nullptr;
		}
	}
	file.close();
}

void add_Student_to_Course_By_Console(Course *pCur, Student *&pHead, passInfo *&headPass)
{
	cout << "Enter new student ID: ";
	string student_ID;
	cin >> student_ID;
	Student *pTraverse = nullptr;
	if (pHead != nullptr)
		pTraverse = pHead;
	while (pTraverse != nullptr)
	{
		cout << "The student ID has been created before!. Try again" << endl;
		cout << "Enter new student ID: ";
		cin >> student_ID;
		pTraverse = pHead;
		while (pTraverse != nullptr && pTraverse->student_ID != student_ID)
		{
			pTraverse = pTraverse->pNext;
		}
	}
	Student *pAdd = nullptr;
	if (pHead != nullptr)
	{
		pAdd = pHead;
		while (pAdd != nullptr && pAdd->pNext != nullptr)
		{
			pAdd = pAdd->pNext;
		}
		pAdd->pNext = new Student;
		pAdd = pAdd->pNext;
		pAdd->pNext = nullptr;
	}

	if (pHead == nullptr)
	{
		pHead = new Student;
		pAdd = pHead;
		pHead->pNext = nullptr;
	}
	pAdd->student_ID = student_ID;

	cout << "Enter new student first name: ";
	cin >> pAdd->first_name;

	cout << "Enter new student last name: ";
	cin >> pAdd->last_name;

	cout << "Enter new student gender: ";
	cin >> pAdd->gender;

	cout << "Enter new student date of birth: ";
	cin >> pAdd->date_of_birth;

	cout << "Enter new student social ID: ";
	cin >> pAdd->social_ID;

	passInfo *addPass = nullptr;
	if (headPass != nullptr)
	{
		addPass = headPass;
		while (addPass != nullptr && addPass->next != nullptr)
			addPass = addPass->next;
	}
	// Check if the account is exist or not:
	if (is_Exist_account(headPass, pAdd->student_ID) == false)
	{
		if (headPass == nullptr)
		{
			headPass = new passInfo;
			addPass = headPass;
		}
		else
		{
			addPass->next = new passInfo;
			addPass = addPass->next;
		}
		addPass->login = pAdd->student_ID;
		addPass->password = default_password;
		addPass->type = 's';
		addPass->next = nullptr;
	}
}

void remove_Student_from_Course(Student *&pHead)
{
	Student *pCur = pHead;
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
		pCur = nullptr;
		pPrevCur = nullptr;
		cout << "Delete Student from Course successfully!!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}
	cout << "There is no student ID matching with your typing !!!" << endl;
	cout << "Press any key to continue...\n";
	string s;
	cin >> s;
	clrscr();
}
