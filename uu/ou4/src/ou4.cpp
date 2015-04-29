#include "media.h"
#include "book.h"
#include "journal.h"
#include "cd.h"
#include "fiction.h"
#include "noneFiction.h"
#include "regHandler.h"
#include <iostream>
#include "library.h"


int main()
{
    const string _FILE = "reg.dat";

    try
    {        
        vector<Media*> *v;
        RegHandler r(_FILE);
        v = r.ReadRegFromFile();
        Library lib(v);
        lib.ShowMenu();
        cout << "Spara registerfil\n";
        r.SaveToFile(v);

        delete v;
    }
    catch(exception)
    {
        return 1;
    }
	

	return 0;
}
