#ifndef FICTION_H
#define FICTION_H
#include "book.h"

class Fiction : public Book
{
public:
    Fiction(int id, int borrower, string title, string author);
    void Print();

    static string _FICTION;
    void Print(ostream &os);
    bool IsSearchCandidate(string s, SearchMode sMode); //override

private:
    bool SearchAuthor(string s); //override

};
#endif
