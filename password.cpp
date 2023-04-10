#include "lib.h"
#include "addStudent.h"
#include "menuScoreTemp.h"

//Set the max length of the password
const int max_value = 20;

//Check login infomation
bool LoginCheck(string login, string password, char& type, string& ID, passInfo* readfile)
{
	while (readfile != nullptr)
	{
		if (password == readfile->password && login == readfile->login)
		{
			type = readfile->type;
			ID = readfile->login;
			return true;
		}
		readfile = readfile->next;
	}
	return false;
}

//Login menu
void login(char& type, string& ID, passInfo* readfile)
{
    string login, password;
    while (true)
    {
        cout << "Enter your account name:0 to exit\n";
        cout << "Enter your account name: ";
        cin >> login;
        cout << "Enter your password: ";
        password = pass();
        if (login == "0")
        {   
            type = '0';
            return;
        }
        if (LoginCheck(login, password, type, ID, readfile) == true)
            break;
        cout << "Fail successful! Please try again.\n";
    }
    clrscr();
}

//Edit password menu
void edit(passInfo*& readfile)
{
    char type;
    int i;
    string ID;
    string new_login, new_password;
    login(type, ID, readfile);
    if (ID == "0")
        return;
    do
    {
        cout << "Do you want to change your password:\n";
        cout << "1. Yes. 0. No. Enter options:\n";
        cin >> i;
        if (i == 0)
            break;
        cout << "Enter your new password: ";
        new_password = pass();
    } while (doTheEdit(new_password, ID, readfile));
    dialocatePass(readfile);
    stop();
    clrscr();
}

//Read password file to linked list
void ReadPassword(SchoolYear* pHead_schoolYear, Class* pHead_class, passInfo*& readfile)
{

	//Long's code 
	ifstream fi;
	fi.open("password.txt");
	if (fi.is_open() == false)
	{
		cout << "Error cannot open file.";
		return;
	}
	passInfo* dummyNode = new passInfo;
	passInfo* temp;
	dummyNode->next = readfile;
	passInfo* cur = dummyNode;
	while (!fi.eof())
	{
		temp = new passInfo;
		temp->next = nullptr;

		fi >> temp->login;
		fi >> temp->password;
		

		fi >> temp->type;

		cur->next = temp;
		cur = cur->next;
	}
	readfile = dummyNode->next;
	delete dummyNode;
	fi.close();




	//Thai's code
	/*temp = readfile;
	while (temp->next != nullptr)
		temp = temp->next;

	while (pHead_schoolYear != nullptr)
	{
		Semester* pHead2 = pHead_schoolYear->semester;
		while (pHead2 != nullptr)
		{
			Course* pHead3 = pHead2->course;
			while (pHead3 != nullptr)
			{
				Student* pHead4 = pHead3->student;
				while (pHead4 != nullptr)
				{
					temp->next = new passInfo;
					temp = temp->next;
					temp->login = pHead_schoolYear->semester->course->student->student_ID;
					temp->password = "1234";
					temp->type = 's';
					temp->next = nullptr;

					pHead4 = pHead4->pNext;
				}
				pHead3 = pHead3->pNext;
			}
			pHead2 = pHead2->pNext;
		}
		pHead_schoolYear = pHead_schoolYear->pNext;
	}

	while (pHead_class != nullptr)
	{
		Student* pHead5 = pHead_class->student;
		while (pHead5 != nullptr)
		{
			temp->next = new passInfo;
			temp = temp->next;
			temp->login = pHead_class->student->student_ID;
			temp->password = "1234";
			temp->type = 's';
			temp->next = nullptr;
			pHead5 = pHead5->pNext;
		}
		pHead_class = pHead_class->pNext;
	}*/


}

//Clear the linked list
void clear(passInfo*& readfile)
{
    dialocatePass(readfile);
    passInfo* temp;
    while (readfile != nullptr)
    {
        temp = readfile;
        readfile = readfile->next;
        delete temp;
    }
}

//Edit password
bool doTheEdit(string password, string ID, passInfo*& head)
{
	passInfo* readfile = head;
	while (readfile != nullptr)
	{
		if (readfile->login == ID)
		{
			readfile->password = password;
			cout << "Change password successfully.\n";
			return false;
		}
		readfile = readfile->next;
	}
	cout << "Change password fail. Please try again;\n";
	return true;
}

string pass()
{
    char* password = new char[max_value];
    int i = 0;
    while ((password[i] = _getch()) != '\n' && password[i] != '\r' && i < (max_value - 1))
    {
        if (password[i] != '\b')
        {
            putchar('*');
            i++;
        }
        else
            if (i != 0)
            {
                putchar('\b');
                putchar(' ');
                putchar('\b');
                i--;
            }
    }
    if (i < (max_value - 1))
    {
        password[i] = '\0';
        cout << '\n';
        string s = password;
        delete password;
        return s;
    }
    else
    {
        cout << "\nPassword exceeded the maximun number of characters allow.\n Please try again: ";
        return pass();
    }
}

void dialocatePass(passInfo* readfile)
{
    ofstream fo;
    fo.open("password.txt");
    passInfo* cur = readfile;
    while (cur != nullptr)
    {
        fo << cur->login << ' ' << cur->password << ' ' << cur->type;
        cur = cur->next;
        if (cur->next != nullptr)
            fo << '\n';
    }
    fo.close();
}