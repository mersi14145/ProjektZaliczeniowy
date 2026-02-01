#ifndef CYKLOMETR_H
#define CYKLOMETR_H

#include "graf.h"
#include <map>
#include <fstream>

using namespace std;

void SZUKACZ(int wierzcholek, const Graf& graf, map<int, bool>& odwiedzone, ofstream& str_wyjsciowy);

#endif // CYKLOMETR_H