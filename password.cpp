#include "lib.h"

// Check login infomation
bool LoginCheck(string login, string password, char &type, string &ID, passInfo *readfile)
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

// Login menu
void login(char &type, string &ID, passInfo *readfile)
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
}

// Edit password menu
void edit(passInfo *&readfile)
{
    char type;
    int i;
    string ID;
    string new_login, new_password;
    login(type, ID, readfile);
    if (ID == "0")
        return;
    while (true)
    {
        cout << "Do you want to change your password:\n";
        cout << "1. Yes.\n";
        cout << "0. No.\n";
        cout << "Enter your option:\n";
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            cout << "Enter your new password: ";
            new_password = pass();
            doTheEdit(new_password, ID, readfile);
            break;
        }
        case 0:
            return;
        default:
            continue;
        }
    }
    // do
    // {
    //     cout << "Do you want to change your password:\n";
    //     cout << "1. Yes. 0. No. Enter options:\n";
    //     cin >> i;
    //     if (i != 1)
    //         break;
    //     cout << "Enter your new password: ";
    //     new_password = pass();
    // } while (doTheEdit(new_password, ID, readfile));
}

// Read password file to linked list
void ReadPassword(passInfo *&pHead_readfile, SchoolYear *pHead_schoolYear, Class *pHead_class)
{

    // Long's code
    ifstream fi;
    fi.open("password.txt");
    if (fi.is_open() == false)
    {
        cout << "Error cannot open file.";
        return;
    }

    passInfo *pCur = nullptr;
    while (!fi.eof())
    {
        if (pHead_readfile == nullptr)
        {
            pHead_readfile = new passInfo;
            pCur = pHead_readfile;
        }
        else
        {
            pCur->next = new passInfo;
            pCur = pCur->next;
        }

        getline(fi, pCur->login, ',');
        getline(fi, pCur->password, ',');
        string temp;
        getline(fi, temp, '\n');

        pCur->type = temp[0];

        pCur->next = nullptr;
    }
    pCur = nullptr;
    fi.close();
    // This can't change password of student

    // Thai's code
    passInfo *pAdd_account = pHead_readfile;
    while (pAdd_account->next != nullptr)
        pAdd_account = pAdd_account->next;

    while (pHead_schoolYear != nullptr)
    {
        Semester *pHead_semester = pHead_schoolYear->semester;
        while (pHead_semester != nullptr)
        {
            Course *pHead_course = pHead_semester->course;
            while (pHead_course != nullptr)
            {
                Student *pHead_student = pHead_course->student;
                while (pHead_student != nullptr)
                {
                    if (is_Exist_account(pHead_readfile, pHead_student->student_ID) == false)
                    {
                        pAdd_account->next = new passInfo;
                        pAdd_account = pAdd_account->next;
                        pAdd_account->login = pHead_student->student_ID;
                        pAdd_account->password = default_password;
                        pAdd_account->type = 's';
                        pAdd_account->next = nullptr;
                    }

                    pHead_student = pHead_student->pNext;
                }
                pHead_course = pHead_course->pNext;
            }
            pHead_semester = pHead_semester->pNext;
        }
        pHead_schoolYear = pHead_schoolYear->pNext;
    }

    while (pHead_class != nullptr)
    {
        studentClass *pHead_studentClass = pHead_class->student;
        while (pHead_studentClass != nullptr)
        {
            if (is_Exist_account(pHead_readfile, pHead_studentClass->student_ID) == false)
            {

                pAdd_account->next = new passInfo;
                pAdd_account = pAdd_account->next;
                pAdd_account->login = pHead_studentClass->student_ID;
                pAdd_account->password = default_password;
                pAdd_account->type = 's';
                pAdd_account->next = nullptr;
            }
            pHead_studentClass = pHead_studentClass->pNext;
        }
        pHead_class = pHead_class->pNext;
    }
}

bool is_Exist_account(passInfo *pHead_pass, string student_ID)
{
    while (pHead_pass != nullptr)
    {
        if (pHead_pass->login == student_ID)
            return true;
        pHead_pass = pHead_pass->next;
    }
    return false;
}

// Clear the linked list
void clear(passInfo *&readfile)
{
    passInfo *temp = readfile;
    while (readfile != nullptr)
    {
        temp = readfile;
        readfile = readfile->next;
        delete temp;
    }
}

// Edit password
bool doTheEdit(string password, string ID, passInfo *&head)
{
    passInfo *readfile = head;
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
    char *password = new char[max_value];
    int i = 0;
    while ((password[i] = _getch()) != '\n' && password[i] != '\r' && i < (max_value - 1))
    {
	SET_COLOR(i);    
        if (password[i] != '\b')
        {
            putchar('*');
            i++;
        }
        else if (i != 0)
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

void dialocatePass(passInfo *readfile)
{
    ofstream fo;
    fo.open("password.txt");
    passInfo *cur = readfile;
    while (cur != nullptr)
    {
        fo << cur->login << ',' << cur->password << ',' << cur->type;
        if (cur->next != nullptr)
            fo << '\n';
        cur = cur->next;
    }
    fo.close();
}
void SET_COLOR(int color)
{
	WORD wColor;
     

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
void BackGroundColor (int color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
