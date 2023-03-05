#ifndef _PASSWORD_H_
#define _PASSWORD_H_
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool LoginCheck(string login, string password, int &type);
void login();

#endif