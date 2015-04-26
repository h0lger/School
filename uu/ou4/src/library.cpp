#include "library.h"

Library::Library(vector<Media*> *v)
{
    _v = v;
}

void Library::ShowMenu()
{
    cout << "C - insert new CD\n";
    cout << "F - insert new Fiction book\n";
    cout << "N - insert new Non-Fiction book\n";
    cout << "J - insert new Journal\n";
    cout << "X - remove an object from the library\n";
    cout << "H - show this text\n";
    cout << "S - search\n";
    cout << "B - borrow a object\n";
    cout << "R - return an object\n";
    cout << "Q - quit the program\n";
    cout << "\nChoose one of X/C/F/N/J/H(Help)/S/B/R/Q\n";
}

void Library::ShowSearch()
{
    SearchMode sMode;
    char c;
    for(bool ok = false;!ok;)
    {
        cout << "Search by title (T) or author/artist (A)? ";
        cin >> c;
        switch(c)
        {
            case 'T':
                sMode = SearchMode::Title;
                ok = true;
                break;
             case 'A':
                sMode = SearchMode::Author;
                ok = true;
                break;
        }
    }

    string s;
    cout << "Search string: ";
    cin >> s;
    Search(s, sMode);
}

void Library::Search(string s, SearchMode sMode)
{    
    for(vector<Media*>::iterator it = _v->begin();it != _v->end();it++)
    {
        Media *m = *it;
        if(m->IsSearchCandidate(s, sMode))
        {
            cout << _LINE;
            m->Print(cout);
            cout << _LINE << "\n";
        }
    }
}

void Library::ShowBorrow()
{
    int id;
    int borrower;
    //id
    for(bool ok = false;!ok;)
    {
        cout << "ID: ";
        //TODO: validera om numeriskt
        cin >> id;
        ok = IdExists(id);
        if(!ok)
            cout << "Id finns inte\n";
        else
        {
            ok = OkToBorrow(id);
            if(!ok)
                cout << "Det är redan utlånat\n";
        }
    }
    cout << "Borrower: ";
    //TODO: validera om numeriskt
    cin >> borrower;
    if(Borrow(id, borrower))
        cout << "Media utlånat till '" << borrower << "'\n";
    else
        cerr << "Det gick inte att lånt ut\n";
}

void Library::ShowReturn()
{
    int id;
    int borrower;
    //id
    for(bool ok = false;!ok;)
    {
        cout << "ID: ";
        //TODO: validera om numeriskt
        cin >> id;
        ok = IdExists(id);
        if(!ok)
            cout << "Id finns inte\n";
        else
        {
            cout << "Borrower: ";
            //TODO: validera om numeriskt
            cin >> borrower;
            ok = OkToReturn(id, borrower);
            if(!ok)
                cout << "Media går inte att lämna tillbaka (utlånad till någon annan eller ej utlånat)\n";
            else
            {
                if(ReturnMedia(id))
                    cout << "Media har lämnats tillbaka\n";
                else
                {
                    cerr << "Det gick inte att lämna tillbaka\n";
                    break;
                }
            }
        }
    }


}

bool Library::Borrow(int id, int borrower)
{
    for(vector<Media*>::iterator it = _v->begin();it != _v->end();it++)
    {
        Media *m = *it;
        if(m->GetId() == id)
        {
            m->BorrowMe(borrower);
            return true;
        }
    }

    return false;
}

bool Library::ReturnMedia(int id)
{
    for(vector<Media*>::iterator it = _v->begin();it != _v->end();it++)
    {
        Media *m = *it;
        if(m->GetId() == id)
        {
            m->ReturnMe();
            return true;
        }
    }

    return false;
}

bool Library::OkToReturn(int id, int borrower)
{
    for(vector<Media*>::iterator it = _v->begin();it != _v->end();it++)
    {
        Media *m = *it;
        if(m->GetId() == id && m->GetBorrower() == borrower)
            return true;
    }

    return false;
}

bool Library::OkToBorrow(int id)
{
    for(vector<Media*>::iterator it = _v->begin();it != _v->end();it++)
    {
        Media *m = *it;
        if(m->GetId() == id && m->GetBorrower() == 0)
            return true;
    }

    return false;
}

bool Library::IdExists(int id)
{
    for(vector<Media*>::iterator it = _v->begin();it != _v->end();it++)
    {
        Media *m = *it;
        if(m->GetId() == id)
            return true;
    }

    return false;
}
