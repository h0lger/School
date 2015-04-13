#ifndef JOURNAL_H
#define JOURNAL_H
#include <ctime>
#include "media.h"
class Journal : public Media
{
public:
	time_t Published;
};
#endif