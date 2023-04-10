
#include "lib.h"


int main()
{
	SchoolYear* pHead_schoolYear = nullptr;
	Class* pHead_class = nullptr;

	load_input(pHead_schoolYear, pHead_class);
	char type;
	string ID;
	passInfo* headPass = nullptr;
	ReadPassword(headPass);
	login(type, ID, headPass);

	switch (type)
	{
	case '0':
		break;
	case 't':
		menuStaff(pHead_schoolYear, pHead_class, headPass);
		break;
	case 's':
		//menuStudent(pHead_schoolYear, pHead_class, ID);
		break;
	case 'm':
		//menuManager(pHead_schoolYear, pHead_class, headPass);
		break;
	default:
		cout << "Error! Pls report to the admin!";
		break;
	}
		
	clrscr();
	clear(headPass);
	print_output(pHead_schoolYear, pHead_class);
	deallocated(pHead_schoolYear, pHead_class);
	return 0;
}