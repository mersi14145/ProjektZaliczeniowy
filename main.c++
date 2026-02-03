/**
 * @file main.cpp
 * @brief Punkt wejścia programu. Obsługa argumentów i uruchomienie DFS.
 */

#include <iostream>
#include <cstring>
#include <fstream>

#include "graf.h"
#include "cyklometr.h"

int main(int argc, char* argv[]) {

    if (argc == 1) {
        std::cout << "Schemat uzycia: program -i plik_wej -o plik_wyj\n";
        return 0;
    }

    std::string plikWej;
    std::string plikWyj;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0 && i + 1 < argc)
            plikWej = argv[i + 1];

        if (strcmp(argv[i], "-o") == 0 && i + 1 < argc)
            plikWyj = argv[i + 1];
    }

    Graf graf = daneWejsciowe(plikWej);

    std::ofstream str_wyjsciowy(plikWyj);

    std::map<int, bool> odwiedzone;
    std::map<int, bool> naStosie;
    std::vector<int> sciezka;

    // DFS dla całego grafu (wszystkie składowe)
    for (const auto& p : graf) {
        if (!odwiedzone[p.first]) {
            SZUKACZ(p.first, graf, odwiedzone, naStosie, sciezka, str_wyjsciowy);
        }
    }

    return 0;
}
