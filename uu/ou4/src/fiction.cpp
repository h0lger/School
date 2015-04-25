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

bool Fiction::IsSearchCandidate(string s, SearchMode sMode)
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

bool Fiction::SearchAuthor(string s)
{
    size_t found;
    found = Author.find(s);
    return found != Author.npos;
}
