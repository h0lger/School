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
