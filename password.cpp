#include "password.h"

const int max_value = 20;

bool LoginCheck(string login, string password, char &type, string &ID)
{
    ifstream fi;
    fi.open("password.txt");
    string dataLogin, dataPassword;
    if(fi.is_open() == false)
    {
        cout << "Error cannot open file.";
        return false;
    }
    while (!fi.eof())
    {
        fi >> dataLogin;
        fi >> dataPassword >> type >> ID;
        if((login == dataLogin) && (password == dataPassword))
        {
            fi.close();
            return true;  
        }
    }
    cout << "Invalid account name or password." << endl;
    fi.close();
    return false;
}

void login(char &type, string &ID)
{
    string login, password;
    cout << "Enter your account name: ";
    cin >> login;
    cout << "Enter your password: ";
    password = pass();
    if(LoginCheck(login, password, type, ID) == true)
        cout << "Login successful! " << type << " " << ID << endl;
}

bool checkForSame(string login, string password, string ID)
{
    int trash1, trash2;
    ifstream fi;
    fi.open("password.txt");
    string dataLogin, dataPassword;
    if ((password == ID) || (login == ID))
    {
        cout << "Account name or Password can't be ID. Please try again:\n";
        return true;
    }
    while (!fi.eof())
    {
        fi >> dataLogin;
        fi >> dataPassword >> trash1 >> trash2;
        if((login == dataLogin) || (password == dataPassword))
        {
            cout << "Account name or Password already exists. Please try again:\n";
            fi.close();
            return true;  
        }
    }
    fi.close();
    return false;
}

void edit(string ID)
{
    char type;
    string temp_ID;
    string new_login, new_password;
    do
    {
        cout << "Enter your new account name: ";
        cin >> new_login;
        cout << "Enter your new password: ";
        new_password = pass();
    }
    while (checkForSame(new_login, new_password, ID));
    string content = "", tempLogin, tempPassword;
    ifstream fi;
    fi.open("password.txt");
    while(fi >> tempLogin >> tempPassword >> type >> temp_ID)
    {
        if(temp_ID != ID)
            content += tempLogin + ' ' + tempPassword + ' ' + type + ' ' + temp_ID + '\n';
        else    
            content += new_login + ' ' + new_password + ' ' + type + ' ' + temp_ID + '\n';
    }
    fi.close();
    ofstream fo("password.txt");
    fo << content;
    fo.close();
}

string pass()
{
    char *pass = new char[max_value];
    int i = 0;   
    while((pass[i]=getch() ) != '\n' && pass[i] != '\r' && i< (max_value - 1))
    {
        putchar('*'); 
        i++;
    }
    pass[i] = '\0';
    cout << '\n';
    string s = pass;
    delete pass;
    return s;
}
