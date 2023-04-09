#include "lib.h"

void clrscr()
{
   fprintf(stdout, "\033[2J");
   fprintf(stdout, "\033[1;1H");
}