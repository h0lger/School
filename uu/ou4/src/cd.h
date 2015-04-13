#ifndef CD_H
#define CD_H
#include <string>
#include "media.h"
using namespace std;
class CD : public Media
{
public:
	string Artist;
	int Length; //i antal sekunder
};
#endif