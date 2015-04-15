#ifndef CD_H
#define CD_H
#include <string>
#include "media.h"
using namespace std;
class CD : public Media
{
public:
    CD(int id, int borrower, string title, string artist, int length);
	string Artist;
	int Length; //i antal sekunder

    static string _CD;
};
#endif
