#include "lib.h"

void clrscr()
{
   printf("\e[1;1H\e[2J");
}

void stop()
{
        cout << "Press any key to continue..." << endl;
        cin.get();
        cin.get();
}

float float_one_point_round(float value)
{
        return ((float)((int)(value * 10))) / 10;
}

float stf(string str)
{
        return strtof(str.c_str(), NULL);
}