#include "lib.h"

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
void edit(string ID, passInfo*& readfile)
{
    char type;
    int i;
    string temp_ID;
    string new_login, new_password;
    do
    {
        cout << "Do you want to change your username and password:\n";
        cout << "1. Yes. 0. No. Enter options:\n";
        cin >> i;
        if (i == 0)
            break;
        cout << "Enter your new password: ";
        new_password = pass();
    } while (doTheEdit(new_password, ID, readfile));
    cout << "Press any key to continue...";
    getchar();
    clrscr();
}

//Read password file to linked list
void ReadPassword(passInfo*& readfile)
{
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
        fi >> temp->login >> temp->password >> temp->type;
        cur->next = temp;
        cur = cur->next;
    }
    readfile = dummyNode->next;
    delete dummyNode;
    fi.close();
}

//Clear the linked list
void clear(passInfo*& readfile)
{
    ofstream fo;
    fo.open("password.txt");
    passInfo* cur = readfile;
    while (cur->next != nullptr)
    {
        fo << cur->login << ' ' << cur->password << ' ' << cur->type << ' ' << '\n';
        cur = cur->next;
    }
    fo.close();
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