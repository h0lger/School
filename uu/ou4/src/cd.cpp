#include "cd.h"

string CD::_CD = "CD";

CD::CD(int id, int borrower, string title, string artist, string length): Media(id, borrower, title), Artist(artist), Length(length)
{

}

void CD::Print(ostream &os)
{
    os << _CD << endl <<
          Artist << endl <<
          Title << endl <<
          Length << endl <<
          Id << endl <<
          Borrower << endl;
}

bool CD::IsSearchCandidate(string s, SearchMode sMode)
{
    if(sMode == SearchMode::Title)
        return SearchTitle(s);
    else if(sMode == SearchMode::Author)
        return SearchArtist(s);
    else
    {
        cerr << "Fel söktyp\n";
        return false;
    }

}

bool CD::SearchArtist(string s)
{
    size_t found;
    found = Artist.find(s);
    return found != Artist.npos;
}
