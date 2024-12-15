//
// Created by lutero on 15/12/24.
//

#include "vetor.hpp"
#include "customTypes.hpp"

#ifndef SORT_HPP
#define SORT_HPP

void quick_sort(vetor<sudoku_info_t>& vet, ulong inicio, ulong fim);

ulong partition(vetor<sudoku_info_t>& vet, ulong inicio, ulong fim);

#endif //SORT_HPP
