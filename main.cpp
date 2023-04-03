#include "scoreview.h"
#include "password.h"
#include "lib.h"
#include "staff.h"

int main ()
{
    ifstream fin;
    Class *pHead = nullptr;
    fin.open("listOfClass.txt");
    if (!fin.is_open()) {
        cout << "Can not open file !!!";
        return 0;
    }
    else {
        loadClass(fin, pHead);
        list_of_class(pHead);
    }
    fin.close();
    deleteClass(pHead);

    passInfo *readfilePass = nullptr;
    ReadPassword(readfilePass);
    char type;
    string ID;
    login(type, ID, readfilePass);
    edit(ID, readfilePass);
    clear(readfilePass);
    return 0;
}