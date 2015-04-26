#include "media.h"
Media::Media() {}
Media::Media(int id, int borrower, string title): Id(id), Borrower(borrower), Title(title)
{

}

void Media::Print(ostream &os)
{
    cerr << "Använd inte\n";
}

bool Media::IsSearchCandidate(string s, SearchMode sMode)
{
    cout << "Ska ej användas!\n";
    return false;
}

bool Media::SearchTitle(string s)
{
    size_t found;
    found = Title.find(s);
    return found != Title.npos;
}

int Media::GetId() const
{
    return Id;
}

int Media::GetBorrower() const
{
    return Borrower;
}

void Media::BorrowMe(int borrower)
{
    Borrower = borrower;
}

void Media::ReturnMe()
{
    Borrower = 0;
}
