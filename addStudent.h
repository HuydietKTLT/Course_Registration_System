#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
using namespace std;
struct course{
	string namecouse;
	double* score[11];
	char* rank={NULL}; 
	course * next,*prev,*data;  
};
struct student{
	int NO;
	int ID;
	string Fname;
	string Lname;
	string date;
	string gender;
	string clas;
	course c;
};
int row(student &s,string clas);
void addStudent(string schoolYear,student&st);
