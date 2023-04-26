#include "lib.h"

int main()
{
	SchoolYear *pHead_schoolYear = nullptr;
	Class *pHead_class = nullptr;

	load_input(pHead_schoolYear, pHead_class);
	char type;
	string ID;
	passInfo *headPass = nullptr;
	ReadPassword(headPass, pHead_schoolYear, pHead_class);
	string log_in_studentID;
	BackGroundColor(7);
	SET_COLOR(0);
	login(type, ID, headPass);
	log_in_studentID = ID;
	switch (type)
	{
	case '0':
		break;
	case 't':
	{
		// cout << "Hello World" << endl;

		cout << "Type: Teacher " << endl;
		cout << "ID: " << ID << endl;
		menuStaff(pHead_schoolYear, pHead_class, headPass);
		break;
	}
	case 's':
	{
		cout << "Type: Student " << endl;
		cout << "ID: " << ID << endl;
		menuStudent(pHead_schoolYear, ID, headPass);
		break;
	}
	case 'm':
	{
		cout << "Type: Manager " << endl;
		cout << "ID: " << ID << endl;
		// menuManager(pHead_schoolYear, pHead_class, headPass);
		/*
		1. Cho thêm bới thành viên staff và manager
			Nhập từ console hoặc từ file
				File staff.txt : ID,type
			Xoa theo ID
		2. Edit password
			Cho phép edit password của bất cứ ai
		3. Giống staff menu
		*/
		break;
	}
	default:
	{
		cout << "Error! Please report to the admin!";
		break;
	}
	}
	dialocatePass(headPass);
	clear(headPass);
	print_output(pHead_schoolYear, pHead_class);
	deallocated(pHead_schoolYear, pHead_class);
	return 0;
}
