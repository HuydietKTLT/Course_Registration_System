
#include "lib.h"


int main()
{
	SchoolYear* pHead_schoolYear = nullptr;
	Class* pHead_class = nullptr;

	load_input(pHead_schoolYear, pHead_class);
	char type;
	string ID;
	passInfo* headPass = nullptr;
	ReadPassword(pHead_schoolYear, pHead_class, headPass);
	string log_in_studentID;
	login(type, ID, headPass, log_in_studentID);

	if (type == 't')
	{
		cout << "Type: Teacher " << endl;
		cout << "ID: " << ID << endl;
		menuStaff(pHead_schoolYear, pHead_class, headPass);
	}
	else if (type == 's')
	{
		cout << "Type: Student ";
		cout << "ID: " << ID << endl;
		menuStudent(pHead_schoolYear, ID);
	}
	clear(headPass);
	print_output(pHead_schoolYear, pHead_class);
	deallocated(pHead_schoolYear, pHead_class);
	return 0;
}