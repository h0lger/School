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
#define NOR_ROWS 5 //hur många rader ett "normalt" objekt utnyttjar i filen
#define BIG_ROWS 6 // hur många rader ett "större" objekt  utnyttjar i filen (cd)

class RegHandler
{    
public:
    RegHandler(const string filename);
    vector<Media> *ReadRegFromFile(); //läser upp registret i minnet
    bool SaveToFile(vector<Media> *v); //sparar minnet till registret

    //radpositioner för normala objekt
    enum RowPos: short
    {
        Type = 0, //typ t.ex. Fiction, CD (alltid på samma pos!)
        NorRow_Creator = 1, //kan vara författare, artist
        BigRow_Creator = 1, //kan vara författare, artist
        NorRow_Title = 2, //titel, utgivningsår
        BigRow_Title = 2, //titel, utgivningsår, längd
        NorRow_Id = 3,
        BigRow_Id = 4,
        BigRow_Length = 3,
        NorRow_Borrower = 4, //låntagarnummer
        BigRow_Borrower = 5 //låntagarnummer
    };


private:
    const string _filename;

    Media *CreateMedia(string *sArr, vector<Media> *v);
};
#endif
