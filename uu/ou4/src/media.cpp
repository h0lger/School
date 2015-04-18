#include "media.h"
Media::Media() {}
Media::Media(int id, int borrower, string title): Id(id), Borrower(borrower), Title(title)
{

}

void Media::Print(ostream &os)
{
    cerr << "Använd inte\n";
}
