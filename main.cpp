
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

	cout << "Type: " << type << endl;
	cout << "ID: " << ID << endl;
	if (type == 't')
	{
		menuStaff(pHead_schoolYear, pHead_class, headPass);
	}
	else if (type == 's')
	{

	}
	clear(headPass);
	print_output(pHead_schoolYear, pHead_class);
	deallocated(pHead_schoolYear, pHead_class);
	return 0;
}