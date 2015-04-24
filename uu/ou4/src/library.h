#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "media.h"
using namespace std;

class Library
{
public:

    Library(vector<Media*> *v);

    enum SearchMode: short
    {
        Title = 0,
        Author = 1 //Author/Artist
    };

    void Search(string s, SearchMode sMode); //söker och skriver ut resultatet
    void ShowMenu();

private:
    vector<Media*> *_v;
    const string _LINE = "-----------------------------------\n";

};
#endif
