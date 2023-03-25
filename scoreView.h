#ifndef _SCOREVIEW_H_
#define _SCOREVIEW_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Class {
    string data;
    Class *pNext;
};

Class *createNode (string s);
void loadClass (ifstream &fin, Class *&pHead);
void deleteClass (Class *&pHead);
void list_of_class (Class *pHead);

#endif