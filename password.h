#ifndef _PASSWORD_H_
#define _PASSWORD_H_
#include "lib.h"

struct passInfo;

bool LoginCheck(string login, string password, char &type, string &ID, passInfo *readfile);
void login(char &type, string &ID);
void edit(string ID);
bool doTheEdit(string login, string password, string ID, passInfo *&head);
string pass();

#endif