#ifndef REG_HANDLER
#define REG_HANDLER
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "media.h"
using namespace std;
#define LINE_LENGTH 50
class RegHandler
{
public:
    RegHandler(const string);
    vector<Media> *ReadRegFromFile(); //läser upp registret i minnet
    bool SaveToFile(vector<Media> *); //sparar minnet till registret

private:
    const string _filename;
};
#endif
