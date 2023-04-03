#ifndef _PASSWORD_H_
#define _PASSWORD_H_
#include "lib.h"

bool LoginCheck(string login, string password, char &type, string &ID, passInfo *readfile);
void login(char &type, string &ID, passInfo* readfile);
void edit(string ID, passInfo* readfile);
void ReadPassword(passInfo*& readfile);
bool doTheEdit(string login, string password, string ID, passInfo *&head);
void clear(passInfo*& readfile);
string pass();

#endif