#ifndef GRAF_H
#define GRAF_H

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

using Graf = map<int, vector<int>>;

Graf daneWejsciowe(const string& nazwaPliku);

#endif // GRAF_H