#include "scoreview.h"

Class *createNode (string s)
{
    Class *p = new Class;
    p->data = s;
    p->pNext = nullptr;
    return p;
}

// Load data from file "listOfClass.txt" to LinkedList 
void loadClass (ifstream &fin, Class* &pHead)
{
    string temp;
    getline(fin, temp);
    if (temp.empty()) return;
    string data = temp.substr(temp.find(',') + 2);
    Class *p = createNode(data);
    pHead = p;
    Class *cur = pHead;
    while (!fin.eof())
    {
        getline(fin, temp);
        if (temp.empty()) return;
        data = temp.substr(temp.find(',') + 2);
        p = createNode(data);
        cur->pNext = p;
        cur = cur->pNext;
    }
    // just load file, dont need to care, it MAY corrected...
}

// delete the whole Linked List
void deleteClass (Class *&pHead)
{
    while (pHead != nullptr)
    {
        Class *p = pHead;
        pHead = pHead->pNext;
        delete p;
    }
}


// This function use to show all of classes being available
void list_of_class (Class *pHead)
{
    if (pHead == nullptr) return;
    int count = 0;
    while (pHead != nullptr)
    {
        cout << count+1 << ", " << pHead->data << endl;
        pHead = pHead->pNext;
        count++;
    }
    cout << "There are " << count << " classes total. " << endl;
}