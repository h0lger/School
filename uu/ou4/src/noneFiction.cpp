#include "noneFiction.h"

string NoneFiction::_NONEFICTION = "NonFiction";

NoneFiction::NoneFiction(int id, int borrower, string title, string author)
{
    Id = id;
    Borrower = borrower;
    Title = title;
    Author = author;
}

void NoneFiction::Print(ostream &os)
{
    os << _NONEFICTION << endl <<
          Author << endl <<
          Title << endl <<
          Id << endl <<
          Borrower << endl;

}

bool NoneFiction::IsSearchCandidate(string s, SearchMode sMode)
{
    if(sMode == SearchMode::Title)
        return SearchTitle(s);
    else if(sMode == SearchMode::Author)
        return SearchAuthor(s);
    else
    {
        cerr << "Fel söktyp\n";
        return false;
    }

}

bool NoneFiction::SearchAuthor(string s)
{
    size_t found;
    found = Author.find(s);
    return found != Author.npos;
}
