//
// Created by lutero on 15/12/24.
//

#include "sort.hpp"


void quick_sort(vetor<sudoku_t> &vet, const ulong inicio, const ulong fim) {
    ulong q = 0;
    if (inicio < fim) {
        q = partition(vet, inicio, fim);
        quick_sort(vet, inicio, q);
        quick_sort(vet, q + 1, fim);
    }
}

ulong partition(vetor<sudoku_t> &vet, ulong i, ulong j) {
    vetor<char> pivo = vet[i].entrada;

    while (true) {
        while (compara2(vet[i].entrada, pivo) == -1) {
            ++i;
        }


        while (compara2(vet[j].entrada, pivo) == 1 && j > 0) {
            --j;
        }

        if (i >= j)
            return j;

        vet.swap(i, j);
    }
}

int compara2(const vetor<char> &vet, const vetor<char>& entrada) {
    for (ulong i = 0; i < vet.size(); ++i) {
        if (vet[i] > entrada[i])
            return 1;

        if (vet[i] < entrada[i])
            return -1;
    }
    return 0;
}
