#ifndef REG_HANDLER
#define REG_HANDLER
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "media.h"
#include "fiction.h"
#include "cd.h"
#include "noneFiction.h"
#include "journal.h"
using namespace std;
#define ROWS 5 //hur många rader ett objekt utnyttjar i filen

class RegHandler
{    
public:
    RegHandler(const string);
    vector<Media> *ReadRegFromFile(); //läser upp registret i minnet
    bool SaveToFile(vector<Media> *); //sparar minnet till registret

    enum FileRowEnum: short
    {
        Type = 0, //typ t.ex. Fiction, CD
        Creator = 1, //kan vara författare, artist
        Title = 2, //titel, utgivningsår, längd
        Id = 3,
        Borrower = 4 //låntagarnummer
    };

private:
    const string _filename;

    Media *CreateMedia(string *);
};
#endif
