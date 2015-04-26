#include "journal.h"

string Journal::_JOURNAL = "Journal";

Journal::Journal(int id, int borrower, string title, string pub): Media(id, borrower, title), Published(pub)
{

}

void Journal::Print(ostream &os)
{
    os << _JOURNAL << endl <<
          Published << endl <<
          Title << endl <<
          Id << endl <<
          Borrower << endl;
}

bool Journal::SearchPublished(string s)
{
    size_t found;
    found = Published.find(s);
    return found != Published.npos;
}

bool Journal::IsSearchCandidate(string s, SearchMode sMode)
{
    if(sMode == SearchMode::Title)
        return SearchPublished(s);
    else if(sMode == SearchMode::Author)
        return false; //inte applicerbart
    else
    {
        cerr << "Fel söktyp\n";
        return false;
    }

}
