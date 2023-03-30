#include "lib.h"

<<<<<<< HEAD
int main () 
{

    
    return 0;
=======
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
>>>>>>> 6d9a762884200ae5cfc04bb6f155ee886da889c7
}