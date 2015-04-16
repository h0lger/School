#include "noneFiction.h"

string NoneFiction::_NONEFICTION = "NonFiction";

NoneFiction::NoneFiction(int id, int borrower, string title, string author)
{
    Id = id;
    Borrower = borrower;
    Title = title;
    Author = author;
}

void NoneFiction::Print()
{

}
