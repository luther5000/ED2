//
// Created by lutero on 15/12/24.
//

#include "sort.hpp"


void quick_sort(vetor<sudoku_info_t>& indice, const ulong inicio, const ulong fim) {
    ulong q = 0;
    if (inicio < fim) {
        q = partition(indice, inicio, fim);
        quick_sort(indice, inicio, q);
        quick_sort(indice, q + 1, fim);
    }
}

ulong partition(vetor<sudoku_info_t>& indice, ulong i, ulong j) {
    ullong pivo = indice[i].chave;

    while (true) {
        while (indice[i].chave < pivo) {
            ++i;
        }


        while (indice[j].chave > pivo && j > 0) {
            --j;
        }

        if (i >= j)
            return j;

        indice.swap(i, j);
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
