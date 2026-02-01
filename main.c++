#include <iostream>
#include <cstring>
#include <fstream>

#include "graf.h"
#include "cyklometr.h"

using namespace std;


int main(int argc, char* argv[]) {

    if (argc == 1) {
        cout << "Schemat użycia: program -i plik_wej -o plik_wyj" << endl;
        return 0;
    }

    string flagaPWe = "-i";
    string pWejsciowy;

    string flagaPWy = "-o";
    string pWynikowy;
    
    for(int i = argc - 1; i > 0; i--) {
        
        if(strcmp(argv[i], "-i") == 0 && i + 1 < argc)    {
            cout << "znaleziono flage: " << flagaPWe << endl <<  "Dla pliku wejściowego: " << argv[i + 1] << endl;
            pWejsciowy =  argv[i + 1];
        }

        if(strcmp(argv[i], "-o") == 0 && i + 1 < argc)    {
            cout << "znaleziono flage: " << flagaPWy << endl <<  "Dla pliku wynikowego: " << argv[i + 1] << endl;
            pWynikowy =  argv[i + 1];
        }
        
    }

    Graf graf = daneWejsciowe(pWejsciowy);

    ofstream str_wyjsciowy(pWynikowy);
    map<int, bool> odwiedzone;
    
    int start = graf.begin()->first;
    SZUKACZ(start, graf, odwiedzone, str_wyjsciowy);

    str_wyjsciowy.close();

    return 0;

    

}
