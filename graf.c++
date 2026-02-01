#include "graf.h"

using namespace std;

Graf daneWejsciowe(const string& Plik) {
    Graf graf;
    ifstream str_czytający(Plik);
    string linijki;

    while (getline(str_czytający, linijki)) {
        stringstream sl(linijki);  //sl = strumień linii
        string krawedz;

        while (getline(sl, krawedz, ',')) {
            stringstream sk(krawedz); //sk = strumień krawędzi
            int od, doo;
            char a1, a2;    // a1 i a2 to strzałki "->"

            if (sk >> od >> a1 >> a2 >> doo) {
                graf[od].push_back(doo);
            }
        }
    }
    str_czytający.close();
    return graf;
}

