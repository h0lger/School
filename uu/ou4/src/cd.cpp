#include "cd.h"

string CD::_CD = "CD";

CD::CD(int id, int borrower, string title, string artist, int length): Media(id, borrower, title), Artist(artist), Length(length)
{

}
