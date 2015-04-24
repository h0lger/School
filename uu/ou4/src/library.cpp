#include "library.h"

Library::Library(vector<Media*> *v)
{
    _v = v;
}

void Library::Search(string s, SearchMode sMode)
{
    for(vector<Media*>::iterator it = _v->begin();it != _v->end();it++)
    {
        Media *m = *it;
        cout << _LINE;
        m->Print(cout);
        cout << _LINE << "\n";
    }
}

void Library::ShowMenu()
{
    cout << "C - insert new CD\n";
    cout << "F - insert new Fiction book\n";
    cout << "N - insert new Non-Fiction book\n";
    cout << "J - insert new Journal\n";
    cout << "X - remove an object from the library\n";
    cout << "H - show this text\n";
    cout << "S - search";
    cout << "B - borrow a object\n";
    cout << "R - return an object\n";
    cout << "Q - quit the program\n";
    cout << "\nChoose one of X/C/F/N/J/H(Help)/S/B/R/Q\n";
}
