/**
 * @file cyklometr.cpp
 * @brief Implementacja DFS z wykrywaniem cykli.
 */

#include "cyklometr.h"
#include <algorithm>

void SZUKACZ(int wierzcholek,
             const Graf& graf,
             std::map<int, bool>& odwiedzone,
             std::map<int, bool>& naStosie,
             std::vector<int>& sciezka,
             std::ofstream& str_wyjsciowy) {

    // oznaczenie wejścia do wierzchołka
    odwiedzone[wierzcholek] = true;
    naStosie[wierzcholek] = true;
    sciezka.push_back(wierzcholek);

    auto it = graf.find(wierzcholek);
    if (it != graf.end()) {
        for (int sasiad : it->second) {

            // przypadek 1: wierzchołek jeszcze nieodwiedzony
            if (!odwiedzone[sasiad]) {
                SZUKACZ(sasiad, graf, odwiedzone, naStosie, sciezka, str_wyjsciowy);
            }
            // przypadek 2: sąsiad jest na stosie -> CYKL
            else if (naStosie[sasiad]) {
                str_wyjsciowy << "CYKL: ";

                auto start = std::find(sciezka.begin(), sciezka.end(), sasiad);
                for (auto i = start; i != sciezka.end(); ++i) {
                    str_wyjsciowy << *i << " ";
                }
                str_wyjsciowy << sasiad << "\n";
            }
        }
    }

    // cofanie DFS
    naStosie[wierzcholek] = false;
    sciezka.pop_back();
}
