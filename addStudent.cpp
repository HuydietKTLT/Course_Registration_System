#include "lib.h"

Class* Find_Class(Class* pHead)
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
	// The file addStudentToCourse.txt is an input file, which contain the first line is the Course to be addedd
	// The following next lines are the students information.
	file.open("addStudentToClass.txt");
	if (!file.is_open())
	{
		cout << "Can't open addStudentToClass.txt" << endl;
		file.close();
		return;
	}
	studentClass *pCur = nullptr;
	if (pHead != nullptr)
	{
		pCur = pHead;
		while (pCur->pNext != nullptr)
			pCur = pCur->pNext;
	}
	passInfo *pCurPass = nullptr;
	if (headPass != nullptr)
	{
		pCurPass = headPass;
		while (pCurPass->next != nullptr)
			pCurPass = pCurPass->next;
	}

	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new studentClass;
			pCur = pHead;
		}
		else if (pHead != nullptr)
		{
			pCur->pNext = new studentClass;
			pCur = pCur->pNext;
		}

		if (headPass == nullptr)
		{
			headPass = new passInfo;
			pCurPass = headPass;
		}
		else if (headPass != nullptr)
		{
			pCurPass->next = new passInfo;
			pCurPass = pCurPass->next;
		}

		getline(file, pCur->student_ID, ',');
		getline(file, pCur->first_name, ',');
		getline(file, pCur->last_name, ',');
		getline(file, pCur->gender, ',');
		getline(file, pCur->date_of_birth, ',');
		getline(file, pCur->social_ID);

		// Create a new account for the student
		pCurPass->login = pCur->student_ID;
		pCurPass->password = default_password;
		pCurPass->type = 's';
		pCurPass->next = nullptr;
		pCur->pNext = nullptr;
	}
	file.close();
}