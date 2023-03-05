#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool LoginCheck(string login, string password, int &type)
{
    ifstream fi;
    fi.open("password.txt");
    string dataLogin, dataPassword;
    while (!fi.eof())
    {
        fi >> dataLogin;
        fi >> dataPassword >> type;
        if((login == dataLogin) && (password == dataPassword))
        {
            fi.close();
            return true;  
        }
    }
    fi.close();
    return false;
}

int main()
{
    
    string login, password;
    int type;
    cout << "Enter your account name: ";
    cin >> login;
    cout << "Enter your password: ";
    cin >> password;
    if(LoginCheck(login, password, type) == true)
        cout << "Login successful! " << type << endl;
    else
        cout << "Invalid account name or password." << endl;
    return 0;
}
