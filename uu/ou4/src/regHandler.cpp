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
        string line;
        short i = 0;
        while(!file.eof())
        {
            file >> line;
            cout << line  << "\n";
        }
//        char *c = new char[LINE_LENGTH];
//        while(file.getline(c, LINE_LENGTH))
//        {
//            for(short i = 0; i<LINE_LENGTH;i++)
//            {
//                cout << c[i];
//            }
//            cout << "\n";
//        }
//        delete [] c;
    }
    else
    {
        cerr << "Registerfilen kunde inte öppnas\n";
        throw exception();
    }


    return lista;
}
