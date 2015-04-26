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
    void ShowBorrow();
    void ShowReturn();
    void ShowInsert(char c);
    void ShowRemove();
    void ShowMenu();

private:
    const string _LINE = "-----------------------------------\n";
    vector<Media*> *_v;

    void Search(string s, SearchMode sMode); //söker och skriver ut resultatet
    bool IdExists(int id, int *pos); //kontrollerar om id finns
    bool OkToBorrow(int id); //kontrollera om tillgänglig för utlåning
    bool OkToReturn(int id, int borrower); //kontroller om ok att lämna tillbaka
    bool Borrow(int id, int borrower);
    bool UnBorrow(int id);
    bool ReturnMedia(int id); //lämna tillbaka
    int CreateId(); //validerar och skapar ett unikt id
};
#endif
