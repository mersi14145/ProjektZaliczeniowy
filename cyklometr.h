/**
 * @file cyklometr.h
 * @brief Deklaracja algorytmu DFS wykrywającego cykle.
 */

#ifndef CYKLOMETR_H
#define CYKLOMETR_H

#include "graf.h"
#include <map>
#include <vector>
#include <fstream>

/**
 * @brief Rekurencyjny DFS wykrywający cykle w grafie skierowanym.
 *
 * @param wierzcholek Aktualny wierzchołek DFS
 * @param graf Graf w postaci listy sąsiedztwa
 * @param odwiedzone Informacja, czy wierzchołek był już odwiedzony
 * @param naStosie Informacja, czy wierzchołek jest aktualnie na stosie DFS
 * @param sciezka Aktualna ścieżka DFS (do odtwarzania cyklu)
 * @param str_wyjsciowy Strumień do pliku wynikowego
 */
void SZUKACZ(int wierzcholek,
             const Graf& graf,
             std::map<int, bool>& odwiedzone,
             std::map<int, bool>& naStosie,
             std::vector<int>& sciezka,
             std::ofstream& str_wyjsciowy);

#endif
