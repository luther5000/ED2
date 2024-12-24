//
// Created by lutero on 15/12/24.
//

#include "binary_search.hpp"

long busca_binaria(const vetor<sudoku_info_t>& chaves, ullong chave) {
    long inicio = 0, meio = 0, fim = chaves.size() - 1;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (chaves[meio].chave == chave)
            return meio;

        if (chaves[meio].chave > chave)
            fim = meio -1;

        if (chaves[meio].chave < chave)
            inicio = meio + 1;
    }

    return -1;
}

int compara(const vetor<char> &vet, const vetor<char>& entrada) {
    for (ulong i = 0; i < vet.size(); ++i) {
        if (vet[i] > entrada[i]) {
            return 1;
        }

        if (vet[i] < entrada[i]) {
            return -1;
        }
    }
    return 0;
}
