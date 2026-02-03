/**
 * @file graf.h
 * @brief Definicja struktury grafu oraz funkcji wczytującej dane z pliku.
 */

#ifndef GRAF_H
#define GRAF_H

#include <map>
#include <vector>
#include <string>

/**
 * @brief Reprezentacja grafu jako lista sąsiedztwa.
 *
 * Klucz mapy to numer wierzchołka,
 * wartość to lista jego sąsiadów (krawędzie wychodzące).
 */
using Graf = std::map<int, std::vector<int>>;

/**
 * @brief Wczytuje graf skierowany z pliku.
 *
 * Format danych wejściowych:
 * 1 -> 2, 1 -> 3, 2 -> 4
 *
 * @param nazwaPliku Ścieżka do pliku wejściowego
 * @return Graf w postaci mapy sąsiedztwa
 */
Graf daneWejsciowe(const std::string& nazwaPliku);

#endif
