#include "library.h"
#include "cd.h"
#include "fiction.h"
#include "noneFiction.h"
#include "journal.h"

Library::Library(vector<Media*> *v)
{
    _v = v;
}

Library::~Library()
{

}

void Library::ShowMenu()
{
    char c;
    for(bool quit = false;!quit;)
    {
        cout << "C - lägg till en ny 'CD'\n";
        cout << "F - lägg till en ny 'Fiction' bok\n";
        cout << "N - lägg till en ny 'Non-Fiction' bok\n";
        cout << "J - lägg till en nu 'Journal'\n";
        cout << "X - ta bort ett media från biblioteket\n";
        cout << "H - visa denna text\n";
        cout << "S - sök\n";
        cout << "B - låna\n";
        cout << "R - lämna tillbaka\n";
        cout << "Q - avsluta programmet\n";
        cout << "\nVälj ett av valen: X/C/F/N/J/H(Help)/S/B/R/Q\n";
        cin >> c;

        switch(c)
        {
            case 'C':
            case 'F':
            case 'N':
            case 'J':
                ShowInsert(c);
                cout << "Mediat är tillagt\n";
            break;

            case 'X':
                ShowRemove();
            break;

            case 'S':
                ShowSearch();
            break;

            case 'B':
                ShowBorrow();
            break;

            case 'R':
                ShowReturn();
            break;

            case 'Q':
                cout << "Välkommen tillbaka\n";
                //TODO: spara till fil
                quit = true;
            break;

            default:
                if(c != 'H')
                    cout << "Felaktigt val\n";
            break;
        }
    }
}

void Library::ShowInsert(char c)
{
    int id;
    string title, artist, length, author, published;
    switch(c)
    {
        //CD
        case 'C':
        {
            id = CreateId();
            cout << "Titel: ";
            cin.ignore();
            getline(cin, title);
            cout << "Artist: ";            
            getline(cin, artist);
            cout << "Längd (hh:mm): ";
            cin >> length;
            CD *cd = new CD(id, 0, title, artist, length);
            _v->push_back(cd);
        }
        break;

        //Fiction
        case 'F':
        {
            id = CreateId();
            cout << "Titel: ";
            cin.ignore();
            getline(cin, title);
            cout << "Författare: ";
            getline(cin, author);
            Fiction *f = new Fiction(id, 0, title, author);
            _v->push_back(f);
        }
        break;

        //None Fiction
        case 'N':
        {
            id = CreateId();
            cout << "Titel: ";
            cin.ignore();
            getline(cin, title);
            cout << "Författare: ";
            getline(cin, author);
            NoneFiction *f = new NoneFiction(id, 0, title, author);
            _v->push_back(f);
        }
        break;

        //Journal
        case 'J':
        {
            id = CreateId();
            cout << "Titel: ";
            cin.ignore();
            getline(cin, title);
            cout << "Publicerad datum (dd/yy): ";
            cin >> published;
            Journal *j = new Journal(id, 0, published, title);
            _v->push_back(j);
        }
        break;
    }
}

void Library::ShowRemove()
{
    int id;
    int pos = -1;
    for(bool ok = false;!ok;)
    {
        cout << "Id som ska tas bort: ";
        cin >> id;
        ok = IdExists(id, &pos) == true;
        if(!ok)
            cout << "Id finns inte\n";
        else
        {
            _v->erase(_v->begin() + pos);
            cout << "'" << id << "' borttagen\n";
        }
    }
}

int Library::CreateId()
{
    int id;
    int pos = -1;
    for(bool ok = false;!ok;)
    {
        cout << "Id: ";
        cin >> id;
        ok = IdExists(id, &pos) == false;
        if(!ok)
            cout << "Id finns redan\n";
    }

    return id;
}

void Library::ShowSearch()
{
    SearchMode sMode;
    char c;
    for(bool ok = false;!ok;)
    {
        cout << "Search på titel (T) eller författare/artist (A)? ";
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
    cout << "Söksträng: ";
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
    int pos = -1;
    //id
    for(bool ok = false;!ok;)
    {
        cout << "ID: ";
        //TODO: validera om numeriskt
        cin >> id;
        ok = IdExists(id, &pos);
        if(!ok)
            cout << "Id finns inte\n";
        else
        {
            ok = OkToBorrow(id);
            if(!ok)
                cout << "Det är redan utlånat\n";
        }
    }
    cout << "Låntagare: ";
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
    int pos = -1;
    //id
    for(bool ok = false;!ok;)
    {
        cout << "Id: ";
        //TODO: validera om numeriskt
        cin >> id;
        ok = IdExists(id, &pos);
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

bool Library::IdExists(int id, int *pos)
{
    int i = -1;
    for(vector<Media*>::iterator it = _v->begin();it != _v->end();it++)
    {
        i++;
        Media *m = *it;
        if(m->GetId() == id)
        {
            *pos = i;
            return true;
        }
    }

    return false;
}
