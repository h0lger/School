#ifndef FICTION_H
#define FICTION_H
#include "book.h"

class Fiction : public Book
{
public:
    Fiction(int id, int borrower, string title, string author);
    void Print();

    static string _FICTION;
};
#endif
