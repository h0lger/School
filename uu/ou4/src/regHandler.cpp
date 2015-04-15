#include "regHandler.h"
//konstruktor
RegHandler::RegHandler(const string filename) : _filename(filename)
{

}

vector<Media> * RegHandler::ReadRegFromFile()
{
    vector<Media> *lista = new vector<Media>();
    ifstream file(_filename.c_str());
    if(file)
    {
        string *s = new string[ROWS];
        int i = 0;
        while(getline(file, s[i]))
        {
            if(i > 0 && i % (ROWS - 1) == 0)
            {
                CreateMedia((s));
                i = 0;
            }
            else
                i++;
        }
        delete [] s;
    }
    else
    {
        cerr << "Registerfilen kunde inte öppnas\n";
        throw exception();
    }


    return lista;
}

Media *RegHandler::CreateMedia(string *sArr)
{
    Media *m;

    if(sArr[FileRowEnum::Type] == Fiction::_FICTION)
    {
        cout << "Skapar en fiction\n";

//        m = new Fiction(sArr[FileRowEnum::Id],
//                (int)sArr[FileRowEnum::Borrower],
//                sArr[FileRowEnum::Title,
//                sArr[FileRowEnum::Creator]]);

    }
    else if(sArr[FileRowEnum::Type] == NoneFiction::_NONEFICTION)
    {
        cout << "Skapar en none fiction";
    }
    else if(sArr[FileRowEnum::Type] == Journal::_JOURNAL)
    {
        cout << "Skapar en journal";
    }
    else if(sArr[FileRowEnum::Type] == CD::_CD)
    {
        cout << "Skapar en CD";
    }




    return m;
}
