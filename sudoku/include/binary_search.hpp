#include "vetor.hpp"
#include "customTypes.hpp"
#include <iostream>

#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

long busca_binaria(const vetor<sudoku_t>& s, const vetor<ulong>& indice, const vetor<char>& entrada);

int compara(const vetor<char> &vet, const vetor<char>& entrada);

#endif //BINARY_SEARCH_HPP
