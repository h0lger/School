#include "journal.h"

string Journal::_JOURNAL = "Journal";

Journal::Journal(int id, int borrower, string title, time_t pub): Media(id, borrower, title), Published(pub)
{

}
