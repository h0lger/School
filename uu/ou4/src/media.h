#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <iostream>
using namespace std;
class Media
{
protected:
    Media();
    Media(int id, int borrower, string title);

	int Id; //internt nummer
	int Borrower; //låntagarnummer (om 0 är den tillgänglig för utlåning)
    string Title;

public:
    virtual void Print(ostream &os);
};
#endif
