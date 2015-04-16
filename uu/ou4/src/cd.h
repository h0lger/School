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
};
#endif
