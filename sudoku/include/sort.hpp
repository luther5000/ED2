//
// Created by lutero on 15/12/24.
//

#include "customTypes.hpp"
#include "vetor.hpp"

#ifndef SORT_HPP
#define SORT_HPP

void quick_sort(vetor<sudoku_t>& vet, ulong inicio, ulong fim);

ulong partition(vetor<sudoku_t>& vet, ulong inicio, ulong fim);

int compara2(const vetor<char>& vet, const vetor<char>& entrada);

#endif //SORT_HPP
