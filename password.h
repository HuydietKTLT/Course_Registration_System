#ifndef _PASSWORD_H_
#define _PASSWORD_H_
#include "lib.h"

struct passInfo;

bool LoginCheck(string login, string password, char &type, string &ID, passInfo *readfile);
void login(char &type, string &ID, passInfo *readfile);
void edit(string ID, passInfo *&readfile);
bool doTheEdit(string login, string password, string ID, passInfo *&head);
string pass();
void clear(passInfo *&readfile);
void ReadPassword(passInfo *&readfile);

#endif