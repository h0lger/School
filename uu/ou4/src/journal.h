#ifndef JOURNAL_H
#define JOURNAL_H
#include "media.h"
class Journal : public Media
{
public:
    Journal(int id, int borrower, string title, string published);

    string Published;
    static string _JOURNAL;

    void Print(ostream &os); //override
    bool IsSearchCandidate(string s, SearchMode sMode); //override

};
#endif
