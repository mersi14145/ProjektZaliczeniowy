#include "cyklometr.h"

using namespace std;

void SZUKACZ(int wierzcholek, const Graf& graf, map<int, bool>& odwiedzone, ofstream& str_wyjsciowy) {
    odwiedzone[wierzcholek] = true;
    str_wyjsciowy << wierzcholek << " ";

    auto it = graf.find(wierzcholek); // it to iterator do pary klucz-wartość. A find zwraca iterator do elementu lub graf.end() jeśli nie znaleziono.
    if (it != graf.end()) {
        for (int sasiad : it->second) {
            if (!odwiedzone[sasiad]) {
                SZUKACZ(sasiad, graf, odwiedzone, str_wyjsciowy);
                
            }
        }
    }
}