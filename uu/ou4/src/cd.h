#ifndef CD_H
#define CD_H
#include <string>
#include "media.h"
using namespace std;
class CD : public Media
{
public:
    CD(int id, int borrower, string title, string artist, string length);
	string Artist;
    string Length;

    static string _CD;

    void Print(ostream &os); //override
    bool IsSearchCandidate(string s, SearchMode sMode); //override

private:
    bool SearchArtist(string s);
};
#endif
