#include "customTypes.hpp"
#include "vetor.hpp"

#ifndef SORT_HPP
#define SORT_HPP

void quick_sort(vetor<sudoku_t>& v, vetor<ulong>& indice, long inicio, long fim);

ulong partition(vetor<sudoku_t>& v, vetor<ulong>& indice, long inicio, long fim);

int compara2(const vetor<char>& vet, const vetor<char>& entrada);

#endif //SORT_HPP
