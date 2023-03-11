#include "staff.h"

void menuStaff()
{
    cout << "-------------------------------------------\n";
    int i;
    ifstream fi;
    fi.open("currentschoolyear.txt");
    bool check = false;
    string currentshoolyear;
    if (fi >> currentshoolyear)
    {
        int k = atoi(currentshoolyear.c_str()) + 1;
        string temp = to_string(k);
        cout << "Current school year: " << currentshoolyear << "-"<< temp;
        check = true;
    }
    else    
        cout << "Current school year: NULL";
    fi.close();
    cout << "\n-------------------------------------------\n";
    cout << "\n1. New school year.\n2. New classess for current school year.\n0. Exit\nEnter options: ";
    cin >> i;
    switch (i)
    {
    case 0:
        return;
    case 1:
        createNewSchoolYear();
        break;
    case 2:
        if (check == true)
            createNewClass();
        else
            cout << "There are no current year. Please create a new school year.\n";
        break;
    }
    menuStaff();
}

string revString(string a)
{
    string b = "";
    int n = a.length();
    for (int i = 0; i < n; i++)
        b += a[n - i - 1];
    return b;
}

void createNewSchoolYear()
{
    string year;
    cout << "-------------------------------------------\n";
    cout << "Ender new school year: ";
    cin >> year;
    year = year.substr(0, year.find('-'));
    if (_mkdir(year.c_str()) == 0) {
        cout << "Folder created successfully.\n";
    }
    else {
        cout << "Failed to create folder.\n";
    }

    ofstream fo;
    fo.open("currentschoolyear.txt");
    fo << year;
    fo.close();
    fo.open("schoolyearlist.txt", ios_base::app);
    fo << year;
    fo.close();
    string a = revString(year);
    fo.open("currrentclass.txt");
    fo << a[1] << a[0] << '\n';
    fo.close();
}

void createNewClass()
{
    string type, year;
    int numberOfClasses;
    ifstream fi;
    fi.open("currrentclass.txt");
    fi >> year;
    fi.close();
    int i;
    cout << "-------------------------------------------\n";
    cout << "1. New classes\n0. Exit\nEnter options: ";
    cin >> i;
    if (i != 0)
    {
        cout << "Type of education: ";
        cin >> type;
        cout << "Number of classes: ";
        cin >> numberOfClasses;
        createClasses(year, type,numberOfClasses);
        createNewClass();
    }
}

void createClasses(string year, string type, int numberOfClasses)
{
    string ID = "0", yearschool;
    ifstream fi;
    fi.open("currentschoolyear.txt");
    fi >> yearschool;
    fi.close();
    ofstream fo;
    year = yearschool + "//" + year;
    year = year + type;
    for (int i = 1; i <= numberOfClasses; i++)
    {
        int k = atoi(ID.c_str()) + 1;
        ID = to_string(k);
        if (ID.length() == 1)
            ID = "0" + ID;
        string classes = year + ID + ".txt";
        fo.open(classes);
        fo.close();
    }
}