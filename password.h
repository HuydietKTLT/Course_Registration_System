#ifndef _PASSWORD_H_
#define _PASSWORD_H_
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

bool LoginCheck(string login, string password, char &type, string &ID);
void login(char &type, string &ID);
void edit(string ID);
bool checkForSame(string login, string password, string ID);
string pass();

#endif