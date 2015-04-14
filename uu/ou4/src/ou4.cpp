#include "media.h"
#include "book.h"
#include "journal.h"
#include "cd.h"
#include "fiction.h"
#include "noneFiction.h"
#include "helper.h"
#include "regHandler.h"
#include <iostream>

int main()
{
    const string _FILE = "src/reg.dat";
    try
    {
        std::cout << "Hello\n";
        RegHandler r(_FILE);
        r.ReadRegFromFile();
    }
    catch(exception)
    {
        return 1;
    }
	

	return 0;
}
