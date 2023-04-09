#include "lib.h"

void clrscr()
{
   fprintf(stdout, "\033[2J");
   fprintf(stdout, "\033[1;1H");
}

float float_one_point_round(float value)
{
        return ((float)((int)(value * 10))) / 10;
}

float stf(string str)
{
        return strtof(str.c_str(), NULL);
}