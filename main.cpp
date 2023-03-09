#include "password.h"

int main()
{
    string ID = "";
    char type;
    login(type, ID);
    if (ID != "")
        edit(ID);
    return 0;
}

