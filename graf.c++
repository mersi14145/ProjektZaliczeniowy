/**
 * @file graf.cpp
 * @brief Implementacja funkcji wczytującej graf z pliku.
 */

#include "graf.h"
#include <fstream>
#include <sstream>

Graf daneWejsciowe(const std::string& Plik) {
    Graf graf;
    std::ifstream str_czytajacy(Plik);
    std::string linia;

    while (getline(str_czytajacy, linia)) {
        std::stringstream ss_linia(linia);
        std::string fragment;

        // rozbijanie po przecinkach
        while (getline(ss_linia, fragment, ',')) {
            std::stringstream ss(fragment);
            int od, doo;
            char a1, a2; // '-' i '>'

            if (ss >> od >> a1 >> a2 >> doo) {
                graf[od].push_back(doo);
            }
        }
    }

    return graf;
}
