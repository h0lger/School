#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "media.h"
using namespace std;
//abstrakt
class Book : public Media
{
public:
	string Author;
	virtual void Print() = 0;
};
#endif