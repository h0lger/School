#include "regHandler.h"
//konstruktor
RegHandler::RegHandler(const string filename) : _filename(filename)
{

}

vector<Media*> * RegHandler::ReadRegFromFile()
{
    vector<Media*> *lista = new vector<Media*>();
    ifstream file(_filename.c_str());
    if(file)
    {
        string *s = new string[BIG_ROWS];
        int i = 0;
        while(getline(file, s[i]))
        {
            //läs in media när vi itererat för normala objekt
            if(i > 0 && i % (NOR_ROWS - 1) == 0 && s[0] != CD::_CD)
            {
                CreateAddMedia(s, lista);
                i = 0;
            }
            else if(i > 0 && i % (BIG_ROWS - 1) == 0 && s[0] == CD::_CD)
            {
                CreateAddMedia(s, lista);
                i = 0;
            }
            else
                i++;
        }
        delete [] s;
    }
    else
    {
        cerr << "Registerfilen kunde inte öppnas för läsning\n";
        throw exception();
    }


    return lista;
}

bool RegHandler::SaveToFile(vector<Media*> *v)
{
    ofstream file(("test_" + _filename).c_str());
    if(file)
    {
        for(vector<Media*>::iterator it = v->begin();it != v->end();it++)
        {
            Media *m = *it;
            m->Print(file);
        }
    }
    else
    {
        cerr << "Registerfilen kunde inte öppnas för skrivning\n";
        return false;
    }
}

void RegHandler::CreateAddMedia(string *sArr, vector<Media*> *v)
{
    if(sArr[RowPos::Type] == Fiction::_FICTION)
    {
        string title = sArr[RowPos::NorRow_Title];
        int id = stoi(sArr[RowPos::NorRow_Id]);
        int b = stoi(sArr[RowPos::NorRow_Borrower]);
        string author = sArr[RowPos::NorRow_Creator];

        Fiction *f = new Fiction(id, b, title, author);
        v->push_back(f);

    }
    else if(sArr[RowPos::Type] == NoneFiction::_NONEFICTION)
    {
        string title = sArr[RowPos::NorRow_Title];
        int id = stoi(sArr[RowPos::NorRow_Id]);
        int b = stoi(sArr[RowPos::NorRow_Borrower]);
        string author = sArr[RowPos::NorRow_Creator];

        NoneFiction *nf = new NoneFiction(id, b, title, author);
        v->push_back(nf);
    }
    else if(sArr[RowPos::Type] == Journal::_JOURNAL)
    {
        string title = sArr[RowPos::NorRow_Title];
        int id = stoi(sArr[RowPos::NorRow_Id]);
        int b = stoi(sArr[RowPos::NorRow_Borrower]);
        string pub = sArr[RowPos::NorRow_Creator];

        Journal *j = new Journal(id, b, title, pub);
        v->push_back(j);
    }
    else if(sArr[RowPos::Type] == CD::_CD)
    {
        string artist = sArr[RowPos::BigRow_Creator];
        string title = sArr[RowPos::BigRow_Title];
        string l = sArr[RowPos::BigRow_Length];
        int id = stoi(sArr[RowPos::BigRow_Id]);
        int b = stoi(sArr[RowPos::BigRow_Borrower]);

        CD *cd = new CD(id, b, title, artist, l);
        v->push_back(cd);
    }
    else
    {
        cerr << "Typen kan inte kännas igen från filen\n";
        throw exception();
    }

}
