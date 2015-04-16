#include "journal.h"

string Journal::_JOURNAL = "Journal";

Journal::Journal(int id, int borrower, string title, string pub): Media(id, borrower, title), Published(pub)
{

}
