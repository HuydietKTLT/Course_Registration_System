#include "staff.h"

void menuStaff()
{
    
    int i;
    bool check = currentSchoolYear();
    cout << "-------------------------------------------\n";
    cout << "1. New school year.\n2. New classess for current school year.\n4. New semester.\n0. Exit\nEnter options: ";
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
    case 4:
        if (check == true)
            addCourseMenu();
        else
            cout << "There are no current year. Please create a new school year.\n";
        break;
    default:
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
    if (_mkdir(year.c_str()) == 0) {
        cout << "New school year created successfully.\n";
    }
    else {
        cout << "Failed to create new school year.\n";
    }

    ofstream fo;
    fo.open("currentschoolyear.txt");
    fo << year;
    fo.close();
    fo.open("schoolyearlist.txt", ios_base::app);
    fo << year << '\n';
    fo.close();
    year = year.substr(0, year.find('-'));
    year = revString(year);
    fo.open("currrentclass.txt");
    fo << year[1] << year[0] << '\n';
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
    year = yearschool + "/" + year;
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

void addCourseMenu()
{
    currentSchoolYear();
    cout << "-------------------------------------------\n";
    cout << "1. Choose a different school year\n2. Choose a semester\n0. Exit\nEnter options: ";
    int i;
    cin >> i;
    string a;
    switch (i)
    {
    case 0:
        return;
    case 1:
        cout << "Pick a school year:\n";
        cin >> a;
        struct stat metaData;
        if ((a.c_str(), &metaData) != 0)
            cout << "The school year doesn't exists.\nPlease create the school year or choose a different school year.\n";
        else
        {
            ofstream fo;
            fo.open("currentschoolyear.txt");
            fo << a;
            a = a.substr(0, a.find('-'));
            a = revString(a);
            fo.open("currrentclass.txt");
            fo << a[1] << a[0] << '\n';
            fo.close();
        }
        break;
    case 2:
        addSemester();
        break;
    default:
        break;
    }
    addCourseMenu();
}

void addSemester()
{
    cout << "-------------------------------------------\n";
    cout << "1. Semester 1\n2. Semester 2\n3. Semester 3\n0. Exit\nEnter options: ";
    ifstream fi;
    fi.open("currentschoolyear.txt");
    string path;
    fi >> path;
    fi.close();
    int i;
    cin >> i;
    if (i == 0)
        return;
    else 
        if (i >= 1 && i <= 3)
        {
            path = path + "/SM" +to_string(i);
            struct stat metaData;
            if ((path.c_str(), &metaData) != 0)
                if (_mkdir(path.c_str()) == 0)
                    cout << "New semester created successfully.\n";
                else
                {
                    cout << "Failed to create new semester.\n";
                    return addSemester();
                }
            ofstream fo;
            fo.open ("currentSemester.txt");
            fo << "SM" << i;
            fo.close();
            fo.open (path + "/listOfCourse.txt");
            fo.close();
        }
    addSemester();
}

bool currentSchoolYear()
{
    cout << "-------------------------------------------\n";
    ifstream fi;
    fi.open("currentschoolyear.txt");
    string currentshoolyear;
    if (fi >> currentshoolyear)
    {
        cout << "Current school year: " << currentshoolyear << '\n';
        return true;
    }
    else    
        cout << "Current school year: NULL\n";
    fi.close();
    return false;
}