#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "media.h"
using namespace std;
//abstrakt
class Book : public Media
{
public:
    Book();
    //Book(int, int, string, string);
	string Author;
    virtual void Print(ostream &) = 0;

protected:
    virtual bool SearchAuthor(string s) = 0;
};
#endif
