
#include "lib.h"
#include "password.h"
#include "staff.h"



int main()
{
	SchoolYear* pHead = nullptr;
	load_input(pHead);




	char type;
	string ID;
	passInfo* headPass;
	ReadPassword(headPass);
	//login(type, ID, headPass);
	//edit(ID, headPass);

	//if (type == 't')
	{
		menuStaff();
	}



	clear(headPass);




	return 0;