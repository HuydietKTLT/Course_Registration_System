#include "lib.h"
int main()
{
	SchoolYear* pHead_schoolYear = nullptr;
	Class* pHead_class = nullptr;

	load_input(pHead_schoolYear, pHead_class);

	string s;
	cout << "Enter when done!!: ";
	cin >> s;
	
	print_output(pHead_schoolYear, pHead_class);
	deallocated(pHead_schoolYear, pHead_class);

	return 0;
}