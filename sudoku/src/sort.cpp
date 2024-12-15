//
// Created by lutero on 15/12/24.
//

#include "sort.hpp"


void quick_sort(vetor<sudoku_info_t> &vet, const ulong inicio, const ulong fim) {
    ulong q = 0;
    if (inicio < fim) {
        q = partition(vet, inicio, fim);
        quick_sort(vet, inicio, q);
        quick_sort(vet, q + 1, fim);
    }
}

ulong partition(vetor<sudoku_info_t> &vet, ulong i, ulong j) {
    ullong pivo = vet[i].chave;

    while (true) {
        while (vet[i].chave < pivo)
            ++i;

        while (vet[j].chave > pivo)
            --j;

        if (i >= j)
            return j;

        vet.swap(i, j);
    }
}


