#include "fiction.h"
string Fiction::_FICTION = "Fiction";

Fiction::Fiction(int id, int borrower, string title, string author)
{
    //får initiera de såhär eftersom det inte går via initparams
    Id = id;
    Borrower = borrower;
    Title = title;
    Author = author;
}

void Fiction::Print(ostream &os)
{
    os << _FICTION << endl <<
          Author << endl <<
          Title << endl <<
          Id << endl <<
          Borrower << endl;

}
