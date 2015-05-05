#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <iostream>
#include "utils.h"
using namespace std;
class Media
{
protected:
    Media();
    Media(int id, int borrower, string title);    
    int Id; //internt nummer
	int Borrower; //låntagarnummer (om 0 är den tillgänglig för utlåning)
    string Title;
    bool SearchTitle(string s);

public:
    virtual ~Media();
    virtual void Print(ostream &os);
    virtual bool IsSearchCandidate(string s, SearchMode sMode);
    int GetId() const;
    int GetBorrower() const;
    void BorrowMe(int borrower);
    void ReturnMe();
};
#endif
