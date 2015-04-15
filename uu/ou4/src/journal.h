#ifndef JOURNAL_H
#define JOURNAL_H
#include <ctime>
#include "media.h"
class Journal : public Media
{
public:
    Journal(int id, int borrower, string title, time_t published);

	time_t Published;
    static string _JOURNAL;
};
#endif
