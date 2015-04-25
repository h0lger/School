#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "media.h"
using namespace std;

class Library
{
public:

    Library(vector<Media*> *v);


    void ShowSearch();
    void ShowMenu();

private:
    void Search(string s, SearchMode sMode); //söker och skriver ut resultatet
    vector<Media*> *_v;
    const string _LINE = "-----------------------------------\n";

};
#endif
