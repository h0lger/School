#ifndef MEDIA_H
#define MEDIA_H
#include <string>
using namespace std;
class Media
{
protected:
	int Id; //internt nummer
	int Borrower; //låntagarnummer (om 0 är den tillgänglig för utlåning)
	string Title;
};
#endif