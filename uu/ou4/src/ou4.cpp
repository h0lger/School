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
    const string _FILE = "reg.dat";

    try
    {
        std::cout << "Hello\n";
        vector<Media*> *v;
        RegHandler r(_FILE);
        v = r.ReadRegFromFile();
        r.SaveToFile((v));

    }
    catch(exception)
    {
        return 1;
    }
	

	return 0;
}
