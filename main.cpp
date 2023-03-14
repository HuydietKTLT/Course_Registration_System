#include "scoreview.h"

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
    return 0;
}