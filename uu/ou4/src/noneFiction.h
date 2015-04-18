#ifndef NONEFICTION_H
#define NONEFICTION_H
#include "book.h"
class NoneFiction : public Book
{
public:
    NoneFiction(int id, int borrower, string title, string author);
    void Print();
    static string _NONEFICTION;
    void Print(ostream &os);
};
#endif
